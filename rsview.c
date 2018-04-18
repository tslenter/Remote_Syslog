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

static void show_usage(std::string name)
{
    std::cerr << "Usage rsview:\n"
              << "\n"
              << "\t-h,--help\t\t\t\t Display help\n"
              << "\t-s,--search <search string>\t\t Search through logging\n"
              << "\t-v,--view\t\t\t\t View logging\n"
              << "\t-l,--live\t\t\t\t View live logging\n"
              << "\t-ls,--livesearch <search string>\t Search through live logging\n"
              << "\t-t,--testmessage\t\t\t Send a test message\n"
              << "\t-c,--clearlog\t\t\t\t Clear total log archive\n"
              << "\n"
              << "Remote Syslog v1.1.3.3 by T.Slenter\n"
              << "More information: remotesyslog.com\n"
              << std::endl;
}

int setversion ()
{
 printf("#Version: 1.1.3.3                               #\n");
 return(0);
}

int donate ()
{
 printf("#Donate XRP: rHdkpJr3qYqBYY3y3S9ZMr4cFGpgP1eM6B #\n");
 return(0);
}

inline bool livebanner () {
 printf("#################################################\n");
 printf("#Remote Syslog by T.Slenter                     #\n");
 printf("#More information: remotesyslog.com             #\n");
 setversion ();
 donate ();
 printf("#################################################\n");
 printf("\n");
 printf("Press ctrl + c to quit\n");
 printf("\n");
}

inline bool logbanner () {
 printf("#################################################\n");
 printf("#Remote Syslog by T.Slenter                     #\n");
 printf("#More information: remotesyslog.com             #\n");
 setversion ();
 donate ();
 printf("#################################################\n");
 printf("\n");
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        show_usage(argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            show_usage(argv[0]);
            return 0;
        } else if ((arg == "-s") || (arg == "--search")) {
            if (i + 1 < argc) {
		logbanner();
                printf ("This program was called with search string: \"%s\".\n",argv[++i]);
		std::string const command = std::string( "cat /var/log/remote_syslog/remote_syslog.log | grep --color=always " ) + argv[i];
		system( command.c_str() );
                return 0;
            }
        } else if ((arg == "-l") || (arg == "--live")) {
		livebanner();
        	system("colortail -n 30 -f /var/log/remote_syslog/remote_syslog.log");
		return 0;
        } else if ((arg == "-ls") || (arg == "--livesearch")) {
            if (i + 1 < argc) {
                livebanner();
	        printf ("This program was called with search string: \"%s\".\n",argv[++i]);
		std::string const command = std::string( "tail -n 30 -f /var/log/remote_syslog/remote_syslog.log | grep --color=always " ) + argv[i];
       		system( command.c_str() );
                return 0;
            }
        } else if ((arg == "-v") || (arg == "--view")) {
                logbanner();
		system("colortail -n 3000 /var/log/remote_syslog/remote_syslog.log");
                return 0;
        } else if ((arg == "-t") || (arg == "--testmessage")) {
                logbanner();
                system("logger -n 127.0.0.1 -d 'This is a UDP test message!'; logger -T -P 514 -n 127.0.0.1 'This is a TCP test message!'");
		printf ("Sending test message! Check logging!\n");
                printf ("\n");
                return 0;
        } else if ((arg == "-c") || (arg == "--clearlog")) {
                logbanner();
		if (getuid()) {
			printf("%s", "You must be root!\n");
			printf ("\n");
		} else {
                	system("rm -rf /var/log/remote_syslog/remote_syslog.log.*");
                	printf ("Total logging archive cleared!\n");
                	printf ("\n");
                	return 0;
		}
        } else {
	        show_usage(argv[0]);
	        return 1;
        }
    }
}
