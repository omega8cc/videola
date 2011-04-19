<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function videola_browser_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videola_browser';
  $context->description = 'the taxonomy browser block';
  $context->tag = 'videos';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'videos*' => 'videos*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-videola_video_topics-block_1' => array(
          'module' => 'views',
          'delta' => 'videola_video_topics-block_1',
          'region' => 'content_top',
          'weight' => 0,
        ),
        'views-videola_video_topics-block_2' => array(
          'module' => 'views',
          'delta' => 'videola_video_topics-block_2',
          'region' => 'content_top',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('the taxonomy browser block');
  t('videos');

  $export['videola_browser'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videola_browser_home';
  $context->description = 'Home page blocks from the videola_browser feature';
  $context->tag = 'home';
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
        'views-videola_video_topics-block_1' => array(
          'module' => 'views',
          'delta' => 'videola_video_topics-block_1',
          'region' => 'content_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home page blocks from the videola_browser feature');
  t('home');

  $export['videola_browser_home'] = $context;
  return $export;
}
