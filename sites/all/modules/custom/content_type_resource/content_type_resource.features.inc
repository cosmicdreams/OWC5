<?php
/**
 * @file
 * content_type_resource.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_type_resource_node_info() {
  $items = array(
    'resource' => array(
      'name' => t('Resource'),
      'base' => 'node_content',
      'description' => t('Use Resource pages for information that an organization might need (eg. School Kit).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
