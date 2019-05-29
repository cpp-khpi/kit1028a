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
	friend bool operator< (const InfoWork &obj,const InfoWork &obj2) {
		return (obj.pages < obj2.pages);
	}
	friend bool operator> (const InfoWork &obj,const InfoWork &obj2) {
		return (obj.pages > obj2.pages);
	}
	friend bool operator== (const InfoWork &obj1,const InfoWork &obj2) {
		return (obj1.pages == obj2.pages);
	}
	friend bool operator!= (const InfoWork &obj,const InfoWork &obj2) {
		return (obj.pages != obj2.pages);
	}
	friend std::ostream& operator<< (std::ostream &out, const InfoWork &obj) {
		out << "Name: " << obj.name << " Mark: " << obj.mark << endl;
		out << "Pages: " << obj.pages << " Type: " << obj.type << endl;
		return out;
	}
	friend std::istream& operator>> (std::istream &in, InfoWork &obj) {
		cout << "Input pages: ";
		in >> obj.pages;
		cout << "Input mark: ";
		in >> obj.mark;
		cout << "Input type: ";
		in >> obj.type;
		cout << "Input name: ";
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