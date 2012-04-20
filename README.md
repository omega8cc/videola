Videola
=======
![videola](http://videola.tv/images/videola-logo.png)

Built on [Drupal](http://drupal.org), Videola is a highly flexible, easily expandable, feature-rich open source solution for organizing and managing video content, users, and ecommerce. Create your own Netflix On-Demand style (subscription), Hulu style (ad supported), or Blockbuster / Amazon style (rental) streaming video websites with your own video content. Want to see Videola in action? Check-out [Drupalize.me](http://drupalize.me) to get an idea for what you can do with Videola!

Videola is a base installation profile for creating a video portal website
using Drupal. This package consists of two drush make files which download all dependencies of the project. The install profile uses [Profiler](http://drupal.org/project/profiler) to provide initial configuration settings and some default sample content. The easiest way to get started, assuming you have relatively recent versions of drush and drush make and git installed on your machine is:

`drush make https://raw.github.com/Videola/videola/master/videola_starter.make videola`

This initial alpha release of Videola currently uses local file storage for videos. While we don't recommend this as a long term solution, the videola_video feature module is designed to be swappable to allow you to support any video hosting solution. A feature module which will support Ooyala hosted videos is forthcoming.

Community contributions (including bug reports) should utilize the [github issue queue](http://github.com/Videola/videola/issues). Additional documentation can be found in [http://github.com/Videola/videola/blob/master/INSTALL.txt](INSTALL.txt).

NOTE: This is an initial alpha release targeted at developers; while we'll try our best, we can't guarantee an upgrade path for future versions as we move towards a 1.0 release. Caveat emptor.
