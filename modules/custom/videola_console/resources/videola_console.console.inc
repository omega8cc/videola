<?php
/**
 * @file
 */

/**
 * Access callback for videola/actions/console_authorization service.
 */
function videola_console_authorization_access() {
  return TRUE;
}

/**
 * Services callback for console/authorize POST.
 */
function videola_console_authorization($device_id, $uid = NULL) {
  $device = videola_console_device_load($device_id, TRUE);
  // If there is no activation record at all for this device_id we need to
  // initiate a new activation process.
  if ($device === FALSE) {
    $pin = _videola_console_activation_pin($device_id);
    return array(
      'device_id' => $device_id,
      'status' => 'authorizing',
      'data' => array('authorization_pin' => $pin),
    );
  }
  else if ($device->status == 'authorizing') {
    // This device is in the middle of the authorization dance.
    return array(
      'device_id' => $device_id,
      'status' => 'authorizing',
      'last_updated' => $device->last_updated,
      'data' => array('authorization_pin' => $device->authorization_pin),
    );
  }
  else if ($device->status == 'authorized') {
    // If the device is authorized now we need to make sure the associated
    // user is in good standing. Whatever that means. Since we can't assume
    // anything we just let someone else handle that part. So we just set up
    // a mock response and let everyone go to town on it.
    // Things to do during this phase.
    // - make sure the user has an active account and has paid their bills
    // - see if the associated user account is logged in via another session and
    //   delete that session if so.
    $response = array(
      'session_id' => session_id(),
      'session_name' => session_name(),
      'device_id' => $device_id,
      'status' => $device->status,
      'last_updated' => $device->last_updated,
      'data' => array(),
    );
    $account = user_load($uid);
    drupal_alter('videola_console_authorized_response', $response, $device, $account);

    return $response;
  }

  // Unable to process this request.
  return FALSE;
}

/**
 *
 */
function _videola_console_activation_pin($device_id) {
  // Generate an activation pin.
  $pin = videola_console_activation_pin($device_id);
  // Create a new record that shows this device_id is in the process of being
  // activated.
  $record = array(
    'device_id' => $device_id,
    'status' => 'authorizing',
    'authorization_pin' => $pin,
    'last_updated' => time(),
  );

  if (drupal_write_record('videola_console_devices', $record)) {
    return $pin;
  }

  return FALSE;
}
