#pragma once

#include <fstream>
#include "TwoDimenIntArray.h"
#include "MyException.h"

using std::ifstream;
using std::ofstream;
using std::endl;

/** Reading information about array of integers.
* @param fileName: name of being read file.
* @param intArray: reference to struct variable with integers' array
* and its information.
*/
void readFromFile(const string fileName, 
	TwoDimenIntArray& intArray);

/**
* Receipt array of negative elements are located in all subarrays.
* @param intArray: reference to struct variable with integers' array
* and its information.
* @param size: reference to size of negative elements' array.
* @return pointer to array of negative elements.
*/
int* getNegativeElements(TwoDimenIntArray& intArray, 
	unsigned int& size);

/** 
* Writing to file elements' array.
* @param elemArray: elements' array is which is written to file.
* @param size: size of array.
* @param fileName: name of writing file.
*/
void writeToFile(int* elemArray,
	const unsigned int& size,
	const string fileName);

/**
* Delete intArray's arrays memory.
* @param intArray: reference to struct variable with integers' array
* and its information.
*/
void deleteArray(TwoDimenIntArray& intArray);

/**
* Receipt of subarray size by index.
* @param i: index of requested size.
* @param intArray: reference to struct variable with integers' array
* and its information.
* @return reference to size of subarray with index i.
*/
int& getSizeByIndex(const unsigned int i, 
	TwoDimenIntArray& intArray);

/**
* Assignment of subarray pointer by index.
* @param i: index of requested pointer.
* @param newArray is assigned subarray of intArray by index .
* @param intArray: reference to struct variable with integers' array
* and its information.
* @return pointer to subarray with index i.
*/
void setArrayByIndex(const unsigned int i, 
	int* newArray, 
	TwoDimenIntArray& intArray);

/**
* Receipt of reference to element by indexes.
* @param i: index of subarray.
* @param J: index of element.
* @param intArray: reference to struct variable with integers' array
* and its information.
* @return reference to element with index j
* of subarray with index i.
*/
int& getElemByIndexes(const unsigned int i, 
	const unsigned int j, 
	TwoDimenIntArray& intArray);