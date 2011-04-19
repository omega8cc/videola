<?php
/**
 * @file
 * Documentation for videola.module's hooks.
 */

/**
 * Declare total number of videos and their combined length in seconds.
 *
 * This hook allows videola provider modules to to declare the total number of
 * videos they are providing and the combined length of all the videos in
 * seconds.
 *
 * @return
 *   An associative array keyed by module name containing an array with the
 *   following keys.
 *   'count' => (int) Total number of videos provided by the module.
 *   'sum' => (int) Total length of all videos combined in seconds.
 */
function hook_videola_core_video_totals() {
  return array(
    'mymodule' => array(
      'count' => 5,
      'sum' => 12345,
    )
  );
}
