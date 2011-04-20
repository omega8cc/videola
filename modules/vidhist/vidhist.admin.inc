<?php
// $Id:$

/**
 * @file
 * Administration pages and functions for vidhist module.
 */

/**
 * Form builder; System settings form for vidhist.
 */
function vidhist_settings() {
  $form = array();
  $period = drupal_map_assoc(array(15, 30, 60, 120, 180, 300, 600, 1200, 1800, 3600), 'format_interval');
  $period = array(0 => t('never')) + $period;
  $form['vidhist_interval'] = array(
    '#type' => 'select',
    '#title' => t('Playhead save rate'),
    '#options' => $period,
    '#description' => t("When a video is playing, how often should the playhead position be autosaved to the server? Lower rates may affect site performance."),
    '#default_value' => variable_get('vidhist_interval', 60),
  );

  $form['vidhist_enabled_players'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enable tracking for the following players.'),
    '#options' => vidhist_get_players(),
    '#default' => variable_get('vidhist_enabled_players', NULL),
  );

  return system_settings_form($form);
}