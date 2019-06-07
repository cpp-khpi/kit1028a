#include "TestPhoneArray.h"

bool TestPhoneArray::testAddPhone()
{
	int expectedSize = 3;
	Phone** expectedPhoneArray = new Phone*[expectedSize];
	
	Phone* tmpPhone;
	string titleStr;
	for (int i = 0; i < expectedSize; i++) {
		tmpPhone = new IosPhone;
		titleStr = to_string(i);
		tmpPhone->setPhoneInfo(titleStr, i, i, i, i);
		expectedPhoneArray[i] = tmpPhone;
	}

	int testSize = expectedSize - 1;
	Phone** testPhoneArray = new Phone*[testSize];

	for (int i = 0; i < testSize; i++) {
		tmpPhone = new IosPhone;
		titleStr = to_string(i);
		tmpPhone->setPhoneInfo(titleStr, i, i, i, i);
		testPhoneArray[i] = tmpPhone;
	}

	testingPhoneArray.setPhoneArrayInfo(testSize, testPhoneArray);

	Phone* newPhone = new IosPhone;
	titleStr = to_string(testSize);
	newPhone->setPhoneInfo(titleStr, testSize, testSize, testSize, testSize);

	testingPhoneArray.addPhone(newPhone);

	bool result;
	if (testingPhoneArray.comparisonPhoneArray(expectedPhoneArray, expectedSize))
		result = true;
	else
		result = false;

	for (int i = 0; i < expectedSize; i++)
		delete expectedPhoneArray[i];
	delete[] expectedPhoneArray;

	return result;
}

bool TestPhoneArray::isRemoveFromEnd()
{
	int expectedSize = 2;
	Phone** expectedPhoneArray = new Phone*[expectedSize];

	string titleStr;
	Phone* tmpPhone;
	for (int i = 0; i < expectedSize; i++) {
		tmpPhone = new IosPhone;
		titleStr = to_string(i);
		tmpPhone->setPhoneInfo(titleStr, i, i, i, i);
		expectedPhoneArray[i] = tmpPhone;
	}

	int testSize = expectedSize + 1;
	Phone** testPhoneArray = new Phone*[testSize];

	for (int i = 0; i < testSize; i++) {
		tmpPhone = new IosPhone;
		titleStr = to_string(i);
		tmpPhone->setPhoneInfo(titleStr, i, i, i, i);
		testPhoneArray[i] = tmpPhone;
	}

	testingPhoneArray.setPhoneArrayInfo(testSize, testPhoneArray);

	testingPhoneArray.removePhone(testSize - 1);

	bool endRemove = testingPhoneArray.comparisonPhoneArray(expectedPhoneArray, expectedSize);

	for (int i = 0; i < expectedSize; i++)
		delete expectedPhoneArray[i];
	delete[] expectedPhoneArray;

	return endRemove;
}

bool TestPhoneArray::isRemoveFromBegin()
{
	int expectedSize = 3;
	Phone** expectedPhoneArray = new Phone*[expectedSize];

	string titleStr;
	Phone* tmpPhone;
	for (int i = 0; i < expectedSize; i++) {
		tmpPhone = new IosPhone;
		titleStr = to_string(i + 1);
		tmpPhone->setPhoneInfo(titleStr, i + 1, i + 1, i + 1, i + 1);
		expectedPhoneArray[i] = tmpPhone;
	}

	int testSize = expectedSize + 1;
	Phone** testPhoneArray = new Phone*[testSize];

	for (int i = 0; i < testSize; i++) {
		tmpPhone = new IosPhone;
		titleStr = to_string(i);
		tmpPhone->setPhoneInfo(titleStr, i, i, i, i);
		testPhoneArray[i] = tmpPhone;
	}

	testingPhoneArray.setPhoneArrayInfo(testSize, testPhoneArray);

	testingPhoneArray.removePhone(0);

	bool beginRemove = testingPhoneArray.comparisonPhoneArray(expectedPhoneArray, expectedSize);

	for (int i = 0; i < expectedSize; i++)
		delete expectedPhoneArray[i];
	delete[] expectedPhoneArray;

	return beginRemove;
}

bool TestPhoneArray::testRemovePhone()
{
	if (isRemoveFromEnd() && isRemoveFromBegin())
		return true;
	else
		return false;
}

bool TestPhoneArray::testAll()
{
	return testAddPhone() && testRemovePhone();
}