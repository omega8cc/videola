// Initialize Drupal.ooyala if it hasn't been yet since it is possible for this
// module's javascript to be loaded before ooyala_player.js
Drupal.ooyala = Drupal.ooyala || {'listeners': {}};
Drupal.ooyala.playingPlayers = Drupal.ooyala.playingPlayers || {};


/**
 * Register event listener for ooyala API callbacks.
 */
Drupal.ooyala.listeners.history = function(player, eventName, params) {
  
  var $pl = $(player);
  
  player.startTimer = player.startTimer || startTimer;
  player.restartTimer = player.restartTimer || restartTimer;
  player.stopTimer = player.stopTimer || stopTimer;
  player.sendData = player.sendData || sendData;
  
  if (eventName != 'playheadTimeChanged') {
    //console.log(eventName, params);
  }
    
  if (eventName == 'playheadTimeChanged') {
    if ($pl.data('storeStart')) {
      $pl.data('started', params.playheadTime);
      $pl.data('storeStart', false);
    }
    $pl.data('playHead', params.playheadTime);
  }
  else if (eventName == 'stateChanged' && params.state == 'playing' && !$pl.data('playing')) {
    // store the next playHeadTime as the start
    $pl.data('storeStart', true);
    $pl.data('playing', true);
    
    // generate a random token for this viewing session
    $pl.data('token', Math.floor(Math.random()*100000) + 1);
    
    Drupal.ooyala.playingPlayers[$pl.attr('id')] = player;
    player.startTimer();
    
  }
  else if ((eventName == 'stateChanged' && params.state == 'paused') || eventName == 'seeked') {
    player.stopTimer();
    // if it was playing & 'started' data is current
    if ($pl.data('playing') && !$pl.data('storeStart')) {
      $pl.data('playing', false);
      // it was playing, now it's paused...
      delete Drupal.ooyala.playingPlayers[$pl.attr('id')];
      
      // send the play time to the server
      var playTime = Math.round($pl.data('playHead') - $pl.data('started'));
      // don't send zero, negative numbers, or any play less than 10 seconds to the server
      if (playTime > 10) {
        player.sendData(1);
      }
    }
  }
  
  function sendData(manual) {  
    var auto = manual ? 0 : 1;
    var $p = $(this);
    $.post(Drupal.settings.basePath + '?q=_vidhist',
      {
        start: Math.round($p.data('started')),
        end: Math.round($p.data('playHead')),
        nid: Drupal.settings.vidHist.nid,
        delta: player.id,
        auto: auto,
        token: $p.data('token')
      }
    );
  }
    
  function startTimer() {
    var obj = this;
    this.histTimer = setInterval(function() {obj.sendData();}, Drupal.settings.vidHist.interval);
  }
  
  function stopTimer() {
    //clearInterval(intervalId);
    if (this.histTimer) {
      clearInterval(this.histTimer);
    }
  }
  
  function restartTimer() {
    this.stopTimer();
    this.startTimer();
  }
  
  
};


/**
 * Bind to window unload in order to send ajax request for playingPlayers
 * just before user exits page - Not sure if this actually works
 */

$(window).unload(function() {
  Drupal.ooyala.playingPlayers.each(function(){
    Drupal.ooyala.listeners.history(this, 'seeked');
  });
});

