<?php

/**
 * @file
 * Add handlers to views
 */

/**
 * Implements hook_views_data_alter().
 *
 * @param array $data
 *   Add fields to views.
 */
function entitydemo_ui_views_data_alter(&$data) {
  $data['entity_demo']['link_entitydemo'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the entity demo.'),
      'handler' => 'entitydemo_ui_handler_link_field',
    ),
  );
  $data['entity_demo']['edit_entitydemo'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the entity demo.'),
      'handler' => 'entitydemo_ui_handler_edit_link_field',
    ),
  );
  $data['entity_demo']['delete_entitydemo'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the entity demo.'),
      'handler' => 'entitydemo_ui_handler_delete_link_field',
    ),
  );
}
