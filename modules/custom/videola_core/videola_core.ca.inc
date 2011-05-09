<?php

/**
 * Implements hook_ca_predicate().
 */
function videola_core_ca_predicate() {
  $predicates = array();
  $predicates['videola_renewal_failed'] = array(
    '#title' => t('Update order status when renewal fails.'),
    '#trigger' => 'uc_recurring_renewal_failed',
    '#class' => 'notification',
    '#status' => 1,
    '#weight' => 0,
    '#conditions' => array(),
    '#actions' => array(
      array(
        '#name' => 'uc_order_update_status',
        '#title' => t('Update the order status to Declined.'),
        '#argument_map' => array(
          'order' => 'order',
        ),
        '#settings' => array(
          'order_status' => 'declined',
        ),
      )
    ),
  );
  return $predicates;
}
