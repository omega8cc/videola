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
 * Implements hook_profile_task_list().
 */
function videola_profile_task_list() {
  return array(
    'videola' => st('Videola Configuration'),
  );
}

/**
 * Implements hook_profile_tasks().
 */
function videola_profile_tasks(&$task, $url) {
  if ($task == 'profile') {
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
    $dir = file_directory_path() . '/private';
    file_check_directory($dir, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
    $filename = $dir .'/.htaccess';
    // Grab the system settings form for the private download module and use the
    // default .htaccess file contents from there.
    $form = private_download_admin_form();
    $htaccess = $form['private_download_htaccess']['#default_value'];
    if (!private_download_write($filename, $htaccess)) {
      drupal_set_message(t('Unable to write data to file: !filename', array('!filename' => $filename)), 'error', FALSE);
    }

    // Let profiler module do it's thing.
    include_once('profiles/videola/libraries/profiler/profiler_api.inc');
    profiler_profile_tasks(profiler_v2_load_config('videola'), $task, $url);
    // Profiler stets the $task to 'profile-finished', in order to add our own
    // tasks we need to override that and set it to our task.
    if (defined('DRUSH_BASE_PATH')) {
      $task = 'profile-finished'; // Required to support Aegir.
    }
    else {
      $task = 'videola';
    }
  }

  if ($task == 'videola') {
    // Get the configuration form.
    $output = drupal_get_form('videola_profile_form', $url);
    // We can't use redirection in profiles so we need a different method for
    // tracking if the form has been submitted or not.
    if (!variable_get('videola_profile_form', FALSE)) {
      drupal_set_title(st('Videola Configuration'));
      return $output;
    }
    else {
      // Form was submitted, advance to the next task.
      variable_del('videola_profile_form');
      $task = 'profile-finished';
    }
  }
}

/**
 * Form for configuring videola instance during installation.
 */
function videola_profile_form(&$form_state, $url) {
  $form['pricing_options'] = array(
    '#type' => 'fieldset',
    '#title' => st('Subscription Pricing Options'),
    '#description' => st('Videola is configured out of the box to allow users to purchase a monthly, bi-annual (6 months) or annual (1 year) subscription. Users will be automatically re-billed every 1, 6, or 12 months after their initial purchase date depending on the subscription they chose until they cancel their account.'),
  );
  $form['pricing_options']['monthly_price'] = array(
    '#type' => 'textfield',
    '#title' => st('Monthly subscription cost'),
    '#description' => st('Price of a monthly subscription. Billed once per month.'),
    '#field_prefix' => st('$'),
    '#size' => 5,
  );
  $form['pricing_options']['bi_annual_price'] = array(
    '#type' => 'textfield',
    '#title' => st('Bi-Annual subscription cost'),
    '#description' => st('Price of a bi-annual subscription. Billed once every 6 months.'),
    '#field_prefix' => st('$'),
    '#size' => 5,
  );
  $form['pricing_options']['annual_price'] = array(
    '#type' => 'textfield',
    '#title' => st('Annual subscription cost'),
    '#description' => st('Price of a yearly subscription. Billed once per year.'),
    '#field_prefix' => st('$'),
    '#size' => 5,
  );

  $form['continue'] = array(
    '#type' => 'submit', 
    '#value' => st('Continue'),
  );

  // Note that #action is set to the url passed through from
  // installer, ensuring that it points to the same page, and
  // #redirect is FALSE to avoid broken installer workflow.
  $form['errors'] = array();
  $form['#action'] = $url;
  $form['#redirect'] = FALSE;

  return $form;
}

/** 
 * Validation callback for videola_profile configuration form.
 */
function videola_profile_form_validate($form, &$form_state) {
  // Ensure that pricing options are numeric values.
  if (!is_numeric($form_state['values']['monthly_price'])) {
    form_set_error('monthly_price', st('Must be a numeric value.'));
  }
  if (!is_numeric($form_state['values']['bi_annual_price'])) {
    form_set_error('monthly_price', st('Must be a numeric value.'));
  }
  if (!is_numeric($form_state['values']['annual_price'])) {
    form_set_error('monthly_price', st('Must be a numeric value.'));
  }
}

/**
 * Submit handler for videola_profile configuration form.
 */
function videola_profile_form_submit($form, &$form_state) {
  // Save pricing options to the DB.
  // Need to update the already created node as well.
  $results = db_query('SELECT oid, name FROM {uc_attribute_options}');
  while ($row = db_fetch_object($results)) {
    switch ($row->name) {
      case 'Monthly':
        db_query('UPDATE {uc_attribute_options} SET price = %f WHERE name = "Monthly"', $form_state['values']['monthly_price']);
        db_query('UPDATE {uc_product_options} SET price = %d WHERE oid = %d', $form_state['values']['monthly_price'], $row->oid);
        break;
      case 'Bi-annual':
        db_query('UPDATE {uc_attribute_options} SET price = %f WHERE name = "Bi-annual"', $form_state['values']['bi_annual_price']);
        db_query('UPDATE {uc_product_options} SET price = %d WHERE oid = %d', $form_state['values']['bi_annual_price'], $row->oid);
        break;
      case 'Yearly':
        db_query('UPDATE {uc_attribute_options} SET price = %f WHERE name = "Yearly"', $form_state['values']['annual_price']);
        db_query('UPDATE {uc_product_options} SET price = %d WHERE oid = %d', $form_state['values']['annual_price'], $row->oid);
        break;
    }
  }

  // Update help text of the product features to replace the correct $MONTHLY_FEE, $BIANNUAL_FEE and $ANNUAL_FEE amounts.
  $monthly_product_features = db_fetch_object(db_query("SELECT * FROM {uc_product_features} WHERE fid = 'recurring' AND description LIKE '%MONTHLY_FEE%' LIMIT 1"));
  $new_monthly_description = str_replace('MONTHLY_FEE', '$' .$form_state['values']['monthly_price'], $monthly_product_features->description);
  db_query("UPDATE {uc_product_features} SET description = '%s' WHERE pfid = %d", $new_monthly_description, $monthly_product_features->pfid);
  // Bi-annual update.
  $biannual_product_features = db_fetch_object(db_query("SELECT * FROM {uc_product_features} WHERE fid = 'recurring' AND description LIKE '%BIANNUAL_FEE%' LIMIT 1"));
  $new_biannual_description = str_replace('BIANNUAL_FEE', '$' .$form_state['values']['bi_annual_price'], $biannual_product_features->description);
  db_query("UPDATE {uc_product_features} SET description = '%s' WHERE pfid = %d", $new_biannual_description, $biannual_product_features->pfid);
  // Annual update.
  $annual_product_features = db_fetch_object(db_query("SELECT * FROM {uc_product_features} WHERE fid = 'recurring' AND description LIKE '%YEARLY_FEE%' ORDER BY pfid DESC LIMIT 1"));
  $new_annual_description = str_replace('YEARLY_FEE', '$' .$form_state['values']['annual_price'], $annual_product_features->description);
  db_query("UPDATE {uc_product_features} SET description = '%s' WHERE pfid = %d", $new_annual_description, $annual_product_features->pfid);

  // Add uc recurring product info for monthly, bi-annual and annual products.
  db_query("INSERT INTO {uc_recurring_product} (pfid, model, fee_amount, initial_charge, regular_interval, number_intervals) VALUES (%d, '%s', %f, '%s', '%s', %d), (%d, '%s', %f, '%s', '%s', %d), (%d, '%s', %f, '%s', '%s', %d)",
    // monthly
    $monthly_product_features->pfid, 'subscription-monthly', $form_state['values']['monthly_price'], '1 months', '1 months', -1,
    // biannual
    $biannual_product_features->pfid, 'subscription-biannual', $form_state['values']['bi_annual_price'], '6 months', '6 months', -1,
    // annual
    $annual_product_features->pfid, 'subscription-annual', $form_state['values']['annual_price'], '1 years', '1 years', -1
  );

  // Update the path alias for the subscription node to be signup rather than content/membership.
  $nid = db_result(db_query("SELECT nid FROM {node} WHERE type='subscription' LIMIT 1"));
  $node = node_load($nid);
  $node->path = 'signup';
  node_save($node);

  // Flag so that videola_profile_tasks knows the form has been submitted and
  // can move on.
  variable_set('videola_profile_form', TRUE);
}
