#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;

class Textbook {
protected:
	int num, pages, grade, cost, year_of_release;
	string author;
public:
	Textbook();
	Textbook(int num, int pages, int grade, int cost, int year_of_release, string author);
	Textbook(const Textbook &obj);
	~Textbook() {
	}

	int getNum();
	int getPages();
	int getGrade();
	int getCost();
	int getYearOfRelease();
	string getAuthor();
	virtual void getInfo(string sur) = 0;
	void setInfo(int num, int pages, int grade, int cost, int year_of_release, string author);

	virtual void input() = 0;
	virtual void output() = 0;
	virtual void output_to_file(ofstream& file) = 0;
};


