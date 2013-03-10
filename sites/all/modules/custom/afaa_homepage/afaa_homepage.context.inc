<?php
/**
 * @file
 * afaa_homepage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function afaa_homepage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-primary-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-primary-navigation',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'afaa_blocks-afaa_block_tagline' => array(
          'module' => 'afaa_blocks',
          'delta' => 'afaa_block_tagline',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'views-rotator_view-block' => array(
          'module' => 'views',
          'delta' => 'rotator_view-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-whats_new-block_whatsnew' => array(
          'module' => 'views',
          'delta' => 'whats_new-block_whatsnew',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-upcoming_events-upcoming_events' => array(
          'module' => 'views',
          'delta' => 'upcoming_events-upcoming_events',
          'region' => 'sidebar_second',
          'weight' => '-22',
        ),
        'afaa_blocks-afaa_block_support' => array(
          'module' => 'afaa_blocks',
          'delta' => 'afaa_block_support',
          'region' => 'sidebar_second',
          'weight' => '-21',
        ),
        'afaa_blocks-afaa_block_connect' => array(
          'module' => 'afaa_blocks',
          'delta' => 'afaa_block_connect',
          'region' => 'sidebar_second',
          'weight' => '-20',
        ),
        'afaa_blocks-afaa_block_facebook' => array(
          'module' => 'afaa_blocks',
          'delta' => 'afaa_block_facebook',
          'region' => 'sidebar_second',
          'weight' => '-19',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-utility-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-utility-navigation',
          'region' => 'utility',
          'weight' => '-10',
        ),
        'menu-menu-primary-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-primary-navigation',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'constant_contact-1' => array(
          'module' => 'constant_contact',
          'delta' => '1',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'menu-menu-footer-menu-1' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu-1',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'menu-menu-footer-menu-2' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu-2',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'menu-menu-footer-menu-3' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu-3',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sitewide'] = $context;

  return $export;
}
