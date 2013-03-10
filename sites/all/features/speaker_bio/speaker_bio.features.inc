<?php
/**
 * @file
 * speaker_bio.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function speaker_bio_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function speaker_bio_node_info() {
  $items = array(
    'speaker_bio' => array(
      'name' => t('Speaker Bio'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
