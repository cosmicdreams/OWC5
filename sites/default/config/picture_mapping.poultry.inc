<?php
/**
 * @file
 * picture_mapping.poultry.inc
 */

$api = '2.0.0';

$data = $picture_mapping = new stdClass();
$picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
$picture_mapping->api_version = 1;
$picture_mapping->machine_name = 'poultry';
$picture_mapping->breakpoint_group = 'poultry';
$picture_mapping->mapping = array(
  'breakpoints.theme.poultry.mobile' => array(
    '1x' => 'thumbnail',
  ),
  'breakpoints.theme.poultry.narrow' => array(
    '1x' => 'medium',
  ),
  'breakpoints.theme.poultry.wide' => array(
    '1x' => 'large',
  ),
  'breakpoints.theme.poultry.tv' => array(
    '1x' => 'large',
  ),
);


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'picture',
);
