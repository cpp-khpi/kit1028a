#include "TestPhoneDatabase.h"

bool TestPhoneDatabase::testAddPhone()
{
	int expectedSize = 3;
	Phone * expectedPhoneArray = new Phone[expectedSize];

	string titleStr;
	for (int i = 0; i < expectedSize; i++) {
		titleStr = to_string(i);
		expectedPhoneArray[i].setPhoneInfo(titleStr, i, i, i, i);
	}

	int testSize = expectedSize - 1;
	Phone * testPhoneArray = new Phone[testSize];

	for (int i = 0; i < testSize; i++) {
		titleStr = to_string(i);
		testPhoneArray[i].setPhoneInfo(titleStr, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(testSize, testPhoneArray);

	delete[] testPhoneArray;

	Phone newPhone;
	titleStr = to_string(testSize);
	newPhone.setPhoneInfo(titleStr, testSize, testSize, testSize, testSize);

	phoneDatabase.addPhone(newPhone);

	bool result;
	if (phoneDatabase.comparisonPhoneArray(expectedPhoneArray, expectedSize))
		result = true;
	else
		result = false;

	delete[] expectedPhoneArray;

	return result;
}

bool TestPhoneDatabase::testRemovePhone()
{
	int expectedSize;
	Phone * expectedPhoneArray;
	int testSize;
	Phone * testPhoneArray;

	/* Last item removal test. */

	expectedSize = 2;
	expectedPhoneArray = new Phone[expectedSize];

	string titleStr;
	for (int i = 0; i < expectedSize; i++) {
		titleStr = to_string(i);
		expectedPhoneArray[i].setPhoneInfo(titleStr, i, i, i, i);
	}

	testSize = expectedSize + 1;
	testPhoneArray = new Phone[testSize];

	for (int i = 0; i < testSize; i++) {
		titleStr = to_string(i);
		testPhoneArray[i].setPhoneInfo(titleStr, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(testSize, testPhoneArray);
	delete[] testPhoneArray;

	phoneDatabase.removePhone(testSize - 1);

	bool endRemove;
	if (phoneDatabase.comparisonPhoneArray(expectedPhoneArray, expectedSize))
		endRemove = true;
	else
		endRemove = false;

	delete[] expectedPhoneArray;

	/* First item removal test. */

	expectedSize = 3;
	expectedPhoneArray = new Phone[expectedSize];

	for (int i = 0; i < expectedSize; i++) {
		titleStr = to_string(i + 1);
		expectedPhoneArray[i].setPhoneInfo(titleStr, i + 1, i + 1, i + 1, i + 1);
	}

	testSize = expectedSize + 1;
	testPhoneArray = new Phone[testSize];

	for (int i = 0; i < testSize; i++) {
		titleStr = to_string(i);
		testPhoneArray[i].setPhoneInfo(titleStr, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(testSize, testPhoneArray);
	delete[] testPhoneArray;

	phoneDatabase.removePhone(0);

	bool beginRemove;
	if (phoneDatabase.comparisonPhoneArray(expectedPhoneArray, expectedSize))
		beginRemove = true;
	else
		beginRemove = false;

	delete[] expectedPhoneArray;

	/* Single item removal test. */

	expectedSize = 0;
	expectedPhoneArray = new Phone[expectedSize];

	for (int i = 0; i < expectedSize; i++) {
		titleStr = to_string(i);
		expectedPhoneArray[i].setPhoneInfo(titleStr, i, i, i, i);
	}

	testSize = expectedSize + 1;
	testPhoneArray = new Phone[testSize];

	for (int i = 0; i < testSize; i++) {
		titleStr = to_string(i);
		testPhoneArray[i].setPhoneInfo(titleStr, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(testSize, testPhoneArray);
	delete[] testPhoneArray;

	phoneDatabase.removePhone(0);

	bool singleRemove;
	if (phoneDatabase.comparisonPhoneArray(expectedPhoneArray, expectedSize))
		singleRemove = true;
	else
		singleRemove = false;

	delete[] expectedPhoneArray;

	/* Final testing. */

	if (endRemove && beginRemove && singleRemove)
		return true;
	else
		return false;
}

bool TestPhoneDatabase::testGetPhone()
{
	int size = 2;
	Phone * phoneArray = new Phone[size];

	string titleStr;
	for (int i = 0; i < size; i++) {
		titleStr = to_string(i);
		phoneArray[i].setPhoneInfo(titleStr, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(size, phoneArray);

	Phone expectedPhone;
	titleStr = to_string(1);
	expectedPhone.setPhoneInfo(titleStr, 1, 1, 1, 1);

	bool result = phoneDatabase.getPhone(1) == expectedPhone;

	delete[] phoneArray;

	return result;
}

bool TestPhoneDatabase::testGetSmallestResolutPhone()
{
	int size = 3;
	Phone * phoneArray = new Phone[size];

	string titleStr;
	for (int i = 0; i < size; i++) {
		titleStr = to_string(i);
		phoneArray[i].setPhoneInfo(titleStr, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(size, phoneArray);

	Phone expectedPhone;
	titleStr = to_string(0);
	expectedPhone.setPhoneInfo(titleStr, 0, 0, 0, 0);

	bool result = phoneDatabase.getSmallestResolutPhone() == expectedPhone;
	delete[] phoneArray;

	return result;
}

bool TestPhoneDatabase::testAll()
{
	if (testAddPhone() && testRemovePhone() && testGetPhone() && testGetSmallestResolutPhone())
		return true;
	else
		return false;
}