<?php
/**
 * @file
 * Theme functions for the c4m_content module.
 */

/**
 * Theme function for website statistics summary block.
 *
 * @param array $variables
 *   Template variables.
 *
 * @return mixed
 *   Rendered output.
 */
function theme_c4m_website_statistics_summary(array $variables) {
  $statistics = $variables['data'];
  if (empty($statistics)) {
    return;
  }

  $flip = array('even' => 'odd', 'odd' => 'even');
  $class = 'even';
  $list = array();
  foreach ($statistics as $key => $stat) {
    if (!$stat) {
      continue;
    }

    $class = $flip[$class];

    // Format single/plural text.
    $text = $stat['count'] . ' ' . format_plural(
      $stat['count'],
      $stat['title']['singular'],
      $stat['title']['plural']
    );

    // Show as link?
    if (!empty($stat['link']['path'])) {
      $options = isset($stat['link']['options'])
        ? $stat['link']['options']
        : array();

      $text = l($text, $stat['link']['path'], $options);
    }

    // Add css classes defined in hook.
    $stat_classes = isset($stat['attributes']['class'])
      ? $stat['attributes']['class']
      : array();

    // Create a list item.
    $list[$key] = array(
      'data' => $text,
      'class' => array(
        'statistics-item',
        'stats-' . $key,
        $class,
        implode(',', $stat_classes),
      ),
    );
  }

  $summary = array(
    '#theme'      => 'item_list',
    '#items'      => $list,
    '#attributes' => array(
      'class' => array('statistics-list'),
    ),
  );

  return render($summary);
}