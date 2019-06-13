#pragma once
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;

class SomeArray {
public:
	int size;
	int *arr;

	void delArr();
};