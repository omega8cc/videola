This module provides a simple and light-weight field formatter for all filefields. When applied to filefields containing .flv or .mp4 video file it will use the JWPlayer flash video player to embed the video directly onto the page.

-------------------------------------------------------------------------------
Requirements:
-------------------------------------------------------------------------------

This module requires the jwplayer.js, and player.swf files from the JWPLayer project. Available from http://www.longtailvideo.com/players/

Download the files and unzip them then move/rename the resulting directory to sites/all/modules/filefield_jwplayer/jwplayer/.


-------------------------------------------------------------------------------
Usage:
-------------------------------------------------------------------------------

Once enabled you will be able to apply the new formatter to any filefield by editing the display settings for the associated content type.

-------------------------------------------------------------------------------
For Developers/Themers:
-------------------------------------------------------------------------------

The module exposes a single hook for developers. hook_filefield_jwplayer_config_alter(&$config) which receives an associative array that will eventually be used for configuring and embedding the jwplayer. For more information about possible values for this $config array see the jwplayer documentation, specifically information related to the JW Embedder. http://www.longtailvideo.com/support/jw-player/jw-player-for-flash-v5

Example:

function mymodule_filefield_jwplayer_config_alter(&$config) {
  // Add the quality monitor 2 plugin.
  $config['plugins'] = 'qualitymonitor-2';
  // Add a poster image to use when the player is embedded on the page but
  // before playback has started.
  $config['image'] = 'http://example.com/image.png';
}

Themers can also modify the $config options by overriding theme_filefield_jwplayer_formatter_jwplayer() and adding their own changes.

-------------------------------------------------------------------------------
Credits:
-------------------------------------------------------------------------------
Initial development by Lullabot: joe.shindelar@lullabot.com