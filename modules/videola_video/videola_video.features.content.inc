<?php

/**
 * Implementation of hook_content_default_fields().
 */
function videola_video_content_default_fields() {
  $fields = array();

  // Exported field: field_videola_chapters
  $fields['videola_video-field_videola_chapters'] = array(
    'field_name' => 'field_videola_chapters',
    'type_name' => 'videola_video',
    'display_settings' => array(
      'weight' => '1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'jwplayer',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'jwplayer',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'chaptermarker',
    'required' => '0',
    'multiple' => '1',
    'module' => 'chaptermarkers',
    'active' => '1',
    'widget' => array(
      'chaptermarkers_video_field' => 'field_videola_video',
      'default_value' => array(
        '0' => array(
          'title' => '',
          'time' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Chapters',
      'weight' => '3',
      'description' => '',
      'type' => 'chaptermarker',
      'module' => 'chaptermarkers',
    ),
  );

  // Exported field: field_videola_free
  $fields['videola_video-field_videola_free'] = array(
    'field_name' => 'field_videola_free',
    'type_name' => 'videola_video',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '0|Make this video free
1|Make this video free',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Free Video',
      'weight' => '2',
      'description' => 'If checked the full length video will be displayed for all users including non subscribed users.',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_videola_video
  $fields['videola_video-field_videola_video'] = array(
    'field_name' => 'field_videola_video',
    'type_name' => 'videola_video',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'jwplayer',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp4',
      'file_path' => 'private/videola_videos',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Video',
      'weight' => '-3',
      'description' => 'Full length video.',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_videola_video_length
  $fields['videola_video-field_videola_video_length'] = array(
    'field_name' => 'field_videola_video_length',
    'type_name' => 'videola_video',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'videola_duration',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'videola_duration',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_videola_video_length][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Video Length',
      'weight' => 0,
      'description' => 'Length of the video in seconds.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_videola_video_preview
  $fields['videola_video-field_videola_video_preview'] = array(
    'field_name' => 'field_videola_video_preview',
    'type_name' => 'videola_video',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'jwplayer',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp4',
      'file_path' => 'videola_preview_videos',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Preview Video',
      'weight' => '-2',
      'description' => 'Preview video shown to non subscribed users.',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_videola_video_still
  $fields['videola_video-field_videola_video_still'] = array(
    'field_name' => 'field_videola_video_still',
    'type_name' => 'videola_video',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'videola_video_still_linked',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'videola_video_still_default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'videola_video_stills',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 1,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Video Still',
      'weight' => '-1',
      'description' => 'Still image from video used for thumbnails and for non subscribed users when no preview video is supplied.',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Chapters');
  t('Free Video');
  t('Preview Video');
  t('Video');
  t('Video Length');
  t('Video Still');

  return $fields;
}
