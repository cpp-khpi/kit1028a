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

	virtual void setInfo(int num, int works, int pages, string surname) = 0;

	int getNum()const;
	int getWorks()const;
	int getPages()const;
	int getMark()const;
	string getSur()const;

	void setMark(int mark);

	virtual void printInfo()const = 0;	//exemple using clear virtual method

protected:
	int num;			// ID
	int works;			// Number of completed works
	int pages;			// The average number of pages in the work
	int mark;			// Mark )
	string surname;		// Surname))
};