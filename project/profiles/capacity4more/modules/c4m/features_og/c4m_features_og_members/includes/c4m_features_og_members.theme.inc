<?php

/**
 * @file
 * Custom Display Suite function fields.
 */

/**
 * Render administrator actions on OG members list.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered admin actions.
 */
function theme_c4m_features_og_members_admin_actions(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $group = c4m_og_current_group();
  if (empty($group)) {
    return;
  }

  $entity = $field['entity'];
  $user = user_load($entity->uid);

  $context = og_context();
  if ($context) {
    if (($group_type = c4m_og_get_group_type($context))) {
      if ($group_type == 'event_site' && current_path() == 'members') {
        if ($group->uid == $user->uid) {
          return theme('c4m_administer_member_level', array('membership_level' => 'Owner'));
        }
        if (c4m_user_og_get_role_in_group($user, $group) == 'administrator') {
          return theme('c4m_administer_member_level', array('membership_level' => 'Administrator'));
        }
        if ($role = c4m_og_user_role_load_by_name('attendee', 'event_site')) {
          if (!empty(og_get_user_roles('node', $group->nid, $user->uid)[$role->rid])) {
            return theme('c4m_administer_member_level', array('membership_level' => 'Attendee'));
          }
        } else {
          return theme('c4m_administer_member_level', array('membership_level' => 'Member'));
        }
      }
    }
  }

  $membership_level = NULL;

  if ('membership_level' == $field['formatter']) {
    $membership_level = c4m_user_og_get_role_in_group_human($user, $group);
  }

  if (!c4m_user_og_has_group_permission('manage members')) {
    return $membership_level;
  }

  $links = c4m_features_og_members_get_administer_links_for_user_in_group(
    $user, $group
  );

  // There are no links (group owner).
  if (empty($links)) {
    return theme(
      'c4m_administer_member_level',
      array(
        'membership_level' => $membership_level,
      )
    );
  }

  return theme(
    'c4m_administer_member_links',
    array(
      'membership_level' => $membership_level,
      'links' => $links,
      'user_id' => $user->uid,
    )
  );
}

/**
 * Render the role within the group.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered role name.
 */
function theme_c4m_features_og_members_role(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $group = c4m_og_current_group();
  if (empty($group)) {
    return;
  }

  $entity = $field['entity'];
  $user = user_load($entity->uid);
  return c4m_user_og_get_role_in_group_human($user, $group);
}

/**
 * Render date on which user became group member.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered member since date.
 */
function theme_c4m_features_og_members_since(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $group = c4m_og_current_group();
  if (empty($group)) {
    return;
  }

  $membership = og_get_membership('node', $group->nid, 'user',
    $field['entity']->uid);
  if (!$membership) {
    return;
  }

  $tag['element'] = array(
    '#tag'       => 'span',
    '#attributes' => array(
      'class' => array('member-since'),
    ),
    '#value'     => c4m_helper_date_time_ago($membership->created,
      $field['formatter']),
  );
  return theme_html_tag($tag);
}

/**
 * Render user activity summary within group.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered user activity summary.
 */
function theme_c4m_features_og_members_activity_summary(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $group = c4m_og_current_group();
  if (empty($group)) {
    return;
  }
  $user = $field['entity'];

  $membership = og_get_membership('node', $group->nid, 'user', $user->uid);
  if (!$membership) {
    return;
  }

  // Get published posts of user in this group.
  $count_posts = c4m_og_get_membership_totals($group->nid, $user->uid, 'node');

  // Get published comments of user in this group.
  $count_comments = c4m_og_get_membership_totals($group->nid, $user->uid, 'comment');

  // Format the string to show the number of posts/comments.
  $output = c4m_ds_user_activity_summary_helper($count_posts, $count_comments);
  return $output;
}

/**
 * Render count of posts (nodes) for the given user in the current group.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered posts count.
 */
function theme_c4m_features_og_members_activity_posts(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $group = c4m_og_current_group();
  if (empty($group)) {
    return;
  }
  $user = $field['entity'];

  $membership = og_get_membership('node', $group->nid, 'user', $user->uid);
  if (!$membership) {
    return;
  }

  // Get published posts of user in this group.
  $count =  c4m_og_get_membership_totals($group->nid, $user->uid, 'node');
  return format_plural($count, '1 Post', '@count Posts');
}

/**
 * Render count of comments for the given user in the current group.
 *
 * @param array $field
 *   The field info.
 *
 * @return mixed
 *   The rendered comment count.
 */
function theme_c4m_features_og_members_activity_comments(array $field) {
  if (empty($field['entity'])) {
    return;
  }

  $group = c4m_og_current_group();
  if (empty($group)) {
    return;
  }
  $user = $field['entity'];

  $membership = og_get_membership('node', $group->nid, 'user', $user->uid);
  if (!$membership) {
    return;
  }

  // Get published comments of user in this group.
  $count = c4m_og_get_membership_totals($group->nid, $user->uid, 'comment');
  return format_plural($count, '1 Comment', '@count Comments');
}
