#pragma once
#pragma once
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class InfoWork {
private:
	int pages;
	int mark;
	int type;
	char *name;
public:
	InfoWork(int a, int b, int c, char* creator) {
		pages = a;
		mark = b;
		type = c;
		name = (char *) operator new (sizeof(char) * 256);
		strcpy_s(name, 256, creator);
	}
	InfoWork() {
		cout << "konstructor " << endl;
		pages = 0;
		mark = 0;
		type = 0;
		name = (char *) operator new (sizeof(char) * 256);
	}
	InfoWork &operator=(const InfoWork &obj) {
		cout << "copy operator" << endl;
		this->pages = obj.pages;
		strcpy_s(name, 256, obj.name);
		this->mark = obj.mark;
		this->type = obj.type;
		return *this;
	}
	~InfoWork() {
		delete[] name;
	}
	void set(char *creator);
	void set_n(int a, int b, int c, char *creator);
	int getPages();
	int getMark();
	int getType();
	char* getName();
};