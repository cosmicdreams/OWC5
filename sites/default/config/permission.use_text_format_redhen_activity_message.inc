<?php
/**
 * @file
 * permission.use_text_format_redhen_activity_message.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'use text format redhen_activity_message',
  'roles' => array(
    0 => 'administrator',
  ),
);

$dependencies = array(
  'text_format.redhen_activity_message' => 'text_format.redhen_activity_message',
);

$optional = array();

$modules = array(
  0 => 'filter',
);
