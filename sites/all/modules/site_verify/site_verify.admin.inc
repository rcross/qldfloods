<?php
// $Id: site_verify.admin.inc,v 1.18 2010/08/12 14:32:03 davereid Exp $

function site_verify_list() {
  $engines = site_verify_get_engines();
  $destination = drupal_get_destination();

  $header = array(
    array('data' => t('Engine'), 'field' => 'engine'),
    array('data' => t('Meta tag'), 'field' => 'meta'),
    array('data' => t('File'), 'field' => 'file'),
    array('data' => t('Operations')),
  );

  $query = db_select('site_verify');
  $query->fields('site_verify');
  $query->extend('TableSort')->orderByHeader($header);
  //$query->extend('PagerDefault')->limit(50);
  $verifications = $query->execute();

  $rows = array();
  foreach ($verifications as $verification) {
    $row = array('data' => array());
    $row['data'][] = $engines[$verification->engine]['name'];
    $row['data'][] = $verification->meta ? '<span title="' . check_plain(truncate_utf8($verification->meta, 48)) . '">' . t('Yes') . '</spam>' : t('No');
    $row['data'][] = $verification->file ? l($verification->file, $verification->file) : t('None');
    $operations = array();
    $operations['edit'] = array(
      'title' => t('Edit'),
      'href' => 'admin/config/search/verifications/edit/' . $verification->svid,
      'query' => $destination,
    );
    $operations['delete'] = array(
      'title' => t('Delete'),
      'href' => 'admin/config/search/verifications/delete/' . $verification->svid,
      'query' => $destination,
    );
    $row['data']['operations'] = array(
      'data' => array(
        '#theme' => 'links',
        '#links' => $operations,
        '#attributes' => array('class' => array('links', 'inline')),
      ),
    );
    $rows[] = $row;
  }

  $build['verification_tabe'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No verifications available. <a href="@add">Add verification</a>.', array('@add' => url('admin/config/search/verifications/add'))),
  );
  //$build['verification_pager'] = array('#theme' => 'pager');
  return $build;
}

function site_verify_edit_form($form, &$form_state, $record = array(), $engine = NULL) {
  if (!isset($form_state['storage']['step'])) {
    $record += array(
      'svid' => NULL,
      'file' => '',
      'file_contents' => t('This is a verification page.'),
      'meta' => '',
      'engine' => $engine,
    );
    $form_state['storage']['record'] = $record;
    $form_state['storage']['step'] = $record['engine'] ? 2 : 1;
  }
  else {
    $record = $form_state['storage']['record'];
  }

  $form['actions'] = array('#type' => 'actions');

  switch ($form_state['storage']['step']) {
    case 1:
      $engines = site_verify_get_engines();
      $options = array();
      foreach ($engines as $key => $engine) {
        $options[$key] = $engine['name'];
      }
      asort($options);

      $form['engine'] = array(
        '#type' => 'select',
        '#title' => t('Search engine'),
        '#options' => $options,
      );
      $form['actions']['next'] = array(
        '#type' => 'submit',
        '#value' => t('Next'),
      );
      break;
    case 2:

      $form['svid'] = array(
        '#type' => 'value',
        '#value' => $record['svid'],
      );
      $form['engine'] = array(
        '#type' => 'value',
        '#value' => $record['engine']['key'],
      );
      $form['engine_name'] = array(
        '#type' => 'item',
        '#title' => t('Search engine'),
        '#value' => $record['engine']['name'],
      );
      $form['#engine'] = $record['engine'];

      $form['meta'] = array(
        '#type' => 'textfield',
        '#title' => t('Verification META tag'),
        '#default_value' => $record['meta'],
        '#description' => t('This is the full meta tag provided for verification. Note that this meta tag will only be visible in the source code of your <a href="@frontpage">front page</a>.', array('@front-page' => url('<front>'))),
        '#element_validate' => $record['engine']['meta_validate'],
        '#access' => $record['engine']['meta'],
      );

      $form['file_upload'] = array(
        '#type' => 'file',
        '#title' => t('Upload an existing verification file'),
        '#description' => t('If you have been provided with an actual file, you can simply upload the file.'),
        '#access' => $record['engine']['file'],
      );
      $form['file'] = array(
        '#type' => 'textfield',
        '#title' => t('Verification file'),
        '#default_value' => $record['file'],
        '#description' => t('The name of the HTML verification file you were asked to upload.'),
        '#element_validate' => $record['engine']['file_validate'],
        '#access' => $record['engine']['file'],
      );
      $form['file_contents'] = array(
        '#type' => 'textarea',
        '#title' => t('Verification file contents'),
        '#default_value' => $record['file_contents'],
        '#element_validate' => $record['engine']['file_contents_validate'],
        '#wysiwyg' => FALSE,
        '#access' => $record['engine']['file_contents'],
      );
      if (!variable_get('clean_url', 0)) {
        drupal_set_message(t('Using verification files will not work if <a href="@clean-urls">clean URLs</a> are disabled.', array('@clean-urls' => url('admin/settings/clean-url'))), 'error', FALSE);
        $form['file']['#disabled'] = TRUE;
        $form['file_contents']['#disabled'] = TRUE;
        $form['file_upload']['#disabled'] = TRUE;
      }

      if ($record['engine']['file']) {
        $form['#validate'][] = 'site_verify_validate_file';
        $form['#attributes'] = array('enctype' => 'multipart/form-data');
      }

      $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save'),
        '#weight' => 10,
      );
      break;
  }

  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#href' => isset($_GET['destination']) ? $_GET['destination'] : 'admin/config/search/verifications',
    '#title' => t('Cancel'),
    '#weight' => 15,
  );

  return $form;
}

