<?php
/**
 * @file
 * content_type.event.inc
 */

$api = '2.0.0';

$data = (object) array(
  'type' => 'event',
  'name' => 'Event',
  'description' => 'An event that you can register for.',
  'has_title' => '1',
  'title_label' => 'Title',
  'base' => 'node_content',
  'help' => '',
);

$dependencies = array();

$optional = array(
  'field.node.body.event' => 'field.node.body.event',
  'field.node.field_registration.event' => 'field.node.field_registration.event',
  'permission.create_event_content' => 'permission.create_event_content',
  'permission.edit_own_event_content' => 'permission.edit_own_event_content',
  'permission.edit_any_event_content' => 'permission.edit_any_event_content',
  'permission.delete_own_event_content' => 'permission.delete_own_event_content',
  'permission.delete_any_event_content' => 'permission.delete_any_event_content',
);

$modules = array(
  0 => 'node',
);
