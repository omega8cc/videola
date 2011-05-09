<?php


class vidhist_handler_filter_lateststamp extends views_handler_filter {
  function option_definition() {
    $options = parent::option_definition();
    $options['latest_only'] = array('default' => 1);
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    $form['latest_only'] = array(
      '#type' => 'checkbox',
      '#title' => t('Limit to just the most recent viewing'),
      '#default_value' => isset($this->options['latest_only']) ? $this->options['latest_only'] : 1,
    );
  }
  
  function query() {
    $this->ensure_my_table();
    
    //$this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field " . $this->operator . " '%s'", $this->value);
  }
   
}