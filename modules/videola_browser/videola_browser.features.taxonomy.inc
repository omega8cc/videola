<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function videola_browser_taxonomy_default_vocabularies() {
  return array(
    'categories' => array(
      'name' => 'Categories',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '0',
      'required' => '1',
      'tags' => '0',
      'module' => 'features_categories',
      'weight' => '0',
      'nodes' => array(
        'videola_video' => 'videola_video',
      ),
    ),
  );
}
