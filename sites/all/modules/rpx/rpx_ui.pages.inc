<?php
// $Id: rpx_ui.pages.inc,v 1.5 2011/01/16 21:40:02 geokat Exp $

/**
 * @file
 * User page callback file for the rpx_ui module.
 */

/**
 * Menu callback; manage Engage 3rd party identities for the specified user.
 */
function rpx_user_identities($account) {
  drupal_set_title(format_username($account));

  $header = array(t('Account type'), t('Janrain Engage Identifier'), t('Operations'));
  $rows = array();

  $result = db_query("SELECT * FROM {authmap} WHERE module = :module AND uid = :uid", array(':module' => 'rpx_core', ':uid' => $account->uid));

  foreach ($result as $identity) {
    $provider = _rpx_get_identity_provider($identity->authname);
    $rows[] = array(
      theme('rpx_icon', array('provider' => $provider['name'])) . ' ' . $provider['title'],
      check_plain($identity->authname),
      l(t('Delete'), 'user/' . $account->uid . '/rpx/delete/' . $identity->aid),
    );
  }

  rpx_js();
  $realm = variable_get('rpx_realm', '');
  $realm_scheme = variable_get('rpx_realm_scheme', 'http');
  $sign_in_url = "$realm_scheme://$realm/openid/v2/signin";
  $token_url = _rpx_token_url(array('add_to_account' => 'true'));

  $links['add_id'] = array(
    'title' => t('Add identity'),
    'href' => $sign_in_url,
    'query' => array('token_url' => $token_url),
    'attributes' => array('class' => 'rpxnow', 'onclick' => 'return false;'),
  );

  $build['add_link'] = array(
    '#theme' => 'links',
    '#links' => $links,
    '#attributes' => array('class' => array('action-links')),
  );

  $build['rpx_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $build;
}

/**
 * Menu callback; Delete the specified Engage identity from the system.
 */
function rpx_user_delete_form($form, $form_state, $account, $aid = 0) {
  $authname = db_query("SELECT authname FROM {authmap} WHERE uid = :uid AND aid = :aid AND module = 'rpx_core'", array(
    ':uid' => $account->uid,
    ':aid' => $aid,
  ))
  ->fetchField();

  if (!$authname) {
    drupal_not_found();
    drupal_exit();
  }

  return confirm_form(array(), t('Are you sure you want to delete the Janrain Engage ID %authname for %user?', array('%authname' => $authname, '%user' => $account->name)), 'user/' . $account->uid . '/rpx');
}

/**
 * Handle identity deletion by removing {authmap} entry.
 */
function rpx_user_delete_form_submit($form, &$form_state) {
  $uid = $form_state['build_info']['args'][0]->uid;
  $aid = $form_state['build_info']['args'][1];

  $rpxid = db_query('SELECT authname FROM {authmap} WHERE uid = :uid AND aid = :aid AND module = :module', array(
    ':uid' => $uid,
    ':aid' => $aid,
    ':module' => 'rpx_core',
  ))->fetchField();

  $query = db_delete('authmap')
    ->condition('uid', $uid)
    ->condition('aid', $form_state['build_info']['args'][1])
    ->condition('module', 'rpx_core')
    ->execute();

  if ($query) {
    drupal_set_message(t('Janrain Engage ID deleted.'));

    // Let other modules (e.g. rpx_rules) know that a linked account has been
    // removed.
    $user = user_load($uid);
    $account = array(
      'user' => $user,
      'id' => $rpxid,
    );
    module_invoke_all('rpx_linked_account', 'deleted', $account);
  }
  $form_state['redirect'] = 'user/' . $uid . '/rpx';
}
