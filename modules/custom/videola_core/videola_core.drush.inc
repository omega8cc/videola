<?php
/**
 * @file
 */

/**
 * Implementation of hook_drush_comman().
 */
function videola_core_drush_command() {
  $items = array();
  $items['videola-generate-orders'] = array(
    'description' => "Generate random Ubercart orders.",
    'arguments' => array(
      'number' => 'The number of orders to generate',
    ),
    'options' => array(
      'nids' => 'Comma separated list of nids representing products to use when generating orders.',
      'random' => 'Randomize the number of products and the products that are added to each generated order.',
      'kill' => 'Delete all existing ubercart orders.',
    ),
    'aliases' => array('vgo'),
  );
  $items['videola-purge-orders'] = array(
    'description' => 'Purge all Ubercart orders from the system.',
    'aliases' => array('vpo'),
    'options' => array(
      'purge-users' => 'Include user accounts created when the order was created when purging.',
    ),
  );
  $items['videola-randomize-next-charge'] = array(
    'description' => 'Randomize the next charge date on recurring orders so that at least some of the orders will be charged on the next cron run.',
    'aliases' => array('vrnc'),
    'options' => array(
      'uid' => 'Uid or username of a user that you want to ensure is charged next time cron is run.',
    ),
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function videola_core_drush_help($section) {
  switch ($section) {
    case 'drush:videola-generate-subscriptions':
      return dt("This command will generate a given number of random orders.");
    case 'drush:videola-generate-subscriptions':
      return dt("This command will purge all ubercart orders from the database.");
  }
}

/**
 * Drush command callback. Delete all existing ubercart orders.
 */
function drush_videola_purge_orders() {
  // Sanity check.
  drush_print(dt('Running this command will delete ALL order data from your database. This can not be un-done.'));
  if(!drush_confirm(dt('Do you really want to continue?'))) {
    return drush_user_abort();
  }

  $purge_users = drush_get_option('purge-users', FALSE);

  // Set the fee handler for all uc_recurring subscriptions to the test
  // gateway so that when we delete them it doesn't do things like try and
  // remove the order's Authorize.net CIM profile stored on the authorize.net
  // servers.
  if (module_exists('uc_recurring')) {
    db_query('UPDATE {uc_recurring_users} SET fee_handler = "test_gateway"');
    // We also need to cleanup some other tables after doing this manually.
    db_query('TRUNCATE {uc_recurring_hosted}');
    db_query('TRUNCATE {uc_recurring_orders}');
  }

  $results = db_query('SELECT order_id, data FROM {uc_orders}');
  $count = $user_count = 0;
  while ($row = db_fetch_object($results)) {
    uc_order_delete($row->order_id);

    // Delete an associated users if requested.
    $data = unserialize($row->data);
    if ($purge_users && isset($data['new_user'])) {
      // Delete the user that was created in conjunction with this account. We
      // can not call user_delete() directly as that may end up sending out
      // un-intended e-mails under certian configurations. The code below is the
      // same as user_delete() with e-mailing and watchdog funcitonality
      // removed.
      $account = user_load(array('name' => $data['new_user']['name']));
      sess_destroy_uid($account->uid);
      db_query('DELETE FROM {users} WHERE uid = %d', $account->uid);
      db_query('DELETE FROM {users_roles} WHERE uid = %d', $account->uid);
      db_query('DELETE FROM {authmap} WHERE uid = %d', $account->uid);
      user_module_invoke('delete', $edit, $account);
      $user_count++;
    }
    $count++;
  }

  // Reset the AUTO_INCREMENT order_id to 0.
  db_query('TRUNCATE TABLE {uc_orders}');

  $msg = ($user_count > 0) ? dt('Deleted @count orders and @user_count users.', array('@count' => $count, '@user_count' => $user_count)) : dt('Deleted @count orders.', array('@count' => $count));
  drush_log($msg, 'ok');
}

/**
 * Drush command callback.
 */
function drush_videola_generate_orders($number) {
  if (drush_get_option('kill', FALSE)) {
    drush_videola_purge_orders();
  }

  module_load_include('inc', 'uc_cart', 'uc_cart.pages');

  $nids = drush_get_option('nids');
  $random = drush_get_option('random', FALSE);

  if (!empty($nids)) {
    // Use supplised nids.
    $nids = explode(',', $nids);
    foreach ($nids as $key => $value) {
      $value = trim($value);
      $nids[$key] = (int) $value;
    }
  }
  else {
    // Get a list of nids for all products and randomly add products to each
    // order.
    $results = db_query('SELECT up.nid FROM {uc_products} up INNER JOIN {node} n ON n.nid = up.nid WHERE n.status = 1');
    while ($row = db_fetch_object($results)) {
      $nids[]= $row->nid;
    }
  }

  for ($i = 0; $i < $number; $i++) {
    $ret = _drush_videola_generate_orders($nids, $random);
    drush_log(dt('Order @order_id created.', array('@order_id' => $ret)), 'ok');
  }
}

/**
 * Helper function to generate a sudo random order containing the specified
 * products.
 *
 * @param $nids
 *   An array of nids representing the products to add to the order.
 * @param $random
 *   Boolean. If TRUE a random number of random nids from $nids is added to each
 *   generated order.
 */
function _drush_videola_generate_orders($nids, $random) {
  // Add a random number of random products to the order.
  if ($random && count($nids) > 1) {
    $i = rand(1, 5);
    $tmp_nids = $nids;
    $nids = array();
    for ($i = rand(1, 5); $i > 0; $i--) {
      $key = array_rand($tmp_nids);
      $nids[$tmp_nids[$key]] = $tmp_nids[$key];
    }
  }
  
  // Build a shopping cart full of products.
  foreach ($nids as $nid) {
    uc_cart_add_item($nid, 1, NULL, NULL, NULL, FALSE);
  }

  // Fake submission of checkout form.
  $contents = uc_cart_get_contents();
  $result = db_fetch_object(db_query('SELECT zone_id, zone_country_id FROM {uc_zones} ORDER BY rand() LIMIT 1'));
  $form_state = array(
    'values' => array(
      'panes' => array(
        'customer' => array(
          'primary_email' => user_password() . '@example.com',
        ),
        'billing' => array(
          'billing_first_name' => user_password(5),
          'billing_last_name' => user_password(),
          'billing_phone' => rand(100000000, 999999999),
          'billing_street1' => rand(0, 100) . ' Anywhere Street',
          'billing_city' => user_password(),
          'billing_postal_code' => rand(10000, 99999),
          'billing_country' => $result->zone_country_id,
          'billing_zone' => $result->zone_id,
        ),
        'payment' => array(
          'payment_method' => 'credit',
        ),
      ),
      'cart_contents' => serialize($contents),
    ),
  );
  
  // The function below pulls stuff out of $_POST directly.
  $_POST['cc_number'] = '4111111111111111';
  $_POST['cc_cvv'] = '123';
  $_POST['cc_exp_month'] = date('m');
  $_POST['cc_exp_year'] = date('Y') + 1;

  $form = array();
  uc_cart_checkout_form_validate($form, $form_state);

  // Fake submission of checkout review form.
  $_SESSION['do_review'] = TRUE;
  uc_cart_checkout_review_form_submit($form, $form_state);

  // Fake the redirect after checkout is complete, which actually updates the
  // order as well.
  $order = uc_order_load(intval($_SESSION['cart_order']));
  // Fake entering a payment so the order gets marked as 'completed' in the next step.
  uc_payment_enter($order->order_id, 'credit', $order->order_total, $order->uid, array('cc_number' => 4111111111111111), 'Drush fake payment');
  // Complete the order.
  uc_cart_complete_sale($order, FALSE);
  // Add a comment to let sales team know this came in through drush.
  uc_order_comment_save($order->order_id, 0, t('Order created through drush.'), 'admin');

  // For some reason the above workflow doesn't update the uid in the {uc_recurring_users}
  // table so we do that manually here.
  if (module_exists('uc_recurring')) {
    db_query('UPDATE {uc_recurring_users} SET uid = %d WHERE order_id = %d', $order->uid, $order->order_id);
  }

  return $order->order_id;
}

/**
 * Drush command callback; Set semi random next_charge date in the past for uc_reccuring_users.
 */
function drush_videola_randomize_next_charge() {
  // Verify presence of uc_recurring module before proceeding.
  if (!module_exists('uc_recurring')) {
    drush_log(dt('uc_recurring module is not installed. This command will have no effect.'), 'error');
    return drush_user_abort();
  }

  if ($uid = drush_get_option('uid', FALSE)) {
    // Generate a next_charge date in the past for the specified user.
    $next_charge = time() - 14000;
    $account = is_numeric($uid) ? user_load(array('uid' => $uid)) : user_load(array('name' => $uid));
    if (!$account) {
      drush_log(dt('Unable to locate specified user account'), 'error');
      return drush_user_abort();
    }
    db_query('UPDATE {uc_recurring_users} SET next_charge = %d WHERE uid = %d', $next_charge, $account->uid);
    drush_log(dt('Set next_charge date for @uid to @date', array('@uid' => $account->name, '@date' => format_date($next_charge))), 'ok');
  }
  else {
    // Generate a next_charge date in the past for a random set of users.
    $time = time();
    $count = 0;
    $results = db_query('SELECT uid FROM {uc_recurring_users}');
    while ($row = db_fetch_object($results)) {
      if (rand(0, 3) == 1) {
        db_query('UPDATE {uc_recurring_users} SET next_charge = %d WHERE uid = %d', $time - rand(3600, 140000), $row->uid);
        $count++;
      }
    }
    drush_log(dt('Set random next_charge date in the past for @count users.', array('@count' => $count)), 'ok');
  }
}