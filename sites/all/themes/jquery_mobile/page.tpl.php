<?php
// $Id$
/**
 * @file
 * Themeing file for pages 
*/
?>
<style type="text/css">
  /* temporary css hacks, will go in external file */
  #skip-link{ display: none; }
  body { background: #E6E6E6; }
</style>
<meta name="apple-mobile-web-app-capable" content="yes" />
<div data-role="page" data-theme="b" <?php if (!$is_front) { ?>id="jqm-home"<?php } if ($user->uid == 1) { ?> style="margin-top:25px;"<?php } ?>>

	<div data-role="header">
		<h1><?php if ($is_front) { print $site_name; } else { print $title; } ?></h1>
	</div><!-- /header -->
	
	<div data-role="content">
		<?php if ($is_front) { ?>
		<center><h1 id="jqm-logo">QLD Floods</h1></center>
		<?php } ?>
		
        <?php print render($page['header']); ?>
        
        <?php print render($tabs); ?>
        
        <?php print render($tabs2); ?>
		
		<?php print render($page['content']); ?>

		<?php
          if (isset($main_menu)) { 
        ?>
          <ul data-role="listview" data-inset="true" data-theme="c" data-dividertheme="b">
            <li data-role="list-divider">Main Menu</li>
          <?php
            foreach($main_menu as $link_name => $link) { 
              $pos = strpos($link['href'], 'http://');

              if ($pos === 0) {
                $href = null;
              } else {
                $href = $base_path;
              }
              
              $link_title = $link['attributes']['title'] ? $link['attributes']['title'] : $link['title'];
              print "<li data-role=\"list-divider\"><a href='{$href}{$link['href']}'>{$link_title}</a></li>";
            }
		  ?>
		  </ul>
		<?php
		  } // end $main_menu
		?>
		
		<?php
          if (isset($secondary_menu)) {
        ?>
          <ul data-role="listview" data-inset="true" data-theme="c" data-dividertheme="b">
          <?php
            foreach($secondary_menu as $link_name => $link) {
              $link_title = $link['attributes']['title'] ? $link['attributes']['title'] : $link['title'];
              print "<li data-role=\"list-divider\"><a href='{$base_path}{$link['href']}'>{$link_title}</a></li>";
            }
		  ?>
		  </ul>
		<?php
		  } // end $secondary_menu
		?>
		
		<?php print render($page['left']); ?>
		
		<?php print render($page['right']); ?>

	</div>

	<div id="footer" style="text-align:center; padding: 20px;">
      <?php print render($page['footer']); ?>
	</div>

</div>
