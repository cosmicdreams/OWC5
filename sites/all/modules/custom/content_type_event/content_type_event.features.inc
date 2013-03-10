<?php
/**
 * @file
 * content_type_event.features.inc
 */

/**
 * Implements hook_views_api().
 */
function content_type_event_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function content_type_event_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An event that can appear on a calendar.'),
      'has_title' => '1',
      'title_label' => t('Event Name'),
      'help' => '',
    ),
    'event_location' => array(
      'name' => t('Event Location'),
      'base' => 'node_content',
      'description' => t('An address that can be associated with an Event.'),
      'has_title' => '1',
      'title_label' => t('Location Name'),
      'help' => '',
    ),
  );
  return $items;
}