<?php
/**
 * @file
 * afaa_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function afaa_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-menu-1.
  $menus['menu-footer-menu-1'] = array(
    'menu_name' => 'menu-footer-menu-1',
    'title' => 'Footer Menu 1',
    'description' => 'Displays links in the leftmost menu in the footer.',
  );
  // Exported menu: menu-footer-menu-2.
  $menus['menu-footer-menu-2'] = array(
    'menu_name' => 'menu-footer-menu-2',
    'title' => 'Footer Menu 2',
    'description' => 'Displays links in the middle menu in the footer.',
  );
  // Exported menu: menu-footer-menu-3.
  $menus['menu-footer-menu-3'] = array(
    'menu_name' => 'menu-footer-menu-3',
    'title' => 'Footer Menu 3',
    'description' => 'Displays links in the rightmost menu in the footer.',
  );
  // Exported menu: menu-primary-navigation.
  $menus['menu-primary-navigation'] = array(
    'menu_name' => 'menu-primary-navigation',
    'title' => 'Primary Navigation',
    'description' => 'The navigation which stays constant throughout the site.',
  );
  // Exported menu: menu-utility-navigation.
  $menus['menu-utility-navigation'] = array(
    'menu_name' => 'menu-utility-navigation',
    'title' => 'Utility Navigation',
    'description' => 'The menu which appears on the very top of the website, above search.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Displays links in the leftmost menu in the footer.');
  t('Displays links in the middle menu in the footer.');
  t('Displays links in the rightmost menu in the footer.');
  t('Footer Menu 1');
  t('Footer Menu 2');
  t('Footer Menu 3');
  t('Primary Navigation');
  t('The menu which appears on the very top of the website, above search.');
  t('The navigation which stays constant throughout the site.');
  t('Utility Navigation');


  return $menus;
}
