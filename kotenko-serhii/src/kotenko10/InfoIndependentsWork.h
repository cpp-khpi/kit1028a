#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>

class InfoIndependentsWork {
private:
	int size;
	int mark;
public:
	InfoIndependentsWork& operator= (const InfoIndependentsWork &obj);
	friend std::ostream& operator<< (std::ostream &out, const InfoIndependentsWork &obj);
	friend std::istream& operator>> (std::istream &in, InfoIndependentsWork &obj);		
	bool operator< (const InfoIndependentsWork obj);
	bool operator== (const InfoIndependentsWork obj);
	InfoIndependentsWork();
	InfoIndependentsWork(const InfoIndependentsWork &obj);
	InfoIndependentsWork(int mark, int size);
	int get_mark();
	int get_size();
	void generation_values();
	void set_data(int mark,int size);
	~InfoIndependentsWork();
};