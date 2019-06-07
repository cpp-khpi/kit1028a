/**
* @file Tester.cpp
* Implementation of all functions of Tester class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/


#include "Tester.h"
#include "CourseWork.h"
#include "DetailInfo.h"

bool Tester::testAdd()
{
	int expectedSize = 3;
	InfoWork** expectedArray = new InfoWork*[expectedSize];

	InfoWork* tempWork;
	string titleStr;
	for (int i = 0; i < expectedSize; i++) {
		tempWork = new CourseWork;
		titleStr = to_string(i);
		tempWork->set_n(i,i,i,titleStr);
		expectedArray[i] = tempWork;
	}

	int testSize = expectedSize -1;
	InfoWork** testArray = new InfoWork*[testSize];

	for (int i = 0; i < testSize; i++) {
		tempWork = new CourseWork;
		titleStr = to_string(i);
		tempWork->set_n(i,i,i,titleStr);
		testArray[i] = tempWork;
	}

	testingArray.setArray(testSize, testArray);

	InfoWork* newWork = new CourseWork;
	titleStr = to_string(testSize);
	newWork->set_n(testSize, testSize, testSize, titleStr);

	testingArray.addElem(newWork);

	bool result;
	if (testingArray.comparisonArray(expectedArray, expectedSize))
		result = true;
	else
		result = false;

	for (int i = 0; i < expectedSize; i++)
		delete expectedArray[i];
	delete[] expectedArray;

	return result;
}

bool Tester::isDelFromEnd()
{
	int expectedSize = 2;
	InfoWork** expectedArray = new InfoWork*[expectedSize];

	string titleStr;
	InfoWork* tempWork;
	for (int i = 0; i < expectedSize; i++) {
		tempWork = new CourseWork;
		titleStr = to_string(i);
		tempWork->set_n(i, i, i, titleStr);
		expectedArray[i] = tempWork;
	}

	int testSize = expectedSize + 1;
	InfoWork** testArray = new InfoWork*[testSize];

	for (int i = 0; i < testSize; i++) {
		tempWork = new CourseWork;
		titleStr = to_string(i);
		tempWork->set_n(i, i, i, titleStr);
		testArray[i] = tempWork;
	}

	testingArray.setArray(testSize, testArray);

	testingArray.delElem(testSize);

	bool endRemove = testingArray.comparisonArray(expectedArray, expectedSize);

	for (int i = 0; i < expectedSize; i++)
		delete expectedArray[i];
	delete[] expectedArray;

	return endRemove;
}

bool Tester::testDel()
{
	if (isDelFromEnd())
		return true;
	else
		return false;
}

bool Tester::testAll()
{	
	return testAdd() && testDel();
}