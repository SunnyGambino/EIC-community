<?php
/**
 * @file
 * c4m_features_og_members.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_og_members_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_features_og_members_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function c4m_features_og_members_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_c4m_overview_og_members'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_c4m_overview_og_members",
    "name" : "Overview - OG - Members",
    "index_id" : "c4m_search_users",
    "suggester_id" : "",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : { "result count" : true, "fields" : [] },
    "rdf_mapping" : []
  }');
  return $items;
}