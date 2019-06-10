#include <fstream>
#include "Exception.h"

struct Arrays {
	int SIZE;
	int* arrSizes = nullptr;
	int** array = nullptr;
};

void readFromFile(const string fileName, Arrays& arrays);
void writeToFile(int* elemArray, const int& SIZE, const string fileName);

int* getArrPositiveValues(Arrays& arr, int& SIZE);
int& getPositiveValue(int* arr, int SIZE);

int& getSize(const int i, Arrays& Arrays);
int& getByIndex(const int i, const int j, Arrays& Arrays);


void setArr(const int i, int* newArray, Arrays& Arrays);
void removeArr(Arrays& Arrays);

