<?php
/**
 * @file
 * views_view.relations.inc
 */

$api = '2.0.0';

$data = $view = new view();
$view->name = 'relations';
$view->description = 'Lists relations of a certain type';
$view->tag = 'default';
$view->base_table = 'relation';
$view->human_name = 'Relations';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Relations';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Relation: endpoints */
$handler->display->display_options['fields']['endpoints']['id'] = 'endpoints';
$handler->display->display_options['fields']['endpoints']['table'] = 'field_data_endpoints';
$handler->display->display_options['fields']['endpoints']['field'] = 'endpoints';
$handler->display->display_options['fields']['endpoints']['label'] = '';
$handler->display->display_options['fields']['endpoints']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['endpoints']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['endpoints']['click_sort_column'] = 'entity_type';
$handler->display->display_options['fields']['endpoints']['delta_offset'] = '0';
/* Contextual filter: Relation: Relation type */
$handler->display->display_options['arguments']['relation_type']['id'] = 'relation_type';
$handler->display->display_options['arguments']['relation_type']['table'] = 'relation';
$handler->display->display_options['arguments']['relation_type']['field'] = 'relation_type';
$handler->display->display_options['arguments']['relation_type']['default_action'] = 'summary';
$handler->display->display_options['arguments']['relation_type']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['relation_type']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['relation_type']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['relation_type']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['relation_type']['limit'] = '0';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'relations';


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'views',
  1 => 'relation',
  2 => 'relation_endpoint',
);
