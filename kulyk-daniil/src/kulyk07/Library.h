#pragma once
#include "Grammarway.h"

class Library {
private:
	int size = 0;
	Textbook **info;

public:
	Library();
	~Library();

	void printAll(int size);
	void addTextbook(Textbook* hard);
	void removeTextbook(int num);
	void getRequiredTextbook(int num);
	void deleteBacklist();
	float averageAmountOfPages(int num);
	void sortByDifficulty(bool(*comp)(int x, int y));
	void setSize(int size);

	void readFromFile(int new_size);
	void writeToFile();
};
