#pragma once
#pragma once
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class InfoWork {
private:
	int pages;
	int mark;
	int type;
	string name;
public:
	InfoWork(int a, int b, int c, string creator) {
		pages = a;
		mark = b;
		type = c;
		name = creator;
	}
	InfoWork() {
		cout << "konstructor " << endl;
		pages = 0;
		mark = 0;
		type = 0;
		name;
	}
	InfoWork &operator=(const InfoWork &obj) {
		cout << "copy operator" << endl;
		this->pages = obj.pages;
		this->name = obj.name;
		this->mark = obj.mark;
		this->type = obj.type;
		return *this;
	}
	~InfoWork() {
	}
	void set(string creator);
	void set_n(int a, int b, int c, string creator);
	int getPages();
	int getMark();
	int getType();
	string getName();
};