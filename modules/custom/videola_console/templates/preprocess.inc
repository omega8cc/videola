<?php
/**
 * @file
 * Preprocess functions for template files.
 */

function template_preprocess_videola_console_device_list(&$vars) {
  if (count($vars['devices'])) {
    $rows = array();
    foreach ($vars['devices'] as $device) {
      $rows[] = array(
        check_plain($device->device_id),
        format_date($device->last_updated, 'medium'),
        l(t('deactivate'), 'device/' . $device->device_id . '/remove'),
      );
    }
    $headers = array(t('Device ID'), t('Last Updated'), t('Options'));
    $rendered = theme('table', $headers, $rows);
  }
  else {
    $rendered = FALSE;
  }
  $vars['devices_rendered'] = $rendered;
}
