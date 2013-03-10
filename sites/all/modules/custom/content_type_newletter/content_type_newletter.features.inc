<?php
/**
 * @file
 * content_type_newletter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_newletter_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_newletter_node_info() {
  $items = array(
    'newsletter' => array(
      'name' => t('E-Magazine Newsletter'),
      'base' => 'node_content',
      'description' => t('A complete newsletter that will be mass emailed to subscribers.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
