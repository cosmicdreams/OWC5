<?php
/**
 * @file
 * breakpoint_group.poultry.inc
 */

$api = '2.0.0';

$data = // Breakpoints.
$breakpoints = array();
$breakpoints[] = 'breakpoints.theme.poultry.mobile';
$breakpoints[] = 'breakpoints.theme.poultry.narrow';
$breakpoints[] = 'breakpoints.theme.poultry.wide';
$breakpoints[] = 'breakpoints.theme.poultry.tv';

// Breakpoint group.
$breakpoint_group = new stdClass();
$breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
$breakpoint_group->api_version = 1;
$breakpoint_group->machine_name = 'poultry';
$breakpoint_group->name = 'poultry';
$breakpoint_group->breakpoints = $breakpoints;
$breakpoint_group->type = 'custom';
$breakpoint_group->overridden = 0;


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'breakpoints',
);
