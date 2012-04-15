<?php

/**
 * Implementation of hook_default_oauth_common_context().
 */
function videola_services_default_oauth_common_context() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 1;
  $context->name = 'videola_oauth';
  $context->title = 'Videola OAuth';
  $context->authorization_options = array(
    'access_token_lifetime' => 0,
    'disable_auth_level_selection' => 1,
    'signature_methods' => array(
      0 => 'HMAC-SHA1',
      1 => 'HMAC-SHA256',
      2 => 'HMAC-SHA384',
      3 => 'HMAC-SHA512',
    ),
    'default_authorization_levels' => array(
      0 => 'deafult',
    ),
  );
  $context->authorization_levels = array(
    'deafult' => array(
      'name' => 'deafult',
      'title' => 'Default',
      'description' => '',
      'default' => 1,
      'delete' => 0,
    ),
  );

  $export['videola_oauth'] = $context;
  return $export;
}
