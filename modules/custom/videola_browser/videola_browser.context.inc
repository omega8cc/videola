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
    'views' => array(
      'values' => array(
        'videola_videos:page_1' => 'videola_videos:page_1',
        'videola_videos:page_2' => 'videola_videos:page_2',
        'videola_videos_by_cat:page_1' => 'videola_videos_by_cat:page_1',
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
  t('the taxonomy browser block');
  t('videos');

  $export['videola_browser'] = $context;
  return $export;
}
