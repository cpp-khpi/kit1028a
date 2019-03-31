#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <regex>
#include "Teacher.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::getline;

class InfoWork {
private:
	Teacher person;
	int pages;
	int mark;
	int type;
	string name;
public:
	InfoWork();
	InfoWork(int a, int b, int c, string creator);
	InfoWork(const InfoWork &obj);
	InfoWork& operator= (const InfoWork obj) {
		person = obj.person;
		pages = obj.pages;
		mark = obj.mark;
		type = obj.type;
		name = obj.name;
		return *this;
	}
	~InfoWork() {};
	void set(string creator);
	void set_n(int a, int b, int c, string creator,string tchName);
	int getPages();
	int getMark();
	int getType();
	string getName();
	string getTch();
}typedef InfoW;