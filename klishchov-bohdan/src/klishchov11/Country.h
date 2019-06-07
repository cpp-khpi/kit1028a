#pragma once

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>

class Country {
private:
	int size;
	int popul;
public:
	Country& operator= (const Country &obj);
	friend std::ostream& operator<< (std::ostream &out, const Country &obj);
	friend std::istream& operator>> (std::istream &in, Country &obj);
	bool operator< (const Country obj);
	bool operator== (const Country obj);
	Country();
	Country(const Country &obj);
	Country(int mark, int size);
	int get_popul();
	int get_size();
	void generation_values();
	void set_data(int mark, int size);
	~Country();
};