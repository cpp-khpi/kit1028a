#pragma once
#include <cstddef>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Textbook {
protected:
	int pages;
	int grade;
	int cost;
	string author;
public:
	Textbook();
	Textbook(int p, int g, int c, string surname);
	Textbook(const Textbook &obj);
	Textbook& operator= (const Textbook obj) {
		pages = obj.pages;
		grade = obj.grade;
		cost = obj.cost;
		author = obj.author;
		return *this;
	}

	friend bool operator< (const Textbook &obj, const Textbook &obj2) {
		return (obj.pages < obj2.pages);
	}
	friend bool operator> (const Textbook &obj, const Textbook &obj2) {
		return (obj.pages > obj2.pages);
	}
	friend bool operator== (const Textbook &obj1, const Textbook &obj2) {
		return (obj1.pages == obj2.pages);
	}
	friend bool operator!= (const Textbook &obj, const Textbook &obj2) {
		return (obj.pages != obj2.pages);
	}
	friend std::ostream& operator<< (std::ostream &out, const Textbook &obj) {
		out << "Author: " << obj.author << " Grade: " << obj.grade << endl;
		out << "Pages: " << obj.pages << " Cost: " << obj.cost << endl;
		return out;
	}
	friend std::istream& operator>> (std::istream &in, Textbook &obj) {
		cout << "Enter the number of pages in textbook: ";
		in >> obj.pages;
		cout << "Enter the grade this textbook for: ";
		in >> obj.grade;
		cout << "Enter the cost of the textbook: ";
		in >> obj.cost;
		cout << "Enter the name of textbook's author: ";
		in >> obj.author;

		return in;
	}

	Textbook getInfo();
	~Textbook() {};
	void generateObject(string sur);
	void setInfo(int g, int p, int c, string surname);
	int getPages();
	int getGrade();
	int getCost();
	string getAuthor();
}typedef Book;
