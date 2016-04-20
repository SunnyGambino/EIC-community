<?php
/**
 * @file
 * Hooks provided by the c4m_user_profile module.
 */

/**
 * Validates an email address.
 *
 * @param string $mail
 *   Email addresss.
 *
 * @return array
 *   An array of error messages keyed by message weight.
 */
function hook_c4m_user_profile_validate_email($mail, $form_state, $form) {
  return array(
    9 => t('Error message'),
  );
}
