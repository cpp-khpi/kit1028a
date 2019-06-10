/**
* @file TestsInfo.h
* File assignment				| Header file with TestsInfo class + connection of required libraries
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/

typedef unsigned int ID;			//Creating an unsigned int type synonym

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


/**
* Class containing the type of graphics
*/
class Ñhart {
private:
	string typeSome = "!NONE!";			// Type of graphics
public:
	void setType(string chart) {
		typeSome = chart;
	}

	string getType() {return typeSome;}
};


/**
* Stores information about the works, their number, the average number of pages, evaluation and surname + availability of graphics
*/
class TestsInfo {
public:
	TestsInfo();
	TestsInfo(int num, int works, int pages, string surname);
	TestsInfo(const TestsInfo& o);
	~TestsInfo() {};

	void setInfo(int num, int works, int pages, string surname);

	int getNum()const;
	int getWorks()const;
	int getPages()const;
	int getMark()const;
	string getSur()const;

	string printInfo()const;

	/*     Composition example     */
	class Plan {
	private:
		ID num = 0;		// Number of points plan  +   Using ID type
	public:
		void setNum(int number) {
			num = number;
		}
		ID getNum() { return num; }
	};

	void setPlan() {
		plan.setNum(getMark());
	}

	/*     Aggregation example     */
	void setGraph();
	void printGraph();

private:
	int num;			// ID
	int works;			// Number of completed works
	int pages;			// The average number of pages in the work
	int mark;			// Mark )
	string surname;		// Surname))
	Ñhart graph;		// Graphics
	Plan plan;			// Plan
};