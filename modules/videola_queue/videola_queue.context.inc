<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function videola_queue_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videola_queue';
  $context->description = 'Context for videola queue blocks.';
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
        'views-videola_queue-block_1' => array(
          'module' => 'views',
          'delta' => 'videola_queue-block_1',
          'region' => 'content_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for videola queue blocks.');
  t('videola');

  $export['videola_queue'] = $context;
  return $export;
}
