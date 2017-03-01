1. License:
“Remote Syslog” is a free application what can be used to view syslog messages.
Copyright (C) 2017 Tom Slenter

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

For more information contact the author:
Name author: Tom Slenter
E-mail: info@remotesyslog.com

2. Manual installation package:
Update installer cache:
apt update

Remove conflicting packages:
apt -y purge rsyslog

Install new packages:
apt install syslog-ng colortail wget logrotate grep apache2 apache2-bin apache2-data apache2-utils libapache2-mod-php5 libapr1 libaprutil1 libaprutil1-dbd-sqlite3 libaprutil1-ldap liblua5.1-0 libonig2 libqdbm14 php5-cli php5-common php5-json php5-readline ssl-cert tar

3. Manual configuration packages

3.1 Creating dummy remote_syslog file:
mkdir /var/log/remote_syslog/
touch /var/log/remote_syslog/remote_syslog.log

3.2 Set permissions dummy file:
chown www-data:www-data /var/log/remote_syslog/
chown www-data:www-data /var/log/remote_syslog/remote_syslog.log

3.3 Set sym link from remote_log directory -> html public dir:
ln -s /var/log/remote_syslog /var/www/html/

3.4 Add new configuration syslog-ng:
cp -rf syslog-ng /etc/syslog-ng/conf.d/99-remote.conf

3.5 Apply new syslog-ng configuration:
service syslog-ng restart

3.6 Apply new configuration for logrotate:
cp -rf logrotate /etc/logrotate.d/remotelog

3.7 Activate new REGEX for colortail:
cp -rf colortail /etc/colortail/conf.colortail

4. Deploy CLI application:

4.1 Install packages to build rsview
apt install g++ make

4.2 Compile rsview
g++ rsview.c -o rsview

4.3 Copy rsview
cp -rf rsview /usr/bin/rsview

4.4 Set permissions to rsview
chmod +x /usr/bin/rsview

5. Deploy GUI webpage:

5.1 Copy all files to your Apache 2 web direcotry:
cp -rf index.php /var/www/html/
cp -rf favicon.ico /var/www/html/
cp -rf jquery-latest.js /var/www/html/
cp -rf loaddata.php /var/www/html/

6. Config files

6.1 To change some configuration use the following files:
/etc/colortail/conf.colortail => for a new color regex
/etc/syslog-ng/conf.d/99-remote.conf => syslog configuration
/etc/logrotate.d/remotelog => change file rotation
/var/www/html/index.php => chang GUI
Recompile rsview.c => change CLI

Note 1: When you use a not recommended (Debian or Ubuntu) distrubution, your path to add configuration or copy files could be different.
