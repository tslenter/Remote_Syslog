/*
 *License:
 *“Remote Syslog” is a free application what can be used to view syslog messages.
 *Copyright (C) 2017 Tom Slenter
 *
 *This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *For more information contact the author:
 *Name author: Tom Slenter
 *E-mail: info@remotesyslog.com
 */

#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
using namespace std;

inline bool file_exist (const std::string& name) {
	if (FILE *file = fopen(name.c_str(), "r")) {
		fclose(file);
		printf("OK ...\n");
	} else {
                printf("Failed ...\n");
	}
}

inline bool install_exist (const std::string& name) {
        if (FILE *file = fopen(name.c_str(), "r")) {
                fclose(file);
                printf("Previous instalation found ...\n");
        } else {
                printf("No Remote Syslog upgrade or update possible ...\n");
		exit(0);
        }
}

inline bool package_exist (const std::string& name) {
        if (FILE *file = fopen(name.c_str(), "r")) {
                fclose(file);
                printf("Package installation ok ...\n");
        } else {
                printf("Package installation failed, is your OS supported? ...\n");
		exit(0);
        }
}

inline bool downloadexist (const std::string& name) {
        if (FILE *file = fopen(name.c_str(), "r")) {
                fclose(file);
                printf("Download ok ...\n");
        } else {
                printf("Download failed ...\n");
                exit(0);
        }
}

inline bool extraupgrade_exist (const std::string& name) {
        if (FILE *file = fopen(name.c_str(), "r")) {
                fclose(file);
                printf("Extra update file found ...\n");
		system("chmod +x /tmp/extraupgrade");
		system("/tmp/extraupgrade");
                printf("Remove update file ...\n");
		system("rm -rf /tmp/extraupgrade");
        } else {
                printf("No extra update file ...\n");
        }
}

inline bool localsyslog_activated (const std::string& name) {
        if (FILE *file = fopen(name.c_str(), "r")) {
                fclose(file);
                printf("Local log to Remote Syslog is activated ...\n");
        } else {
                printf("Local log to Remote Syslog is not activated ...\n");
        }
}

inline bool installer_exist (const std::string& name) {
        if (FILE *file = fopen(name.c_str(), "r")) {
                fclose(file);
                printf("Package is already installed. Please upgrade or reconfigure ...\n");
		exit(0);
        } else {
                printf("Full installer ready ...\n");
        }
}

int checkinstallation()
{
        printf("Check CLI application 1X ...\n");
        file_exist("/usr/bin/rsview");
        printf("Check installer 1X ...\n");
        file_exist("/usr/bin/rsinstaller");
        printf("Check GUI file 4X ...\n");
        file_exist("/var/www/html/index.php");
        file_exist("/var/www/html/favicon.ico");
        file_exist("/var/www/html/jquery-latest.js");
        file_exist("/var/www/html/loaddata.php");
        printf("Check logrotate 1X ...\n");
        file_exist("/etc/logrotate.d/remotelog");
        printf("Check colortail 1X ...\n");
        file_exist("/etc/colortail/conf.colortail");
        printf("Check syslog-ng 1X ...\n");
        file_exist("/etc/syslog-ng/conf.d/99-remote.conf");
        printf("Check remote_log dummy file 1X ...\n");
        file_exist("/var/log/remote_syslog/remote_syslog.log");
	printf("Check reconfiguration files 7X ...\n");
	file_exist("/opt/remotesyslog/syslog-ng");
	file_exist("/opt/remotesyslog/logrotate");
        file_exist("/opt/remotesyslog/colortail");
        file_exist("/opt/remotesyslog/syslog-ngdefault");
        file_exist("/opt/remotesyslog/logrotatedefault");
        file_exist("/opt/remotesyslog/colortaildefault");
	file_exist("/opt/remotesyslog/syslog-ng-localdefault");
	printf("Checking optional module activation ...\n");
	localsyslog_activated("/etc/syslog-ng/conf.d/99-remote-local.conf");
}

int debpackage()
{
        installer_exist("/usr/bin/rsinstaller");
        printf("Notice: This installation is tested for Debian 8.7 or higher...\n");
        printf("Starting installation ...\n");
        printf("Update installer cache ...\n");
        system("apt update");
        printf("Checking dependencies ...\n");
        system("apt -y purge rsyslog");
        system("apt -y install syslog-ng colortail wget logrotate grep apache2 apache2-bin apache2-data apache2-utils libapache2-mod-php5 libapr1 libaprutil1 libaprutil1-dbd-sqlite3 libaprutil1-ldap liblua5.1-0 libonig2 libqdbm14 php5-cli php5-common php5-json php5-readline ssl-cert tar");
}

