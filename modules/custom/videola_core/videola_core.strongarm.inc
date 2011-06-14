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
  $strongarm->name = 'radioactivity_decay_granularity';
  $strongarm->value = '600';

  $export['radioactivity_decay_granularity'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'radioactivity_profiles';
  $strongarm->value = array(
    1 => array(
      'label' => '5-day',
      'description' => 'Popular content with a half-life of 5 days',
      'half_life' => 432000,
      'cut_off_energy' => 0.5,
      'energy' => array(
        'node' => array(
          'subclasses' => array(
            'videola_video' => array(
              'view' => '2',
              'view_auth' => '4',
              'node_create' => '10000',
              'comment_insert' => '200',
              'comment_publish' => '20',
            ),
          ),
        ),
      ),
    ),
  );

  $export['radioactivity_profiles'] = $strongarm;
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
