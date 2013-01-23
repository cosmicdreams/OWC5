<?php
/**
 * @file
 * text_format.redhen_activity_message.inc
 */

$api = '2.0.0';

$data = (object) array(
  'format' => 'redhen_activity_message',
  'name' => 'RedHen Activity Message',
  'cache' => '1',
  'status' => '1',
  'weight' => '0',
  'filters' => array(
    'filter_html' => array(
      'weight' => '1',
      'status' => '1',
      'settings' => array(
        'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
        'filter_html_help' => 1,
        'filter_html_nofollow' => 0,
      ),
    ),
  ),
);

$dependencies = array();

$optional = array(
  'permission.use_text_format_redhen_activity_message' => 'permission.use_text_format_redhen_activity_message',
);

$modules = array(
  0 => 'filter',
);
