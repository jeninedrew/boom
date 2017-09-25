<?php
/**
 * @file
 * Form template functions.
 */

/**
 * Implements template_preprocess_input().
 */
function boom_preprocess_input(&$vars) {
  $vars['required'] = $vars['element']['#required'];
  $vars['type'] = isset($vars['element']['#attributes']['type']) ? $vars['element']['#attributes']['type'] : NULL;
  $vars['dropbutton'] = isset($vars['element']['#dropbutton']) ? $vars['element']['#dropbutton'] : NULL;
}

/**
 * Implements template_preprocess_fieldset().
 */
function boom_preprocess_fieldset(&$vars) {
  $vars['type'] = isset($vars['element']['#type']) ? $vars['element']['#type'] : NULL;
}
