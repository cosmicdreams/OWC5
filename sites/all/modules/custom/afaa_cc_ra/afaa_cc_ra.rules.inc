<?php

/**
 * @file afaa_cc_ra.rules.inc
 */

/**
 * Implements hook_rules_action_info().
 */
function afaa_cc_ra_rules_action_info() {
  $actions = array(
    'afaa_cc_ra_action_subscribe_to_list' => array(
      'label' => t('Subscribe user to Constant Contact list'),
      'group' => t('AFAA Forms'),
      'parameter' => array(
        'entity_form_entity' => array(
          'type'  => 'entityform',
          'label' => t('Entity being submit'),
        ),
      ),
      'parameter' => array(
        'cc_list' => array(
          'type'         => 'text',
          'label'        => t('Constant Contact list'),
          'restriction'  => 'input',
          'options list' => 'afaa_cc_ra_get_cc_list',
        ),
      ),
    ),
  );

  return $actions;
}


/**
 * Action callback for subscribe to list custom action
 */
function afaa_cc_ra_action_subscribe_to_list($entity_form_entity, $cc_list) {
  dpm($entity_form_entity, 'Entity');
  dpm($cc_list, 'LIST ID');
}
