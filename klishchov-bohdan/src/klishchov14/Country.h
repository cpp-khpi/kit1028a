#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Country {
private:
	int area;
	int popul;
	string name;
public:

	bool operator <(const Country& rhs) {
		return area < rhs.area;
	}
	friend std::ostream& operator<< (std::ostream &out, const Country &obj) {
		out << "Name: " << obj.name << endl << " ARea: " << obj.area << endl;
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