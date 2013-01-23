<?php
/**
 * @file
 * field.message.message_redhen_contact.redhen_membership.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'settings' => array(
      'target_type' => 'redhen_contact',
      'handler' => 'base',
      'handler_settings' => array(
        'target_bundles' => array(),
        'sort' => array(
          'type' => 'property',
          'property' => 'contact_id',
          'direction' => 'ASC',
        ),
      ),
    ),
    'entity_types' => array(),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_message_redhen_contact' => array(
              'target_id' => 'message_redhen_contact_target_id',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_message_redhen_contact' => array(
              'target_id' => 'message_redhen_contact_target_id',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'redhen_contact' => array(
        'table' => 'redhen_contact',
        'columns' => array(
          'target_id' => 'contact_id',
        ),
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'field_name' => 'message_redhen_contact',
    'type' => 'entityreference',
    'module' => 'entityreference',
    'active' => '1',
    'locked' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'target_id' => array(
        'description' => 'The id of the target entity.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Contact',
    'required' => TRUE,
    'widget' => array(
      'type' => 'entityreference_autocomplete',
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'size' => '60',
        'path' => '',
      ),
      'weight' => 0,
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'entityreference_label',
        'settings' => array(
          'link' => FALSE,
        ),
        'module' => 'entityreference',
        'weight' => 0,
      ),
    ),
    'description' => '',
    'field_name' => 'message_redhen_contact',
    'entity_type' => 'message',
    'bundle' => 'redhen_membership',
    'deleted' => '0',
    'default_value' => NULL,
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'entityreference',
);
