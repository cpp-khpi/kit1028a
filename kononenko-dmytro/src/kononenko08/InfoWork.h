#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <regex>
//#include "Teacher.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::getline;
using std::ofstream;

class InfoWork {
protected:
	int pages;
	int mark;
	int type;
	string name;
public:
	InfoWork();
	InfoWork(int a, int b, int c, string creator);
	InfoWork(const InfoWork &obj);
	InfoWork& operator= (const InfoWork obj) {}
	bool operator== (const InfoWork obj) {}
	bool operator!= (const InfoWork obj) {}
	friend std::ostream& operator<< (std::ostream &out, const InfoWork &obj) {}
	friend std::istream& operator>> (std::istream &in, InfoWork &obj) {}
	InfoWork get_element();
	~InfoWork() {};
	void set(string creator);
	void set_n(int a, int b, int c, string creator);
	int getPages();
	int getMark();
	int getType();
	string getName();
}typedef InfoW;