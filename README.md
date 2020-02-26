#### A newer version will be released 29 februari 2020 @ 15:00 CEST. The new software is announced @ https://www.remotesyslog.com/. The download link after release: https://github.com/tslenter/RSX-RSC.git.

#### All support will be dropped from Remote Syslog 1.x on 25 march 2020. Upgrade available after 29 february.

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

# FAQ
Our Frequently Asked Questions section allows you to search for some addition / requested configuration for Remote Syslog.

## 18. How do I forward my local syslog to another syslog server?
Edit the following file:
```bash
nano /opt/remotesyslog/syslog-ng
```

#Add the following lines, where “IP or hostname” = your new remote syslog server:
```bash
destination remote_server {
tcp(“IP or hostname” port(514));
udp(“IP or hostname” port(514));
};
log { source(s_src); destination(remote_server); };
```

Run the Remote Syslog installer to apply the configuration:
```bash
rsinstaller -r
```

## 19. How do I include my local syslog to 1 file?
To include all local syslog to 1 file do:
```bash
nano /etc/syslog-ng/syslog-ng.conf
```

Add the following rules:
```bash
destination all_log { file(“/var/log/all_syslog.log”); };
log { source(“s_src”); destination(“all_log”); };
```

Then reload or restart the syslog-ng service:
```bash
service syslog-ng reload or service syslog-ng restart
```

## 20. How do I include my local syslog within the Remote Syslog viewer?
This option is included in version 1.1.2a. Run the following command to activate:
```bash
rsinstaller -al
```

To deactivated this function run:
```bash
rsinstaller -rl
```

If you run a version lower then 1.1.2a then you can activate this function manual. Just follow the instructions below.

Edit the rsview syslog-ng configuration file:
```bash
nano /opt/remotesyslog/syslog-ng
```

Add the following line:
```bash
log { source(“s_src”); destination(“Y”); };
```

Then run the rsinstaller to apply the configuration:
```bash
rsinstaller -r
```

## 21. How do I restore my default configuration?
You can restore the default configuration with the following command:
```bash
rsinstaller -d
```

## 22. How do I make my Remote Syslog server redundant?
Install 2 Remote Syslog Servers. Then add a primary and secondary host to your device configuration. If there is no option to add a secondary syslog server you could use option 2 of this section to forward the syslog messages.

## 23. How do I disable the loaddata.php messages in the apache 2 access.log?
Your log recieves the following messages:
```
172.168.29.251 – rsuser [25/May/2017:21:07:01 +0200] “GET /loaddata.php?randval=0.05259220201918463&_=1495738782510 HTTP/1.1” 200 548 “http://172.168.29.109/” “Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/6.0; rv:10.0) like Gecko”
```

This is the php page what request the realtime data. To disable this message do:

In this example we use ubuntu with the setenvif module enabled:

```bash
sudo nano /etc/apache2/sites-enabled/000-default.conf
```

Add:

```
<VirtualHost *:80>
SetEnvIf Request_URI “^/loaddata.php” dontlog
</VirtualHost>
```

Change the CustomLog directive to:

```
<VirtualHost *:80>
CustomLog ${APACHE_LOG_DIR}/access.log combined env=!dontlog
</VirtualHost>
```

If SSL is enabled create the following rules:

```
<VirtualHost *:443>
CustomLog ${APACHE_LOG_DIR}/access.log combined env=!dontlog
SetEnvIf Request_URI “^/loaddata.php” dontlog
</VirtualHost>
```

## 24. How do i check my syslog-ng service?
You can check the status with:
```bash
systemctl syslog-ng.service status
```

Check for the text:
Active: active (running)

“If the service is running make sure it binds to TCP and/or UDP port 512. You can check it with:
```bash
netstat -tuna
```

Check for the text:
```bash
tcp 0 0 0.0.0.0:514
udp 0 0 0.0.0.0:514
```

## 25. How do i search for multiple strings of text?
Login as a regular user (root is not required) and run the following command:

