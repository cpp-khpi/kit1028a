#pragma once
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

class TestsInfo {
private:
	int num;
	int works, pages, mark;
	string surname;
public:
	TestsInfo();
	TestsInfo(int num);
	TestsInfo(const TestsInfo &o);

	void setSurname(string surname);
	void setInfo(int num);
	string getInfo()const;

	int getWorks()const;
	int idInfo()const;
};