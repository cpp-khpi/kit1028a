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
using std::ofstream;
using std::ifstream;

class Textbook {
protected:
	int pages;
	int grade;
	int cost;
	string author;
public:
	/**
	* InfoIndependentsWork class constructors.
	*/
	Textbook();
	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param obj: its fields initialize fields current object.
	*/
	Textbook(const Textbook &obj);
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param pages initializes Textbook::pages.
	* @param grade initializes Textbook::grade.
	* @param cost initializes Textbook::cost.
	* @param author initializes Textbook::author.
	*/
	Textbook(int pages, int grade, int cost, string author);
	/**
	* Operator overload = .
	*/
	Textbook& operator= (const Textbook &obj);
	/**
	* Overloading of the output operator at the pointer and without.
	*/
	friend ostream& operator<< (ostream &out, const Textbook &obj);
	friend ostream& operator<< (ostream &out, const Textbook *obj);
	/**
	* Overloading of the input operator at the pointer and without.
	*/
	friend istream& operator>> (istream &in, Textbook &obj);
	friend istream& operator>> (istream &in, Textbook *obj);
	/**
	* Virtual data entry and output functions and file recording.
	*/
	virtual void input() = 0;
	virtual void output() = 0;
	virtual void outputToFile(ofstream& file) = 0;
	/**
	* Virtual function to generate values.
	*/
	virtual void generateData(string s);
	/**
	* Get copy of field.
	* Return current value.
	*/
	int getPages();
	int getGrade();
	int getCost();
	string getAuthor();
	/**
	* Assignment field value.
	*/
	void setInfo(int pages, int grade, int cost, string author);
	/**
	* Textbookk class destructor.
	*/
	~Textbook();
};
