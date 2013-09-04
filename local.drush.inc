<?php
error_log('included file');
/**
 * Custom drush make download mechanism for sourcing local directories.
 */
function make_download_local($name, $download, $location) {
  error_log('executing command');
  $path = $download['source'];

  if (is_dir($path) || is_file($path)) {
    drush_log(dt('@project found in @url.', array('@project' => $name, '@url' => $path)), 'ok');
    return drush_copy_dir($path, $location, TRUE);
  }

  return drush_set_error('DRUSH_BAD_PATH', dt('Could not evaluate source path !path.', array('!path' => $path)));
}


class DrushMakeProject_Local extends DrushMakeProject_Library {
  /**
   * Override contructor so that projects can decide where they are
   * belong, relative to the Drupal root.
   */
   protected function __construct(&$project) {
     parent::__construct($project);
     $this->contrib_destination = '';
   }
}
