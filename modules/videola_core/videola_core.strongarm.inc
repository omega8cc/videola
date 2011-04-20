<?php

/**
 * Implementation of hook_strongarm().
 */
function videola_core_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ejectorseat_background';
  $strongarm->value = '0';

  $export['ejectorseat_background'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ejectorseat_interval';
  $strongarm->value = '60';

  $export['ejectorseat_interval'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'session_limit_auto_drop';
  $strongarm->value = 1;

  $export['session_limit_auto_drop'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'session_limit_max';
  $strongarm->value = '1';

  $export['session_limit_max'] = $strongarm;
  return $export;
}
