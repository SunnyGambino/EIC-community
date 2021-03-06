<?php

/**
 * @file
 * All forms related manipulations to the theme.
 */

/**
 * Returns HTML for a form element label and required marker.
 *
 * Form element labels include the #title and a #required marker. The label is
 * associated with the element itself by the element #id. Labels may appear
 * before or after elements, depending on theme_form_element() and
 * #title_display.
 *
 * This function will not be called for elements with no labels, depending on
 * #title_display. For elements that have an empty #title and are not required,
 * this function will output no label (''). For required elements that have an
 * empty #title, this will output the required marker alone within the label.
 * The label will use the #id to associate the marker with the field that is
 * required. That is especially important for screenreader users to know
 * which field is required.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #required, #title, #id, #value, #description.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see bootstrap_form_element_label()
 * @see theme_form_element_label()
 *
 * @ingroup theme_functions
 */
function kapablo_form_element_label(array &$variables) {
  $element = $variables['element'];

  // Extract variables.
  $output = '';
  $title = isset($element['#title']) ? filter_xss_admin($element['#title']) . ' ' : '';
  if ($title && ($required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '')) {
    $title .= $required;
  }
  $display = isset($element['#title_display']) ? $element['#title_display'] : 'before';
  $type = !empty($element['#type']) ? $element['#type'] : FALSE;
  $checkbox = $type && $type === 'checkbox';
  $radio = $type && $type === 'radio';

  $help_text = '';
  // Adding the "What's this?" in case of a help text.
  if (!empty($element['#what_is_this'])) {
    $help_text = kapablo_render_what_is_this($element['#what_is_this']);
  }

  // Immediately return if the element is not a checkbox or radio and there is
  // no label to be rendered.
  if (!$checkbox && !$radio && ($display === 'none' || !$title)) {
    return $help_text;
  }

  // Retrieve the label attributes array.
  $attributes = &_bootstrap_get_attributes($element, 'label_attributes');

  // Add Bootstrap label class.
  $attributes['class'][] = 'control-label';

  // Add the necessary 'for' attribute if the element ID exists.
  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // Checkboxes and radios must construct the label differently.
  if ($checkbox || $radio) {
    if ($display === 'before') {
      $output .= '<span>' . $title . '</span>';
    }
    elseif ($display === 'none' || $display === 'invisible') {
      $output .= '<span class="element-invisible">' . $title . '</span>';
    }
    // Inject the rendered checkbox or radio element inside the label.
    if (!empty($element['#children'])) {
      $output .= $element['#children'];
    }
    if ($display === 'after') {
      $output .= '<span>' . $title . '</span>';
    }
  }
  // Otherwise, just render the title as the label.
  else {
    // Show label only to screen readers to avoid disruption in visual flows.
    if ($display === 'invisible') {
      $attributes['class'][] = 'element-invisible';
    }
    $output .= $title;
  }

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $output . "</label>{$help_text}\n";
}

/**
 * Renders the "what's this?" tooltip element.
 *
 * @param string $description
 *   The text that should be in the tooltip.
 *
 * @return string
 *   The rendered tooltip element.
 */
function kapablo_render_what_is_this($description) {
  // Strip all tags because it doesn't make any sense to use them inside the
  // tooltip.
  $description = strip_tags($description);

  if (empty($description)) {
    return '';
  }

  $tag['element'] = array(
    '#tag' => 'span',
    '#attributes' => array(
      'class' => array('what-is-this'),
      'data-toggle' => 'tooltip',
      'title' => $description,
    ),
    '#value' => t("What's this?"),
  );

  return theme_html_tag($tag);
}
