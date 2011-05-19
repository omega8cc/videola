<?php

/**
 * @see hook_profile_modules().
 *
 * @param $config
 *   The config array for an Install Profile.
 */
function profiler_profile_modules($config) {
  // Retrieve install profile dependencies.
  $modules = isset($config['dependencies']) ? profiler_config_reduce($config['dependencies']) : array();

  // Include code for building the module dependency tree.
  require_once('profiler_module.inc');
  $files = profiler_module_rebuild_cache();

  // Always install required modules first. Respect the dependencies between
  // the modules.
  $required = array();
  $non_required = array();

  // Add modules that other modules depend on.
  foreach ($modules as $module) {
    if ($files[$module]->requires) {
      $modules = array_merge($modules, array_keys($files[$module]->requires));
    }
  }
  $modules = array_unique($modules);
  foreach ($modules as $module) {
    if (!empty($files[$module]->info['required'])) {
      $required[$module] = $files[$module]->sort;
    }
    else {
      $non_required[$module] = $files[$module]->sort;
    }
  }
  arsort($required);
  arsort($non_required);
  return array_unique(array_keys(array_merge($required, $non_required)));
}

/**
 * @see hook_profile_task_list().
 *
 * @param $config
 *   The config array for an Install Profile.
 */
function profiler_profile_task_list($config) {
  return array();
}

/**
 * @see hook_profile_tasks().
 *
 * @param $config
 *   The config array for an Install Profile.
 * @param $task
 *   The current $task of the install system. When hook_profile_tasks() is first
 *   called, this is 'profile'.
 * @param $url
 *   Complete URL to be used for a link or form action on a custom page, if
 *   providing any, to allow the user to proceed with the installation.
 */
function profiler_profile_tasks($config, &$task, $url) {
  if ($task == 'profile') {
    // Disable all DB blocks
    db_query("UPDATE {blocks} SET status = 0, region = ''");

    // We flush caches at the beginning to ensure that any necessary module
    // tasks, such as Features component rebuilding, is complete before the
    // remaining tasks are run.
    drupal_flush_all_caches();

    // Run any component installations
    profiler_install_components($config);

    // Run hook_install() for the install profile.
    global $profile;
    $function = "{$profile}_install";
    $file = "./profiles/{$profile}/{$profile}.install";
    if (file_exists($file)) {
      require_once($file);
    }
    if (function_exists($function)) {
      call_user_func($function);
    }

    // Rebuild key tables/caches
    menu_rebuild();
    module_rebuild_cache(); // Detects the newly added bootstrap modules
    node_access_rebuild();
    drupal_get_schema('system', TRUE); // Clear schema DB cache
    drupal_flush_all_caches();

    // Finish
    profiler_install_configure($config);
    $task = 'profile-finished';
  }
  return '';
}

/**
 * Helper to implementation of hook_form_alter() for Install profiles.
 *
 * Allows the profile to alter the site-configuration form. This is
 * called through custom invocation, so $form_state is not populated.
 *
 * @param $config
 *   The config array for an Install Profile.
 */
function profiler_form_alter($config, &$form, $form_state, $form_id) {
  // If site_name and site_mail are in the config, we can possibly bypass a step
  // during the installation.
  if ($form_id == 'install_configure' &&
    isset($config['variables']['site_name']) &&
    isset($config['variables']['site_mail']) &&
    profiler_config_load_superuser($config)
  ) {
    variable_set('site_name', $config['variables']['site_name']);
    variable_set('site_mail', $config['variables']['site_mail']);
  }
}

/**
 * Reduce an array of components with mixed keys to its final reduced set of
 * values allowing for later entries to override former entries. Example:
 *
 *   profiler_config_reduce(array('foo', 'bar', 'foo' => 0));
 *
 * Will return the following:
 *
 *   array('bar');
 */
function profiler_config_reduce($data) {
  $reduced = array();
  foreach ($data as $key => $value) {
    if (is_int($key)) {
      $reduced[$value] = TRUE;
    }
    elseif (is_string($key)) {
      $reduced[$key] = (bool) $value;
    }
  }
  return array_keys(array_filter($reduced));
}

