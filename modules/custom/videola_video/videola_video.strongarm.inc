<?php

/**
 * Implementation of hook_strongarm().
 */
function videola_video_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_videola_video';
  $strongarm->value = 0;

  $export['comment_anonymous_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_videola_video';
  $strongarm->value = '3';

  $export['comment_controls_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_videola_video';
  $strongarm->value = '2';

  $export['comment_default_mode_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_videola_video';
  $strongarm->value = '2';

  $export['comment_default_order_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_videola_video';
  $strongarm->value = '30';

  $export['comment_default_per_page_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_videola_video';
  $strongarm->value = '1';

  $export['comment_form_location_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_videola_video';
  $strongarm->value = '0';

  $export['comment_preview_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_videola_video';
  $strongarm->value = '0';

  $export['comment_subject_field_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_videola_video';
  $strongarm->value = '2';

  $export['comment_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_videola_video';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '5',
    'revision_information' => '7',
    'author' => '6',
    'options' => '8',
    'comment_settings' => '9',
    'menu' => '4',
    'taxonomy' => '-4',
    'path' => '10',
    'flag' => '1',
  );

  $export['content_extra_weights_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_videola_video';
  $strongarm->value = array(
    0 => 'revision',
  );

  $export['node_options_videola_video'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'private_download_directory';
  $strongarm->value = 'private';

  $export['private_download_directory'] = $strongarm;
  return $export;
}
