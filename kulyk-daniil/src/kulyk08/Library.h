#pragma once
#include "Textbook.h"

class Library {
private:
	int size = 0;
	Textbook *info;

public:
	friend std::ostream& operator<< (std::ostream &out, const Library &obj);
	friend std::istream& operator>> (std::istream &in, Library &obj);
	Textbook &operator[] (const int index);

	void printAll(int size);
	void getSurname(string *sur);
	void addTextbook(int num, int pages, int grade, int cost, int year_of_release, string author);
	void removeTextbook(int index);
	void getRequiredTextbook(int index);
	void deleteBacklist();
	float averageAmountOfPages(int num);
	void sortByCost(bool(*comp)(int x, int y));
	void setSize(int size);

	void readFromFile(string *book);
	void writeToFile();
};
