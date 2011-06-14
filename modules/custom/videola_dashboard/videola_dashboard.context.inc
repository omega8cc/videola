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
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-videola_anonymous_signup_box' => array(
          'module' => 'boxes',
          'delta' => 'videola_anonymous_signup_box',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'user-0' => array(
          'module' => 'user',
          'delta' => 0,
          'region' => 'sidebar_last',
          'weight' => 1,
        ),
        'boxes-videola_anon_front' => array(
          'module' => 'boxes',
          'delta' => 'videola_anon_front',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'views-videola_video_topics-block_1' => array(
          'module' => 'views',
          'delta' => 'videola_video_topics-block_1',
          'region' => 'content_top',
          'weight' => 1,
        ),
      ),
    ),
  );
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
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'videola_core-my_subscription' => array(
          'module' => 'videola_core',
          'delta' => 'my_subscription',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'views-videola_queue-block_1' => array(
          'module' => 'views',
          'delta' => 'videola_queue-block_1',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'views-videola_video_topics-block_1' => array(
          'module' => 'views',
          'delta' => 'videola_video_topics-block_1',
          'region' => 'content_top',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard/Frontpage for authenticated users');
  t('videola');

  $export['videola_dashboard_subscribed'] = $context;
  return $export;
}
