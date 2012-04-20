TABLE OF CONTENTS
-----------------
- What is Videola
- How to Download Via Drush
- How to Download Manually
- How to Install
- Videola Core Feature
- Videola Video Feature
- Videola Browser Feature
- Videola Dashboard Feature
- Videola Queue Feature
- Videola UberCart Feature
- Other Videola Functionality
- Developed By
- Support/Feature Requests
- Enjoy


WHAT IS VIDEOLA
---------------
[Videola][1] is an enterprise-level video management system and video delivery
platform. It allows you to create paid-access or free-access video websites
which can serve video to the desktop, mobile, or television-based devices.
Create your own Netflix On-Demand style (subscription), Hulu style
(ad supported), or Blockbuster / Amazon style (rental) streaming video websites
with your own video content.

Built on [Drupal][2], Videola is a highly flexible, easily expandable,
feature-rich open source solution for organizing and managing video content,
users, and ecommerce. Want to see Videola in action? Check-out [Drupalize.me][3]
to get ideas for what you can do with Videola!

Videola is a base installation profile for creating your video portal website
using Drupal. This package consists of a .make file which can download all
dependencies of the profile using Drush Make and an installation profile.

Note that Videola is designed to be a new website and not a feature added to an
existing website. Future development may include that option, but in the
meantime, you can subdomain your video section.


HOW TO DOWNLOAD VIA DRUSH (recommended)
---------------------------------------
If you have [Drush][4] & [Drush Make][5] installed on your system, you can run
our script to download the latest version of Drupal, contributed modules and
custom modules.

- Where is the Drush Make file?
  - We keep an updated version of the make file on Git Hub in our project
    section. https://github.com/Videola/videola
  - You can also download the most recent stable version on [Videola][1]

- Where do I put the file?
  - Put the file in the folder you want to be your Drupal root.

- What command do I run?
  - `drush make videola.make path_to_my_drupal_root_folder`
OR
  - cd into your drupal root directory and run: `drush make videola.make`
  - When asked if you want to make new site in your current directory, answer
    yes.
  - NOTE: If you want to download Pressflow Drupal core instead of normal
    Drupal core, in the make file, you can uncomment the three lines with
    "`projects[pressflow]`". If you do use pressflow, there is a current
    incompatibility with an un-patched boxes module. You can read about the
    issue (and find a patch to fix it) [here][6].
  - NOTE: If you don't want to download Drupal core using our Drush Make file,
    but only want the contributed and custom modules, run this instead:
    `drush make --no-core --contrib-destination=. videola.make`


HOW TO DOWNLOAD MANUALLY (not recommend)
----------------------------------------
Download [Drupal][2] or [PressFlow Drupal][7] following [standard procedures][8].

Download the contributed modules/libraries/themes found in the videola.make
file following the [standard proceedures][8].


HOW TO INSTALL
--------------
If you are new to Drupal and require some guidance getting started, may we be
so humble as to recommend our very own Videola-based Drupal video training
website: [Drupalize.Me][3].

For detailed information, please see the newly downloaded INSTALL.txt in the
website root.  The basic steps are outlined below.

- Create a database and remember your database name, database user and password.
- Copy my_drupal_root/sites/default/default.settings.php and name it settings.php
  - Update the following line with your database information:
  - $db_url = 'mysql://username:password@localhost/databasename';
- Go to http://mywebsite.com/install.php and select Videola Base Profile.
- Follow the instructions on the screen
  - Enter prices for each subscription type
  - Click the link for "Visit your new site."

- Complete Site Configurations
  - The administrative user (user/1)
    - Using the "wrench" admin menu in the upper left corner, select Administer
      > User Management > Users
    - Click "edit" for the "admin" user and update the email address and
      password
  - Site Elements
    - Using the "wrench" admin menu in the upper left corner, select Administer
      > Site Configuration > Site Information (admin/settings/site-information)
    - Set the sitename and site email address
  - Placeholder Content
    - We have created some placeholder content for you so you can see the
      Features in action.


VIDEOLA CORE FEATURE
--------------------
Ejector Seat & Session Limit are used to ensure that each user on the site is
only allowed to have one active session at any given time and automatically logs
the user out if a new session is started from a different browser/location.


