<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function open_bed_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer field permissions
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: create field_assisted
  $permissions['create field_assisted'] = array(
    'name' => 'create field_assisted',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: create field_contact_screened
  $permissions['create field_contact_screened'] = array(
    'name' => 'create field_contact_screened',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: create field_contact_screened_by
  $permissions['create field_contact_screened_by'] = array(
    'name' => 'create field_contact_screened_by',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: create field_contact_screened_date
  $permissions['create field_contact_screened_date'] = array(
    'name' => 'create field_contact_screened_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: create field_journal
  $permissions['create field_journal'] = array(
    'name' => 'create field_journal',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: create field_source
  $permissions['create field_source'] = array(
    'name' => 'create field_source',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: create field_validation
  $permissions['create field_validation'] = array(
    'name' => 'create field_validation',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: edit field_assisted
  $permissions['edit field_assisted'] = array(
    'name' => 'edit field_assisted',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: edit field_contact_screened
  $permissions['edit field_contact_screened'] = array(
    'name' => 'edit field_contact_screened',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: edit field_contact_screened_by
  $permissions['edit field_contact_screened_by'] = array(
    'name' => 'edit field_contact_screened_by',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: edit field_contact_screened_date
  $permissions['edit field_contact_screened_date'] = array(
    'name' => 'edit field_contact_screened_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: edit field_journal
  $permissions['edit field_journal'] = array(
    'name' => 'edit field_journal',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: edit field_source
  $permissions['edit field_source'] = array(
    'name' => 'edit field_source',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: edit field_validation
  $permissions['edit field_validation'] = array(
    'name' => 'edit field_validation',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: view field_assisted
  $permissions['view field_assisted'] = array(
    'name' => 'view field_assisted',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: view field_contact_screened
  $permissions['view field_contact_screened'] = array(
    'name' => 'view field_contact_screened',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: view field_contact_screened_by
  $permissions['view field_contact_screened_by'] = array(
    'name' => 'view field_contact_screened_by',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: view field_contact_screened_date
  $permissions['view field_contact_screened_date'] = array(
    'name' => 'view field_contact_screened_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: view field_journal
  $permissions['view field_journal'] = array(
    'name' => 'view field_journal',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  // Exported permission: view field_source
  $permissions['view field_source'] = array(
    'name' => 'view field_source',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'datacleansers',
    ),
  );

  // Exported permission: view field_validation
  $permissions['view field_validation'] = array(
    'name' => 'view field_validation',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'datacleansers',
    ),
  );

  return $permissions;
}
