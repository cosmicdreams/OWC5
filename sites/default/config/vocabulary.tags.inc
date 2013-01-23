<?php
/**
 * @file
 * vocabulary.tags.inc
 */

$api = '2.0.0';

$data = (object) array(
  'vid' => '2',
  'name' => 'Tags',
  'machine_name' => 'tags',
  'description' => 'Use tags to group articles on similar topics into categories.',
  'hierarchy' => '0',
  'module' => 'taxonomy',
  'weight' => '0',
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'taxonomy',
);
