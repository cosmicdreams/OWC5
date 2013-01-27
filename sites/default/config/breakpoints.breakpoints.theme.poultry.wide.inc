<?php
/**
 * @file
 * breakpoints.breakpoints.theme.poultry.wide.inc
 */

$api = '2.0.0';

$data = $breakpoint = new stdClass();
$breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
$breakpoint->api_version = 1;
$breakpoint->machine_name = 'breakpoints.theme.poultry.wide';
$breakpoint->name = 'wide';
$breakpoint->breakpoint = '(min-width: 851px)';
$breakpoint->source = 'poultry';
$breakpoint->source_type = 'theme';
$breakpoint->status = 1;
$breakpoint->weight = 2;
$breakpoint->multipliers = array(
  '1x' => '1x',
);


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'breakpoints',
);
