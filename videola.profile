<?php
// $Id: profiler_example.profile,v 1.2 2010/07/04 12:25:50 q0rban Exp $

/**
 * @file
 *
 * An example Install profile that uses Profiler. To create your own Install 
 * profile, copy the directory that this file resides in, and rename all files 
 * and directories, replacing profiler_example with the machine name of your 
 * install profile. Then do a find and replace in this file to replace all 
 * instances of profiler_example with the machine name of your profile. Edit the 
 * renamed profiler_example.info file to your taste, and presto-change-o,
 * you've got yourself an install profile!
 */

  !function_exists('profiler_v2') ? require_once('profiles/videola/libraries/profiler/profiler.inc') : FALSE;
  profiler_v2('videola');

/**
 * Implements hook_profile_tasks().
 */
function videola_profile_tasks(&$task, $url) {
  // Create a basic page content type.
  $types = array(
    array(
      'type' => 'page',
      'name' => st('Page'),
      'module' => 'node',
      'description' => st("A <em>page</em> is a simple method for creating and displaying information that rarely changes, such as an \"About us\" section of a website. By default, a <em>page</em> entry does not allow visitor comments and is not featured on the site's initial home page."),
      'custom' => TRUE,
      'modified' => TRUE,
      'locked' => FALSE,
      'help' => '',
      'min_word_count' => '',
    ),
  );

  foreach ($types as $type) {
    $type = (object) _node_type_set_defaults($type);
    node_type_save($type);
  }

  // Setup directory and .htaccess file for private_download module.
  $filename = file_directory_path() .'/private/.htaccess';
  // Grab the system settings form for the private download module and use the
  // default .htaccess file contents from there.
  $form = private_download_admin_form();
  $htaccess = $form['private_download_htaccess']['#default_value'];
  if (!private_download_write($filename, $htaccess)) {
    drupal_set_message(t('Unable to write data to file: !filename', array('!filename' => $filename)), 'error', FALSE);
  }

  // Let profiler module do it's thing.
  include_once('profiles/videola/libraries/profiler/profiler_api.inc');
  return profiler_profile_tasks(profiler_v2_load_config('videola'), $task, $url);

}
