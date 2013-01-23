<?php
/**
 * @file
 * field.message_type.message_text.message_type.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(
      0 => 'message_type',
    ),
    'translatable' => '1',
    'settings' => array(
      'message_text' => TRUE,
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_message_text' => array(
              'value' => 'message_text_value',
              'format' => 'message_text_format',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_message_text' => array(
              'value' => 'message_text_value',
              'format' => 'message_text_format',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'format' => array(
        'table' => 'filter_format',
        'columns' => array(
          'format' => 'format',
        ),
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'field_name' => 'message_text',
    'type' => 'text_long',
    'module' => 'text',
    'active' => '1',
    'locked' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'text',
        'size' => 'big',
        'not null' => FALSE,
      ),
      'format' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'label' => 'Message text',
    'description' => 'This is the text of all messages of this type.',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'text_default',
        'settings' => array(),
        'module' => 'text',
        'weight' => 0,
      ),
    ),
    'widget' => array(
      'type' => 'text_textarea',
      'settings' => array(
        'rows' => 5,
      ),
      'weight' => 0,
      'module' => 'text',
    ),
    'field_name' => 'message_text',
    'entity_type' => 'message_type',
    'bundle' => 'message_type',
    'deleted' => '0',
    'default_value' => NULL,
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'text',
);
