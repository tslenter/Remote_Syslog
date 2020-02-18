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

# GETTING STARTED
Remote Syslog is a free application what can be used to view syslog messages. It uses 3 small c++ programs for installation and CLI log control. Recently we added a web based GUI, this gives you a easy way of viewing and extracting syslog messages. The buildin installer installs syslog-ng as syslog deamon and combines this with colortail and apache2 to enhance the display output.

Remote Syslog is currently tested for the following vendors: Cisco, HP, Ubiquiti and F5. This test concluded a network with 400 devices with some devices in debug mode.

## 1. Remote Syslog  functionality
- Recieve syslog information on port 514 UDP and TCP
- Upgrade over internet installation via rsinstaller
- Easy reconfiguration via rsinstaller
- Easy to use CLI
- Easy to use GUI
- View live syslog messages
- Allows you to clear the live archive
- Send a test message to your syslog server
- Editable configuration files
- View per host logging with the archive button
- View live logging with the archive button
- Allows you to download the archived/live syslog
- Saves syslog for 1 year
- Archives total logging every week
- Open files quickly (Plain text files)
- Support for 32-bit, 64-bit and arm
- O/S support Debian 8.x /9.x, and Ubuntu 16.04 LTS / 18.x LTS
- Raspberry Pi supported (recommended 3B)
- Raspberry Pi O/S support Stretch and Jessie
- Module to activate local logging in Remote Syslog

## 2. Installation
### 2.1 Automatic installation

To start follow the instructions below:

Check requirements:
Only for Ubuntu 18.x
```bash
apt-add-repository multiverse
```
Download Remote Syslog 64-bit:
```bash
wget https://sourceforge.net/projects/remote-syslog/files/remote-syslog-latest-AMD64.tar
```
Download Remote Syslog 32-BIT:
```bash 
wget https://sourceforge.net/projects/remote-syslog/files/remote-syslog-latest-x86.tar
```
Download Remote Syslog ARM:
```bash
wget https://sourceforge.net/projects/remote-syslog/files/remote-syslog-latest-arm.tar
```
Extract archive 64-BIT:
```bash
tar -xvf remote-syslog-latest-AMD64.tar
```
Extract archive 32-BIT:
```bash
tar -xvf remote-syslog-latest-x86.tar
```
Extract archive ARM:
```bash
tar -xvf remote-syslog-latest-arm.tar
```
Go to the following directory
```bash
cd syslog-latest
```
Make the installer executable
```bash
chmod +x rsinstaller
```
Run the installer as root
```bash
./rsinstaller -f
```
### 2.3 Automatic installation video (DEMO)

Watch the following YouTube video for a installation and functionality check:

<a href="http://www.youtube.com/watch?feature=player_embedded&v=jk6wwRvr6GE
" target="_blank"><img src="http://img.youtube.com/vi/jk6wwRvr6GE/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

# REQUIREMENTS
Make sure that you meet the minimum system requirements. Increase the capacity if you experience any performance issues.

## 3. Hardware requirements
### 3.1 Custom build:

- Intel ATOM 1.6Ghz processor or better
- 512MB RAM or higher
- 128GB Storage
- Monitor resolution of 1920×1080
- CPU microarchitectures: X86 (32-Bit), X64 (64-Bit) and ARM (Acorn RISC Machine)

### 3.2 Device support:

- Raspberry Pi
- 3B version recommended
- Tested for Raspbian Jessie Lite and Stretch Lite

## 4. Software requirements
Operating System:
- Ubuntu 16.04 LTS server / 18.04 LTS Server
Note: Activate multiverse repository for 18.x
- Debian 9.x
- Debian 8.x
- Jessie Lite (Raspberry Pi 3B)
- Stretch Lite (Raspberry Pi 3B)

To compile use:
- g++
- make

# USAGE
To start download and extract all files to your server. Make sure that the rsinstaller file is executable. You need to run the installer with root rights. More information: Getting Started.

