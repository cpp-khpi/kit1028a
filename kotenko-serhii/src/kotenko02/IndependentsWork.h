#pragma once
#include "InfoIndependentsWork.h"

class IndependentsWork {
private:
	int size;
	InfoIndependentsWork *arr;
public:
	void getSize(int size);
	void newArray(char **s);
	void print();
	void addElem(int amount, int written, int mark, char *surname);
	void deleteElem(int l);
	void getByIndex(int index);
	void deleteArray();
};
