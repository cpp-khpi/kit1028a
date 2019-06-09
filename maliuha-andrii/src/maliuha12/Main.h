#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <list>
#include <map>

using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
using std::set;
using std::list;
using std::map;


struct Version {
	string name;
	int arr[3];
};

void menue();

#include "InstalledProgram.h"
