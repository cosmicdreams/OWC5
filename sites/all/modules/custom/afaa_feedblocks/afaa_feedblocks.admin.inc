<?php
/**
 * @file
 * Administrative page callbacks for the AFAA Feedblocks module.
 */

/**
 * Implements hook_admin_settings()
 */
function afaa_feedblocks_admin_settings_form($form_state) {
  $form = array(
    'settings' => array(
      '#tree' => true,
    ),
  );
  $defaults = array(
    'count' => 2,
  );
  $settings = variable_get('afaa_feedblocks', $defaults);

  $form['settings']['count'] = array(
    '#title' => t('Number of blocks'),
    '#type'  => 'select',
    '#default_value' => $settings['count'],
    '#options' => array(
      1 => '1 Block',
      2 => '2 Blocks',
      3 => '3 Blocks',
      4 => '4 Blocks',
      5 => '5 Blocks',
      6 => '6 Blocks',
      7 => '7 Blocks',
      8 => '8 Blocks',
      9 => '9 Blocks',
    ),
    '#element_validate' => array(
       'element_validate_integer_positive'
    ),
    '#description' => t('Specify the number of blocks to provide. You can find these on the admin page for block settings.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Saves the form.
 * @param array $form
 * @param array $form_state
 */
function afaa_feedblocks_admin_settings_form_submit($form = array(), $form_state = array()) {
  variable_set('afaa_feedblocks', $form_state['values']['settings']);
  drupal_set_message('Settings Saved', 'status');
}

