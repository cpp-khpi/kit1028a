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
using std::istream;
using std::ostream;

struct Time {
	int hours;
	int minutes;
	int seconds;
};

struct Version {
	string name;
	int arr[3];
};

#include "WorkingProgram.h"
#include "Viruses.h"
#include "Array.h"

void menu();
