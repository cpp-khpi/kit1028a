#pragma once
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
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
	TestsInfo(int num, int works, int pages,string surname);
	TestsInfo(const TestsInfo &o);
	~TestsInfo() {};

	void setInfo(int num, int works, int pages,string surname);
	int getNum()const;
	int getWorks()const;
	int getPages()const;
	int getMark()const;
	string getSurname()const;

	string printInfo()const;
};