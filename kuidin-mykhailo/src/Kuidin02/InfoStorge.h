#pragma once
#include "School.h"
class InfoStorge {
private:
	School *s;
public:

	int count = 0;
	void menu();
	void printall();
	void addObject(int index, int num, int cos, int pup, int emp, char *p);
	void delElem(int index);
	void find(int index);
	void print(int i);
	void createObjects();
	void deleteall();
	void setCount(int c);
	void average();

};