<?php
/**
 * @file
 * content_type_testimonial.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_type_testimonial_node_info() {
  $items = array(
    'testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
