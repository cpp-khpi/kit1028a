#pragma once

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::regex;
using std::string;
using std::getline;
using std::istream;
using std::ostream;

class Textbook {
protected:
	int pages;
	int grade;
	int cost;
	string author;
public:
	Textbook();
	Textbook(const Textbook &obj);
	Textbook(int pages, int grade, int cost, string author);
	Textbook& operator= (const Textbook &obj);
	~Textbook();

	friend ostream& operator<< (ostream &out, const Textbook &obj);
	friend istream& operator>> (istream &in, Textbook &obj);
	virtual void generateData(string s);
	int getPages();
	int getGrade();
	int getCost();
	string getAuthor();
	void setInfo(int pages, int grade, int cost, string author);

	void* operator new(size_t size);
	void operator delete(void *pointer);
	void* operator new[](size_t size);
	void operator delete[](void *pointer);
};