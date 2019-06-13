#pragma once

#include "Exception.h"
#include "SomeArray.h"

class Operations {
private:
	int amount_of_arrays;
	SomeArray *arrays;
public:
	void createArrays1(stringstream &arrays);
	stringstream readFromFile(string nameFile);
	void ArrMaxValue(int *&arr);
	void writeToFile(int *arr, string nameFile);
	void delArrays();
};
