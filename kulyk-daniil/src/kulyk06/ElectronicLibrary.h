#pragma once
#include"ElectronicTextbook.h"

class ElectronicLibrary {
private:
	int size = 0;
	ElectronicTextbook *backlist;
public:
	void getSurname(string name, string exile);
	void printAll();
	void addTextbook(int num, int pages, int grade, int cost, int year_of_release, string author, string exile);
	void removeTextbook(int num);
	void getRequiredTextbook(int num);
	void deleteBacklist();
	float averageAmountOfPages(int num);
	void sortByCost(bool(*comp)(int x, int y));
	int getSize();
};
