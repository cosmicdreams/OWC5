<?php
/**
 * @file
 * Administration and module settings UI.
 */

function afaa_forms_site_settings($form, &$form_state) {

  $form['afaa_forms_site_form'] = array(
      '#type' => 'select',
      '#title' => t('Site-wide Contact Form'),
      '#default_value' => _afaa_forms_get_site_form(),
      '#description' => t('Select the Entityform to use for the site wide contact form'),
      '#options' => _afaa_forms_form_options(),
  );
  return system_settings_form($form);
}

/*
 * Get the all Entityform types that are availabe to be entityforms
 */
function _afaa_forms_form_options($mode = 'site') {
  $all_forms = entityform_get_types();
  if (empty($all_forms)) {
    return array('' => t('No forms available'));
  }
  $options[''] = t('None');
  foreach ($all_forms as $type => $entityform_type) {
    if ($mode == 'users') {
      $fields = array_keys(field_info_instances('entityform', $type));
      if (!in_array('field_contacted_user', $fields)) {
        continue;
      }
    }
    $options[$type] = $entityform_type->label;
  }
  return $options;
}
function afaa_forms_role_settings($form, $form_state) {
  $roles = user_roles(TRUE);
  //no user contact forms by default
  $role_settings = variable_get('afaa_forms_roles', array());
  $form['afaa_forms_roles'] = array(
      '#tree' => TRUE,
  );
  $options = _afaa_forms_form_options('users');
  foreach ($roles as $rid => $role) {
    $default_value = isset($role_settings[$rid])?_afaa_forms_default_value($role_settings[$rid]):'';

    $form['afaa_forms_roles'][$rid] = array(
        '#type' => 'select',
        '#title' => $role,
        '#options' => $options,
        '#default_value' => $default_value,
    );
    if (!empty($default_value)) {
      $form['afaa_forms_roles'][$rid]['#description'] = t('Edit current form') . ': ' . l($options[$default_value], "admin/structure/entityform_types/manage/$default_value");
    }
  }
  return system_settings_form($form);
}