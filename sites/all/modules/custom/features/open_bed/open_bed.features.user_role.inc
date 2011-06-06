<?php

/**
 * Implementation of hook_user_default_roles().
 */
function open_bed_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '3',
  );

  // Exported role: datacleansers
  $roles['datacleansers'] = array(
    'name' => 'datacleansers',
    'weight' => '4',
  );

  return $roles;
}
