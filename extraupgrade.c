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

inline bool localsyslog_exist (const std::string& name) {
        if (FILE *file = fopen(name.c_str(), "r")) {
                fclose(file);
                printf("syslog-ng-localdefault is already installed ...\n");
        } else {
                printf("Copy new file syslog-ng-localdefault ...\n");
                system("cp -rf ~/syslog-latest/syslog-ng-local /opt/remotesyslog/syslog-ng-localdefault");
        }
}

int main() {
	localsyslog_exist("/opt/remotesyslog/syslog-ng-localdefault");
}

