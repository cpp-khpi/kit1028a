#pragma once
#include "InfoIndependentsWork.h"

class IndependentsWork {
private:
	int size;
	InfoIndependentsWork *arr;
public:
	void setSize(int size);
	void newArray(std::string *s);
	void print();
	void addElem(int amount, int written, int mark, std::string person);
	void deleteElem(int l);
	void getByIndex(int index);
	void deleteArray();
	void readFromFile(std::string *person);
	void writeToFile();
	void searchBySurname(std::string search_person);
};
