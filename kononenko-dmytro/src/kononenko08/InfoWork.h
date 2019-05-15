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
	InfoWork& operator= (const InfoWork obj) {
		pages = obj.pages;
		mark = obj.mark;
		type = obj.type;
		name = obj.name;
		return *this;
	}
	bool operator== (const InfoWork obj) {
		return (pages == obj.pages && type == obj.type && mark == obj.mark && name == obj.name);
	}
	bool operator!= (const InfoWork obj) {
		return (pages != obj.pages && type != obj.type && mark != obj.mark && name != obj.name);
	}
	friend std::ostream& operator<< (std::ostream &out, const InfoWork &obj){
		out << obj.name << ": " << obj.mark << endl;
		return out;
	}
	friend std::istream& operator>> (std::istream &in, InfoWork &obj) {
		in >> obj.pages;
		in >> obj.mark;
		in >> obj.type;
		in >> obj.name;

		return in;
	}
	InfoWork get_element();
	~InfoWork() {};
	void set(string creator);
	void set_n(int a, int b, int c, string creator);
	int getPages();
	int getMark();
	int getType();
	string getName();
}typedef InfoW;