<?php
/**
 * @file
 * field.redhen_org.field_address.foundation.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'entity_types' => array(),
    'foreign keys' => array(),
    'indexes' => array(),
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
            'field_data_field_address' => array(
              'country' => 'field_address_country',
              'administrative_area' => 'field_address_administrative_area',
              'sub_administrative_area' => 'field_address_sub_administrative_area',
              'locality' => 'field_address_locality',
              'dependent_locality' => 'field_address_dependent_locality',
              'postal_code' => 'field_address_postal_code',
              'thoroughfare' => 'field_address_thoroughfare',
              'premise' => 'field_address_premise',
              'sub_premise' => 'field_address_sub_premise',
              'organisation_name' => 'field_address_organisation_name',
              'name_line' => 'field_address_name_line',
              'first_name' => 'field_address_first_name',
              'last_name' => 'field_address_last_name',
              'data' => 'field_address_data',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_address' => array(
              'country' => 'field_address_country',
              'administrative_area' => 'field_address_administrative_area',
              'sub_administrative_area' => 'field_address_sub_administrative_area',
              'locality' => 'field_address_locality',
              'dependent_locality' => 'field_address_dependent_locality',
              'postal_code' => 'field_address_postal_code',
              'thoroughfare' => 'field_address_thoroughfare',
              'premise' => 'field_address_premise',
              'sub_premise' => 'field_address_sub_premise',
              'organisation_name' => 'field_address_organisation_name',
              'name_line' => 'field_address_name_line',
              'first_name' => 'field_address_first_name',
              'last_name' => 'field_address_last_name',
              'data' => 'field_address_data',
            ),
          ),
        ),
      ),
    ),
    'field_name' => 'field_address',
    'type' => 'addressfield',
    'module' => 'addressfield',
    'active' => '1',
    'locked' => '0',
    'cardinality' => '1',
    'deleted' => '0',
    'columns' => array(
      'country' => array(
        'description' => 'Two letter ISO country code of this address.',
        'type' => 'varchar',
        'length' => 2,
        'not null' => FALSE,
        'default' => '',
      ),
      'administrative_area' => array(
        'description' => 'The administrative area of this address. (i.e. State/Province)',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'sub_administrative_area' => array(
        'description' => 'The sub administrative area of this address.',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'locality' => array(
        'description' => 'The locality of this address. (i.e. City)',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'dependent_locality' => array(
        'description' => 'The dependent locality of this address.',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'postal_code' => array(
        'description' => 'The postal code of this address.',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'thoroughfare' => array(
        'description' => 'The thoroughfare of this address. (i.e. Street address)',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'premise' => array(
        'description' => 'The premise of this address. (i.e. Apartment / Suite number)',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'sub_premise' => array(
        'description' => 'The sub_premise of this address.',
        'type' => 'varchar',
        'length' => 255,
        'default' => '',
        'not null' => FALSE,
      ),
      'organisation_name' => array(
        'description' => 'Contents of a primary OrganisationName element in the xNL XML.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'default' => '',
      ),
      'name_line' => array(
        'description' => 'Contents of a primary NameLine element in the xNL XML.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'default' => '',
      ),
      'first_name' => array(
        'description' => 'Contents of the FirstName element of a primary PersonName element in the xNL XML.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'default' => '',
      ),
      'last_name' => array(
        'description' => 'Contents of the LastName element of a primary PersonName element in the xNL XML.',
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'default' => '',
      ),
      'data' => array(
        'description' => 'Additional data for this address.',
        'type' => 'text',
        'size' => 'big',
        'not null' => FALSE,
        'serialize' => TRUE,
      ),
    ),
  ),
  'field_instance' => array(
    'default_value' => array(
      0 => array(
        'element_key' => 'redhen_org|foundation|field_address|und|0',
        'thoroughfare' => '',
        'premise' => '',
        'locality' => '',
        'country' => 'AF',
      ),
    ),
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'label' => 'Address',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(
          'US' => 'US',
        ),
        'format_handlers' => array(
          'address' => 'address',
          'name-full' => 0,
          'name-oneline' => 0,
          'organisation' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => '2',
    ),
    'field_name' => 'field_address',
    'entity_type' => 'redhen_org',
    'bundle' => 'foundation',
    'deleted' => '0',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'addressfield',
);
