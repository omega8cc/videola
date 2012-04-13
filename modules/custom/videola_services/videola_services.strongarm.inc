<?php

/**
 * Implementation of hook_strongarm().
 */
function videola_services_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oauth_common_enable_provider';
  $strongarm->value = 1;

  $export['oauth_common_enable_provider'] = $strongarm;
  return $export;
}
