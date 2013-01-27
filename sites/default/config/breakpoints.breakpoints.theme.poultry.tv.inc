<?php
/**
 * @file
 * breakpoints.breakpoints.theme.poultry.tv.inc
 */

$api = '2.0.0';

$data = $breakpoint = new stdClass();
$breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
$breakpoint->api_version = 1;
$breakpoint->machine_name = 'breakpoints.theme.poultry.tv';
$breakpoint->name = 'tv';
$breakpoint->breakpoint = 'only screen and (min-width: 3456px)';
$breakpoint->source = 'poultry';
$breakpoint->source_type = 'theme';
$breakpoint->status = 1;
$breakpoint->weight = 3;
$breakpoint->multipliers = array(
  '1x' => '1x',
);


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'breakpoints',
);