## 5. Installer
To print the usage do:
```bash
rsinstaller -h or rsinstaller
```

Usage example:
```bash
-h,–help                  Display help
-r,–reconfigure           Reconfigure services
-f,–fullinstall           Start full installation
-a,–autoupgrade           Auto upgrade (requires internet)
-d,–defaultconfig         Restore default configuration
-al,–addlocallog          Add local syslog to Remote Syslog
-rl,–rmlocallog           Remove local syslog to Remote Syslog
-am,–memlimit             Set new memory limit of 512M
-rm,–defaultmemlimit      Set default memory limit of 128M
```
### 5.1 Change the default configuration:

Use the following configuration files to customize Remote Syslog:
```bash
/opt/remotesyslog/colortail => for a new color regex
/opt/remotesyslog/syslog-ng => syslog configuration
/opt/remotesyslog/logrotate => change file rotation
To apply a new configuration, rerun the installer:
rsinstaller -r or rsinstaller –reconfigure
```

### 5.2 Update Remote Syslog:

There is a new installer in version 1.0 or higher (internet is required). You can update the installation with the following command:
```bash
rsinstaller -a or rsinstaller –autoupgrade
```

This update will not erase or update your configuration files. To update your configuration files to the latest version run (Section 5.4):
```bash
rsinstaller -d or rsinstaller –defaultconfig
```
Info: see section 5.1 to use a custom configuration.

### 5.3 Run a new installation on a new machine:

Run the following command to install Remote Syslog:
```bash
rsinstaller -f or rsinstaller –fullinstall
```

After a successfull run, select your supported operating system:
Select your OS:
```bash
1) Debian 8.x or Raspberry Pi 3B (Jessie Lite)
2) Debian 9.x or Ubuntu 16.04 LTS or Raspberry Pi 3B (Stretch Lite)
3) Exit
Enter your option: <option here>
```

### 5.4 Restore the default configuration:

Run the following command to restore the default configuration:
```bash
rsinstaller -d or rsinstaller –defaultconfig
```

### 5.5 Force a full installation:

To force a full installation run the following commands:
```bash
1. rm /usr/bin/rsinstaller
2. rsinstaller -f
```

Make sure you install Remote Syslog to a clean Ubuntu 16.04 LTS or later installation. We tested the installation and usage for this platform.

### 5.6 Search MEM_LIMIT for GUI:

Currently the default MEM_LIMIT of PHP is 128M to search large plain text files. You can extent this limit to 512M. (higher is possible, but not recommended). You can use the following command to activate a higher limit:
```bash
rsinstaller -am or rsinstaller –memlimit
```

To deactivate this function use and restore the default setting:
```bash
rsinstaller -rm or rsinstaller –defaultmemlimit
```

## 6. Remote Syslog CLI

To start use a SSH client (Recommended Putty or buildin linux ssh client)

To print the usage do:
```bash
rsview -h or rsview
```

Usage example:
```bash
-h,–help                               Display help
-s,–search <search string>             Search through logging
-v,–view                               View logging
-l,–live                               View live logging
-ls,–livesearch <search string>        Search through live logging
-t,–testmessage                        Send a test message
-c,–clearlog                           Clear total log archive
```

### 6.1 View a live log:

Remote Syslog allows you to view a live logging with the following command:
```bash
rsview -l or rsview –live
```

This allow you to follow new messages live in a colorfull console. To filter your output use:
```bash
rsview -ls <text to filter> or rsview –livesearch <text to filter>
```

### 6.2 View logging:

Remote Syslog allows you to view a total logging of a week in your console. Run the following command:
```bash
rsview -v or rsview –view
```

This allow you to view messages in a colorfull console. To filter message do:
```bash
rsview -s <text to filter> or rsview –search <text to filter>
```

Use normal linux commands (like “cat, grep, tail”) to search through your logging. Use the following path:
```bash
/var/log/remote_syslog/<per_host>
```

