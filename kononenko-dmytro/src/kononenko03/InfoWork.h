#pragma once
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

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
};