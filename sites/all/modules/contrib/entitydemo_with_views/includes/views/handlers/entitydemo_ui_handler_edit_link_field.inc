<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */

class entitydemo_ui_handler_edit_link_field extends entitydemo_ui_handler_link_field {
  /**
   * Constructor.
   */
  function construct() {
    parent::construct();
  }

  /**
   * Render a link to edit specific entitydemo.
   *
   * @param object $values
   *   Entity object.
   *
   * @return string
   *   Render link.
   */
  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $entitydemo_id = $values->{$this->aliases['entitydemo_id']};

    return l($text, 'admin/content/entitydemo-list/' . $entitydemo_id . '/edit');
  }
}
