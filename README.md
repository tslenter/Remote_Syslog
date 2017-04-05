Example# Remote_Syslog
Scripts / Programs to deploy a Syslog Server with TUI and GUI

README.txt = > Instruction for manual installation
 
colortail => Configuration for colortail

favicon.ico => Favicon for webpage
 
index.php => PHP GUI for Remote Syslog
 
jquery-latest.js => Cross-platform JavaScript library for index.php
 
loaddata.php => Retrieves data from console
 
logrotate => Configuration for logrotate
 
rsview.c => Small c++ program to view syslog messages
- compile: g++ rsview.c -o rsview

rsinstaller.c => Example installer for Ubuntu or Debian based machines
- compile: g++ rsinstaller.c -o rsinstaller

syslog-ng => Syslog-ng configuration (adds listeners UDP / TCP)

syslog-ng-local => Syslog-ng configuration module (redirects all system logging to Remote Syslog)

Check README.txt for more information or visit https://www.remotesyslog.com/

Version 1.1.2 and below have a bug when upgrading to a version higher then 1.1.2a. To resolve this issue run the "rsinstaller -a" twice.
