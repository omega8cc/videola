; Stub makefile for videola project.
; Get Drupal core and the videola profile which contains a .make file that will
; download all the required projects/libraries.

core = 6.x
api = 2

projects[] = drupal

; If you want to use Pressflow Drupal, uncomment out the following three lines
; projects[pressflow][type] = "core"
; projects[pressflow][download][type] = "file"
; projects[pressflow][download][url] = "http://launchpad.net/pressflow/6.x/6.20.97/+download/pressflow-6.20.97.tar.gz"

; Setup the videola profile from this make file stub.
projects[videola][type] = "profile"
projects[videola][download][type] = git
projects[videola][download][url] = https://github.com/Videola/videola.git
