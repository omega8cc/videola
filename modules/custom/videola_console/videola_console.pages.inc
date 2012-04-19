<?php
/**
 * @file
 */

/**
 * Display a list of devices associated with a user account.
 */
function videola_console_user_devices_page($account) {
  $devices = videola_console_devices($account->uid);
  return theme('videola_console_device_list', $devices);
}

/**
 * Form for entering in a PIN and associating a device with an account.
 */
function videola_console_authorize_form(&$form_state) {
  $form = array();
  $form['authorization_pin'] = array(
    '#type' => 'textfield',
    '#title' => t('Authorization PIN'),
    '#description' => t('Enter in the 8 character PIN provided by your device in order to authorize that device.'),
    '#size' => 8,
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Authorize'),
  );
  return $form;
}

/**
 * Validation callback for videola_console_authorize_form().
 */
function videola_console_authorize_form_validate($form, &$form_state) {
  global $user;

  // Ensure that the entered PIN is 8 characters and is associated with a
  // device that has a 'authorizing' status.
  if (strlen($form_state['values']['authorization_pin']) == 8) {
    $device = db_fetch_object(db_query('SELECT * FROM {videola_console_devices} WHERE status="authorizing" AND authorization_pin = "%s"', $form_state['values']['authorization_pin']));  
    if (!$device) {
      form_set_error('authorization_pin', t('Invalid PIN entered.'));
    }
    // Save the device object in $form_state so that we can use it in our
    // submit handler without having to run the query a second time.
    $form_state['#device'] = $device;
    // We also need to ensure that they are not going above their device limit.
    $count = db_result(db_query('SELECT COUNT(device_id) FROM {videola_console_devices} WHERE status = "authorized" AND uid = %d', $user->uid));
    if ($count && $count >= variable_get('videola_console_device_limit', VIDEOLA_CONSOLE_DEVICE_LIMIT)) {
      form_set_error('', t('You have already reached the maximum number of allowed devices. Please de-activate another device to proceed.'));
    }
  }
  else {
    form_set_error('authorization_pin', t('Invalid PIN entered.'));
  }
}

/**
 * Submit handler for videola_console_authorize_form().
 */
function videola_console_authorize_form_submit($form, &$form_state) {
  global $user;

  $device = $form_state['#device'];
  // Associate this device with the currently logged in user and mark it as
  // authorized.
  videola_console_device_authorize($device->device_id, $user->uid);
  drupal_set_message(t('The device %id has been authorized.', array('%id' => $device->device_id)));
  $form_state['redirect'] = 'user/' . $user->uid . '/devices';
}

/**
 * System settings form for videola console services.
 */
function videola_console_settings() {
  $form = array();
  $form['videola_console_device_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Device limit'),
    '#description' => t('Max number of devices a user can associate with their account.'),
    '#default_value' => variable_get('videola_console_device_limit', VIDEOLA_CONSOLE_DEVICE_LIMIT),
  );
  return system_settings_form($form);
}

/**
 * Validation callback for videola_console_settings form.
 */
function videola_console_settings_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['videola_console_device_limit'])) {
    form_set_error('videola_console_device_limit', t('Must be an integer.'));
  }
}

/**
 * Form to confirm device removal / deactivation.
 */
function videola_console_device_remove_confirm(&$form_state, $device_id) {
  $form['device_id'] = array(
    '#type' => 'value', 
    '#value' => $device_id,
  );

  return confirm_form($form, 
    t('Are you sure you want to deactivate %device?', array('%device' => $device_id)), 
    isset($_GET['destination']) ? $_GET['destination'] : 'user/' . $user->uid . '/devices', 
    t('This action cannot be undone.'), 
    t('Deactivate'), 
    t('Cancel')
  );
}

function videola_console_device_remove_confirm_submit($form, &$form_state) {
  global $user;

  if ($form_state['values']['confirm']) {
    videola_console_device_remove($form_state['values']['device_id']);
    drupal_set_message(t('Device %device has been deactivated.', array('%device' => $form_state['values']['device_id'])));
  }
  $form_state['redirect'] = 'user/' . $user->uid . '/devices';
}
