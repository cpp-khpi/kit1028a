#pragma once
#include "pch.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class infoWork {
private:
	int pages;
	int mark;
	int type;
	char *name;
public:
	infoWork(int a, int b, int c, char* creator) {
		pages = 0;
		mark = 0;
		type = 0;
		name = (char *) operator new (sizeof(char) * 256);
		strcpy_s(name, 256, creator);
	}
	infoWork() {
		cout << "konstructor " << endl;
		pages = 0;
		mark = 0;
		type = 0;
		name = (char *) operator new (sizeof(char) * 256);
	}
	infoWork &operator=(const infoWork &obj) {
		cout << "copy operator" << endl;
		this->pages = obj.pages;
		strcpy_s(name, 256, obj.name);
		this->mark = obj.mark;
		this->type = obj.type;
		return *this;
	}
	~infoWork() {
		delete[] name;
	}
	void set(char *creator);
	void set_n(int a, int b, int c, char *creator);
	int getPages();
	int getMark();
	int getType();
	char* getName();
};

class studentsWork {
private:
	int size;
	infoWork *qual;
public:
	void getSize(int x);
	void createArr();
	void gibi(int index);
	void printArr();
	void findP();
	void add(int n);
	void del(int n);
	void testDel();
	void testAdd();
	void delArr();
};