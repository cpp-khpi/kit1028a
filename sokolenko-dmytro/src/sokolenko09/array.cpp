#include "array.h"

void readFromFile(const string fileName, 
	TwoDimenIntArray& intArray)
{
	ifstream fin(fileName);

	if (!fin) {
		throw MyException("Can't open file for reading", "readFromFile");
	}

	fin.ignore(6);
	fin >> intArray.size;
	intArray.arraySizesArrays = new int[intArray.size];
	intArray.array = new int*[intArray.size];

	int* tmpPointer;
	for (int i = 0; i < intArray.size; i++) {

		fin.ignore(8);
		fin >> getSizeByIndex(i, intArray);
		intArray.array[i] = new int[getSizeByIndex(i, intArray)];

		for (int j = 0; j < getSizeByIndex(i, intArray); j++) {
			fin >> getElemByIndexes(i, j, intArray);
			fin.ignore();
		}
	}

	fin.close();
}

int* getNegativeElements(TwoDimenIntArray& intArray, 
	unsigned int& size)
{
	size = 0;
	for (int i = 0; i < intArray.size; i++) {
		for (int j = 0; j < getSizeByIndex(i, intArray); j++) {
			if (getElemByIndexes(i, j, intArray) < 0)
				size++;
		}
	}
	
	int* negativeElemArray = new int[size];

	int k = 0;
	for (int i = 0; i < intArray.size; i++) {
		for (int j = 0; j < getSizeByIndex(i, intArray); j++) {
			if (getElemByIndexes(i, j, intArray) < 0) {
				negativeElemArray[k] = getElemByIndexes(i, j, intArray);
				k++;
			}
		}
	}

	return negativeElemArray;
}

void writeToFile(int* elemArray,
	const unsigned int& size,
	const string fileName)
{
	ofstream fout(fileName);

	if (!fout) {
		throw MyException("Can't open file for writing", "writeToFile");
	}

	fout << "Negative elements: " << endl;
	for (int i = 0; i < size; i++)
		fout << elemArray[i] << " ";

	fout.close();
}

void deleteArray(TwoDimenIntArray& intArray)
{
	for (int i = 0; i < intArray.size; i++)
		delete[] intArray.array[i];

	delete[] intArray.arraySizesArrays;
	delete[] intArray.array;
}

void setArrayByIndex(const unsigned int i, 
	int* newArray, 
	TwoDimenIntArray& intArray)
{
	if (i >= intArray.size)
		throw MyException("Invalid index", "setArrayByIndex");

	intArray.array[i] = newArray;
}

int& getSizeByIndex(const unsigned int i, 
	TwoDimenIntArray& intArray)
{
	if (i >= intArray.size)
		throw MyException("Invalid index", "getSizeByIndex");

	return intArray.arraySizesArrays[i];
}

int& getElemByIndexes(const unsigned int i, 
	const unsigned int j, 
	TwoDimenIntArray& intArray)
{

	if (i >= intArray.size || j >= getSizeByIndex(i, intArray))
		throw MyException("Invalid index", "getElemByIndexes");

	return intArray.array[i][j];
}