```bash
grep -h “switch1\|switch2\|switch3” /var/log/remote_syslog/* | more
```

This will start a search for the text: switch1, switch2 or switch3  in the text files located in the /var/log/remote_syslog/ directory.

## 26. How do i recieve a message by mail if a event occurs?
We prepared a script what can be used with sendmail. Sendmail should be configured to relay the mail to your provider. The following script use a array of words and the date of today to filter messages. The script is tested for Cisco devices. Use cron to schedule the script.

```bash
#!/bin/bash
#Array of words:
declare -a data=(Trace module)
```

#Check if error messages exist
```bash
for word in “${data[@]}”; do
mesg=$(cat /var/log/remote_syslog/remote_syslog.log | grep “^$(date +’%b %d’)” | grep $word)
if [ -z “$mesg” ]
then
echo “No variable!”
else
echo “Variable filled, setting variable to continue …”
mesgall=1
fi
done
```

#Generate mail
```bash
if [ -z “$mesgall” ]
then
echo “Nothing to do, abort”
exit
else
echo “Subject: Syslog critical errors” > /opt/rs.txt
echo “” >> /opt/rs.txt
echo “Hello <user>,” >> /opt/rs.txt
echo “” >> /opt/rs.txt
echo “The following message is generated by Remote Syslog.” >> /opt/rs.txt
echo “” >> /opt/rs.txt
for word in “${data[@]}”; do
cat /var/log/remote_syslog/remote_syslog.log | grep “^$(date +’%b %d’)” | grep $word >> /opt/rs.txt
done
echo “” >> /opt/rs.txt
echo “The messages above are generated by the <hostname>!” >> /opt/rs.txt
echo “” >> /opt/rs.txt
echo “Thank you for using Remote Syslog … ;-)” >> /opt/rs.txt
cat /opt/rs.txt
/usr/sbin/sendmail -v -F “MIS NS” -f “info@mydomain.com” ticketsystem@domain.com < /opt/rs.txt
fi
```

## 27. How do i uninstall Remote Syslog?
You can uninstall Remote syslog by removing the packages, configuration files and binarys by the following script:

```bash
echo “File is only present if local syslog is activated”
rm -rf /etc/syslog-ng/conf.d/99-remote-local.conf
echo “Remove configuration files”
rm -rf /etc/syslog-ng/conf.d/99-remote.conf
rm -rf /etc/logrotate.d/remotelog
rm -rf /etc/colortail/conf.colortail
rm -rf /opt/remotesyslog
echo “Remove binary files”
rm -rf /usr/bin/rsview
rm -rf /usr/bin/rsinstaller
echo “Removing legacy GUI website …”
rm -rf /var/www/html/favicon.ico
rm -rf /var/www/html/index.php
rm -rf /var/www/html/indexs.php
rm -rf /var/www/html/jquery-latest.js
rm -rf /var/www/html/loaddata.php
echo “Remove packages …”
apt -y purge apache2 apache2-utils php libapache2-mod-php syslog-ng colortail
apt -y autoremove
echo “Reinstall rsyslog”
apt -y install rsyslog
```

## 28. How do i install Remote Syslog for Ubuntu 18.x?

Before the Remote Syslog intallation run the “apt-add-repository multiverse” command. This repo is required to install Remote Syslog.

# VERSION AND LICENSE
Remote Syslog has a stable version to use. (released on 15-02-2017). Feel free to test and install Remote Syslog. Remote Syslog is currently tested with 400 Cisco devices and had no problems saving or displaying syslog messages.

## 29. Version and changes

### 29.1 Latest version (stable):

18-04-2018: Version 1.1.3.3: Sets the default live log (/var/log/remote_syslog/remote_syslog.log) rotation for 1 week or 100MB. (Remote Syslog already installed? Run “rsinstaller -d” to restore the remote syslog defaults.)

Note 1: The upgrade bug can be resolved if you run “rsinstaller -a” twice. (Triggered when upgrading: installer does not load the extra installation file). Version 1.1.2a and lower.

