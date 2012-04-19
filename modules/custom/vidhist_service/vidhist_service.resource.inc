<?php
// $Id:
/**
 * @file
 *  A service which saves video history
 */

/**
 * Fetches user flagged content.
 *
 * @param $uid
 *   Interger. UID of user.
 * @param $nid
 *   Interger. NID of video node.
 ** @param $start
 *   Interger. Start location of video in sec.
 ** @param $end
 *   Interger. End time of vide in sec.
 ** @param $duration
 *   Interger. total duration of video in sec.
 * @return
 *   Array. The user flagged content of type videola_video.
 */

function vidhist_service_save($record) {
  $record = _services_arg_value($record, 'vidhist');
	$user = user_load($record['uid']);

  if (user_access('keep video viewing history', $user)) {
    $record['delta'] = 'field_videola_cf_video-0';
    $record['viewtime'] = $record['end'] - $record['start'];
    $record['auto'] = 0;
    $record['token'] = '';
        
    // do some validation on the post data
    if (is_numeric($record['nid']) && is_numeric($record['start']) && is_numeric($record['end']) && $record['viewtime'] > 10 && $user->uid == $record['uid']) {
    
      $record['uid'] = $user->uid;
      $record['timestamp'] = time();
      $record['ip'] = $_SERVER['SERVER_ADDR'];
      $record['latest'] = 1; // this is always the latest
      
      // check to see if there's an existing (autosaved) record with this token
      $existing = db_result(db_query("SELECT nid FROM {vidhist} WHERE token='%s' AND nid=%d AND delta='%s' AND uid=%d", $record['token'], $record['nid'], $record['delta'], $record['uid']));

      // this probably isn't the right way to do this, but we're about to save the new info
      // so we remove 'latest' from all instances of this nid/delta/user in the vidhist table
      db_query("UPDATE {vidhist} SET latest=0 WHERE nid=%d AND delta='%s' AND uid=%d", $record['nid'], $record['delta'], $record['uid']);
      
      if (!$record['auto']) {
        // @todo: if start time of this chunk is same as end time of previous, join chunks
        
        // Final save. Save and remove tokens from the db. 
        if (!$existing) {
          // this is a new (non auto) save, video was probably played for less than 1 min
          db_query("INSERT INTO {vidhist} (nid, delta, start, end, duration, viewtime, auto, token, uid, timestamp, ip, latest) VALUES (%d, '%s', %d, %d, %d, %d, %d, %d, %d, %d, '%s', %d)", $record['nid'], $record['delta'], $record['start'], $record['end'], $record['duration'], $record['viewtime'], 0, 0, $record['uid'], $record['timestamp'], $record['ip'], $record['latest']);
        }
        else {
          // video has been paused or shuttled - this is the final save of this chunk
          db_query("UPDATE {vidhist} SET start=%d, end=%d, duration=%d, viewtime=%d, auto=0, token=0, timestamp=%d, ip='%s', latest=%d WHERE nid=%d AND uid=%d AND delta='%s' AND token=%d", $record['start'], $record['end'], $record['duration'], $record['viewtime'], $record['timestamp'], $record['ip'], $record['latest'], $record['nid'], $record['uid'], $record['delta'], $record['token']);
        }
      }
      else {
        // This is an autosave (video is still playing).
        // If video is existing, we update. Otherwise it's a new save.
        $update = $existing ? array('token', 'nid', 'delta', 'uid') : array();
        drupal_write_record('vidhist', $record, $update);
      }
      return 1;
    } else {
      return 0;
    }
  }
  else {
    return 0;
  }
}

/**
 * Check the access permission to a given user.
 * @TODO add better access handlers
 */
function vidhist_service_get_access() {
  return TRUE;
}
