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
    'body' => 'Here you would probably put something about your videos and why people should <a href="/signup">signup</a> or login to your site.',
    'format' => '1',
  );

  $export['videola_anon_front'] = $box;
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'videola_anonymous_signup_box';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Videola: Anonymous Signup Link';
  $box->options = array(
    'body' => '<h2><a href="/signup">Signup</a></h2>',
    'format' => '2',
  );

  $export['videola_anonymous_signup_box'] = $box;
  return $export;
}
