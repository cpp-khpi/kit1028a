#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>

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
using std::for_each;
using std::sort;

struct Version {
	string name;
	int arr[3];
};

template <class T1, class T2>
vector<T1> ContainerInsert(vector<T1> t1, vector<T2> t2)
{
	for (const auto& el : t2) {
		t1.insert(t1.end(), el);
	}
	return t1;
}



void menue();

#include "InstalledProgram.h"
