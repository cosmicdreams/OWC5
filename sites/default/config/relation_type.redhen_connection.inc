<?php
/**
 * @file
 * relation_type.redhen_connection.inc
 */

$api = '2.0.0';

$data = $relation_type = new stdClass();
$relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
$relation_type->api_version = 1;
$relation_type->relation_type = 'redhen_connection';
$relation_type->label = 'Personal connection';
$relation_type->reverse_label = 'Personal connection';
$relation_type->directional = 0;
$relation_type->transitive = 0;
$relation_type->r_unique = 1;
$relation_type->min_arity = 2;
$relation_type->max_arity = 2;
$relation_type->source_bundles = array(
  0 => 'redhen_contact:*',
);
$relation_type->target_bundles = array();


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'relation',
);
