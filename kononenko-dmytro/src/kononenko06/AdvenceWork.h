#pragma once
#include "DetailInfo.h"
#include "InfoWork.h"

class AdvenceWork {
private:
	DetailInfo * works;
	int Size;
public:
	void search(int index);
	void add(DetailInfo obj, int n);
	void del(int n);
	AdvenceWork() :Size(0) {};
	void setSize(int x);
	void createArr(string* name);
	void printArr();
	void delArr();
};