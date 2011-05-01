/**
 * Register event listener for jwplayer API callbacks.
 * 
 * It needs to be initialized on ready since Drupal.behaviors is too early.
 */

$(document).ready(function() {
  jwplayer().onReady(Drupal.vidhist_jwplayer(jwplayer()));
});

Drupal.vidhist_jwplayer = function(player) {

  Drupal.vidHist.setPlayer(player);
  
  player.onTime(function(params){
    Drupal.vidHist.event.playheadTimeChanged(params.position, params.position);
  });
  
  player.onPlay(function(oldstate){
    Drupal.vidHist.event.playing();
  });
  
  player.onPause(function(oldstate){
    Drupal.vidHist.event.stoped();
  });
  
  player.onComplete(function(){
    Drupal.vidHist.event.stoped();
  });
};
