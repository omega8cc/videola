Drupal.vidHist = Drupal.vidHist || {};
Drupal.vidHist.event = Drupal.vidHist.event || {};
Drupal.vidHist.$pl = Drupal.vidHist.$pl || null;
Drupal.vidHist.player = Drupal.vidHist.player || null;
Drupal.vidHist.playingPlayers = Drupal.vidHist.playingPlayers || {};

/**
 *  Initializes the different player objects.
 */
Drupal.vidHist.setPlayer = function(player) {
  Drupal.vidHist.$pl = $(player);
  Drupal.vidHist.player = player;

  Drupal.vidHist.player.startTimer = Drupal.vidHist.player.startTimer || Drupal.vidHist.startTimer;
  Drupal.vidHist.player.restartTimer = Drupal.vidHist.player.restartTimer || Drupal.vidHist.restartTimer;
  Drupal.vidHist.player.stopTimer = Drupal.vidHist.player.stopTimer || Drupal.vidHist.stopTimer;
  Drupal.vidHist.player.sendData = Drupal.vidHist.player.sendData || Drupal.vidHist.sendData;
}

/**
 * Sets the duration of the video being played.
 */
Drupal.vidHist.setDuration = function(duration) {
  Drupal.vidHist.$pl.duration = duration;
}

/**
 * Sends playing information back to the server, usually when the player is 
 * paused / stopped or the windows is closed. 
 */
Drupal.vidHist.sendData = function(manual) {
  var auto = manual ? 0 : 1;
  $.post(Drupal.settings.basePath + '?q=_vidhist', {
    start : Math.round(Drupal.vidHist.$pl.data('started')),
    end : Math.round(Drupal.vidHist.$pl.data('playHead')),
    duration: Math.round(Drupal.vidHist.$pl.data('duration')),
    nid : Drupal.settings.vidHist.nid,
    delta : Drupal.vidHist.player.id,
    auto : auto,
    token : Drupal.vidHist.$pl.data('token'),
    uid: Drupal.settings.vidHist.uid
  });
}

/**
 * Fires a timer that will be executed every defined interval and will
 * send playing information back to the server.
 */
Drupal.vidHist.startTimer = function() {
  var obj = this;
  this.histTimer = setInterval(function() {
    obj.sendData();
  }, Drupal.settings.vidHist.interval);
}

Drupal.vidHist.stopTimer = function() {
  // clearInterval(intervalId);
  if (this.histTimer) {
    clearInterval(this.histTimer);
  }
}

Drupal.vidHist.restartTimer = function() {
  this.stopTimer();
  this.startTimer();
}

/**
 * This function should be called everytime the player cursor position changes.
 */
Drupal.vidHist.event.playheadTimeChanged = function(started, playHead, duration) {
  if (Drupal.vidHist.$pl.data('storeStart')) {
    Drupal.vidHist.$pl.data('started', started);
    Drupal.vidHist.$pl.data('storeStart', false);
  }
  // Only process the duration if we don't have it already.
  if (!Drupal.vidHist.$pl.data('duration')) {
    Drupal.vidHist.$pl.data('duration',duration);
    console.log(duration);
  }
  Drupal.vidHist.$pl.data('playHead', playHead);
}

/**
 * The reproduction has started.
 */
Drupal.vidHist.event.playing = function() {
  if (!Drupal.vidHist.$pl.data('playing')) {
    // store the next playHeadTime as the start
    Drupal.vidHist.$pl.data('storeStart', true);
    Drupal.vidHist.$pl.data('playing', true);

    // generate a random token for this viewing session
    Drupal.vidHist.$pl.data('token', Math.floor(Math.random() * 100000) + 1);

    Drupal.vidHist.player.startTimer();
    Drupal.vidHist.playingPlayers[Drupal.vidHist.$pl.attr('id')] = Drupal.vidHist.player;
  }
}

/**
 * The reproduction has been paused or stopped.
 */
Drupal.vidHist.event.stoped = function(player) {
  player = player || Drupal.vidHist.player;
  player.stopTimer();
  // if it was playing & 'started' data is current
  if (Drupal.vidHist.$pl.data('playing')
      && !Drupal.vidHist.$pl.data('storeStart')) {
    Drupal.vidHist.$pl.data('playing', false);
    // it was playing, now it's paused...
    delete Drupal.vidHist.playingPlayers[Drupal.vidHist.$pl.attr('id')];

    // send the play time to the server
    var playTime = Math.round(Drupal.vidHist.$pl.data('playHead')
        - Drupal.vidHist.$pl.data('started'));
    // don't send zero, negative numbers, or any play less than 10 seconds to
    // the server
    if (playTime > 10) {
      player.sendData(1);
    }
  }
}

/**
 * Bind to window unload in order to send ajax request for playingPlayers just
 * before user exits page - Not sure if this actually works
 */
$(window).unload(function() {
  if(Drupal.vidHist.playingPlayers !== undefined){
    Drupal.vidHist.playingPlayers.each(function() {
      Drupal.vidHist.event.stoped(this);
    });
  }
});