VIDEOLA VIDEO FEATURE
---------------------
Video providers are primarily built as features that provide a CCK content type
and additional configuration for any other modules that are required in order
for integration with the video hosting provider to work.

### CONTENT TYPE DEFINITION: Video

- Machine name = 'video'
  - All video provider plugins MUST implement a CCK content type with a machine
readable name of 'video'.
- `node.title` = "Title"
- `node.body` = "Description" - The primary description field for the video.
- `node.field_videola_video` = "Video" Field that provides the full length video
- `node.field_videola_video_preview` = "Preview Video" - Field that provides an
optional preview video.
- `node.field_videola_video_still` = "Video Still" - Field that provides a still
frame from the video.
- `node.field_videola_free` = "Free Video" = int / single on/off checkbox, if
checked the video should be considered free and available for consumption by
anon. users.
- `node.field_videola_video_length` = "Video Length" - Field that contains the
video length in seconds.
- `node.field_videola_chapters` = "Chapters" - Field that allows the
administrator to enter in chapter information for the video which can be used to
jump to different segments of the video. Should allow for entry of a Chapter
title and an associated time. The time should be represented as an integer, the
number seconds in to the video to jump to.

### TAXONOMY

We have created the Categories Vocabulary (required) and added in some
placeholder terms.

### ADDITIONAL INTEGRATION POINTS

- `hook_videola_video_totals()`, implement this hook, it should provide a total
length of all the videos on the site from this provider that are published in
seconds.  Used by the videola module which implements a filter so that an admin
can input tags into the body of their text that will be dynamically replaced
with the total hh:mm:ss of all videos currently on the site.
- `hook_filefield_jwplayer_config_alter()`, if you're using jwplayer to play
videos you'll probably want to implement this hook. One obvious use case is to
add a $config['image'] variable so that the imagefield above is used as the
poster image for jwplayer when a user visits the page but has not started the
video yet.


VIDEOLA BROWSER FEATURE
---------------------------
This feature provides several Views and block placements via Context so that the
user can easily browse videos by category.


VIDEOLA DASHBOARD FEATURE
-------------------------
This feature provides content for the front page for both anonymous and
subscribed users.


VIDEOLA QUEUE FEATURE
---------------------
This feature uses Flags so that each user can keep a list of videos that they
want to watch and displays a block via Context.


VIDEOLA UBERCART FEATURE
------------------------
Videola uses Ubercart and several related contributed modules. For documentation
on Ubercart, go to http://drupal.org/project/ubercart for links to their issue
queue and forums.

There are many settings in Ubercart, all of which can be found using the
administrative menu by clicking the "wrench" in the top left corner of the site.
Administration > Store Configuration

The user signs up for the subscription at /signup. This membership node can be
configured at /node/1/edit.

- Description text area.
- Product Information vertical tab: Configure the "Sell Price".

The Payment option select list can be configured at /admin/store/attributes.
Click "options" to specify monthly/bi-annual/yearly prices.

- http://www.ubercart.org/docs/user/8390/attribute_settings

Configure how you accept money: /admin/store/settings/payment

- http://www.ubercart.org/docs/user/8457/payment_settings

Configure the recurring payment settings: /admin/store/settings/payment

Configure conditional actions to control things like emails sent to customers:
/admin/store/ca

- http://www.ubercart.org/docs/user/7657/configuring_conditional_actions


OTHER VIDEOLA FUNCTIONALITY
---------------------------
The VidHist module provides a tab on the video node about the viewing history.


DEVELOPED BY
------------
Videola is brought to you by your friends at [Lullabot][9].


SUPPORT/FEATURE REQUESTS
------------------------
Please use the tools within GitHub to share ideas and communicate with each
other about additional development. We will be checking that area too!
Videola is a development platform for you to use in creating your website, but
if you are interested in hiring Lullabot to provide customization, please
contact us at http://www.lullabot.com/contact.

ENJOY!
------
Lullabot loves you.

[1]: http://videola.tv
[2]: http://drupal.org
[3]: http://drupalize.me
[4]: http://drupal.org/project/drush
[5]: http://drupal.org/project/drush_make
[6]: http://drupal.org/node/887260
[7]: http://pressflow.org
[8]: http://drupal.org/documentation/install/modules-themes/modules-5-6
[9]: http://lullabot.com