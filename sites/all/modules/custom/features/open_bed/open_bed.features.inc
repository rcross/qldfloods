<?php

/**
 * Implementation of hook_node_info().
 */
function open_bed_node_info() {
  $items = array(
    'open_bed' => array(
      'name' => t('Open Bed'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Summary'),
      'help' => t('Please don\'t add your full address - just the street and suburb are enough. Make sure you add contact details so people can contact you.'),
    ),
  );
  return $items;
}
