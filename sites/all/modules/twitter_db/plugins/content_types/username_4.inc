<?php
/**
 * @file Twitter DB plugin.
 * @todo
 *   Create 1 plugin file to handle all twitter feeds
 *   instead of one file for each feed.
 */

$name = variable_get('twitter_db_retrieve_name_4', 'User 4 not configured');
$type = ' - '. variable_get('twitter_db_what_to_retrieve_4', 0);
if (!$name) {
  $name = 'User 4 not configured';
  $type = '';
}

$plugin = array(
  'single' => TRUE,
  'title' => t('Twitter DB Pane: '. $name . $type),
  'description' => t('Recent tweets.'),
  'category' => t('Miscellaneous'),
  'defaults' => array(
    'variable' => 1,
  ),
);

function twitter_db_username_4_content_type_render($subtype, $conf, $panel_args, $context) {
  
  $name = variable_get('twitter_db_retrieve_name_4', 0);
  $type = variable_get('twitter_db_what_to_retrieve_4', 0);
  if (!$name || !$type) {
    return;
  }
  
  $return = new stdClass();
  $return->title = '';
  $content = _twitter_db_generate_content($name, $type);
  $return->content = $content;
  return $return;
}