<?php
// $Id$

/**
 * Callback for settings form.
 * Turn monitoring on or off and refresh the reference data.
 */
function browscap_settings() {
  $version = variable_get('browscap_version', 0);
  $form['browscap_data_status'] = array(
    '#markup' => '<p>' . t('Current browscap data version: %fileversion.',
                   array('%fileversion' => $version ? $version : t('Never fetched'))) . '</p>',
  );

  $form['browscap_monitor'] = array(
    '#type' => 'checkbox',
    '#title' => t('Monitor browsers'),
    '#default_value' => variable_get('browscap_monitor', FALSE),
    '#description' => t('Monitor all user agents visiting the site.'),
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  $form['refresh'] = array(
    '#type' => 'submit',
    '#value' => t('Refresh browscap data'),
  );

  return $form;
}

/**
 * Submit handler for settings page.
 */
function browscap_settings_submit($form, &$form_state) {
  switch ($form_state['clicked_button']['#id']) {
    case 'edit-save':
      variable_set('browscap_monitor', $form_state['values']['browscap_monitor']);
      break;

    case 'edit-refresh':
      _browscap_import(FALSE);
      break;
  }

}

/**
 * Menu callback; presents the user agents monitoring page.
 *
 * @param $view
 *   - "browsers": Only display "real" browsers
 *   - "crawlers": Only display search engine crawlers
 *   - "all": Display all user agents.
 */
function browscap_top_useragents($view = 'all') {
  $header = array(
    0 => array('data' => t('User agent'), 'field' => 'parent'),
    1 => array('data' => t('Count'), 'field' => 'counter', 'sort' => 'desc'),
    2 => array('data' => t('Percent'), 'field' => 'counter'),
    3 => array('data' => t('Crawler?'), 'field' => 'is_crawler')
  );

  $query_total = db_select('browscap_statistics', 'bs');
  $query_total->addExpression('SUM(bs.counter)');

  $query = db_select('browscap_statistics', 'bs')
    ->fields('bs', array('parent', 'counter', 'is_crawler'))
    ->extend('PagerDefault')
    ->extend('TableSort')
    ->limit(50)
    ->orderByHeader($header);

  switch ($view) {
    case 'browsers':
      $title = t('Top browsers');
      $header[0]['data'] = t('Browser');
      unset($header[3]);
      $query->condition('is_crawler', 0);
      $query_total->condition('is_crawler', 0);
      break;

    case 'crawlers':
      $title = t('Top crawlers');
      $header[0]['data'] = t('Crawler');
      unset($header[3]);
      $query->condition('is_crawler', 1);
      $query_total->condition('is_crawler', 1);
      break;

    default:
      $title = t('Top user agents');
      break;
  }
  drupal_set_title($title);

  $total = $query_total
    ->execute()
    ->fetchField();
  if (!$total) {
    $total = 1;
  }

  $result = $query->execute();

  $rows = array();
  foreach ($result as $useragent) {
    $exists = (bool) db_query_range('SELECT 1 FROM {browscap} WHERE useragent = :useragent', 0, 1,
      array(':useragent' => $useragent->parent))
      ->fetchField();

    if ($exists) {
      $parent = l($useragent->parent, 'admin/reports/browscap/useragent/' . urlencode($useragent->parent));
    }
    else {
      $parent = check_plain($useragent->parent);
    }
    $tablerow = array();
    $tablerow[] = $parent;
    $tablerow[] = $useragent->counter;
    $tablerow[] = round(100 * $useragent->counter / $total, 4);
    if (!in_array($view, array('browsers', 'crawlers'))) {
      $tablerow[] = $useragent->is_crawler ? t('Yes') : t('No');
    }
    $rows[] = $tablerow;
  }

  $build['browscap_statistics_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('It appears that your site has not recorded any visits. If you want to record the visitors to your site you can enable "Monitor browsers" on the <a href="!settings_uri">Browscap settings screen</a>.', array('!settings_uri' => url('admin/reports/browscap/settings'))),
  );
  $build['browscap_statistics_pager'] = array(
    '#theme' => 'pager',
  );

  return $build;
}

/**
 * If there's a new version of browscap.csv, fetch it and update the database.
 */
function _browscap_import($cron = TRUE) {
  // Try to allocate enough time to parse and import the data.
  drupal_set_time_limit(240);

  // Politely check the version for updates before fetching the file
  $versionpage = drupal_http_request('http://browsers.garykeith.com/versions/version-number.asp');
  if (isset($versionpage->error)) {
    watchdog('browscap', "Couldn't check version: %error", array('%error' => $versionpage->error), WATCHDOG_ERROR);
    if (!$cron) {
      drupal_set_message(t("Couldn't check version: %error", array('%error' => $versionpage->error)), 'error');
    }
    return;
  }

  $browscapversion = trim($versionpage->data);
  $oldversion = variable_get('browscap_version', 0);
  if ($browscapversion == $oldversion) {
    // No update, nothing to do here
    watchdog('browscap', 'No new version of browscap to import.');
    if (!$cron) {
      drupal_set_message(t('No new version of browscap to import.'));
    }
    return;
  }

  // Fetch the new version, and dump it in the temp directory
  $server = $_SERVER['SERVER_NAME'];
  $path = variable_get('file_directory_temp', '/tmp');
  $browscapfile = "$path/browscap_$server.ini";

  $browscap = drupal_http_request('http://browsers.garykeith.com/stream.asp?PHP_BrowsCapINI');
  if (isset($browscap->error) || empty($browscap)) {
    watchdog('browscap', "Couldn't retrieve updated browscap: %error", array('%error' => $browscap->error), WATCHDOG_ERROR);
    if (!$cron) {
      drupal_set_message(t("Couldn't retrieve updated browscap: %error", array('%error' => $browscap->error)), 'error');
    }
    return;
  }

  $browscapfp = fopen($browscapfile, "w");
  fwrite($browscapfp, $browscap->data);
  fclose($browscapfp);

  $a = parse_ini_file($browscapfile, TRUE);
  if ($a) {
    // the first entry in the array is the version info
    $version = array_shift($a);
    foreach ($a as $key => $vals) {
      $e = $vals;
      // some recursive magic!
      $last_parent = array();
      while (isset($vals['Parent']) && $vals['Parent'] !== $last_parent) {
        $vals = isset($a[$vals['Parent']]) ? $a[$vals['Parent']] : array();
        $e = array_merge($vals, $e);
        $last_parent = $vals;
      }
      $useragent = strtr($key, '*?', '%_');
      $e = array_change_key_case($e);
      db_delete('browscap')
        ->condition('useragent', $useragent)
        ->execute();
      db_insert('browscap')
        ->fields(array(
         'useragent' => $useragent,
         'data' => serialize($e)
        ))
        ->execute();
    }

    cache_clear_all('*', 'cache_browscap', TRUE);
    variable_set('browscap_version', $browscapversion);
    watchdog('browscap', 'New version of browscap imported: %version', array('%version' => $browscapversion));
    if (!$cron) {
      drupal_set_message(t('New version of browscap imported: %version', array('%version' => $browscapversion)));
    }
  }
}

/**
 * Page callback to show details about known useragents.
 *
 * @param $useragent
 *   The useragent object, loaded from the database.
 * @return array
 *   the data about this useragent.
 */
function browscap_useragent_properties(array $useragent) {
  $header = array(
    t('Property'),
    t('Value'),
  );
  $rows = array();
  foreach ($useragent as $key => $val) {
    $rows[] = array(check_plain($key), check_plain($val));
  }
  $build = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#attributes' => array('id' => 'browscap-useragent'),
    '#empty' => t('No useragent properties available.'),
  );
  return $build;
}