/**
 * Take an array of arrays and return a single array merging the child arrays.
 * The resulting array can optionally be reduced & made unique.
 *
 * @param array $data
 *   An array of arrays.
 * @param array $excluded_keys
 *   An array of keys to exclude. By default, no keys are excluded.
 * @param boolean $process
 *   Optional. Reduce and make the merged array unique.
 * @return array
 *   A single merged array.
 */
function profiler_config_merge($data, $excluded_keys = array(), $process = TRUE) {
  $merged = array();
  foreach ($data as $key => $value) {
    if (is_array($value) && !in_array($key, $excluded_keys, TRUE)) {
      $merged = array_merge($merged, $process ? profiler_config_reduce($value) : $value);
    }
  }
  return $process ? array_unique($merged) : $merged;
}

/**
 * Returns user 1 for a config, if it exists.
 */
function profiler_config_load_superuser($config) {
  if (isset($config['users'])) {
    foreach ($config['users'] as $account) {
      if ($account['uid'] == 1) {
        return $account;
      }
    }
  }
  return FALSE;
}

/**
 * Install components.
 */
function profiler_install_components($config) {
  if (is_array($config)) {
    $components = profiler_components();
    $identifiers = array();
    foreach ($config as $name => $data) {
      if (isset($components[$name], $components[$name]['callback'])) {
        if (isset($components[$name]['file'])) {
          require_once($components[$name]['file']);
        }
        if (function_exists($components[$name]['callback']) && !empty($data)) {
          $components[$name]['callback']($data, $config, $identifiers);
        }
      }
    }
  }
}

/**
 * This function mimics a lot of the functionality of install_configure_form_submit() inside install.php
 */
function profiler_install_configure($config) {
  if ($array = profiler_config_load_superuser($config)) {
    // We need to mimic being user 1 in order to bypass administeruserbyrole.
    global $user;
    $user->uid = 1;

    // Save user 1
    profiler_install_users(array($array));
    user_authenticate($array);

    // The user is now logged in, but has no session ID yet, which
    // would be required later in the request, so remember it.
    $user->sid = session_id();

    // Force clean URLs... (why?)
    variable_set('clean_url', TRUE);

    // Record when this install ran.
    variable_set('install_time', time());
  }
}

/**
 * Invoke module hooks to retrieve component info.
 */
function profiler_components() {
  $components = module_invoke_all('profiler_components');
  drupal_alter('profiler_components', $components);
  uasort($components, 'profiler_components_sort');
  return $components;
}

/**
 * Sort callback for ordering components.
 */
function profiler_components_sort($a, $b) {
  $a = (array)$a + array('weight' => 0);
  $b = (array)$b + array('weight' => 0);
  return $a['weight'] < $b['weight'] ? -1 : 1;
}

/**
 * Implementation of hook_profiler_components() on behalf of system.
 */
function system_profiler_components() {
  return array(
    'theme' => array('callback' => 'profiler_install_theme'),
    'variables' => array('callback' => 'profiler_install_variables'),
    'files' => array('callback' => 'profiler_install_files'),
  );
}

/**
 * Implementation of hook_profiler_components() on behalf of node.
 */
function node_profiler_components() {
  return array(
    'nodes' => array(
      'callback' => 'profiler_install_nodes',
      'weight' => 10,
    ),
  );
}

/**
 * Implementation of hook_profiler_components() on behalf of taxonomy.
 */
function taxonomy_profiler_components() {
  return array(
    'terms' => array(
      'callback' => 'profiler_install_terms',
      'weight' => 10,
    ),
  );
}

/**
 * Implementation of hook_profiler_components() on behalf of user.
 */
function user_profiler_components() {
  return array(
    'users' => array(
      'callback' => 'profiler_install_users',
      'weight' => -10,
    ),
  );
}

/**
 * Component install callback for 'theme'.
 */
function profiler_install_theme($key, $config, &$identifiers) {
  system_theme_data();
  variable_set('theme_default', $key);
  list_themes(TRUE);
  system_initialize_theme_blocks($key);
  db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' and name = '%s'", $key);
  list_themes(TRUE);
  menu_rebuild();
  drupal_rebuild_theme_registry();
}

/**
 * Component install callback for 'variables'.
 */
function profiler_install_variables($vars, $config, &$identifiers) {
  foreach($vars as $key => $value) {
    variable_set($key, $value);
  }
}

