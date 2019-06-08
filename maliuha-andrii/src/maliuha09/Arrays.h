#pragma once

#include "MyException.h"
#include "Array.h"
#include <cstdlib>
#include <sstream>
#include <fstream>

class Arrays {
private:
	int amountArr;
	Array *arrays;
public:
	void createArrays1(std::stringstream &arrays);
	std::stringstream readFromFile(std::string nameFile);
	void ArrMaxValue(int *&arr);
	void writeArrToFile(int *arr, std::string nameFile);
	void delArrays();
};


