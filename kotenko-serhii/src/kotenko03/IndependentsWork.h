#pragma once
#include "InfoIndependentsWork.h"

class IndependentsWork {
private:
	int size;
	InfoIndependentsWork *arr;
public:
	void getSize(int size);
	void newArray(std::string *s);
	void print();
	void addElem(int amount, int written, int mark, std::string surname);
	void deleteElem(int l);
	void getByIndex(int index);
	void deleteArray();
	void readFromFile(std::string *surname);
	void writeToFile();
};
