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
; Contrib Modules
projects[admin][subdir] = "contrib"

projects[adminrole][subdir] = "contrib"
projects[adminrole][version] = "1.3"

projects[advanced_help][subdir] = "contrib"
projects[advanced_help][version] = "1.2"

projects[autoload][subdir] = "contrib"
projects[autoload][version] = "2.1"

projects[better_formats][subdir] = "contrib"
projects[better_formats][version] = "1.2"

projects[boxes][subdir] = "contrib"
projects[boxes][version] = "1.0"

projects[bueditor][subdir] = "contrib"
projects[bueditor][version] = "2.2"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.8"

projects[ubercart][subdir] = "contrib"
projects[ubercart][version] = "2.4"

projects[comment_notify][subdir] = "contrib"
projects[comment_notify][version] = "1.5"

projects[commentmail][subdir] = "contrib"
projects[commentmail][version] = "1.0-beta1"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.9"

projects[context][subdir] = "contrib"
projects[context][version] = "3.0"

projects[date][subdir] = "contrib"
projects[date][version] = "2.7"

projects[devel][subdir] = "contrib"
projects[devel][version] = "1.26"

projects[diff][subdir] = "contrib"
projects[diff][version] = "2.1"

projects[draggableviews][subdir] = "contrib"
projects[draggableviews][version] = "3.5"

projects[ed_readmore][subdir] = "contrib"
projects[ed_readmore][version] = "5.0-rc7"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0"

projects[filefield][subdir] = "contrib"
projects[filefield][version] = "3.10"

projects[flag][subdir] = "contrib"
projects[flag][version] = "2.0-beta5"

projects[flag_weights][subdir] = "contrib"
projects[flag_weights][version] = "1.1"

projects[globalredirect][subdir] = "contrib"
projects[globalredirect][version] = "1.3-alpha1"

projects[imageapi][subdir] = "contrib"
projects[imageapi][version] = "1.9"

projects[imagecache][subdir] = "contrib"
projects[imagecache][version] = "2.0-beta10"

projects[imagefield][subdir] = "contrib"
projects[imagefield][version] = "3.10"

projects[install_profile_api][subdir] = "contrib"
projects[install_profile_api][version] = "2.1"

projects[jcarousel][subdir] = "contrib"
projects[jcarousel][version] = "2.4"

projects[jquery_ui][subdir] = "contrib"
projects[jquery_ui][version] = "1.4"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "2.0-alpha1"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "1.0"

projects[login_destination][subdir] = "contrib"
projects[login_destination][version] = "2.12"

projects[logintoboggan][subdir] = "contrib"
projects[logintoboggan][version] = "1.9"

projects[mass_contact][subdir] = "contrib"
projects[mass_contact][version] = "1.1"

projects[oauth][subdir] = "contrib"
projects[oauth][version] = "3.0-beta4"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.5"

projects[private_download][subdir] = "contrib"
projects[private_download][version] = "1.3"

projects[radioactivity][subdir] = "contrib"
projects[radioactivity][version] = "1.3"

projects[role_watchdog][subdir] = "contrib"
projects[role_watchdog][version] = "1.2"

projects[securepages][subdir] = "contrib"
projects[securepages][version] = "1.9"

projects[semanticviews][subdir] = "contrib"
projects[semanticviews][version] = "1.1"

projects[services][subdir] = "contrib"
projects[services][version] = "3.x-dev"

projects[services_views][subdir] = "contrib"
projects[services_views][version] = "1.x-dev"

projects[session_limit][subdir] = "contrib"
projects[session_limit][version] = "2.1"

projects[similarterms][subdir] = "contrib"
projects[similarterms][version] = "2.2"

projects[stringoverrides][subdir] = "contrib"
projects[stringoverrides][version] = "1.8"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[term_node_count][subdir] = "contrib"
projects[term_node_count][version] = "1.3"

projects[token][subdir] = "contrib"
projects[token][version] = "1.15"

projects[uc_atctweaks][subdir] = "contrib"
projects[uc_atctweaks][version] = "1.0-rc1"

projects[uc_coupon][subdir] = "contrib"
projects[uc_coupon][version] = "1.5"

projects[uc_free_order][subdir] = "contrib"
projects[uc_free_order][version] = "1.0-beta4"

projects[uc_recurring][subdir] = "contrib"
projects[uc_recurring][version] = "2.0-alpha6"

projects[uc_termsofservice][subdir] = "contrib"
projects[uc_termsofservice][version] = "1.2"

projects[vertical_tabs][subdir] = "contrib"
projects[vertical_tabs][version] = "1.0-rc2"

projects[views][subdir] = "contrib"
projects[views][version] = "2.16"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "1.12"

projects[views_calc][subdir] = "contrib"
projects[views_calc][version] = "1.3"

projects[views_cycle][subdir] = "contrib"
projects[views_cycle][version] = "1.0"

; Themes
projects[omega][subdir] = "contrib"
projects[omega][version] = "1.0"

; Sandbox Projects
projects[chaptermarkers][type] = module
projects[chaptermarkers][subdir] = "contrib"
projects[chaptermarkers][download][type] = git
projects[chaptermarkers][download][url] = http://git.drupal.org/sandbox/eojthebrave/1131026.git

projects[ejectorseat][type] = module
projects[ejectorseat][subdir] = "contrib"
projects[ejectorseat][download][type] = git
projects[ejectorseat][download][branch] = 6.x-1.x
projects[ejectorseat][download][url] = git://github.com/Lullabot/ejectorseat.git

; Libraries
; Download jquery_ui as a library
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"

; Download jquery.cycle as a library
libraries[jquery.cycle][download][type] = "get"
libraries[jquery.cycle][download][url]  = "https://raw.github.com/malsup/cycle/master/jquery.cycle.all.js"
libraries[jquery.cycle][directory_name] = "jquery.cycle"
libraries[jquery.cycle][download][filename] = "jquery.cycle.all.min.js"
libraries[jquery.cycle][destination]    = "libraries"

; Patches
projects[ubercart][patch][] = 'http://drupal.org/files/issues/ubercart_api.patch'
projects[vertical_tabs][patch][] = 'http://drupal.org/files/issues/533720-vertical_tabs-p1-D6.patch'