int ubnpackage()
{
        installer_exist("/usr/bin/rsinstaller");
        printf("Notice: This installation is tested for Ubuntu 14.04 LTS or higher ...\n");
        printf("Starting installation ...\n");
        printf("Update installer cache ...\n");
        system("apt update");
        printf("Checking dependencies ...\n");
        system("apt -y purge rsyslog");
        system("apt -y install syslog-ng colortail wget logrotate grep apache2 apache2-utils php libapache2-mod-php tar");
}

int fullinstallation()
{
	package_exist("/etc/init.d/syslog-ng");
        printf("Creating dummy remote_syslog file ...\n");
        system("mkdir /var/log/remote_syslog/");
        system("touch /var/log/remote_syslog/remote_syslog.log");
        printf("Set dummy remote_syslog file permissions ...\n");
        system("chown www-data:www-data /var/log/remote_syslog/");
        system("chown www-data:www-data /var/log/remote_syslog/remote_syslog.log");
	printf("Set archive symlink ...\n");
        system("ln -s /var/log/remote_syslog /var/www/html/");
	printf("Remove default GUI website ...\n");
        system("rm -rf /var/www/html/index.html");
        printf("Configuring syslog-ng ...\n");
        system("cp -rf syslog-ng /etc/syslog-ng/conf.d/99-remote.conf");
        printf("Restart syslog-ng ...\n");
        system("service syslog-ng restart");
        printf("Set logrotation ...\n");
        system("cp -rf logrotate /etc/logrotate.d/remotelog");
        printf("Activate colortail regex ...\n");
        system("cp -rf colortail /etc/colortail/conf.colortail");
        printf("Deploying application for CLI logging ...\n");
        system("cp -rf rsview /usr/bin/rsview");
        printf("Set permissions for CLI application ...\n");
        system("chmod +x /usr/bin/rsview");
        printf("Set GUI website ...\n");
        system("cp -rf index.php /var/www/html/");
        system("cp -rf favicon.ico /var/www/html/");
        system("cp -rf jquery-latest.js /var/www/html/");
        system("cp -rf loaddata.php /var/www/html/");
        printf("Deploying installer ...\n");
        system("cp -rf rsinstaller /usr/bin/rsinstaller");
	printf("Deploy config to /opt/remotesyslog/ ...\n");
	system("mkdir /opt/remotesyslog/");
	system("cp -rf syslog-ng /opt/remotesyslog/");
        system("cp -rf syslog-ng /opt/remotesyslog/syslog-ngdefault");
	system("cp -rf logrotate /opt/remotesyslog/");
        system("cp -rf logrotate /opt/remotesyslog/logrotatedefault");
	system("cp -rf colortail /opt/remotesyslog/");
        system("cp -rf colortail /opt/remotesyslog/colortaildefault");
        system("cp -rf syslog-ng-local /opt/remotesyslog/syslog-ng-localdefault");
}

int reconfigure()
{
	printf("Configuring syslog-ng ...\n");
        system("cp -rf /opt/remotesyslog/syslog-ng /etc/syslog-ng/conf.d/99-remote.conf");
        printf("Restart syslog-ng ...\n");
        system("service syslog-ng restart");
        printf("Set logrotation ...\n");
        system("cp -rf /opt/remotesyslog/logrotate /etc/logrotate.d/remotelog");
        printf("Activate colortail regex ...\n");
        system("cp -rf /opt/remotesyslog/colortail /etc/colortail/conf.colortail");
}

int restoredefault()
{
        printf("Restore default syslog-ng ...\n");
        system("cp -rf /opt/remotesyslog/syslog-ngdefault /etc/syslog-ng/conf.d/99-remote.conf");
        printf("Restart syslog-ng ...\n");
        system("service syslog-ng restart");
        printf("Restore default logrotation ...\n");
        system("cp -rf /opt/remotesyslog/logrotatedefault /etc/logrotate.d/remotelog");
        printf("Restore default colortail regex ...\n");
        system("cp -rf /opt/remotesyslog/colortaildefault /etc/colortail/conf.colortail");
}

