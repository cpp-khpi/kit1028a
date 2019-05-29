#pragma once

#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::regex;


struct Time {
	int hours;
	int minutes;
	int seconds;
};

struct Version {
	string name;
	int arr[3];
};


#include "Program.h"
#include "InstalledProgram.h"
#include "WorkingProgram.h"
#include "Array.h"

void menu();
