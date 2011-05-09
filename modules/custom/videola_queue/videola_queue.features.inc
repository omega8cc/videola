<?php

/**
 * Implementation of hook_flag_default_flags().
 */
function videola_queue_flag_default_flags() {
  $flags = array();
  // Exported flag: "My Video Queue".
  $flags['queue'] = array(
    'content_type' => 'node',
    'title' => 'My Video Queue',
    'global' => '0',
    'types' => array(
      '0' => 'videola_video',
    ),
    'flag_short' => 'Add to queue',
    'flag_long' => 'Add this video to your queue',
    'flag_message' => 'This video has been added to your queue',
    'unflag_short' => 'Remove from queue',
    'unflag_long' => 'Remove this video from your queue',
    'unflag_message' => 'This video has been removed from your queue',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        '0' => '2',
      ),
      'unflag' => array(
        '0' => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'videola_queue',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implementation of hook_views_api().
 */
function videola_queue_views_api() {
  return array(
    'api' => '2',
  );
}
