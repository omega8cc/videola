<?php

/**
 * Implementation of hook_strongarm().
 */
function videola_ubercart_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_add_item_redirect';
  $strongarm->value = 'cart';

  $export['uc_add_item_redirect'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_fields';
  $strongarm->value = array(
    'first_name' => 'first_name',
    'last_name' => 'last_name',
    'phone' => 'phone',
    'street1' => 'street1',
    'street2' => 'street2',
    'city' => 'city',
    'zone' => 'zone',
    'country' => 'country',
    'postal_code' => 'postal_code',
  );

  $export['uc_address_fields'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_fields_required';
  $strongarm->value = array(
    'first_name' => 'first_name',
    'last_name' => 'last_name',
    'phone' => 'phone',
    'street1' => 'street1',
    'city' => 'city',
    'zone' => 'zone',
    'country' => 'country',
    'postal_code' => 'postal_code',
  );

  $export['uc_address_fields_required'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_authnet_api_live_gateway_url';
  $strongarm->value = 'https://secure.authorize.net/gateway/transact.dll';

  $export['uc_authnet_api_live_gateway_url'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_authnet_api_test_gateway_url';
  $strongarm->value = 'https://test.authorize.net/gateway/transact.dll';

  $export['uc_authnet_api_test_gateway_url'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_authnet_arb_mode';
  $strongarm->value = 'production';

  $export['uc_authnet_arb_mode'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_authnet_cim_mode';
  $strongarm->value = 'production';

  $export['uc_authnet_cim_mode'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_authnet_cim_profile';
  $strongarm->value = 1;

  $export['uc_authnet_cim_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_authnet_duplicate_window';
  $strongarm->value = '120';

  $export['uc_authnet_duplicate_window'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_authnet_md5_hash';
  $strongarm->value = '';

  $export['uc_authnet_md5_hash'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_authnet_report_arb_post';
  $strongarm->value = 1;

  $export['uc_authnet_report_arb_post'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_authnet_response_debug';
  $strongarm->value = 0;

  $export['uc_authnet_response_debug'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_add_item_msg';
  $strongarm->value = 0;

  $export['uc_cart_add_item_msg'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_anon_duration';
  $strongarm->value = '4';

  $export['uc_cart_anon_duration'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_anon_unit';
  $strongarm->value = 'hours';

  $export['uc_cart_anon_unit'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_auth_duration';
  $strongarm->value = '1';

  $export['uc_cart_auth_duration'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_auth_unit';
  $strongarm->value = 'years';

  $export['uc_cart_auth_unit'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_breadcrumb_text';
  $strongarm->value = '';

  $export['uc_cart_breadcrumb_text'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_breadcrumb_url';
  $strongarm->value = '';

  $export['uc_cart_breadcrumb_url'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_email_validation';
  $strongarm->value = 0;

  $export['uc_cart_email_validation'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_new_account_details';
  $strongarm->value = '<b>Optional.</b> New customers may supply custom account details.<br />We will create these for you if no values are entered.';

  $export['uc_cart_new_account_details'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_new_account_name';
  $strongarm->value = 1;

  $export['uc_cart_new_account_name'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_new_account_password';
  $strongarm->value = 0;

  $export['uc_cart_new_account_password'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_instructions';
  $strongarm->value = 'You\'re almost done. Simply provide us with some information about yourself and how you wish to pay and then click the "Review Order" button at the bottom.';

  $export['uc_checkout_instructions'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_instructions_format';
  $strongarm->value = '1';

  $export['uc_checkout_instructions_format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_review_instructions';
  $strongarm->value = 'Now let\'s double check to be sure all is well. Please review the details below and if all looks well click the "Submit Order" button. If you need to tweak something click the "Back" button. Once you click the "Submit Order" button you\'ll be all done and ready to be Drupalized!';

  $export['uc_checkout_review_instructions'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_review_instructions_format';
  $strongarm->value = '1';

  $export['uc_checkout_review_instructions_format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_text';
  $strongarm->value = '';

  $export['uc_continue_shopping_text'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_type';
  $strongarm->value = 'link';

  $export['uc_continue_shopping_type'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_url';
  $strongarm->value = '';

  $export['uc_continue_shopping_url'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_use_last_url';
  $strongarm->value = 1;

  $export['uc_continue_shopping_use_last_url'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_pane_description';
  $strongarm->value = '';

  $export['uc_coupon_pane_description'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_accepted_types';
  $strongarm->value = 'Visa
Mastercard
Discover
American Express';

  $export['uc_credit_accepted_types'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_amex';
  $strongarm->value = 1;

  $export['uc_credit_amex'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_bank_enabled';
  $strongarm->value = 0;

  $export['uc_credit_bank_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_checkout_process';
  $strongarm->value = 1;

  $export['uc_credit_checkout_process'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_clear_status';
  $strongarm->value = 'completed';

  $export['uc_credit_clear_status'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_cvv_enabled';
  $strongarm->value = 1;

  $export['uc_credit_cvv_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_debug';
  $strongarm->value = 0;

  $export['uc_credit_debug'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_discover';
  $strongarm->value = 1;

  $export['uc_credit_discover'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_encryption_path';
  $strongarm->value = '/tmp';

  $export['uc_credit_encryption_path'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_fail_message';
  $strongarm->value = 'We were unable to process your credit card payment. Please verify your card details and try again.  If the problem persists, contact us to complete your order.';

  $export['uc_credit_fail_message'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_issue_enabled';
  $strongarm->value = 0;

  $export['uc_credit_issue_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_mastercard';
  $strongarm->value = 1;

  $export['uc_credit_mastercard'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_number_duration';
  $strongarm->value = '3';

  $export['uc_credit_number_duration'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_number_unit';
  $strongarm->value = 'days';

  $export['uc_credit_number_unit'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_owner_enabled';
  $strongarm->value = 0;

  $export['uc_credit_owner_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_policy';
  $strongarm->value = 'Your billing information must match the billing address for the credit card entered below or we will be unable to process your payment.';

  $export['uc_credit_policy'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_start_enabled';
  $strongarm->value = 0;

  $export['uc_credit_start_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_type_enabled';
  $strongarm->value = 0;

  $export['uc_credit_type_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_validate_numbers';
  $strongarm->value = 1;

  $export['uc_credit_validate_numbers'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_credit_visa';
  $strongarm->value = 1;

  $export['uc_credit_visa'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_customer_list_address';
  $strongarm->value = 'billing';

  $export['uc_customer_list_address'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_address';
  $strongarm->value = 'Address';

  $export['uc_field_address'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_city';
  $strongarm->value = 'City';

  $export['uc_field_city'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_company';
  $strongarm->value = 'Company';

  $export['uc_field_company'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_country';
  $strongarm->value = 'Country';

  $export['uc_field_country'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_first_name';
  $strongarm->value = 'First name';

  $export['uc_field_first_name'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_last_name';
  $strongarm->value = 'Last name';

  $export['uc_field_last_name'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_phone';
  $strongarm->value = 'Phone number';

  $export['uc_field_phone'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_postal_code';
  $strongarm->value = 'Postal code';

  $export['uc_field_postal_code'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_street';
  $strongarm->value = 'Street address';

  $export['uc_field_street'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_street1';
  $strongarm->value = 'Street address 1';

  $export['uc_field_street1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_street2';
  $strongarm->value = 'Street address 2';

  $export['uc_field_street2'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_zone';
  $strongarm->value = 'State/Province';

  $export['uc_field_zone'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_footer_message';
  $strongarm->value = 'none';

  $export['uc_footer_message'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_image_';
  $strongarm->value = '';

  $export['uc_image_'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_image_product';
  $strongarm->value = 'field_image_cache';

  $export['uc_image_product'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_image_subscription';
  $strongarm->value = 'field_image_cache';

  $export['uc_image_subscription'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_minimum_subtotal';
  $strongarm->value = '0';

  $export['uc_minimum_subtotal'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_continue_shopping';
  $strongarm->value = '';

  $export['uc_msg_continue_shopping'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_continue_shopping_format';
  $strongarm->value = '1';

  $export['uc_msg_continue_shopping_format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_existing_user';
  $strongarm->value = 'Thank you for shopping at [store-name]. Your current order has been attached to the account we found matching your e-mail address.

<a href="/user">Login</a> to view your current order status and order history. Remember to login when you make your next purchase for a faster checkout experience!';

  $export['uc_msg_order_existing_user'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_existing_user_format';
  $strongarm->value = '1';

  $export['uc_msg_order_existing_user_format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_logged_in';
  $strongarm->value = 'Thank you for shopping at [store-name]. While logged in, you may continue shopping or <a href="[order-url]">view your current order status</a> and order history.';

  $export['uc_msg_order_logged_in'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_logged_in_format';
  $strongarm->value = '1';

  $export['uc_msg_order_logged_in_format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_new_user';
  $strongarm->value = 'Thank you for shopping at [store-name]. A new account has been created for you here that you may use to view your current order status.

<a href=\\"!user_url\\">Login</a> to your new account using the following information:
<strong>Username:</strong> !new_username
<strong>Password:</strong> !new_password';

  $export['uc_msg_order_new_user'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_new_user_format';
  $strongarm->value = '1';

  $export['uc_msg_order_new_user_format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_submit';
  $strongarm->value = '<p>w00t! Way to go [order-first-name]. Your order is complete and you\'re ready to be Drupalized!</p>

<p>Here is your order number in case you have any questions:  <strong>[order-id]</strong>.
For your convenience, all of your order details have been emailed to [order-email].</p>';

  $export['uc_msg_order_submit'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_submit_format';
  $strongarm->value = '1';

  $export['uc_msg_order_submit_format'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_billing_enabled';
  $strongarm->value = 1;

  $export['uc_pane_billing_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_billing_weight';
  $strongarm->value = '4';

  $export['uc_pane_billing_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_cart_enabled';
  $strongarm->value = 1;

  $export['uc_pane_cart_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_cart_weight';
  $strongarm->value = '1';

  $export['uc_pane_cart_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_comments_enabled';
  $strongarm->value = 0;

  $export['uc_pane_comments_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_comments_weight';
  $strongarm->value = '7';

  $export['uc_pane_comments_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_coupon_enabled';
  $strongarm->value = 1;

  $export['uc_pane_coupon_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_coupon_weight';
  $strongarm->value = '5';

  $export['uc_pane_coupon_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_customer_enabled';
  $strongarm->value = 1;

  $export['uc_pane_customer_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_customer_weight';
  $strongarm->value = '2';

  $export['uc_pane_customer_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_delivery_enabled';
  $strongarm->value = 1;

  $export['uc_pane_delivery_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_delivery_weight';
  $strongarm->value = '3';

  $export['uc_pane_delivery_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_payment_enabled';
  $strongarm->value = 1;

  $export['uc_pane_payment_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_payment_weight';
  $strongarm->value = '6';

  $export['uc_pane_payment_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_quotes_enabled';
  $strongarm->value = 1;

  $export['uc_pane_quotes_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_quotes_weight';
  $strongarm->value = '5';

  $export['uc_pane_quotes_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_uc_termsofservice_agreement_checkout_enabled';
  $strongarm->value = 1;

  $export['uc_pane_uc_termsofservice_agreement_checkout_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_uc_termsofservice_agreement_checkout_weight';
  $strongarm->value = '6';

  $export['uc_pane_uc_termsofservice_agreement_checkout_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_credit_gateway';
  $strongarm->value = 'test_gateway';

  $export['uc_payment_credit_gateway'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_credit_checkout';
  $strongarm->value = 1;

  $export['uc_payment_method_credit_checkout'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_credit_weight';
  $strongarm->value = '2';

  $export['uc_payment_method_credit_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_free_order_checkout';
  $strongarm->value = 1;

  $export['uc_payment_method_free_order_checkout'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_free_order_weight';
  $strongarm->value = '10';

  $export['uc_payment_method_free_order_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_show_order_total_preview';
  $strongarm->value = 1;

  $export['uc_payment_show_order_total_preview'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pg_authorizenet_cc_txn_type';
  $strongarm->value = 'auth_capture';

  $export['uc_pg_authorizenet_cc_txn_type'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pg_authorizenet_enabled';
  $strongarm->value = 1;

  $export['uc_pg_authorizenet_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pg_test_gateway_cc_txn_type';
  $strongarm->value = 'auth_capture';

  $export['uc_pg_test_gateway_cc_txn_type'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pg_test_gateway_enabled';
  $strongarm->value = 1;

  $export['uc_pg_test_gateway_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_add_to_cart_qty';
  $strongarm->value = 0;

  $export['uc_product_add_to_cart_qty'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_add_to_cart_teaser';
  $strongarm->value = 1;

  $export['uc_product_add_to_cart_teaser'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_add_to_cart_text';
  $strongarm->value = 'Signup';

  $export['uc_product_add_to_cart_text'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_enable_nodes';
  $strongarm->value = FALSE;

  $export['uc_product_enable_nodes'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_field_enabled';
  $strongarm->value = array(
    'display_price' => 1,
    'image' => 0,
    'model' => 0,
    'list_price' => 0,
    'cost' => 0,
    'sell_price' => 0,
    'weight' => 0,
    'dimensions' => 0,
    'add_to_cart' => 1,
  );

  $export['uc_product_field_enabled'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_field_weight';
  $strongarm->value = array(
    'display_price' => '-10',
    'image' => '-2',
    'model' => '0',
    'list_price' => '2',
    'cost' => '3',
    'sell_price' => '4',
    'weight' => '5',
    'dimensions' => '6',
    'add_to_cart' => '10',
  );

  $export['uc_product_field_weight'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_image_widget';
  $strongarm->value = '';

  $export['uc_product_image_widget'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_shippable_subscription';
  $strongarm->value = 1;

  $export['uc_product_shippable_subscription'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_cancel_redirect';
  $strongarm->value = '/cancellation-survey';

  $export['uc_recurring_cancel_redirect'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_checkout_fail';
  $strongarm->value = 'fail';

  $export['uc_recurring_checkout_fail'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_checkout_message';
  $strongarm->value = '';

  $export['uc_recurring_checkout_message'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_checkout_process';
  $strongarm->value = 1;

  $export['uc_recurring_checkout_process'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_payment_methods';
  $strongarm->value = array(
    'credit' => 'credit',
  );

  $export['uc_recurring_payment_methods'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_subscription_attribute';
  $strongarm->value = '1';

  $export['uc_recurring_subscription_attribute'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_subscription_product_class';
  $strongarm->value = 'subscription';

  $export['uc_recurring_subscription_product_class'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_trigger_renewals';
  $strongarm->value = 0;

  $export['uc_recurring_trigger_renewals'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_admin_page_display';
  $strongarm->value = '1';

  $export['uc_store_admin_page_display'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_city';
  $strongarm->value = '';

  $export['uc_store_city'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_country';
  $strongarm->value = '840';

  $export['uc_store_country'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_email_include_name';
  $strongarm->value = 1;

  $export['uc_store_email_include_name'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_fax';
  $strongarm->value = '';

  $export['uc_store_fax'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_help_page';
  $strongarm->value = '';

  $export['uc_store_help_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_phone';
  $strongarm->value = '';

  $export['uc_store_phone'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_postal_code';
  $strongarm->value = '';

  $export['uc_store_postal_code'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_street1';
  $strongarm->value = '';

  $export['uc_store_street1'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_street2';
  $strongarm->value = '';

  $export['uc_store_street2'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_zone';
  $strongarm->value = '';

  $export['uc_store_zone'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_teaser_add_to_cart_text';
  $strongarm->value = 'Signup';

  $export['uc_teaser_add_to_cart_text'] = $strongarm;
  return $export;
}
