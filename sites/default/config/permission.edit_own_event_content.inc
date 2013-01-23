<?php
/**
 * @file
 * permission.edit_own_event_content.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'edit own event content',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array(
  'content_type.event' => 'content_type.event',
);

$optional = array();

$modules = array(
  0 => 'node',
);
