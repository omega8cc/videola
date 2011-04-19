<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function videola_dashboard_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videola_dashboard_anon';
  $context->description = 'Dashboard/Frontpage for anonymous users';
  $context->tag = 'videola';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard/Frontpage for anonymous users');
  t('videola');

  $export['videola_dashboard_anon'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videola_dashboard_subscribed';
  $context->description = 'Dashboard/Frontpage for authenticated users';
  $context->tag = 'videola';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard/Frontpage for authenticated users');
  t('videola');

  $export['videola_dashboard_subscribed'] = $context;
  return $export;
}
