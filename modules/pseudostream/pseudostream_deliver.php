<?php
/**
 * @file
 * Deliver requested portion of a file.
 */

// Boolean representing wether this file is called on it's own or included
// by another script.
$self = FALSE;

if (!isset($file)) {
  $file = $_GET['file'];
  $self = TRUE;
}