Note 2: The following legacy commands are removed: syslog_installer, remote_log and remote_livelog

Note 3: Version 1.1.2 and higher is tested for Raspberry Pi.

Note 4: The next major version removes support from Debian 8.x and Raspberry Pi O/S Jessie.

### 29.2 Previous versions:

13-04-2018: Version 1.1.3.2: Optimized GUI code and GUI response. Basic search bar (concept) added and an option to extent the MEM_LIMIT of PHP. Allows you to search a small live log file. 100MB or less. If there is a larger live log file please consider to increase the rotation or filter some messages.

05-03-2018:  Version 1.1.3.2 BETA: Optimized GUI code and GUI response. This is a concept version of Remote Syslog and no final product.   Before you install the BETA version make sure you installed version 1.1.3 stable.  This BETA is a upgrade of 1.1.3.

02-01-2018:  Version 1.1.3.1 BETA: Added a search bar to the GUI. This is a concept version of Remote Syslog and no final product.   Before you install the BETA version make sure you installed version 1.1.3 stable.  This BETA is a upgrade of 1.1.3.

18-09-2017: Version 1.1.3: Small update in GUI and CLI.  Supported O/S changed to Debian 8.x / 9.x and Ubuntu 16.04 LTS. Raspberry Pi new O/S support Stretch. (stable)

05-04-2017: Version 1.1.2a: Fixed upgrade binarie, added a option to send all local logging to the Remote Syslog file, fixed cosmetic bug. (stable)

01-03-2017: Version 1.1.2: Added binaries for Debian and Ubuntu with 64-bit, 32-bit and ARM + OS select added. (stable)

23-02-2017: Version 1.1.1: Added listener on TCP 514 + updated test CLI and GUI commands (stable)

18-02-2017: Version 1.1: Added function to restore default configuration (CLI) + rsview can be run without root permissions (stable)

15-02-2017: Version 1.0: Bug fix GUI + new CLI installer with update over internet + new CLI rsview and rsinstaller commands (stable)

14-02-2017: BETA 1.0: Bug fix GUI + update installer + new CLI rsview command(removal remote_livelog and remote_log commands).

13-02-2017: BETA 0.9: Bug fix GUI + update installer.

11-02-2017: BETA 0.8: Fixed some bugs.

10-02-2017: BETA 0.7: Fixed some bugs. (Not publicly available)

08-02-2017: BETA 0.6: Changed GUI color / Added GUI buttons / Changed daily rotation to weekly / Fixed some bugs / Installer has a auto-detect upgrade/full setup. (Not publicly available)

05-02-2017: BETA 0.5: BUG fix symlink + added per host archive. (Not publicly available)

02-02-2017: BETA 0.4: Added GUI and archive button. (Not publicly available)

28-01-2017: BETA 0.3: Early GUI with bugs. (Not publicly available)

10-01-2017: BETA 0.2: Added color pattern to CLI. (Not publicly available)

27-12-2016: BETA 0.1 First release, CLI only. (Not publicly available)

15-12-2016: ALPHA 0.1 Concept bash version. (Not publicly available)

## 30 LICENSE
"Remote Syslog" is a free application what can be used to view syslog messages. Copyright (C) 2017 Tom Slenter

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

For more information contact the author:

Name author: Tom Slenter

E-mail: info@remotesyslog.com

## 31 Download

Click on the link below to start downloading Remote Syslog 64-BIT:

https://sourceforge.net/projects/remote-syslog/files/remote-syslog-latest-AMD64.tar/download

Click on the link below to start downloading Remote Syslog 32-BIT:

https://sourceforge.net/projects/remote-syslog/files/remote-syslog-latest-x86.tar/download

Click on the link below to start downloading Remote Syslog ARM:

https://sourceforge.net/projects/remote-syslog/files/remote-syslog-latest-arm.tar/download

Click on the link below to start downloading Remote Syslog manual installation (contains source rsview):

https://sourceforge.net/projects/remote-syslog/files/remote-syslog-manual-source.tar/download

## 32 Repository files

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
