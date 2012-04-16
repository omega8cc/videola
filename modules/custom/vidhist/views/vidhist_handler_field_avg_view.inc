<?php
// $Id $

class vidhist_handler_field_avg_view extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';  //the nid of the the video
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['time_format'] = array('default' => 'interval');
    $options['time_granularity'] = array('default' => 3);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
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

  }

  function render($values) {

    #dsm($values);

    // average view time per day for a video =
    // total view time and divide it by the number of days that the video has been published

    $viewtime = $values->{$this->field_alias};
    $nid = $values->{$this->aliases['nid']};
    $postdate = db_result(db_query("SELECT created FROM {node} WHERE nid = %d", $nid));
    $numsecs = time() - $postdate;
    $numdays = $numsecs / (60*60*24);
    $avg = $viewtime / $numdays;

    switch ($this->options['time_format']) {
      case 'raw':
        return $avg;
      case 'raw_milliseconds':
        return $avg * 1000;
      default:
        return format_interval($avg, $this->options['time_granularity']);
    }
  }
}
