<?php

/**
 * @file
 * Views for entitydemo
 */

/**
 * Implements hook_views_default_views().
 */
function entitydemo_ui_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'entitydemo';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entity_demo';
  $view->human_name = 'Entity demo list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Entity demo list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'entitydemo_id' => 'entitydemo_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'entitydemo_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Entity Demo: Entity demo ID */
  $handler->display->display_options['fields']['entitydemo_id']['id'] = 'entitydemo_id';
  $handler->display->display_options['fields']['entitydemo_id']['table'] = 'entity_demo';
  $handler->display->display_options['fields']['entitydemo_id']['field'] = 'entitydemo_id';
  /* Field: Entity Demo: Human_readable_name */
  $handler->display->display_options['fields']['human_readable_name']['id'] = 'human_readable_name';
  $handler->display->display_options['fields']['human_readable_name']['table'] = 'entity_demo';
  $handler->display->display_options['fields']['human_readable_name']['field'] = 'human_readable_name';
  $handler->display->display_options['fields']['human_readable_name']['label'] = 'Human readable name';
  /* Field: Entity Demo: New field demo */
  $handler->display->display_options['fields']['field_new_field_demo']['id'] = 'field_new_field_demo';
  $handler->display->display_options['fields']['field_new_field_demo']['table'] = 'field_data_field_new_field_demo';
  $handler->display->display_options['fields']['field_new_field_demo']['field'] = 'field_new_field_demo';
  /* Field: Entity Demo: Edit Link */
  $handler->display->display_options['fields']['edit_entitydemo']['id'] = 'edit_entitydemo';
  $handler->display->display_options['fields']['edit_entitydemo']['table'] = 'entity_demo';
  $handler->display->display_options['fields']['edit_entitydemo']['field'] = 'edit_entitydemo';
  /* Field: Entity Demo: Delete Link */
  $handler->display->display_options['fields']['delete_entitydemo']['id'] = 'delete_entitydemo';
  $handler->display->display_options['fields']['delete_entitydemo']['table'] = 'entity_demo';
  $handler->display->display_options['fields']['delete_entitydemo']['field'] = 'delete_entitydemo';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/entitydemo-list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Entity demo list';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  $views['entitydemo'] = $view;

  return $views;
}