int setlocallog_start ()
{
        printf("Deploying local syslog to Remote Syslog ...\n");
        system("cp -rf /opt/remotesyslog/syslog-ng-localdefault /etc/syslog-ng/conf.d/99-remote-local.conf");
        printf("Restart syslog-ng ...\n");
        system("service syslog-ng restart");
}

int removelocallog_start ()
{
        printf("Removing local syslog to Remote Syslog ...\n");
        system("rm -rf /etc/syslog-ng/conf.d/99-remote-local.conf");
        printf("Restart syslog-ng ...\n");
        system("service syslog-ng restart");
}

int autoupdate()
{
	printf("Download installation ...\n");
	system("wget -N --tries=1 http://www.remotesyslog.com/syslog-latest.tar -P /tmp");
	downloadexist("/tmp/syslog-latest.tar");
	system("tar -xvf /tmp/syslog-latest.tar --overwrite -C ~");
	printf("Remove tar ...\n");
	system("rm /tmp/syslog-latest.tar");
        printf("Start update ...\n");
        printf("Deploying application for CLI logging ...\n");
        system("cp -rf ~/syslog-latest/rsview /usr/bin/rsview");
        printf("Set permissions for CLI application ...\n");
        system("chmod +x /usr/bin/rsview");
        printf("Set GUI website ...\n");
        system("cp -rf ~/syslog-latest/index.php /var/www/html/");
        system("cp -rf ~/syslog-latest/favicon.ico /var/www/html/");
        system("cp -rf ~/syslog-latest/jquery-latest.js /var/www/html/");
        system("cp -rf ~/syslog-latest/loaddata.php /var/www/html/");
        printf("Deploying installer ...\n");
        system("cp -rf ~/syslog-latest/rsinstaller /usr/bin/rsinstaller");
        printf("Set permissions for installer ...\n");
        system("chmod +x /usr/bin/rsinstaller");
	printf("Set default configuration in /opt/remotesyslog/ ...\n");
        system("cp -rf ~/syslog-latest/syslog-ng /opt/remotesyslog/syslog-ngdefault");
        system("cp -rf ~/syslog-latest/logrotate /opt/remotesyslog/logrotatedefault");
        system("cp -rf ~/syslog-latest/colortail /opt/remotesyslog/colortaildefault");
        printf("Copy upgrade file to /tmp/ ...\n");
	system("cp -rf ~/syslog-latest/extraupgrade /tmp/extraupgrade");
	extraupgrade_exist("/tmp/extraupgrade");
}

static void show_usage(std::string name)
{
	std::cerr << "Usage rsinstaller:\n"
              << "\n"
              << "\t-h,--help\t\t Display help\n"
              << "\t-r,--reconfigure\t Reconfigure services\n"
              << "\t-f,--fullinstall\t Start full installation\n"
              << "\t-a,--autoupgrade\t Auto upgrade (requires internet)\n"
              << "\t-d,--defaultconfig\t Restore default configuration\n"
	      << "\t-al,--addlocallog\t Add local syslog to Remote Syslog\n"
              << "\t-rl,--rmlocallog\t Remove local syslog to Remote Syslog\n"
              << "\n"
              << "Remote Syslog v1.1.2a by T.Slenter\n"
              << "More information: remotesyslog.com\n"
              << std::endl;
}

inline bool ubnfullinstall () {
 printf("\n");
 printf("#####################################\n");
 printf("#Remote Syslog by T.Slenter         #\n");
 printf("#More information: remotesyslog.com #\n");
 printf("#Ubuntu Installation                #\n");
 printf("#Version: 1.1.2a                    #\n");
 printf("#####################################\n");
 printf("\n");
 ubnpackage();
 fullinstallation();
 checkinstallation();
 return(0);
}

inline bool debfullinstall () {
 printf("\n");
 printf("#####################################\n");
 printf("#Remote Syslog by T.Slenter         #\n");
 printf("#More information: remotesyslog.com #\n");
 printf("#Debian Installation                #\n");
 printf("#Version: 1.1.2a                    #\n");
 printf("#####################################\n");
 printf("\n");
 debpackage();
 fullinstallation();
 checkinstallation();
 return(0);
}

