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
using std::ostream;
using std::istream;
using std::ofstream;
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
	/**
	* TestsInfo class constructors.
	*/
	TestsInfo();
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param num     initializes TestsInfo::num.
	* @param works   initializes TestsInfo::works.
	* @param pages   initializes TestsInfo::pages.
	* @param surname initializes TestsInfo::surname.
	*/
	TestsInfo(int num, int works, int pages, string surname);
	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param o: its fields initialize fields current object.
	*/
	TestsInfo(const TestsInfo& o);
	/**
	* InfoIndependentsWork class destructor.
	*/
	~TestsInfo() {};

	/**
	* Operator overload = .
	*/
	TestsInfo& operator = (const TestsInfo& o);
	/**
	* Operator overload == .
	* Compare score, work, page
	*/
	bool operator == (const TestsInfo& o);
	/**
	* Overloading of the output operator at the pointer and without.
	*/
	friend ostream& operator << (ostream& os, const TestsInfo& o);
	/**
	* Overloading of the input operator at the pointer and without.
	*/
	friend istream& operator >> (istream& is, TestsInfo& o);

	/**
	* Virtual function to set info.
	*/
	virtual void setInfo(int num, int works, int pages, string surname) = 0;

	virtual void outputToFile(ofstream& file) = 0;

	/**
	* Virtual function to print info about object.
	*/
	virtual void printInfo()const = 0;

	/**
	* Getters and setters.
	*/
	int getNum()const;
	int getWorks()const;
	int getPages()const;
	int getMark()const;
	string getSur()const;

	void setMark(int mark);

protected:
	int num;			// ID in list
	int works;			// Number of completed works
	int pages;			// The average number of pages in the work
	int mark;			// Mark )
	string surname;		// Surname))
};