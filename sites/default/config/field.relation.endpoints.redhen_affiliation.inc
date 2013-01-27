<?php
/**
 * @file
 * field.relation.endpoints.redhen_affiliation.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(),
    'translatable' => '0',
    'settings' => array(),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_endpoints' => array(
              'entity_type' => 'endpoints_entity_type',
              'entity_id' => 'endpoints_entity_id',
              'r_index' => 'endpoints_r_index',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_endpoints' => array(
              'entity_type' => 'endpoints_entity_type',
              'entity_id' => 'endpoints_entity_id',
              'r_index' => 'endpoints_r_index',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'relation' => array(
        0 => 'entity_type',
        1 => 'entity_id',
        2 => 'r_index',
      ),
    ),
    'field_name' => 'endpoints',
    'type' => 'relation_endpoint',
    'module' => 'relation_endpoint',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '-1',
    'deleted' => '0',
    'columns' => array(
      'entity_type' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
        'default' => '',
        'description' => 'Entity_type of this relation end-point.',
      ),
      'entity_id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'default' => 0,
        'description' => 'Entity_id of this relation end-point.',
      ),
      'r_index' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'default' => 0,
        'description' => 'The index of this row in this relation. The highest index in the relation is stored as "arity" in the relation table.',
      ),
    ),
  ),
  'field_instance' => array(
    'default_value' => NULL,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_endpoint',
        'settings' => array(
          'view_modes' => array(
            'comment' => 'default',
            'message_type_category' => 'default',
            'message_type' => 'default',
            'message' => 'default',
            'node' => 'default',
            'redhen_contact' => 'default',
            'redhen_contact_type' => 'default',
            'redhen_engagement' => 'default',
            'redhen_engagement_score' => 'default',
            'redhen_membership' => 'default',
            'redhen_membership_type' => 'default',
            'redhen_note' => 'default',
            'redhen_org' => 'default',
            'redhen_org_type' => 'default',
            'registration' => 'default',
            'registration_type' => 'default',
            'registration_state' => 'default',
            'relation' => 'default',
            'file' => 'default',
            'taxonomy_term' => 'default',
            'taxonomy_vocabulary' => 'default',
            'user' => 'default',
          ),
        ),
        'type' => 'relation_endpoint',
        'weight' => 0,
      ),
      'teaser' => array(
        'type' => 'hidden',
        'label' => 'above',
        'settings' => array(),
        'weight' => 0,
      ),
    ),
    'label' => 'endpoints',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'relation_endpoint',
      'settings' => array(),
      'type' => 'relation_endpoint',
      'weight' => 0,
    ),
    'field_name' => 'endpoints',
    'entity_type' => 'relation',
    'bundle' => 'redhen_affiliation',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'relation_endpoint',
);
