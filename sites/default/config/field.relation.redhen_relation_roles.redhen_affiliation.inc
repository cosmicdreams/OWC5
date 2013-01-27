<?php
/**
 * @file
 * field.relation.redhen_relation_roles.redhen_affiliation.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'settings' => array(
      'allowed_values' => array(
        0 => 'Admin',
        1 => 'Member',
      ),
      'allowed_values_function' => '',
    ),
    'entity_types' => array(),
    'translatable' => '0',
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_redhen_relation_roles' => array(
              'value' => 'redhen_relation_roles_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_redhen_relation_roles' => array(
              'value' => 'redhen_relation_roles_value',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'field_name' => 'redhen_relation_roles',
    'type' => 'list_text',
    'module' => 'list',
    'active' => '1',
    'locked' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
    ),
  ),
  'field_instance' => array(
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'type' => 'hidden',
        'label' => 'above',
        'settings' => array(),
        'weight' => 0,
      ),
    ),
    'label' => 'Organization Role',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
    'field_name' => 'redhen_relation_roles',
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
