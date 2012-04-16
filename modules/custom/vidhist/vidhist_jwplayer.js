/**
 * Register event listener for jwplayer API callbacks.
 * 
 * Reference: http://www.longtailvideo.com/support/jw-player/jw-player-for-flash-v5/12540/javascript-api-reference
 * 
 */
$(document).ready(function() {
  jwplayer.getPlayers()[0].onReady(Drupal.vidhist_jwplayer);
});

Drupal.vidhist_jwplayer = function() {
  console.debug('Initializing');
  var $pl = jwplayer.getPlayers()[0];
  var player = jwplayer.getPlayers()[0];
  
  player.startTimer = player.startTimer || startTimer;
  player.restartTimer = player.restartTimer || restartTimer;
  player.stopTimer = player.stopTimer || stopTimer;
  player.sendData = player.sendData || sendData;
  
  //playheadTimeChanged
  $pl.onTime(function(duration, offset, position){
    if ($pl.data('storeStart')) {
      $pl.data('started', position);
      $pl.data('storeStart', false);
    }
    $pl.data('playHead', position);
  });
  
  //state == playing
  $pl.onPlay(function(oldstate){
    console.debug('onPlay');
    if(!$pl.data('playing')){
      // store the next playHeadTime as the start
      $pl.data('storeStart', true);
      $pl.data('playing', true);
      
      // generate a random token for this viewing session
      $pl.data('token', Math.floor(Math.random()*100000) + 1);
      
      player.startTimer();
      //Drupal.jwplayer.playingPlayers[$pl.attr('id')] = player;
      //player.startTimer();      
    }
  });
  
  //state == paused
  $pl.onPause(function(oldstate){
    console.debug('onPause');
    player.stopTimer();
    // if it was playing & 'started' data is current
    if ($pl.data('playing') && !$pl.data('storeStart')) {
      $pl.data('playing', false);
      // it was playing, now it's paused...
      //delete Drupal.jwplayer.playingPlayers[$pl.attr('id')];
      
      // send the play time to the server
      var playTime = Math.round($pl.data('playHead') - $pl.data('started'));
      // don't send zero, negative numbers, or any play less than 10 seconds to the server
      if (playTime > 10) {
        player.sendData(1);
      }
    }
  
  });
  
  /*
  if (eventName == 'playheadTimeChanged') {
    
  }
  else if (eventName == 'stateChanged' && params.state == 'playing' && !$pl.data('playing')) {
    
  }
  else if ((eventName == 'stateChanged' && params.state == 'paused') || eventName == 'seeked') {

  }*/
  
  function sendData(manual) {  
    console.debug('Sending data');
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
/*
$(window).unload(function() {
  Drupal.jwplayer.playingPlayers.each(function(){
    Drupal.jwplayer.listeners.history(this, 'seeked');
  });
});

*/