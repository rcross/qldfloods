<?php

/**
 * Implementation of hook_views_default_views().
 */
function open_bed_admin_views_default_views() {
  $views = array();

  // Exported view: open_beds_admin_view
  $view = new view;
  $view->name = 'open_beds_admin_view';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'open_beds_admin_view';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Open Beds';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Field: Node: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 1;
  /* Field: Fields: field_no_beds */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'field_data_field_no_beds';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = 'Beds';
  $handler->display->display_options['fields']['entity_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['entity_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Fields: field_pets */
  $handler->display->display_options['fields']['entity_id_1']['id'] = 'entity_id_1';
  $handler->display->display_options['fields']['entity_id_1']['table'] = 'field_data_field_pets';
  $handler->display->display_options['fields']['entity_id_1']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id_1']['label'] = 'Pets';
  $handler->display->display_options['fields']['entity_id_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_id_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_id_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_id_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id_1']['empty_zero'] = 0;
  /* Field: Fields: field_length_of_stay */
  $handler->display->display_options['fields']['entity_id_3']['id'] = 'entity_id_3';
  $handler->display->display_options['fields']['entity_id_3']['table'] = 'field_data_field_length_of_stay';
  $handler->display->display_options['fields']['entity_id_3']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id_3']['label'] = 'Length of stay';
  $handler->display->display_options['fields']['entity_id_3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_id_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_id_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id_3']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_id_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_id_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id_3']['empty_zero'] = 0;
  /* Field: Fields: field_availability */
  $handler->display->display_options['fields']['entity_id_2']['id'] = 'entity_id_2';
  $handler->display->display_options['fields']['entity_id_2']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['entity_id_2']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id_2']['label'] = 'Availability';
  $handler->display->display_options['fields']['entity_id_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_id_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_id_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_id_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_id_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id_2']['empty_zero'] = 0;
  /* Field: Fields: field_contact_name */
  $handler->display->display_options['fields']['entity_id_5']['id'] = 'entity_id_5';
  $handler->display->display_options['fields']['entity_id_5']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['entity_id_5']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id_5']['label'] = 'Name';
  $handler->display->display_options['fields']['entity_id_5']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id_5']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id_5']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id_5']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_id_5']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_id_5']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id_5']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id_5']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id_5']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_id_5']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_id_5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id_5']['empty_zero'] = 0;
  /* Field: Fields: field_contact_email */
  $handler->display->display_options['fields']['entity_id_4']['id'] = 'entity_id_4';
  $handler->display->display_options['fields']['entity_id_4']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['entity_id_4']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id_4']['label'] = 'Email';
  $handler->display->display_options['fields']['entity_id_4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_id_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_id_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id_4']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_id_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_id_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id_4']['empty_zero'] = 0;
  /* Field: Fields: field_contact_number */
  $handler->display->display_options['fields']['entity_id_6']['id'] = 'entity_id_6';
  $handler->display->display_options['fields']['entity_id_6']['table'] = 'field_data_field_contact_number';
  $handler->display->display_options['fields']['entity_id_6']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id_6']['label'] = 'Phone';
  $handler->display->display_options['fields']['entity_id_6']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id_6']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id_6']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id_6']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_id_6']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_id_6']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id_6']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id_6']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id_6']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_id_6']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_id_6']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id_6']['empty_zero'] = 0;
  /* Field: Taxonomy: All terms */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'Suburb';
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['tid']['limit'] = 1;
  $handler->display->display_options['fields']['tid']['vocabularies'] = array(
    'suburb' => 'suburb',
    'tags' => 0,
    'free_tags' => 0,
    'qld_floods' => 0,
  );
  /* Sort criterion: Node: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'open_bed' => 'open_bed',
  );
  /* Filter: Node: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['single'] = TRUE;
  /* Filter: Fields: field_address (field_address) - value */
  $handler->display->display_options['filters']['field_address_value']['id'] = 'field_address_value';
  $handler->display->display_options['filters']['field_address_value']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_value']['field'] = 'field_address_value';
  $handler->display->display_options['filters']['field_address_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_address_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_address_value']['expose']['operator'] = 'field_address_value_op';
  $handler->display->display_options['filters']['field_address_value']['expose']['label'] = 'Address';
  $handler->display->display_options['filters']['field_address_value']['expose']['identifier'] = 'a';
  $handler->display->display_options['filters']['field_address_value']['expose']['single'] = TRUE;
  /* Filter: Taxonomy: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Suburb';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 's';
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'suburb';
  $handler->display->display_options['filters']['tid']['error_message'] = 0;
  /* Filter: Fields: field_availability (field_availability) */
  $handler->display->display_options['filters']['field_availability_value']['id'] = 'field_availability_value';
  $handler->display->display_options['filters']['field_availability_value']['table'] = 'field_data_field_availability';
  $handler->display->display_options['filters']['field_availability_value']['field'] = 'field_availability_value';
  $handler->display->display_options['filters']['field_availability_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_availability_value']['expose']['operator'] = 'field_availability_value_op';
  $handler->display->display_options['filters']['field_availability_value']['expose']['label'] = 'Availability';
  $handler->display->display_options['filters']['field_availability_value']['expose']['identifier'] = 'av';
  $handler->display->display_options['filters']['field_availability_value']['expose']['reduce'] = 0;
  /* Filter: Fields: field_no_beds (field_no_beds) */
  $handler->display->display_options['filters']['field_no_beds_value']['id'] = 'field_no_beds_value';
  $handler->display->display_options['filters']['field_no_beds_value']['table'] = 'field_data_field_no_beds';
  $handler->display->display_options['filters']['field_no_beds_value']['field'] = 'field_no_beds_value';
  $handler->display->display_options['filters']['field_no_beds_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_no_beds_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_no_beds_value']['expose']['operator'] = 'field_no_beds_value_op';
  $handler->display->display_options['filters']['field_no_beds_value']['expose']['label'] = 'Beds';
  $handler->display->display_options['filters']['field_no_beds_value']['expose']['identifier'] = 'b';
  $handler->display->display_options['filters']['field_no_beds_value']['expose']['single'] = TRUE;
  /* Filter: Fields: field_options (field_options) */
  $handler->display->display_options['filters']['field_options_value']['id'] = 'field_options_value';
  $handler->display->display_options['filters']['field_options_value']['table'] = 'field_data_field_options';
  $handler->display->display_options['filters']['field_options_value']['field'] = 'field_options_value';
  $handler->display->display_options['filters']['field_options_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_options_value']['expose']['operator'] = 'field_options_value_op';
  $handler->display->display_options['filters']['field_options_value']['expose']['label'] = 'Options';
  $handler->display->display_options['filters']['field_options_value']['expose']['identifier'] = 'options';
  $handler->display->display_options['filters']['field_options_value']['expose']['single'] = 0;
  $handler->display->display_options['filters']['field_options_value']['expose']['reduce'] = 0;
  /* Filter: Fields: field_length_of_stay (field_length_of_stay) */
  $handler->display->display_options['filters']['field_length_of_stay_value']['id'] = 'field_length_of_stay_value';
  $handler->display->display_options['filters']['field_length_of_stay_value']['table'] = 'field_data_field_length_of_stay';
  $handler->display->display_options['filters']['field_length_of_stay_value']['field'] = 'field_length_of_stay_value';
  $handler->display->display_options['filters']['field_length_of_stay_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_length_of_stay_value']['expose']['operator'] = 'field_length_of_stay_value_op';
  $handler->display->display_options['filters']['field_length_of_stay_value']['expose']['label'] = 'Length of stay';
  $handler->display->display_options['filters']['field_length_of_stay_value']['expose']['identifier'] = 'stay';
  $handler->display->display_options['filters']['field_length_of_stay_value']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/content/open-beds';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Open Beds';
  $handler->display->display_options['menu']['weight'] = '10';
  $translatables['open_beds_admin_view'] = array(
    t('Defaults'),
    t('Open Beds'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('ID'),
    t('Beds'),
    t('Pets'),
    t('Length of stay'),
    t('Availability'),
    t('Name'),
    t('Email'),
    t('Phone'),
    t('Suburb'),
    t('Address'),
    t('Options'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;
}
