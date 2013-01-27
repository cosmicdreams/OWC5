<?php
/**
 * @file
 * field.relation.redhen_relation_status.redhen_affiliation.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_redhen_relation_status' => array(
              'value' => 'redhen_relation_status_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_redhen_relation_status' => array(
              'value' => 'redhen_relation_status_value',
            ),
          ),
        ),
      ),
    ),
    'field_name' => 'redhen_relation_status',
    'type' => 'list_boolean',
    'module' => 'list',
    'active' => '1',
    'locked' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'int',
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'type' => 'hidden',
        'label' => 'above',
        'settings' => array(),
        'weight' => 0,
      ),
    ),
    'label' => 'Affiliation Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 1,
    ),
    'field_name' => 'redhen_relation_status',
    'entity_type' => 'relation',
    'bundle' => 'redhen_affiliation',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'options',
);