inline bool finstall () {
 printf("#####################################\n");
 printf("#Remote Syslog by T.Slenter         #\n");
 printf("#More information: remotesyslog.com #\n");
 printf("#Installation type: full install    #\n");
 printf("#Version: 1.1.2a                    #\n");
 printf("#####################################\n");
 printf("\n");
}

inline bool upgrade () {
 printf("#####################################\n");
 printf("#Remote Syslog by T.Slenter         #\n");
 printf("#More information: remotesyslog.com #\n");
 printf("#Installation type: Reconfiguration #\n");
 printf("#Version: 1.1.2a                    #\n");
 printf("#####################################\n");
 printf("\n");
 install_exist("/usr/bin/rsview");
 reconfigure();
 checkinstallation();
 return(0);
}

inline bool autoupgrade () {
 printf("#####################################\n");
 printf("#Remote Syslog by T.Slenter         #\n");
 printf("#More information: remotesyslog.com #\n");
 printf("#Installation type: auto update     #\n");
 printf("#Version: 1.1.2a                    #\n");
 printf("#####################################\n");
 printf("\n");
 install_exist("/usr/bin/rsview");
 autoupdate();
 checkinstallation();
 return(0);
}

inline bool setdefault () {
 printf("#####################################\n");
 printf("#Remote Syslog by T.Slenter         #\n");
 printf("#More information: remotesyslog.com #\n");
 printf("#Installation type: Reconfiguration #\n");
 printf("#Version: 1.1.2a                    #\n");
 printf("#####################################\n");
 printf("\n");
 install_exist("/usr/bin/rsview");
 restoredefault();
 checkinstallation();
 return(0);
}

inline bool setlocallog () {
 printf("#####################################\n");
 printf("#Remote Syslog by T.Slenter         #\n");
 printf("#More information: remotesyslog.com #\n");
 printf("#Installation type: Local syslog    #\n");
 printf("#Version: 1.1.2a                    #\n");
 printf("#####################################\n");
 printf("\n");
 install_exist("/usr/bin/rsview");
 setlocallog_start();
 checkinstallation();
 return(0);
}

inline bool removelocallog () {
 printf("#####################################\n");
 printf("#Remote Syslog by T.Slenter         #\n");
 printf("#More information: remotesyslog.com #\n");
 printf("#Installation type: Local syslog    #\n");
 printf("#Version: 1.1.2a                    #\n");
 printf("#####################################\n");
 printf("\n");
 install_exist("/usr/bin/rsview");
 removelocallog_start();
 checkinstallation();
 return(0);
}

int main(int argc, char* argv[])
{
	if (getuid()) {
		printf("%s", "You must be root!\n");
                printf ("\n");
        } else {
		if (argc < 2) {
        	show_usage(argv[0]);
        	return 1;
    		}
    		for (int i = 1; i < argc; ++i) {
        		std::string arg = argv[i];
     		   	if ((arg == "-h") || (arg == "--help")) {
            		show_usage(argv[0]);
           	 	return 0;
        		} else if ((arg == "-r") || (arg == "--reconfigure")) {
				upgrade();
				return(0);
        		} else if ((arg == "-f") || (arg == "--fullinstall")) {
				finstall();
				printf("Select your OS: \n");
                               	printf("1) Debian 8.7 or higher\n");
                               	printf("2) Ubuntu 14.04 or higher\n");
                                printf("3) Exit\n");
				printf("\n");
				int i;
                               	cout << "Enter your option: ";
                               	cin >> i;
				if (i == 1) {
					debfullinstall();
					return(0);
				} else if (i == 2) {
					ubnfullinstall();
					return(0);
                                } else if (i == 3) {
                                        printf("Exit ...\n");
                                        return(0);
				} else {
					printf("Wrong option selected, auto exit.\n");
					return(0);
					}
        		} else if ((arg == "-a") || (arg == "--autoupgrade")) {
				autoupgrade();
				return(0);
        		} else if ((arg == "-d") || (arg == "--defaultconfig")) {
                		setdefault();
                		return(0);
                        } else if ((arg == "-al") || (arg == "--addlocallog")) {
                                setlocallog();
                                return(0);
                        } else if ((arg == "-rl") || (arg == "--rmlocallog")) {
                                removelocallog();
                                return(0);
        		} else {
	        		show_usage(argv[0]);
	        		return 1;
        		}
    		}
	}
}
