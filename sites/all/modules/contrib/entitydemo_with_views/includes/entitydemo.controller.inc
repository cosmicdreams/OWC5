<?php

/**
 * @file
 * Controller
 */

/**
 * The Controller for entity demo
 */
class EntityDemoController extends EntityAPIController {
  /**
   * Constructor.
   *
   * @param string $entityType
   *   Entity type.
   */
  public function __construct($entityType) {
    parent::__construct($entityType);
  }

  /**
   * Create an entity demo.
   *
   * @param array $values
   *   Array of entitydemo values.
   *
   * @return object
   *   An entity demo object with all default fields initialized.
   */
  public function create(array $values = array()) {
    // Add values that are specific to our entitydemo.
    $values += array(
      'entitydemo_id' => '',
      'human_readable_name' => '',
      'language' => '',
      'created' => '',
      'changed' => '',
      'data' => '',
    );

    $entitydemo = parent::create($values);
    return $entitydemo;
  }
}
