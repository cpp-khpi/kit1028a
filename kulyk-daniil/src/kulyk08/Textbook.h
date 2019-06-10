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
	Textbook& operator= (const Textbook &obj);
	friend std::ostream& operator<< (std::ostream &out, const Textbook &obj);
	friend std::istream& operator>> (std::istream &in, Textbook &obj);
	bool operator< (const Textbook obj);
	bool operator> (const Textbook obj);

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
	void getInfo(string sur);
	void setInfo(int num, int pages, int grade, int cost, int year_of_release, string author);

};

