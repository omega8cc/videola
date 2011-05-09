<?php

/**
 * Implementation of hook_default_box().
 */
function videola_dashboard_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'videola_anon_front';
  $box->plugin_key = 'simple';
  $box->title = 'Big Gaudy Headline - OMG! Videos';
  $box->description = 'Videola: Anonymous Front Page Content';
  $box->options = array(
    'body' => 'Here you would probably put something about your videos and why people should signup or login to your site.',
    'format' => '1',
  );

  $export['videola_anon_front'] = $box;
  return $export;
}