### 6.3 Send a test message or clear old live logging:

To test your server we added added a function to test the server:
```bash
rsview -t or rsview –testmessage
```

To clear all archived total logging run:
```bash
rsview -c or rsview –clearlog
```

### 6.4 Add a optional local logging module:

To add local logging to the Remote Syslog file:
```bash
rsinstaller -al
```

To remove local logging from the Remote Syslog file:
```bash
rsinstaller -rl
```

This module can be used for debugging.

## 7. Remote Syslog GUI
Use a browser to start. (Recommended Firefox)

Default port is 80. We recommend that you secure the apache2 http page. Configure SSL and basic/LDAP authentication. See section 9: Optional configuration.

### 7.1 How to control the GUI:

Button “Syslog archive”:
```
shows all archived files + current logging
```

Button “Send test message”:
```
Sends a test message to the syslog-ng deamon
```

Button “Clear live log archive”:
```
Clears the total archived live log files
```

Button “License”:
```
Display license
```

## 8. Usage demo:

<a href="http://www.youtube.com/watch?feature=player_embedded&v=jWtar2RQyi0
" target="_blank"><img src="http://img.youtube.com/vi/jWtar2RQyi0/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

## 9. Optional configuration:
### 9.1 Integrate Active Directory LDAP authentication for Apache 2:

Activate LDAP module apache:
```bash
a2enmod ldap authnz_ldap
```

Configure /etc/apache2/apache2.conf as following:
```bash
<Directory /var/www/html>
AuthType Basic
AuthName “Remote Syslog Login”
Options Indexes FollowSymLinks
AllowOverride None
AuthBasicProvider ldap
AuthLDAPGroupAttributeIsDN On
AuthLDAPURL “ldap://<myadhost>:389/dc=DC01,dc=local?sAMAccountName?sub?(objectClass=*)
AuthLDAPBindDN “CN=,OU=Accounts,DC=DC01,DC=local”
AuthLDAPBindPassword
AuthLDAPGroupAttribute member
require ldap-group cn=,ou=Groups,dc=DC01,dc=local
</Directory>
```

### 9.2 Basic authentication for Apache 2:

Install apache2-utils:
```bash
apt-get install apache2-utils
```

Create .htpasswd file:
```bash
htpasswd -c /etc/apache2/.htpasswd <myuser>
```

Configure /etc/apache2/apache2.conf as following:
```bash
<Directory /var/www/html>
AuthType Basic
AuthName "Remote Syslog Login"
AuthBasicProvider file
AuthUserFile "/etc/apache2/.htpasswd"
Require user
Options Indexes FollowSymLinks
AllowOverride None
Require valid-user
Order allow,deny
Allow from all
</Directory>
```

### 9.3 Activate SSL in Apache 2:

Generate certificate:
```bash
"mkdir /etc/cert/"
"cd /etc/cert/"
"openssl req -new -x509 -days 3650 -sha1 -newkey rsa:1024 -nodes -keyout server.key -out server.crt"
```

Configure apache:
```bash
"nano /etc/apache2/sites-enabled/000-default.conf"
```

#Configure a virtualhost for SSL:
```bash
<VirtualHost *:443>
ServerAdmin norply@rs001
ServerName rs001
DocumentRoot /var/www/html
ErrorLog ${APACHE_LOG_DIR}/error.log
CustomLog ${APACHE_LOG_DIR}/access.log combined
SSLEngine on
SSLCertificateFile /etc/cert/server.crt
SSLCertificateKeyFile /etc/cert/server.key
</VirtualHost>
```

Load SSL module apache2:
```bash
cp /etc/apache2/mods-available/ssl.load /etc/apache2/mods-enabled/
or:
a2enmod ssl
```

Restart apache2:
```bash
service apache2 restart
```

### 9.4 Secure / apply filters for syslog-ng:

