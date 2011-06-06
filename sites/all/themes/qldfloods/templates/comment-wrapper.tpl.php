<?php
// $Id: comment-wrapper.tpl.php,v 1.2 2010/09/25 02:05:51 dries Exp $

/**
 * @file
 * Bartik's theme implementation to provide an HTML container for comments.
 *
 * Available variables:
 * - $content: The array of content-related elements for the node. Use
 *   render($content) to print them all, or
 *   print a subset such as render($content['comment_form']).
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default value has the following:
 *   - comment-wrapper: The current template type, i.e., "theming hook".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the comments are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT
 *   - COMMENT_MODE_THREADED
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_comment_wrapper()
 * @see theme_comment_wrapper()
 */
 global $base_url;
 $openbeds = $base_url . '/open-beds/';
 $helptalk = $base_url . '/forum/';
 $privacy = $base_url . '/privacy-policy';
?>
<div id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($content['comments'] && $node->type != 'forum'): ?>
    <?php print render($title_prefix); ?>
    <h2 class="title"><?php print t('Comments'); ?></h2>
    <?php print render($title_suffix); ?>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php if ($content['comment_form']): ?>
    <h2 class="title comment-form"><?php print t('Add new comment'); ?></h2>
  <div class="smallmessage">
  <h3>Please Note</h3>
  <p>Qldfloods.org are not responsible for listings made within comments on this site. We do not use information in comments for our Bed Matching service.</p>
  <p>If you have a bed to offer, please visit our <a href="<?php print $openbeds; ?>">Open Beds</a> feature. If you have other help to offer, please visit our <a href="<?php print $helptalk; ?>">Help Talk</a> section</p>
  <p>Please also review our <a href="<?php print $privacy; ?>">Terms and Conditions</a>.</p>
  </div>

    <?php print render($content['comment_form']); ?>
  <?php endif; ?>
</div>
