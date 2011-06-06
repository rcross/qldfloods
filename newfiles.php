<?php
define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT.'/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$Directory = "./sites/default/files/maps";

// $existing_pagenode = node_load(139);
// print_r($existing_pagenode);

// open the Directory
$dhandle = dir($Directory);

// define an array to hold the files
$files = array();

if ($dhandle) {
   // loop through all of the files
   while (false !== ($fname = $dhandle->read())) {
      // if the file is not this file, and does not start with a '.' or '..',
      // then store it for later display
      if (($fname != '.') && ($fname != '..') &&
          ($fname != basename($_SERVER['PHP_SELF']))) {       

$file = $Directory."/".$fname;
// Get the town name out of file name
$fname = substr($fname, 9);
$fname = substr($fname, 0,-19);
$fname = str_ireplace("_", " ", $fname);
$fname = ucwords($fname);
$PlaceName = $fname;

// check if term already in:
$suburb = taxonomy_get_term_by_name($PlaceName);
if (empty($suburb)) {
$suburb = new stdClass();
$suburb->name= $PlaceName;
$suburb->vid = 3;
taxonomy_term_save($suburb);
$suburb = taxonomy_get_term_by_name($PlaceName);
} else {
 continue;
}
$numb = array_keys($suburb);
$suburbTermID = $numb[0];


// Create the node:
$newnode = new stdClass();

// Set the Title
$newnode->title = "Flood Flag Map - ".$PlaceName;
$newnode->body = "";
$newnode->uid = 3; // Nicks user;
$newnode->type = 'article';
$newnode->status = 1;
$newnode->promote = 0;
$newnode->field_tags['und'][0]['tid']= 36;

$newnode->field_suburb['und'][0]['tid'] = $suburbTermID;

// have to add in a suburb first?? 
// Get the file size
$details = stat($file);
$filesize = $details['size'];
$dest = 'public://user_files/';
// Copy the file to the Drupal files directory 
$name = basename($file);

// Build the file object
$file_obj = new stdClass();
$file_obj->filename = $name;
$file_obj->uri = $file;
$file_obj->filemime =  file_get_mimetype($name);
$file_obj->filesize = $filesize;
$file_obj->filesource = $name;
$file_obj->uid = 3; // Nick
$file_obj->status = FILE_STATUS_PERMANENT;
$file_obj->timestamp = time();
$file_obj->list = 1;
$file_obj->new = true;

// TODO do a file move 
$file_obj = file_copy($file_obj,$dest);
 // Attach the file object to your node
$newnode->field_file['und'][0]['fid'] = $file_obj->fid;
$newnode->field_file['und'][0]['display'] = 1;
node_save($newnode);
$newpath = strtolower($newnode->title);
$newpath = str_replace(" - ", "-", $newpath);
$newpath = str_replace(" ", "-", $newpath);
$path = array();
$path['source']=$newnode->uri['path'];
$path['alias'] = "article/".$newpath;
path_save($path);

 //content_insert($newnode);
 unset($newnode);
 unset($file_obj);

     }
   }
}

