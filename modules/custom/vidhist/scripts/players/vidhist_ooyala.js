/**
 * @file
 * Vidhist integration for Ooyala video player.
 *
 * @todo:
 * - Test that this still works, lots of changes have been made to the module
 *   since the last time ooyala was used.
 * - Send video duration to backend.
 */

// Initialize Drupal.ooyala if it hasn't been yet since it is possible for this
// module's javascript to be loaded before ooyala_player.js
Drupal.ooyala = Drupal.ooyala || {'listeners': {}};

/**
 * Register event listener for ooyala API callbacks.
 */
Drupal.ooyala.listeners.history = function(player, eventName, params) {
  if (eventName == 'apiReady') {
    Drupal.vidHist.setPlayer(player);
  }
  else if (eventName == 'playheadTimeChanged') {
    Drupal.vidHist.event.playheadTimeChanged(params.playheadTime, params.playheadTime);
  }
  else if (eventName == 'stateChanged' && params.state == 'playing') {
    Drupal.vidHist.event.playing();
  }
  else if ((eventName == 'stateChanged' && params.state == 'paused') || eventName == 'seeked') {
    Drupal.vidHist.event.stoped();
  }
  
};

