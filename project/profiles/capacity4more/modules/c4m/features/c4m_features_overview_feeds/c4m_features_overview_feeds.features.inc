<?php

/**
 * @file
 * c4m_features_overview_feeds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_overview_feeds_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_features_overview_feeds_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
