<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function videola_core_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videola_core_global';
  $context->description = 'On all pages';
  $context->tag = 'global';
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
        'user-0' => array(
          'module' => 'user',
          'delta' => 0,
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
        'user-1' => array(
          'module' => 'user',
          'delta' => 1,
          'region' => 'sidebar_first',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('On all pages');
  t('global');

  $export['videola_core_global'] = $context;
  return $export;
}
