#pragma once
#include "ElectronicTextbook.h"

class ElectronicLibrary {
private:
	int size;
	ElectronicTextbook *backlist;

public:
	void printAll();
	void getSurname(string *sur);
	void addTextbook(int num, int pages, int grade, int cost, int year_of_release, int amount_of_charge, string author);
	void removeTextbook(int index);
	void getRequiredTextbook(int index);
	void deleteBacklist();
	float averageAmountOfPages(int num);
	void sortByCost(bool(*comp)(int x, int y));
	void setSize(int size);

	void readFromFile(string *author);
	void writeToFile();
};

