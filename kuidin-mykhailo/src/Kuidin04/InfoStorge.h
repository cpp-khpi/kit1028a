#pragma once
#include "School.h"
#include "Header.h"
class InfoStorge {
private:
	School *s;
	int count;
public:
	InfoStorge() :count(0) {};
	void menu();
	void printall();
	void addObject(int index, int num, int cos, int pup, int emp, string p);
	void delElem(int index);
	void find(int index);
	void print(int i);
	void createObjects();
	void deleteall();
	void setCount(int c);
	void average();
	void readFromFile(string file, int fnum, int fcost, int fpupils, int femployers, string fname, int index);
	void setAll(int index, int num, int cos, int pup, int emp, string p);
	void printToFile(int index);
	void clearFile(string fname);
	void regexCheck(string str);
	void countWords();
};