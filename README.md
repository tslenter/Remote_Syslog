A newer version is available it will be released around the end of februari 2020. The new software is announced @ https://www.remotesyslog.com/. The download link after release: https://github.com/tslenter/RSX-RSC.git.

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

Old webpage instruction:

```HTML
<h1>GETTING STARTED</h1>
Remote Syslog is a free application what can be used to view syslog messages. It uses 3 small c++ programs for installation and CLI log control. Recently we added a web based GUI, this gives you a easy way of viewing and extracting syslog messages. The buildin installer installs syslog-ng as syslog deamon and combines this with colortail and apache2 to enhance the display output.

Remote Syslog is currently tested for the following vendors: Cisco, HP, Ubiquiti and F5. This test concluded a network with 400 devices with some devices in debug mode.

## 1. Remote Syslog  functionality
– Recieve syslog information on port 514 UDP and TCP
– Upgrade over internet installation via rsinstaller
– Easy reconfiguration via rsinstaller
– Easy to use CLI
– Easy to use GUI
– View live syslog messages
– Allows you to clear the live archive
– Send a test message to your syslog server
– Editable configuration files
– View per host logging with the archive button
– View live logging with the archive button
– Allows you to download the archived/live syslog
– Saves syslog for 1 year
– Archives total logging every week
– Open files quickly (Plain text files)
– Support for 32-bit, 64-bit and arm
– O/S support Debian 8.x /9.x, and Ubuntu 16.04 LTS / 18.x LTS
– Raspberry Pi supported (recommended 3B)
– Raspberry Pi O/S support Stretch and Jessie
– Module to activate local logging in Remote Syslog

## 2. Installation
###2.1 Automatic installation

To start follow the instructions below:

Check requirements
- Only for Ubuntu 18.x
  - apt-add-repository multiverse
Download Remote Syslog 64-bit:
 - wget https://sourceforge.net/projects/remote-syslog/files/remote-syslog-latest-AMD64.tar
Download Remote Syslog 32-BIT:
 - wget https://sourceforge.net/projects/remote-syslog/files/remote-syslog-latest-x86.tar
Download Remote Syslog ARM:
 - wget https://sourceforge.net/projects/remote-syslog/files/remote-syslog-latest-arm.tar
Extract archive 64-BIT:
 - tar -xvf remote-syslog-latest-AMD64.tar
Extract archive 32-BIT:
 - tar -xvf remote-syslog-latest-x86.tar
Extract archive ARM:
 - tar -xvf remote-syslog-latest-arm.tar
Go to the following directory
 - cd syslog-latest
Make the installer executable
 - chmod +x rsinstaller
Run the installer as root
 - ./rsinstaller -f
```