/**
 * Component install callback for 'files'.
 */
function profiler_install_files($files, $config, &$identifiers) {
  global $profiler_files;
  $profiler_files = isset($profiler_files) ? $profiler_files : array();
  foreach (array_filter($files) as $properties) {
    $profiler_files[$properties['filepath']] = _profiler_install_file($properties);
  }
}

/**
 * Helper function to retrieve the file object for a file installed via files[].
 *
 * @param $filepath
 *   Path of the file as specified in files[key][filepath].
 *
 * @return
 *   A file object if one is found or FALSE.
 */
function profiler_get_file($filepath) {
  global $profiler_files;
  return isset($profiler_files[$filepath]) ? $profiler_files[$filepath] : FALSE;
}

/**
 * Helper function to copy a file to it's final destination and save a record
 * in the {files} table.
 *
 * @param $file
 *   Associative array used to start building a file object. The 'filepath' key
 *   is required.
 *
 * @return
 *   The saved file object converted to an associative array or FALSE if the
 *   operation fails.
 */
function _profiler_install_file($file) {
  $error = FALSE;
  if (!isset($file['filepath'])) {
    drupal_set_message(t('Filepath must be specified when installing files.'), 'error', FALSE);
    $error = TRUE;
  }

  if (!isset($file['destination'])) {
    drupal_set_message(t('File destination musy be specified when installing files.'), 'error', FALSE);
    $error = TRUE;
  }

  if (isset($file['name'])) {
    $account = user_load(array('name' => $file['name']));
    if (!$account) {
      drupal_set_message(t('Failed to load Drupal user %user -- file %filepath not saved.', array('%name' => $file['name'], '%title' => $filepath)), 'error', FALSE);
      $error = TRUE;;
    }
  }

  // Verify that the source file exists.
  if (!file_exists($file['filepath'])) {
    drupal_set_message(t('The file %filepath does not exist.', array('%filepath' => $file['filepath'])), 'error', FALSE);
    $error = TRUE;
  }

  if ($error) {
    return FALSE;
  }

  // Begin building file object.
  $file['uid'] = isset($account->uid) ? $account->uid : 0;
  $file['filename'] = isset($file['filename']) ? $file['filename'] : basename($file['filepath']);
  $file['filemime'] = isset($file['filemime']) ? $file['filemime'] : (module_exists('mimedetect') ? mimedetect_mime($file) : file_get_mimetype($file->filename));
  $file['source'] = isset($file['source']) ? $file['source'] : $file['filepath'];
  $file['destination'] = isset($file['destination']) ? file_create_path($file['destination']) : file_create_path();
  $file['filesize'] = isset($file['filesize']) ? $file['filesize'] : filesize($filepath);

  // Conver to an object, necessary for the next couple of operations.
  $file = (object) $file;

  // Make sure the directory exists before trying to copy a file into it.
  file_check_directory($file->destination, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

  // Copy the file to the destination directory.
  if (!file_copy($file, $file->destination, FILE_EXISTS_RENAME)) {
    drupal_set_message(t('File copy error. Could not move file %source to %destination.', array('%source' => $file['source'], '%destination' => $file->destination)), 'error', FALSE);
    return FALSE;
  }

  // If we made it this far it's safe to record this file in the database.
  $file->status = FILE_STATUS_PERMANENT;
  $file->timestamp = time();
  // Insert new record to the database.
  drupal_write_record('files', $file);

  // Let modules add additional properties to the yet barebone file object. This
  // comes from field_file_save_file(), implemented here so that modules which
  // extend filefield are still triggered.
  foreach (module_implements('file_insert') as $module) {
    $function =  $module .'_file_insert';
    $function($file);
  }

  return (array)$file;
}

/**
 * Component install callback for 'nodes'.
 */
function profiler_install_nodes($nodes, $config, &$identifiers) {
  foreach (array_filter($nodes) as $nid => $properties) {
    if (isset($properties['name'])) {
      $account = user_load(array('name' => $properties['name']));
      if (!$account) {
        drupal_set_message(t('Failed to load Drupal user %user -- node %title not saved.', array('%name' => $properties['name'], '%title' => $properties['title'])), 'error', FALSE);
        continue;
      }
    }
    $default = array(
      'nid' => NULL,
      'title' => '',
      'body' => '',
      'type' => 'page',
      'teaser' => '',
      'log' => '',
      'created' => '',
      'format' => FILTER_FORMAT_DEFAULT,
      'uid' => !empty($account) ? $account->uid : 0,
    );
    $node = (object) array_merge($default, $properties);

    // Detect any file/imagefields and handle those.
    $fields = content_fields(NULL, $properties['type']);
    foreach ($properties as $field_name => $values) {
      if (strpos($field_name, 'field_') !== FALSE && $fields[$field_name]['type'] == 'filefield') {
        // Handle multiple values.
        foreach ($values as $delta => $info) {
          $file = profiler_get_file($info['filepath']);
          $node->{$field_name}[$delta] = $file ? $file : _profiler_install_file($info);
        }
      }
    }

    // Detect any taxonomy and handle those.
    if (module_exists('taxonomy') && isset($properties['taxonomy'])) {
      $taxonomy = array();
      $vocabs_by_module = profiler_get_vocabs_by_module();
      foreach ($properties['taxonomy'] as $vocab_module => $terms) {
        $vid = key($vocabs_by_module[$vocab_module]);
        if ($vid != NULL) {
          $terms = explode(',', $terms);
          foreach($terms as $term) {
            $tid = db_result(db_query("SELECT tid FROM {term_data} WHERE vid=%d AND name='%s'", $vid, trim($term)));
            if($tid != NULL) {
              $taxonomy[$vid][$tid] = $tid;
            }
          }
        }
      }
      $node->taxonomy = $taxonomy;
    }

    node_save($node);
  }
}

/**
 * Component install callback for 'terms'.
 */
function profiler_install_terms($terms, $config, &$identifiers) {
  $vocabs = profiler_get_vocabs();
  $vocabs_by_module = profiler_get_vocabs_by_module();
  $weight = 0;
  foreach ($terms as $term) {
    // Support the 'vocab_module' key for referring to a term's vocabulary by
    // its module.
    if (isset($term['vocab_module'], $vocabs_by_module[$term['vocab_module']]) && $vid = key($vocabs_by_module[$term['vocab_module']])) {
      $term['vid'] = $vid;
    }
    // Sanity checks before creating.
    if (!empty($term['name']) && !empty($term['vid']) && isset($vocabs[$term['vid']])) {
      $term['weight'] = empty($term['weight']) ? $weight++ : $term['weight'];
      taxonomy_save_term($term);
    }
  }
}

/**
 * Get an array of defined vocabularies.
 */
function profiler_get_vocabs() {
  static $vocabs;
  if (!isset($vocabs)) {
    $vocabs = taxonomy_get_vocabularies();
  }
  return $vocabs;
}

/**
 * Get an array of defined vocabularies indexed by {vocabulary}.module.
 */
function profiler_get_vocabs_by_module() {
  static $vocabs_by_module;
  if (!isset($vocabs_by_module)) {
    $vocabs = taxonomy_get_vocabularies();
    foreach ($vocabs as $vid => $vocab) {
      $vocabs_by_module[$vocab->module][$vid] = $vocab;
    }
  }
  return $vocabs_by_module;
}

/**
 * Component install callback for 'users'.
 */
function profiler_install_users($users) {
  foreach (array_filter($users) as $array) {
    // For some reason db_last_insert_id() doesn't get the uid of the newly created
    // user, so we need to separate out roles first, create the account, then save
    // again to properly assign roles to this user.
    $roles = isset($array['roles']) ? $array['roles'] : array();
    unset($array['roles']);

    // Use random password.
    $array['pass'] = user_password();

    // Load and update the account or create a new one.
    $account = isset($array['uid']) ? user_load($array['uid']) : user_load(array('name' => $array['name']));
    $account = $account ? $account : new stdClass();
    user_save($account, $array);

    // Load the saved account.
    $account = user_load(array('name' => $array['name']));

    // Set the roles.
    $formatted = array();
    $roles = explode(',', $roles);
    foreach ($roles as $name) {
      if ($rid = db_result(db_query("SELECT rid FROM {role} WHERE name = '%s'", trim($name)))) {
        $formatted[$rid] = TRUE;
      }
    }
    user_save($account, array('roles' => $formatted));
  }
}
