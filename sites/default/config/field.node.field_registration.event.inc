<?php
/**
 * @file
 * field.node.field_registration.event.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(),
    'foreign keys' => array(
      'registration_type' => array(
        'table' => 'registration_type',
        'columns' => array(
          'registration_type' => 'name',
        ),
      ),
    ),
    'indexes' => array(
      'registration_type' => array(
        0 => 'registration_type',
      ),
    ),
    'settings' => array(),
    'translatable' => '0',
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_registration' => array(
              'registration_type' => 'field_registration_registration_type',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_registration' => array(
              'registration_type' => 'field_registration_registration_type',
            ),
          ),
        ),
      ),
    ),
    'field_name' => 'field_registration',
    'type' => 'registration',
    'module' => 'registration',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'registration_type' => array(
        'type' => 'varchar',
        'length' => 32,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'default_value' => array(
      0 => array(
        'registration_type' => 'registration_type_1',
      ),
    ),
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'registration',
        'settings' => array(),
        'type' => 'registration_form',
        'weight' => '1',
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'label' => 'Register',
    'required' => 0,
    'settings' => array(
      'default_registration_settings' => array(
        'capacity' => 0,
        'reminder' => array(
          'reminder_settings' => array(
            'reminder_date' => NULL,
            'reminder_template' => NULL,
          ),
          'send_reminder' => 0,
        ),
        'scheduling' => array(
          'close' => NULL,
          'open' => NULL,
        ),
        'settings' => array(
          'from_address' => '',
          'multiple_registrations' => -1,
        ),
        'status' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'registration',
      'settings' => array(),
      'type' => 'registration_select',
      'weight' => -3,
    ),
    'field_name' => 'field_registration',
    'entity_type' => 'node',
    'bundle' => 'event',
    'deleted' => '0',
  ),
);

$dependencies = array(
  'content_type.event' => 'content_type.event',
);

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'registration',
);
