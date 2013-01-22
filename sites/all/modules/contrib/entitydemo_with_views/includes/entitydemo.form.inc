<?php

/**
 * @file
 * Create, edit, delete forms
 */

/**
 * Form callback: create or edit an insurance.
 *
 * @param $insurance
 *   The insurance object to edit through the form.
 */

/**
 * Form callback: create or edit an entitydemo.
 *
 * @param array $form
 *   Form
 * @param array $form_state
 *   Form State
 * @param object $entitydemo
 *   entitydemo object to edit through the form.
 *
 * @return array
 *   Array of form
 */
function entitydemo_ui_add_edit_form($form, &$form_state, $entitydemo) {
  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'entitydemo_ui') . '/includes/entitydemo.form.inc';

  // Add level field.
  $form['human_readable_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Readable name'),
    '#description' => t('Readable name (in table entity_demo)'),
    '#default_value' => !empty($entitydemo->human_readable_name) ? $entitydemo->human_readable_name : '',
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  // Created & changed.
  $time = time();
  if (empty($entitydemo->created)) {
    $entitydemo->created = $time;
  }
  $entitydemo->changed = $time;

  // Add the field related form elements.
  $form_state['entitydemo'] = $entitydemo;
  field_attach_form('entitydemo', $entitydemo, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 100,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save entity demo', array(), array('context' => 'a drupal entity demo')),
    '#submit' => array_merge($submit, array('entitydemo_ui_add_edit_form_submit')),
    '#weight' => 40,
  );

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'entitydemo_ui_add_edit_form_validate';

  return $form;
}

/**
 * Validation callback for insurance_form().
 */
function entitydemo_ui_add_edit_form_validate($form, &$form_state) {
  $entitydemo = $form_state['entitydemo'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('entitydemo', $entitydemo, $form, $form_state);
}

/**
 * Submit callback for insurance_form().
 */
function entitydemo_ui_add_edit_form_submit($form, &$form_state) {
  $entitydemo = $form_state['entitydemo'];

  // Notify field widgets.
  field_attach_submit('entitydemo', $entitydemo, $form, $form_state);

  $entitydemo->human_readable_name = $form_state['values']['human_readable_name'];

  // Save the insurance.
  entitydemo_save($entitydemo);

  $form_state['redirect'] = 'admin/content/entitydemo-list';
}

/**
 * Form callback: confirmation form for deleting an insurance.
 *
 * @param array $form
 *   Form
 * @param array $form_state
 *   Form State
 * @param object $entitydemo
 *   entitydemo object.
 *
 * @return array
 *   The form array to delete an entitydemo.
 *
 * @see confirm_form()
 */
function entitydemo_ui_delete_form($form, &$form_state, $entitydemo) {
  $form_state['entitydemo'] = $entitydemo;

  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'entitydemo_ui') . '/includes/entitydemo.form.inc';

  $form['#submit'][] = 'entitydemo_ui_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete @entitydemo_id?', array('@entitydemo_id' => $entitydemo->human_readable_name)),
    '',
    '<p>' . t('Deleting this entity demo cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  return $form;
}

/**
 * Submit callback for insurance_delete_form().
 */
function entitydemo_ui_delete_form_submit($form, &$form_state) {
  $entitydemo = $form_state['entitydemo'];

  $deleted = entitydemo_delete($entitydemo);
  if (empty($deleted)) {
    drupal_set_message(t('Entity demo @number has been deleted.', array('@number' => $entitydemo->entitydemo_id)));
    watchdog('entitydemo', 'Deleted entity demo @entitydemo_id.', array('@entitydemo_id' => $entitydemo->entitydemo_id), WATCHDOG_NOTICE);
    $form_state['redirect'] = 'admin/content/entitydemo-list';
  }
  else {
    drupal_set_message(t('Entity demo @number has not been deleted.', array('@number' => $entitydemo->entitydemo_id)), 'error');
  }
}
