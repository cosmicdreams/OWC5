<?php
/**
 * @file
 * content_type_slideshow.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function content_type_slideshow_image_default_styles() {
  $styles = array();

  // Exported image style: homepage_slideshow_image.
  $styles['homepage_slideshow_image'] = array(
    'name' => 'homepage_slideshow_image',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '629',
          'height' => '352',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function content_type_slideshow_node_info() {
  $items = array(
    'slideshow' => array(
      'name' => t('Slideshow'),
      'base' => 'node_content',
      'description' => t('Slideshows are generally displayed on the homepage.
The most recent, published slideshow will be the one displayed to visitors.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
