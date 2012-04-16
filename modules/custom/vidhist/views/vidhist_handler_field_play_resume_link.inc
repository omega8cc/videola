<?php
/**
 * Field handler to present a video play/resume link..
 */
class vidhist_handler_field_play_resume_link extends views_handler_field_node_link {
  function construct() {
    parent::construct();
    $this->additional_fields['duration'] = 'duration';
    $this->additional_fields['end'] = 'end';
    $this->additional_fields['nid'] = 'nid';
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Resume text'),
      '#description' => t('Text to display for user\'s when linking to a specific time in a partially watched video.'),
      '#default_value' => $this->options['text'],
    );
    $form['text_play'] = array(
      '#type' => 'textfield',
      '#title' => t('Play text'),
      '#description' => t('Text to display for user\'s who have completed the video. Links to begning of video.'),
      '#default_value' => $this->options['text_play'],
    );
  }

  function render($values) {
    $duration = $values->{$this->aliases['duration']};
    $end = $values->{$this->aliases['end']};
    $nid = $values->{$this->aliases['nid']};

    if ($end >= $duration) {
      $text = !empty($this->options['text_play']) ? $this->options['text_play'] : t('play');
    }
    else {
      $text = !empty($this->options['text']) ? $this->options['text'] : t('resume');
    }

    if ($this->options['alter']['make_link'] == 1) {
      return check_plain($text);
    }
    return l($text, "node/$nid");
  }
}