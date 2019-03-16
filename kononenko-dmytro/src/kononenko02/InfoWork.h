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
	InfoWork();
	InfoWork(int a, int b, int c, char* creator);
	InfoWork(const InfoWork &obj);
	InfoWork &operator=(const InfoWork &obj) {
		cout << "copy operator" << endl;
		this->pages = obj.pages;
		strcpy_s(name, 256, obj.name);
		this->mark = obj.mark;
		this->type = obj.type;
		return *this;
	}
	~InfoWork();
	void set(char *creator);
	void set_n(int a, int b, int c, char *creator);
	int getPages();
	int getMark();
	int getType();
	char* getName();
};