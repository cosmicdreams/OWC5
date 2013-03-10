<?php
/**
 * @file
 * view_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function view_calendar_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function view_calendar_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function view_calendar_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An event that can appear on a calendar.'),
      'has_title' => '1',
      'title_label' => t('Event Name'),
      'help' => '',
    ),
  );
  return $items;
}
