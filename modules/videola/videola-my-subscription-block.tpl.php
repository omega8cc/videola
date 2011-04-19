<?php
// $Id$

/**
 * @file videola-my-subscription-block.tpl.php
 *
 * Theme implementation to display a the my subscription block.
 *
 * Available variables:
 * - $account: User's $account object.
 * - $subscription: Users's subscription details (e.g start/end date, amount).
 * - $order: User's order details (e.g. billing information).
 */
?>
<div class="my-subscription">
  <h3><?php print $order->full_name; ?></h3>
  <?php if ($order): ?>
  <div class="billing-info">
    <p><?php print t('Credit card: **********@last-4', array('@last-4' => $order->last_4)); ?></p>
    <?php if ($order->address): ?>
      <p><?php print $order->address; ?></p>
    <?php endif; ?>
    <p><?php print l(t('Update Billing Info'), 'user/' . $account->uid . '/recurring/' .$subscription->rfid .'/update/authorizenet_cim'); ?></p>
  </div>
  <?php endif; ?>
  <h3><?php print theme('username', $account); ?></h3>
  <div class="account-info">
    <p><?php print check_plain($account->mail); ?></p>
    <p><?php print t('Password: ******'); ?></p>
    <p><?php print l(t('Update Account Info'), 'user/' . $account->uid . '/edit', array('query' => drupal_get_destination())); ?></p>
  </div>
  <?php if ($subscription): ?>
  <h3><?php print t('@type - @frequency', array('@type' => $subscription->type, '@frequency' => $subscription->frequency)); ?></h3>
  <div class="subscription-info">
    <p><?php print t('Next Billing Date: @date', array('@date' => format_date($subscription->next_charge, 'custom', 'F j, Y', 0))); ?></p>
    <?php
    $links = array(
      l(t('View Billing History'), "user/$account->uid/orders"),
      l(t('Change Your Billing Frequency'), "subscription"),
    );
    print theme('item_list', $links); ?>
  </div>
  <?php endif; ?>
</div>
