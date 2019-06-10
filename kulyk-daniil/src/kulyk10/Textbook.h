#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class Textbook {
private:
	int size;
	int pages;
public:
	Textbook& operator= (const Textbook &obj);
	friend ostream& operator<< (ostream &out, const Textbook &obj);
	friend istream& operator>> (istream &in, Textbook &obj);
	bool operator< (const Textbook obj);
	bool operator== (const Textbook obj);

	Textbook();
	Textbook(const Textbook &obj);
	Textbook(int size, int pages);
	~Textbook();

	int getPages();
	int getSize();
	void setInfo();
	void getInfo(int size, int pages);
};
