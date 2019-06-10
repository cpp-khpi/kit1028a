/**
* @file TestsInfo.h
* File assignment				| Header file with TestsInfo class + connection of required libraries
* @author						| Kabak A. R.
* @version 1.1
* @date 2019.05.31
*/
#pragma once
#include <cstddef>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ifstream;
using std::regex;
using std::regex_match;

/**
* Stores information about the works, their number, the average number of pages, evaluation and surname + availability of graphics
*/
class TestsInfo {
public:
	TestsInfo();
	TestsInfo(int num, int works, int pages, string surname);
	TestsInfo(const TestsInfo& o);
	~TestsInfo() {};

	virtual void setInfo(int num, int works, int pages, string surname);

	virtual int getNum()const final;
	virtual int getWorks()const final;
	virtual int getPages()const final;
	virtual int getMark()const final;
	virtual string getSur()const final;

	virtual void setMark(int mark) final;

	virtual string printInfo()const final;	//exemple using final

protected:
	int num;			// ID
	int works;			// Number of completed works
	int pages;			// The average number of pages in the work
	int mark;			// Mark )
	string surname;		// Surname))
};