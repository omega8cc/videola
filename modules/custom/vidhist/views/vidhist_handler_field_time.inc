<?php
// $Id $

class vidhist_handler_field_time extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    $options['time_format'] = array('default' => 'interval');
    $options['time_granularity'] = array('default' => 3);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    /*$form['time_format'] = array(
      '#type' => 'select',
      '#title' => t('Date format'),
      '#options' => array(
        'small' => format_date($time, 'small'),
        'medium' => format_date($time, 'medium'),
        'large' => format_date($time, 'large'),
        'custom' => t('Custom'),
        'raw time ago' => t('Time ago'),
        'time ago' => t('Time ago (with "ago" appended)'),
        'raw time span' => t('Time span (future dates start with - )'),
        'time span' => t('Time span (with "ago/hence" appended)'),
      ),
      '#default_value' => isset($this->options['date_format']) ? $this->options['date_format'] : 'small',
    );
    */
    $form['time_format'] = array(
      '#type' => 'select',
      '#title' => t('Time format'),
      '#options' => array(
        'interval' => t('hours/minutes/seconds (with granularity)'),
        'raw' => t('raw value (in seconds)'),
        'raw_milliseconds' => t('raw value (in milliseconds)'),
      ),
      '#default_value' => isset($this->options['time_format']) ? $this->options['time_format'] : 'interval',
    );
    
    $form['time_granularity'] = array(
      '#type' => 'select',
      '#title' => t('Granularity'),
      '#description' => t('How many different units of time (years, weeks, days, hours, minutes, seconds) would you like to display?'),
      '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5, 6)),
      '#default_value' => isset($this->options['time_granularity']) ? $this->options['time_granularity'] : 3,
      '#dependency' => array('edit-options-time-format' => array('interval')),
    );
    /*
    $form['custom_time_format'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom time format'),
      '#description' => t('If "Custom", see <a href="http://us.php.net/manual/en/function.date.php" target="_blank">the PHP docs</a> for date formats. If "Time ago" this is the the number of different units to display, which defaults to two.'),
      '#default_value' => isset($this->options['custom_date_format']) ? $this->options['custom_date_format'] : '',
      '#process' => array('views_process_dependency'),
      '#dependency' => array('edit-options-time-format' => array('custom', 'raw time ago', 'time ago', 'raw time span', 'time span')),
    );
    */

  }

  function render($values) {
    $value = $values->{$this->field_alias};
    switch ($this->options['time_format']) {
      case 'raw':
        return $value;
      case 'raw_milliseconds':
        return $value * 1000;
      default:
        return format_interval($value, $this->options['time_granularity']);
    }
  }
}
