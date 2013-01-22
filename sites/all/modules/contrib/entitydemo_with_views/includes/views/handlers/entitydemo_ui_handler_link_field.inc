<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

class entitydemo_ui_handler_link_field extends views_handler_field {
  /**
   * Constructor.
   */
  function construct() {
    parent::construct();

    $this->additional_fields['entitydemo_id'] = 'entitydemo_id';
    $this->additional_fields['human_readable_name'] = 'human_readable_name';
  }

  /**
   * Option definition.
   *
   * Determines if this field will be available as an option
   * to group the result by in the style settings.
   *
   * @return bool
   *   TRUE if this field handler is groupable, otherwise FALSE.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  /**
   * Options form.
   *
   * Default options form that provides the label widget that all fields
   * should have.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  /**
   * Add additional fields.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render a default link to specific entitydemo.
   *
   * @param object $values
   *   Entity object.
   *
   * @return string
   *   Render link.
   */
  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $entitydemo_id = $values->{$this->aliases['entitydemo_id']};

    return l($text, 'admin/content/entitydemo-list/' . $entitydemo_id);
  }
}
