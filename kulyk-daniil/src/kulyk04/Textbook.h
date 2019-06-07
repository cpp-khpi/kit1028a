#pragma once
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::string;
using std::stringstream;

class Textbook {
private:
	int num, pages, grade, cost, year_of_release;
	string author;
public:
	Textbook();
	Textbook(int num, int pages, int grade, int cost, int year_of_release);
	Textbook(const Textbook &obj);
	~Textbook() {};

	void setInfo(int num, int pages, int grade, int cost, int year_of_release, string author);
	int getNum()const;
	int getPages()const;
	int getGrade()const;
	int getCost()const;
	int getYearOfRelease()const;
	string getAuthor();

	string printInfo()const;
};
