#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::string;


class Country {
private:
	int area;
	int popul;
	string name;
public:
	Country& operator= (const Country obj) {
		area = obj.area;
		popul = obj.popul;
		name = obj.name;
		return *this;
	}
	friend bool operator< (const Country &obj, const Country &obj2) {
		return (obj.popul < obj2.popul);
	}
	friend bool operator> (const Country &obj, const Country &obj2) {
		return (obj.popul > obj2.popul);
	}
	friend bool operator== (const Country &obj1, const Country &obj2) {
		return (obj1.popul == obj2.popul);
	}
	friend bool operator!= (const Country &obj, const Country &obj2) {
		return (obj.popul != obj2.popul);
	}
	friend std::ostream& operator<< (std::ostream &out, const Country &obj) {
		out << "Name: " << obj.name << endl << "Area: " << obj.area << endl;
		out << "Population: " << obj.popul << endl;
		return out;
	}
	friend std::istream& operator>> (std::istream &in, Country &obj) {
		cout << "Input area: ";
		in >> obj.area;
		cout << "Input population: ";
		in >> obj.popul;
		cout << "Input name: ";
		in >> obj.name;

		return in;
	}
	void setData(string name);
	string getName();
	int getArea();
	int getPopul();
};