; Make file for videola profile.

core = 6.x
api = 2

; We'll be using Profiler module as well. Installing it as a library.
;
; Commented out for now since we're using a patched version of profiler and
; there is no way to apply a patch via a make file when using libraries[].
; Profiler is included in the videola repository for now.
;libraries[profiler][download][type] = "get"
;libraries[profiler][download][url] = "http://ftp.drupal.org/files/projects/profiler-6.x-2.0-beta2.tar.gz"
;libraries[profiler][destination] = "libraries/profiler"

; Here come the modules
projects[] = install_profile_api

; CCK
projects[] = cck
projects[] = filefield
projects[] = imagefield

; Earl
projects[] = ctools
projects[] = views
;projects[] = panels

; Images
projects[] = imageapi
projects[] = imagecache

; Pretty
projects[] = jquery_ui
projects[] = jquery_update
projects[] = vertical_tabs

; Ubercart
;projects[] = ubercart
projects[] = uc_atctweaks
projects[] = uc_coupon
projects[] = uc_free_order
projects[] = uc_termsofservice
projects[] = uc_recurring

; Views
projects[] = draggableviews
projects[] = semanticviews
projects[] = similarterms
projects[] = views_bulk_operations
projects[] = views_calc
projects[] = views_cycle
;projects[] = views_export

; Other
projects[] = admin_menu
projects[] = adminrole
projects[] = advanced_help
projects[] = amazon_s3
projects[] = better_formats
projects[] = boxes
projects[] = bueditor
projects[] = comment_notify
projects[] = commentmail
projects[] = context
projects[] = date
projects[] = devel
projects[] = diff
projects[] = features
projects[flag] = 2.0-beta5
projects[] = flag_weights
projects[] = globalredirect
projects[] = jcarousel
projects[] = libraries
projects[] = login_destination
projects[] = logintoboggan
projects[] = mass_contact
projects[] = pathauto
projects[] = private_download
projects[] = ed_readmore
projects[] = radioactivity
projects[] = role_watchdog
projects[] = securepages
projects[] = session_limit
projects[] = statistics_advanced
projects[] = stringoverrides
projects[] = strongarm
projects[] = term_node_count
projects[] = token

; Sandbox Projects
projects[chaptermarkers][type] = module
projects[chaptermarkers][download][type] = git
projects[chaptermarkers][download][url] = http://git.drupal.org/sandbox/eojthebrave/1131026.git
projects[ejectorseat][type] = module
projects[ejectorseat][download][type] = git
projects[ejectorseat][download][url] = git://github.com/Lullabot/ejectorseat.git

; Libraries
; Download jquery_ui as a library
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/jquery_ui"

; Themes
projects[] = omega

; Patches
projects[ubercart][patch][] = 'http://drupal.org/files/issues/ubercart_api.patch'
