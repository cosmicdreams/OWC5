<?php
/**
 * @file
 * field.message.message_redhen_org.redhen_note.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'translatable' => '0',
    'settings' => array(
      'target_type' => 'redhen_org',
      'handler' => 'base',
      'handler_settings' => array(
        'target_bundles' => array(),
        'sort' => array(
          'type' => 'property',
          'property' => 'org_id',
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
            'field_data_message_redhen_org' => array(
              'target_id' => 'message_redhen_org_target_id',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_message_redhen_org' => array(
              'target_id' => 'message_redhen_org_target_id',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'redhen_org' => array(
        'table' => 'redhen_org',
        'columns' => array(
          'target_id' => 'org_id',
        ),
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'field_name' => 'message_redhen_org',
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
    'label' => 'Organization',
    'required' => TRUE,
    'widget' => array(
      'type' => 'entityreference_autocomplete',
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'size' => '60',
        'path' => '',
      ),
      'weight' => 1,
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
    'field_name' => 'message_redhen_org',
    'entity_type' => 'message',
    'bundle' => 'redhen_note',
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
