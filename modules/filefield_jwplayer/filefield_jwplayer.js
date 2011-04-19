/**
 * @file
 * Javascript for adding JWPlayer to the page.
 */
Drupal.behaviors.cloudfrontvideoJWPlayer = function(context) {
  var config = Drupal.settings.filefield_jwplayer;

  for (var field in config) {
    if ($('#' + field).length > 0) {
      $player = jwplayer(field).setup(config[field]);
      // Is error logging enabled?
      if (Drupal.settings.filefield_jwplayer.error_log && Drupal.settings.ajaxlog.key && Drupal.settings.ajaxlog.token) {
        $player.onError(Drupal.filefield_jwplayer.JWPlayerLog);
      }
    }
  }
}

Drupal.filefield_jwplayer = {};
Drupal.filefield_jwplayer.JWPlayerLog = function(e) {
  Drupal.ajaxlog('filefield_jwplayer', e.message);
}
