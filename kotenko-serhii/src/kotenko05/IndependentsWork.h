#pragma once
#include "InfoIndependentsWork.h"

class IndependentsWork {
private:
	int size;
	InfoIndependentsWork *arr;
public:
	IndependentsWork(InfoIndependentsWork* mas, int x) : arr(mas), size(x) {};
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
	void sort_by_mark(bool(*sort)(int a, int b));
	void sort_by_amount(bool(*sort)(int a, int b));
	void sort_by_written(bool(*sort)(int a, int b));
};
