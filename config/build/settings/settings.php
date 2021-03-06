<?php

/**
 * @file
 * Drupal master config file.
 */

/**
 * Error logging.
 */
$conf['error_level'] = 0;
ini_set('display_errors', FALSE);
ini_set('display_startup_errors', FALSE);

/**
 * PHP settings.
 */
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 157784760);

/**
 * File system config.
 */
$conf['file_public_path'] = 'sites/default/files';
$conf['file_private_path'] = 'sites/default/files/private';
$conf['file_default_scheme'] = 'public';

/**
 * Cache settings.
 */
$conf['cache'] = FALSE;
$conf['block_cache'] = FALSE;
$conf['page_compression'] = FALSE;
$conf['preprocess_css'] = FALSE;
$conf['preprocess_js'] = FALSE;
$conf['cache_lifetime'] = 5 * 60;
// 10 minutes.
$conf['page_cache_maximum_age'] = 10 * 60;

/**
 * Search settings.
 */
$conf["search_api_attachments_tika_path"] = "/ec/acc/server/fpfis/containers/cap4dev-acceptance-c4dweb-acc01/srv/utils/";
$conf["search_api_attachments_tika_jar"] = "tika-app.jar";

/**
 * Drupal settings.
 */
$update_free_access = FALSE;
$conf['theme_debug'] = FALSE;

/**
 * Other settings.
 */
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

/**
 * Include private settings file.
 *
 * Note that the file "settings.local.php" should not be versioned.
 */
$settings_path = dirname(__FILE__);
$filename = $settings_path . '/settings.local.php';
if (file_exists($filename)) {
  include $filename;
}