To filter specific messages from all host in the /var/log/remote_syslog/remote_syslog.log run as root:
```bash
nano /opt/remotesyslog/syslog-ng
```

Apply the following configuration:
```bash
……. t { tcp(); };
filter messages { not match(“<message_to_exclude>“) };
destination Y …..
```

Then run as root:
```bash
rsinstaller -r
```

The filter is applied and the syslog service is restarted.

To apply extra security or other filters for syslog-ng visit: https://syslog-ng.org/

# MANUAL CONFIGURATION
The manual installation allows you to configure any distribution with our configuration. In this section we give you a example configuration of a debian based operating system.

## 10. Download
### 1.1 To download Remote Syslog directly use:
```bash
wget https://sourceforge.net/projects/remote-syslog/files/remote-syslog-manual-source.tar
```

## 11. Installation packages
### 11.1 Update installer cache:
```bash
apt update
```

### 11.2 Remove conflicting packages:
```bash
apt -y purge rsyslog
```

### 11.3 Install new packages:
```bash
apt install syslog-ng colortail wget logrotate grep apache2 apache2-bin apache2-data apache2-utils libapache2-mod-php5 libapr1 libaprutil1 libaprutil1-dbd-sqlite3 libaprutil1-ldap liblua5.1-0 libonig2 libqdbm14 php5-cli php5-common php5-json php5-readline ssl-cert tar
```

## 12. Configuration packages
### 12.1 Creating dummy remote_syslog file:
```bash
mkdir /var/log/remote_syslog/
touch /var/log/remote_syslog/remote_syslog.log
```

### 12.2 Set permissions dummy file:
```bash
chown www-data:www-data /var/log/remote_syslog/
chown www-data:www-data /var/log/remote_syslog/remote_syslog.log
```

### 12.3 Set symbolic link from remote_log directory -> html public dir:
```bash
ln -s /var/log/remote_syslog /var/www/html/
```

### 12.4 Add a new configuration file for syslog-ng:
```bash
cp -rf syslog-ng /etc/syslog-ng/conf.d/99-remote.conf
```

### 12.5 Copy a optional syslog-ng module (sends all local syslog to Remote Syslog):
```bash
cp -rf syslog-ng-localdefault /etc/syslog-ng/conf.d/99-remote-local.conf
```

Note 1: This module is optional. It sends all local logging to the Remote Syslog file. Usefull when debugging.

### 12.6 Apply new syslog-ng configuration:
```bash
service syslog-ng restart
```

### 12.7 Apply/copy new configuration for logrotate:
```bash
cp -rf logrotate /etc/logrotate.d/remotelog
```

### 12.8 Activate new REGEX for colortail:
```bash
cp -rf colortail /etc/colortail/conf.colortail
```

## 13. Deploy CLI application
### 13.1 Install packages to build rsview:
```bash
apt install g++ make
```

### 13.2 Compile rsview:
```bash
g++ rsview.c -o rsview
```

### 13.3 Copy rsview:
```bash
cp -rf rsview /usr/bin/rsview
```

### 13.4 Set permissions to rsview:
```bash
chmod +x /usr/bin/rsview
```

## 16. Deploy GUI webpage
### 16.1 Copy all files to your Apache 2 webpage directory:
```bash
cp -rf index.php /var/www/html/
cp -rf indexs.php /var/www/html/
cp -rf favicon.ico /var/www/html/
cp -rf jquery-latest.js /var/www/html/
cp -rf loaddata.php /var/www/html/
```

## 17. Config files
### 17.1 To change some configuration use the following files:
```bash
/etc/colortail/conf.colortail => for a new color regex
/etc/syslog-ng/conf.d/99-remote.conf => syslog configuration
/etc/logrotate.d/remotelog => change file rotation
/var/www/html/index.php => chang GUI
Recompile rsview.c => change CLI
```

Note 1: When you use a not recommended (Debian or Ubuntu) distrubution, your path to add configuration or copy files could be different.
