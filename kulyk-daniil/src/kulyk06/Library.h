#pragma once
#include"Textbook.h"

class Library {
private:
	int size = 0;
	Textbook *backlist;
public:
	void getSurname(string name);
	void printAll();
	void addTextbook(int num, int pages, int grade, int cost, int year_of_release, string author);
	void removeTextbook(int num);
	void getRequiredTextbook(int num);
	void deleteBacklist();
	float averageAmountOfPages(int num);
	void sortByCost(bool(*comp)(int x, int y));
	int getSize();
};