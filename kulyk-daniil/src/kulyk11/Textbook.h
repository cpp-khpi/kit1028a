#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class Textbook {
private:
	int pages;
public:
	Textbook& operator= (const Textbook &obj);
	friend ostream& operator<< (std::ostream &out, const Textbook &obj);
	friend istream& operator>> (std::istream &in, Textbook &obj);
	bool operator< (const Textbook obj);
	bool operator== (const Textbook obj);

	Textbook();
	Textbook(const Textbook &obj);
	Textbook(int pages);
	~Textbook();

	int getPages();
	void getInfo();
	void setInfo(int pages);
};
