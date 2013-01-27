<?php
/**
 * @file
 * field.redhen_contact.redhen_contact_email.volunteer.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(),
    'foreign keys' => array(),
    'indexes' => array(),
    'settings' => array(
      'labels' => array(
        0 => 'home',
        1 => 'work',
      ),
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
            'field_data_redhen_contact_email' => array(
              'value' => 'redhen_contact_email_value',
              'hold' => 'redhen_contact_email_hold',
              'bulk' => 'redhen_contact_email_bulk',
              'default' => 'redhen_contact_email_default',
              'label_id' => 'redhen_contact_email_label_id',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_redhen_contact_email' => array(
              'value' => 'redhen_contact_email_value',
              'hold' => 'redhen_contact_email_hold',
              'bulk' => 'redhen_contact_email_bulk',
              'default' => 'redhen_contact_email_default',
              'label_id' => 'redhen_contact_email_label_id',
            ),
          ),
        ),
      ),
    ),
    'field_name' => 'redhen_contact_email',
    'type' => 'redhen_email',
    'module' => 'redhen_fields',
    'active' => '1',
    'locked' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'columns' => array(
      'value' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'hold' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'default' => 0,
      ),
      'bulk' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'default' => 0,
      ),
      'default' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'default' => 0,
      ),
      'label_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'default' => 0,
      ),
    ),
  ),
  'field_instance' => array(
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'redhen_fields',
        'settings' => array(),
        'type' => 'redhen_email_formatter',
        'weight' => '0',
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'label' => 'Email',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'redhen_fields',
      'settings' => array(),
      'type' => 'redhen_email_widget',
      'weight' => '1',
    ),
    'field_name' => 'redhen_contact_email',
    'entity_type' => 'redhen_contact',
    'bundle' => 'volunteer',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'redhen_fields',
);
