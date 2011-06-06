<?php

/**
 * Implementation of hook_field_group_default_field_groups().
 */
function open_bed_field_group_default_field_groups() {
  $field_groups = array();

  // Exported field_group: 'node-open_bed-form-group_admin_only'
  $field_groups['node-open_bed-form-group_admin_only'] = array(
    'group_name' => 'group_admin_only',
    'entity_type' => 'node',
    'bundle' => 'open_bed',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Admin Only',
    'weight' => '6',
    'children' => array(
      '0' => 'field_contact_screened',
      '1' => 'field_contact_screened_by',
      '2' => 'field_contact_screened_date',
      '3' => 'field_assisted',
      '4' => 'field_journal',
      '5' => 'field_validation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Admin Only',
      'instance_settings' => array(
        'classes' => 'admin',
      ),
      'formatter' => 'collapsible',
    ),
  );

  // Exported field_group: 'node-open_bed-form-group_basics'
  $field_groups['node-open_bed-form-group_basics'] = array(
    'group_name' => 'group_basics',
    'entity_type' => 'node',
    'bundle' => 'open_bed',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Basics',
    'weight' => '1',
    'children' => array(
      '0' => 'field_no_beds',
      '1' => 'field_length_of_stay',
      '2' => 'field_bathrooms',
      '3' => 'field_date_from',
      '4' => 'field_date_to',
      '5' => 'field_no_doubles',
      '6' => 'field_no_futons',
      '7' => 'field_no_singles',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-open_bed-form-group_contact'
  $field_groups['node-open_bed-form-group_contact'] = array(
    'group_name' => 'group_contact',
    'entity_type' => 'node',
    'bundle' => 'open_bed',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Contact Details',
    'weight' => '3',
    'children' => array(
      '0' => 'field_contact_details',
      '1' => 'field_contact_name',
      '2' => 'field_contact_number',
      '3' => 'field_contact_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-open_bed-form-group_details'
  $field_groups['node-open_bed-form-group_details'] = array(
    'group_name' => 'group_details',
    'entity_type' => 'node',
    'bundle' => 'open_bed',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Details',
    'weight' => '5',
    'children' => array(
      '0' => 'body',
      '1' => 'field_image',
      '2' => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'details',
      ),
      'formatter' => 'collapsible',
    ),
  );

  // Exported field_group: 'node-open_bed-form-group_location'
  $field_groups['node-open_bed-form-group_location'] = array(
    'group_name' => 'group_location',
    'entity_type' => 'node',
    'bundle' => 'open_bed',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Location',
    'weight' => '2',
    'children' => array(
      '0' => 'field_suburb',
      '1' => 'field_address',
      '2' => 'field_zip',
      '3' => 'field_state',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );

  // Exported field_group: 'node-open_bed-form-group_preferences'
  $field_groups['node-open_bed-form-group_preferences'] = array(
    'group_name' => 'group_preferences',
    'entity_type' => 'node',
    'bundle' => 'open_bed',
    'mode' => 'form',
    'parent_name' => '',
    'label' => 'Preferences',
    'weight' => '4',
    'children' => array(
      '0' => 'field_pets',
      '1' => 'field_options',
      '2' => 'field_animal_details',
      '3' => 'field_children',
      '4' => 'field_elderly',
      '5' => 'field_elderly_details',
      '6' => 'field_preferences',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Preferences',
      'instance_settings' => array(
        'classes' => 'preferences',
      ),
      'formatter' => 'collapsed',
    ),
  );

  return $field_groups;
}
