<?php

/**
 * @file
 * Pointcrop image style functions.
 */

/**
 * Implements hook_image_effect_info().
 */
function pointcrop_image_effect_info() {
  $effects = array(
    'pointcrop_scale_and_crop' => array(
      'label' => t('Pointcrop Scale And Crop'),
      'help' => t('Scale and crop, focusing on a specific point, based on data provided by the <em>Pointcrop</em> module.'),
      'effect callback' => 'pointcrop_scale_and_crop_effect',
      'form callback' => 'pointcrop_scale_and_crop_form',
      'summary theme' => 'pointcrop_scale_and_crop_summary',
    ),
    'pointcrop_crop' => array(
      'label' => t('Pointcrop Crop'),
      'help' => t('Crop, focusing on a specific point, based on data provided by the <em>Pointcrop</em> module.'),
      'effect callback' => 'pointcrop_crop_effect',
      'form callback' => 'pointcrop_crop_form',
      'summary theme' => 'pointcrop_crop_summary',
    ),
  );

  return $effects;
}

/**
 * Implements hook_theme().
 */
function pointcrop_theme() {
  $theme = array(
    'pointcrop_scale_and_crop_summary' => array(
      'variables' => array('data' => NULL),
    ),
    'pointcrop_crop_summary' => array(
      'variables' => array('data' => NULL),
    ),
  );

  return $theme;
}

/**
 * Pointcrop scale and crop settings form.
 */
function pointcrop_scale_and_crop_form($data = array()) {
  $form = image_resize_form($data);

  if (module_exists('smartcrop')) {
    $form['fallback'] = array(
      '#type' => 'radios',
      '#title' => t('Fallback effect'),
      '#options' => array(
        'image' => t('!module: !effect', array('!module' => 'Image', '!effect' => t('Scale And Crop'))),
        'smartcrop' => t('!module: !effect', array('!module' => 'SmartCrop', '!effect' => t('Scale and Smart Crop'))),
      ),
      '#default_value' => isset($data['fallback']) ? $data['fallback'] : 'image',
      '#description' => t('The effect to apply when no focus data is available.'),
    );
  }

  return $form;
}

/**
 * Theme pointcrop scale and crop summary information.
 *
 * @ingroup themeable
 */
function theme_pointcrop_scale_and_crop_summary($variables) {
  $data = $variables['data'];
  return theme('image_resize_summary', array('data' => $data));
}

/**
 * Pointcrop scale and crop effect.
 *
 * This scales and crops images to focus on a specific focus point, which is
 * made up of x and y coordinates that are a ratio between 0 and 1.
 */
function pointcrop_scale_and_crop_effect(&$image, $data) {
  $files = file_load_multiple(array(), array('uri' => $image->source));

  if (count($files)) {
    $file = reset($files);

    // Get the focus point coords.
    if (($point = $file->focus_point) && ($point = pointcrop_parse($point))) {
      // Get the scale of the new image.
      $scale = max($data['width'] / $image->info['width'], $data['height'] / $image->info['height']);

      // Resize the image.
      $current_width = $image->info['width'] * $scale;
      $current_height = $image->info['height'] * $scale;
      if (!image_resize($image, $current_width, $current_height)) {
        return FALSE;
      }

      list($xanchor, $yanchor) = pointcrop_get_anchor_point($point['x'], $point['y'], $current_width, $current_height, $data['width'], $data['height']);

      return image_crop_effect($image, array('width' => $data['width'], 'height' => $data['height'], 'anchor' => $xanchor . '-' . $yanchor));
    }
  }

  // Fallback to smart crop module if desired and present.
  if (isset($data['fallback']) && $data['fallback'] == 'smartcrop' && module_exists('smartcrop')) {
    return smartcrop_scale_effect($image, $data);
  }
  // Fallback to normal drupal scale and crop.
  return image_scale_and_crop_effect($image, $data);
}

/**
 * Pointcrop crop settings form.
 */
function pointcrop_crop_form($data = array()) {
  return image_resize_form($data);
}

/**
 * Theme pointcrop crop summary information.
 *
 * @ingroup themeable
 */
function theme_pointcrop_crop_summary($variables) {
  $data = $variables['data'];
  return theme('image_resize_summary', array('data' => $data));
}

/**
 * Pointcrop crop effect.
 *
 * This crops images to focus on a specific focus point, which is made up of
 * x and y coordinates that are a ratio between 0 and 1.
 */
function pointcrop_crop_effect(&$image, $data) {
  $files = file_load_multiple(array(), array('uri' => $image->source));
  if (count($files)) {
    $file = reset($files);

    // Get the focus point coords.
    if (($point = $file->focus_point) && ($point = pointcrop_parse($point))) {
      list($xanchor, $yanchor) = pointcrop_get_anchor_point($point['x'], $point['y'], $image->info['width'], $image->info['height'], $data['width'], $data['height']);

      return image_crop_effect($image, array('width' => $data['width'], 'height' => $data['height'], 'anchor' => $xanchor . '-' . $yanchor));
    }
  }
  // Default to normal crop.
  return image_crop_effect($image, array('width' => $data['width'], 'height' => $data['height']));
}

/**
 * Get the crop anchor point based on the focus point, image dimensions, and
 * target image dimensions.
 *
 * @param $focus_x
 *   The x coord of the focus point. A number between zero and one.
 * @param $focus_y
 *   The y coord of the focus point. A number between zero and one.
 * @param $current_width
 *   The with of the original image in pixels.
 * @param $current_height
 *   The height of the original image in pixels.
 * @param $target_width
 *   The target width of the new image in pixels.
 * @param $target_height
 *   The target height of the new image in pixels.
 *
 * @return
 *   An array containing the x coord and the y coord that make up the crop
 *   anchor point.
 */
function pointcrop_get_anchor_point($focus_x, $focus_y, $current_width, $current_height, $target_width, $target_height) {
  // If the images is smaller than it needs to be, anchor is zero.
  if ($current_width < $target_width) {
    $x = 0;
  }
  // Otherwise.
  else {
    // Get the focus point in pixels.
    $x = $current_width * $focus_x;
    // Get half the target width.
    $half_width = $target_width / 2;
    // If the focus point centred would leave less than half the target
    // width to the right of the focus point, use the image width less half
    // the target width. Otherwise there will be space to the right of the
    // image.
    if ($current_width - $x < $half_width) {
      $x = $current_width - $half_width;
    }
    // The anchor point will be the focus point less half the target width.
    // However, the anchor can't be less than zero.
    $x = max($x - $half_width, 0);
  }

  // If the images is smaller than it needs to be, anchor is zero.
  if ($current_height < $target_height) {
    $y = 0;
  }
  // Otherwise.
  else {
    // Get the focus point in pixels.
    $y = $current_height * $focus_y;
    // Get half the target height.
    $half_height = $target_height / 2;
    // If the focus point centred would leave less than half the target
    // height to the right of the focus point, use the image height less
    // half the target height. Otherwise there will be space to the right of
    // the image.
    if ($current_height - $y < $half_height) {
      $y = $current_height - $half_height;
    }
    // The anchor point will be the focus point less half the target height.
    // However, the anchor can't be less than zero.
    $y = max($y - $half_height, 0);
  }
  return array($x, $y);
}