/**
 * Validation callback; save the uploaded file and check file name uniqueness.
 */
function site_verify_validate_file($form, &$form_state) {
  $values = &$form_state['values'];

  // Import the uploaded verification file.
  $validators = array('file_validate_extensions' => array());
  if ($file = file_save_upload('file_upload', $validators, FALSE, FILE_EXISTS_REPLACE)) {
    $contents = @file_get_contents($file->uri);
    file_delete($file);
    if ($contents === FALSE) {
      drupal_set_message(t('The verification file import failed, because the file %filename could not be read.', array('%filename' => $file->filename)), 'error');
    }
    else {
      $values['file'] = $file->filename;
      $values['file_contents'] = $contents;
      //drupal_set_message(t('The verification file <a href="@filename">@filename</a> was successfully imported.', array('@filename' => $file->filename)));
    }
  }

  if ($values['file']) {
    $existing_file = db_query("SELECT svid FROM {site_verify} WHERE LOWER(file) = LOWER(:file) AND svid <> :svid", array(':file' => $values['file'], 'svid' => $values['svid']))->fetchField();
    if ($existing_file) {
      form_set_error('file', t('The file %filename is already being used in another verification.', array('%filename' => $values['file'])));
    }
  }
}

/**
 * Submission callback; send form to the next step or save the verification.
 */
function site_verify_edit_form_submit($form, &$form_state) {
  if ($form_state['storage']['step'] == 1) {
    // Send the form to step 2 (verification details).
    $form_state['storage']['record']['engine'] = site_verify_engine_load($form_state['values']['engine']);
    $form_state['storage']['step']++;
    $form_state['rebuild'] = TRUE;
  }
  else {
    // Save the verification to the database.
    if ($form_state['values']['svid']) {
      drupal_write_record('site_verify', $form_state['values'], array('svid'));
    }
    else {
      drupal_write_record('site_verify', $form_state['values']);
    }

    drupal_set_message(t('Verification saved.'));
    $form_state['storage'] = $form_state['rebuild'] = NULL;
    $form_state['redirect'] = 'admin/config/search/verifications';

    // The menu needs to be rebuilt if the page URL has changed or reset.
    variable_set('menu_rebuild_needed', TRUE);
  }
}

function site_verify_delete_form($form, $form_state, $record) {
  $form['record'] = array(
    '#type' => 'value',
    '#value' => $record,
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete the site verification for %engine?', array('%engine' => $record['engine']['name'])),
    'admin/config/search/verifications',
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

function site_verify_delete_form_submit($form, &$form_state) {
  $record = $form_state['values']['record'];
  db_query("DELETE FROM {site_verify} WHERE svid = %d", $record['svid']);
  drupal_set_message(t('Verification for %engine has been deleted.', array('%engine' => $record['engine']['name'])));
  watchdog('site_verify', 'Verification for %engine deleted.', array('%engine' => $record['engine']['name']), WATCHDOG_NOTICE);
  $form_state['redirect'] = 'admin/config/search/verifications';
}

function site_verify_validate_meta_google($element, &$form_state) {
  $value = strtolower(trim($element['#value']));
  if ($value != '' && !preg_match('%\A<meta name="verify-v1" content="[\S]+" />\Z%', $value)) {
    form_error($element, t('Invalid verification meta tag.'));
  }
}

function site_verify_validate_page_google($element, &$form_state) {
  $value = strtolower(trim($element['#value']));
  if ($value != '' && !preg_match('%\Agoogle[\da-f]+\.html\Z%', $value)) {
    form_error($element, t('Invalid verification file.'));
  }
}