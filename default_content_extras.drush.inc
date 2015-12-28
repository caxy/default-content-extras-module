<?php

/**
 * @file
 * Drush integration for the default_content module.
 */

/**
 * Implements hook_drush_command().
 */
function default_content_extras_drush_command() {
  $items['default-content-import'] = [
    'description' => dt('Imports a module\'s default content'),
    'arguments' => [
      'module' => dt('Module'),
    ],
    'aliases' => ['dci'],
    'required-arguments' => 1,
  ];

  return $items;
}

/**
 * Exports a piece of content into the stdout or into a file.
 *
 * @param string $module
 *   The module.
 * @param string $entity_type_id
 *   The entity type ID.
 */
function drush_default_content_extras_default_content_import($module) {
  if (!\Drupal::isConfigSyncing()) {
    /** @var \Drupal\default_content\DefaultContentManagerInterface $manager */
    $manager = \Drupal::service('default_content.manager');
    $manager->importContent($module);
  }
}
