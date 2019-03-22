#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <regex>
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
	int pages;
	int mark;
	int type;
	string name;
public:
	InfoWork();
	InfoWork(int a, int b, int c, string creator);
	InfoWork(const InfoWork &obj);
	~InfoWork() {};
	void set(string creator);
	void set_n(int a, int b, int c, string creator);
	int getPages();
	int getMark();
	int getType();
	string getName();
}typedef InfoW;