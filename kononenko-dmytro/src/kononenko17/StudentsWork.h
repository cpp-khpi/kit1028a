#pragma once
#include "InfoWork.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
using std::ofstream;
using std::ifstream;

class StudentsWork {
private:
	int size;
	InfoWork *qual;
public:
	StudentsWork() :size(0) {};
	void setSize(int size);
	void createArr(string* name);
	void printArr(std::multimap<int, std::string, std::less<int>> tmp,int i);
	void printFile(string file, std::multimap<int, std::string, std::less<int>> tmp,int i);
	int add(InfoWork obj, int n);
	int del(int n);
	void delArr();
	int getSize();
};