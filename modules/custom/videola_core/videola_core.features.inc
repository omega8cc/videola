<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function videola_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function videola_core_imagecache_default_presets() {
  $items = array(
    'videola_video_still' => array(
      'presetname' => 'videola_video_still',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '854',
            'height' => '480',
          ),
        ),
      ),
    ),
    'videola_video_still_thumb' => array(
      'presetname' => 'videola_video_still_thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '210',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}
