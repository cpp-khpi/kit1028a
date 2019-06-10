#include "function.h"
using std::ifstream;
using std::ofstream;



void readFromFile(const string fileName, Arrays& arrays) {
	ifstream fin(fileName);

	if (!fin) {
		throw Exception("Can't open file for reading", "readFromFile");
	}

	fin >> arrays.SIZE;
	arrays.arrSizes = new int[arrays.SIZE];
	arrays.array = new int* [arrays.SIZE];

	int* point;

	for (int i = 0; i < arrays.SIZE; i++) {
		fin >> getSize(i, arrays);
		arrays.array[i] = new int[getSize(i, arrays)];

		for (int j = 0; j < getSize(i, arrays); j++) {
			fin >> getByIndex(i, j, arrays);
			fin.ignore();
		}
	}
	fin.close();
}
void writeToFile(int* elemArray, const int& SIZE, const string fileName) {
	ofstream fout(fileName);

	if (!fout) {
		throw Exception("Can't open file for writing", "writeToFile");
	}

	fout << "Array of positive elements: ";
	for (int i = 0; i < SIZE; i++) {
		fout << elemArray[i] << " ";
	}
	fout.close();
}

int* getArrPositiveValues(Arrays& arr, int& SIZE) {
	SIZE = arr.SIZE;
	int* result = new int[SIZE];

	for (int i = 0; i < arr.SIZE; i++) {
		result[i] = getPositiveValue(arr.array[i], arr.arrSizes[i]);
	}
	return result;
}
int& getPositiveValue(int* arr, int SIZE) {
	int positive = 0;
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] > 0) {
			positive++;
		}
	}
	return positive;
}

int& getSize(const int i, Arrays& Arrays) {
	if (i >= Arrays.SIZE) {
		throw Exception("Invalid index", "getSize");
	}
	return Arrays.arrSizes[i];
}
int& getByIndex(const int i, const int j, Arrays& Arrays) {
	if (i >= Arrays.SIZE || j >= getSize(i, Arrays)) {
		throw Exception("Invalid index", "getByIndex");
	}
	return Arrays.array[i][j];
}

void setArr(const int i, int* newArray, Arrays& Arrays) {
	if (i >= Arrays.SIZE) {
		throw Exception("Invalid index", "setArr");
	}
	Arrays.array[i] = newArray;
}
void removeArr(Arrays& Arrays) {
	for (int i = 0; i < Arrays.SIZE; i++) {
		delete[] Arrays.array[i];
	}
	delete[] Arrays.arrSizes;
	delete[] Arrays.array;
}
