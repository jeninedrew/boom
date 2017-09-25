<?php
/**
 * @file
 * Drush command to create a new theme based on the boom theme.
 */

/**
 * Implements hook_drush_command().
 */
function boom_drush_command() {
  return array('boom' => array(
    'description' => 'Create a new theme based on the boom theme.',
    'arguments' => array(
      'name' => 'The name of your theme.',
    ),
    'options' => array(
      'description' => 'A short description of your new theme.',
      'machine-name' => 'The machine-readable name of your new theme. This will be auto-generated from the human-readable name if omitted.',
    ),
    'examples' => array(
      'drush boom "New Theme Name"' => 'Creates a new theme called "New Theme Name" with a machine name of "new_theme_name".',
      'drush boom "New Theme Name" --machine-name=new_theme' => 'Creates a new theme called "New Theme Name" with a machine name of "new_theme".',
    ),
  ));
}

/**
 * Implements hook_drush_help().
 */
function boom_drush_help($section) {
  switch ($section) {
    case 'drush:boom':
      return dt('This command will create a new theme based on the boom theme.');
  }
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_boom_validate($name = NULL) {
  $description = drush_get_option('description');
  $machine_name = drush_get_option('machine-name', _boom_machine_name($name));

  drush_set_option('machine-name', $machine_name);

  if (!_boom_theme_exists('boom')) {
    return drush_set_error(
      'boom_ERROR',
      dt('Where is the boom theme? I could not find it.')
    );
  }

  if (_boom_theme_exists($machine_name)) {
    return drush_set_error(
      'boom_ERROR',
      dt('A theme with that name already exists. The machine-readable name must be unique.')
    );
  }

  if (!$machine_name || !preg_match('/^[a-z][a-z0-9_]*$/', $machine_name)) {
    return drush_set_error(
      'boom_ERROR',
      dt('The machine name was invalid or could not be generated properly. It must start with a letter and may only contain lowercase letters, numbers, and underscores.')
    );
  }
}

/**
 * Converts $name to a machine-readable format.
 */
function _boom_machine_name($name) {
  $name = str_replace(' ', '_', strtolower($name));
  $search = array(
    '/[^a-z0-9_]/', // Remove characters not valid in function names.
    '/^[^a-z]+/',   // Functions must begin with an alpha character.
  );
  $name = preg_replace($search, '', $name);
  $name = str_replace('__', '_', $name);
  $name = trim($name, '_');

  return $name;
}

/**
 * Checks if $theme_name already exists in Drupal.
 */
function _boom_theme_exists($theme_name) {
  $theme_handler = \Drupal::service('theme_handler');
  $themes = $theme_handler->listInfo();

  return isset($themes[$theme_name]);
}

/**
 * Implements drush_hook_COMMAND().
 */
function drush_boom($name = NULL) {
  // Get new theme options.
  if (!isset($name)) {
    $name = drush_get_option('name');
  }
  $machine_name = drush_get_option('machine-name', _boom_machine_name($name));
  $description = drush_get_option('description');

  // Get theme paths.
  $boom_path = drush_normalize_path(drush_get_context('DRUSH_DRUPAL_ROOT') . '/' . drupal_get_path('theme', 'boom'));
  $theme_path = 'themes';
  $new_path = drush_normalize_path(drush_get_context('DRUSH_DRUPAL_ROOT') . '/' . $theme_path . '/' . $machine_name);

  // Copy the boom theme directory recursively to the new theme’s location.
  drush_op('drush_copy_dir', $boom_path, $new_path);

  // Remove boom’s drush file from the new theme.
  drush_op('unlink', "$new_path/includes/boom.drush.inc");

  // Rename the .info.yml file.
  $boom_info_file = drush_normalize_path($new_path . '/' . 'boom.info.yml');
  $new_info_file = drush_normalize_path($new_path . '/' . $machine_name . '.info.yml');
  drush_op('rename', $boom_info_file, $new_info_file);

  // Update the .info.yml file based on the command options.
  $changes = array(
    'boom' => $name,
    'Sass-based starter theme.' => $description,
    'boom' => $machine_name,
  );
  drush_op('boom_file_str_replace', $new_info_file, array_keys($changes), $changes);

  // Rename the .breakpoints.yml file.
  $boom_info_file = drush_normalize_path($new_path . '/' . 'boom.breakpoints.yml');
  $new_info_file = drush_normalize_path($new_path . '/' . $machine_name . '.breakpoints.yml');
  drush_op('rename', $boom_info_file, $new_info_file);

  // Rename the .libraries.yml file.
  $boom_libraries_file = drush_normalize_path($new_path . '/' . 'boom.libraries.yml');
  $new_libraries_file = drush_normalize_path($new_path . '/' . $machine_name . '.libraries.yml');
  drush_op('rename', $boom_libraries_file, $new_libraries_file);

  // Rename the .theme file.
  $boom_theme_file = drush_normalize_path($new_path . '/' . 'boom.theme');
  $new_theme_file = drush_normalize_path($new_path . '/' . $machine_name . '.theme');
  drush_op('rename', $boom_theme_file, $new_theme_file);

  // Replace all occurrences of 'boom' with the machine name of the new theme.
  $breakpoints_file = $machine_name . '.breakpoints.yml';
  $libraries_file = $machine_name . '.libraries.yml';
  $theme_file = $machine_name . '.theme';
  $files = array(
    $breakpoints_file,
    $libraries_file,
    $theme_file,
    'js/scripts.js',
    'includes/form.inc',
    'includes/html.inc',
    'templates/misc/progress-bar.html.twig',
    'templates/misc/status-messages.html.twig',
    'templates/navigation/pager.html.twig',
    'templates/views/views-mini-pager.html.twig',
  );
  foreach ($files as $file) {
    drush_op('boom_file_str_replace', drush_normalize_path($new_path . '/' . $file), 'boom', $machine_name);
  }

  // Notify user of the newly created theme.
  drush_print(dt(
    "\nThe \"!name\" theme has been created in: !path\n",
    array(
      '!name' => $name,
      '!path' => $new_path,
    )
  ));
}

/**
 * Replace strings in a file.
 */
function boom_file_str_replace($file_path, $find, $replace) {
  $file_path = drush_normalize_path($file_path);
  $file_contents = file_get_contents($file_path);
  $file_contents = str_replace($find, $replace, $file_contents);
  file_put_contents($file_path, $file_contents);
}
