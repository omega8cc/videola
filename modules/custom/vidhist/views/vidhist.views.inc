<?php
// $Id $

/**
 * @file Video History Views data include file
 */

function vidhist_views_data() {  
  // Basic table information.
  $data['vidhist']['table'] = array(
    'group' => t('Video history'),
  );
  
  // Advertise this table as a possible base table.
  $data['vidhist']['table']['base'] = array(
    'field' => 'vhid',
    'title' => t('Vidhist'),
    'help' => t("Video playback history maintained by vidhist module."),
  );
  
  // Joins.
  $data['vidhist']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );
  
  // uid field.
  $data['vidhist']['uid'] = array(
    'title' => t('User'), // The item it appears as on the UI,
    'help' => t('User who watched the video.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('User who watched video'),
    ),
  );
  
  // nid field.
  $data['vidhist']['nid'] = array(
    'title' => t('Node'), // The item it appears as on the UI,
    'help' => t('Node where video was watched.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'field' => 'nid',
      'label' => t('Node where video was watched'),
    ),
  );
  
  // Timestamp and duration fields.
  $data['vidhist']['timestamp'] = $data['vidhist']['duration'] = array(
    'title' => t('Time stamp'),
    'help' => t('Date/time that viewing happened.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Duration field.
  $data['vidhist']['duration']['title'] = t('Duration');
  $data['vidhist']['duration']['help'] = t('Total length of video in seconds.');
  
  // Viewtime field.
  $data['vidhist']['viewtime'] = array(
    'title' => t('View length'),
    'help' => t('Amount of time that the video was watched.'),
    'field' => array(
      'handler' => 'vidhist_handler_field_time',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  // Start field.
  $data['vidhist']['start'] = array(
    'title' => t('Start time'),
    'help' => t('Time marker where this viewing started.'),
    'field' => array(
      'handler' => 'vidhist_handler_field_time',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );
  
  // End field.
  $data['vidhist']['end'] = array(
    'title' => t('End time'),
    'help' => t('Time marker where this viewing ended.'),
    'field' => array(
      'handler' => 'vidhist_handler_field_time',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );
  
  // Delta field.
  $data['vidhist']['delta'] = array(
    'title' => t('Video ID'),
    'help' => t('ID of the video on the node.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // IP field.
  $data['vidhist']['ip'] = array(
    'title' => t('Hostname'),
    'help' => t('Hostname of user that posted the comment.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // Auto field.
  $data['vidhist']['auto'] = array(
    'title' => t('Active'),
    'help' => t('Video is currently being watched.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Active'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  // Latest field.
  $data['vidhist']['latest'] = array(
    'title' => t('Latest'),
    'help' => t('Most recent view of given video by user.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Latest'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Currently logged in user.
  $data['vidhist']['uid_current'] = array(
    'real field' => 'uid',
    'title' => t('Current User'),
    'help' => t('Filter the view to the currently logged in user.'),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
      'type' => 'yes-no',
    ),
  );

  // Resume/Play Again link.
  $data['vidhist']['play_resume_link'] = array(
    'field' => array(
      'title' => t('Play/Resume Link'),
      'help' => t('Provide a simple link to play/resume the video.'),
      'handler' => 'vidhist_handler_field_play_resume_link',
    ),
  );


  // Average View Time per Day.
  $data['vidhist']['avg_view'] = array(
    'title' => t('Average View Time per Day'),
    'help' => t('Show how often this video is watched.'),
    'real field' => 'viewtime',
    'field' => array(
      'handler' => 'vidhist_handler_field_avg_view',
      'click sortable' => TRUE,
    ),
  /*  'sort' => array(
      'handler' => 'views_handler_sort',
    ),*/
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
 

function vidhist_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'vidhist') . '/views',
    ),
    'handlers' => array(
      'vidhist_handler_field_time' => array(
        'parent' => 'views_handler_field',
      ),
      'vidhist_handler_field_play_resume_link' => array(
        'parent' => 'views_handler_field_node_link',
      ),
      'vidhist_handler_field_avg_view' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

