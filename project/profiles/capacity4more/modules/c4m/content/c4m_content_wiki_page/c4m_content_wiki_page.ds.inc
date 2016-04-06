<?php
/**
 * @file
 * c4m_content_wiki_page.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_wiki_page_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_wiki_page|activity_stream';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_wiki_page';
  $ds_fieldsetting->view_mode = 'activity_stream';
  $ds_fieldsetting->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'comment_body',
      ),
    ),
    'fields' => array(
      'comment_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_wiki_page|activity_stream'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_wiki_page|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_wiki_page';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_day',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'span',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'field-name-post-date',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'c4m_user_author_thumb_image',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'linked_user',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'field-name-c4m-user-first-and-last-name',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_related_document' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Documents',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-name-c4m-related-document',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['comment|comment_node_wiki_page|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|wiki_page|activity_global';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'wiki_page';
  $ds_fieldsetting->view_mode = 'activity_global';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => 'purl_auto',
        'wrapper' => 'div',
        'class' => 'message-title',
        'ft' => array(),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|wiki_page|activity_global'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|wiki_page|activity_group';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'wiki_page';
  $ds_fieldsetting->view_mode = 'activity_group';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => 'purl_auto',
        'wrapper' => 'div',
        'class' => 'message-title',
        'ft' => array(),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|wiki_page|activity_group'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|wiki_page|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'wiki_page';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'comments' => array(
      'weight' => '12',
      'label' => 'above',
      'format' => 'default',
    ),
    'book_navigation' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '6',
      'label' => 'inline',
      'format' => 'linked_user',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Page created by',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'user-name',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_ds_creation_date' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'j F Y',
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_content_wiki_page_navigation' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_content_wiki_page_collapse' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'c4m_content_wiki_page_add_links' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'wiki-add-links',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_ds_content_actions' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_related_document' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|wiki_page|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_wiki_page_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_wiki_page|activity_stream';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_wiki_page';
  $ds_layout->view_mode = 'activity_stream';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'comment_body',
      ),
    ),
    'fields' => array(
      'comment_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_wiki_page|activity_stream'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_wiki_page|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_wiki_page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_user_picture',
      ),
      'right' => array(
        1 => 'comment_body',
        2 => 'c4m_user_first_and_last_name',
        3 => 'post_date',
        4 => 'links',
        5 => 'c4m_related_document',
      ),
    ),
    'fields' => array(
      'c4m_user_picture' => 'left',
      'comment_body' => 'right',
      'c4m_user_first_and_last_name' => 'right',
      'post_date' => 'right',
      'links' => 'right',
      'c4m_related_document' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_wiki_page|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|wiki_page|activity_global';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'wiki_page';
  $ds_layout->view_mode = 'activity_global';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'c4m_body',
        2 => 'c4m_ds_content_footer_stats',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'c4m_body' => 'ds_content',
      'c4m_ds_content_footer_stats' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|wiki_page|activity_global'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|wiki_page|activity_group';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'wiki_page';
  $ds_layout->view_mode = 'activity_group';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'c4m_body',
        2 => 'c4m_ds_content_footer_stats',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'c4m_body' => 'ds_content',
      'c4m_ds_content_footer_stats' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|wiki_page|activity_group'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|wiki_page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'wiki_page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_4_8_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_content_wiki_page_collapse',
        1 => 'c4m_content_wiki_page_navigation',
        2 => 'c4m_vocab_topic',
        3 => 'c4m_content_wiki_page_add_links',
        4 => 'group_pages',
        5 => 'c4m_vocab_date',
        6 => 'group_details',
        7 => 'group_node_actions',
        8 => 'c4m_vocab_language',
        9 => 'c4m_vocab_geo',
        10 => 'c4m_ds_content_actions',
        19 => 'og_vocabulary',
      ),
      'right' => array(
        11 => 'title',
        12 => 'c4m_user_first_and_last_name',
        13 => 'c4m_ds_creation_date',
        14 => 'c4m_ds_content_footer_stats',
        15 => 'c4m_body',
        16 => 'c4m_related_document',
        17 => 'book_navigation',
        18 => 'comments',
      ),
    ),
    'fields' => array(
      'c4m_content_wiki_page_collapse' => 'left',
      'c4m_content_wiki_page_navigation' => 'left',
      'c4m_vocab_topic' => 'left',
      'c4m_content_wiki_page_add_links' => 'left',
      'group_pages' => 'left',
      'c4m_vocab_date' => 'left',
      'group_details' => 'left',
      'group_node_actions' => 'left',
      'c4m_vocab_language' => 'left',
      'c4m_vocab_geo' => 'left',
      'c4m_ds_content_actions' => 'left',
      'title' => 'right',
      'c4m_user_first_and_last_name' => 'right',
      'c4m_ds_creation_date' => 'right',
      'c4m_ds_content_footer_stats' => 'right',
      'c4m_body' => 'right',
      'c4m_related_document' => 'right',
      'book_navigation' => 'right',
      'comments' => 'right',
      'og_vocabulary' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|wiki_page|full'] = $ds_layout;

  return $export;
}