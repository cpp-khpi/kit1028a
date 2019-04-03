#include "TestPhoneDatabase.h"

bool TestPhoneDatabase::testAddPhone()
{
	const int TITLESTRLEN = 10;
	char * titleValue = new char[TITLESTRLEN];

	/* Створення очікуваного масиву. */

	int expectedSize = 3;
	Phone * expectedPhoneArray = new Phone[expectedSize];
	
	for (int i = 0; i < expectedSize; i++) {
		_itoa_s(i, titleValue, TITLESTRLEN, 10);
		expectedPhoneArray[i].setPhoneInfo(titleValue, i, i, i, i);
	}

	/* Створення тестуємого масиву, розмір менше очікуваного на 1. */

	int testSize = expectedSize - 1;
	Phone * testPhoneArray = new Phone[testSize];

	for (int i = 0; i < testSize; i++) {
		_itoa_s(i, titleValue, TITLESTRLEN, 10);
		testPhoneArray[i].setPhoneInfo(titleValue, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(testSize, testPhoneArray);

	/* Створення додаваємого об'єкту. */

	Phone * newPhone = new Phone;
	_itoa_s(testSize, titleValue, TITLESTRLEN, 10);
	newPhone->setPhoneInfo(titleValue, testSize, testSize, testSize, testSize);

	phoneDatabase.addPhone(*newPhone);

	testPhoneArray = phoneDatabase.getPhoneArray();
	testSize = phoneDatabase.getSize();

	/* Порівняння очікуваємого і тестового масивів. */

	bool result;
	if (phoneDatabase.comparisonPhoneArray(expectedPhoneArray, testPhoneArray, expectedSize, testSize))
		result = true;
	else
		result = false;

	delete newPhone;
	delete[] expectedPhoneArray;
	delete[] titleValue;

	return result;
}

bool TestPhoneDatabase::testRemovePhone()
{
	const int TITLESTRLEN = 10;
	char * titleValue = new char[TITLESTRLEN];

	int expectedSize;
	Phone * expectedPhoneArray;

	int testSize;
	Phone * testPhoneArray;

	/* Видалення з кінця, створення очікуваного масиву. */

	expectedSize = 3;
	expectedPhoneArray = new Phone[expectedSize];

	for (int i = 0; i < expectedSize; i++) {
		_itoa_s(i, titleValue, TITLESTRLEN, 10);
		expectedPhoneArray[i].setPhoneInfo(titleValue, i, i, i, i);
	}

	/* Створення тестуємого масиву, розмір більше очікуваного на 1. */

	testSize = expectedSize + 1;
	testPhoneArray = new Phone[testSize];

	for (int i = 0; i < testSize; i++) {
		_itoa_s(i, titleValue, TITLESTRLEN, 10);
		testPhoneArray[i].setPhoneInfo(titleValue, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(testSize, testPhoneArray);

	phoneDatabase.removePhone(testSize - 1);

	testPhoneArray = phoneDatabase.getPhoneArray();
	testSize = phoneDatabase.getSize();

	bool endRemove;
	if (phoneDatabase.comparisonPhoneArray(expectedPhoneArray, testPhoneArray, expectedSize, testSize))
		endRemove = true;
	else
		endRemove = false;

	delete[] expectedPhoneArray;

	/* Видалення з початку, створення очікуваного масиву. */

	expectedSize = 3;
	expectedPhoneArray = new Phone[expectedSize];

	for (int i = 1; i < expectedSize + 1; i++) {
		_itoa_s(i, titleValue, TITLESTRLEN, 10);
		expectedPhoneArray[i - 1].setPhoneInfo(titleValue, i, i, i, i);
	}

	/* Створення тестуємого масиву, розмір більше очікуваного на 1. */

	testSize = expectedSize + 1;
	testPhoneArray = new Phone[testSize];


	for (int i = 0; i < testSize; i++) {
		_itoa_s(i, titleValue, TITLESTRLEN, 10);
		testPhoneArray[i].setPhoneInfo(titleValue, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(testSize, testPhoneArray);

	phoneDatabase.removePhone(0);

	testPhoneArray = phoneDatabase.getPhoneArray();
	testSize = phoneDatabase.getSize();

	bool beginRemove;
	if (phoneDatabase.comparisonPhoneArray(expectedPhoneArray, testPhoneArray, expectedSize, testSize))
		beginRemove = true;
	else
		beginRemove = false;

	delete[] expectedPhoneArray;

	/* Видалення масиву з 1 елементом, створення очікуваного масиву. */

	expectedSize = 0;
	expectedPhoneArray = new Phone[expectedSize];
	
	/* Створення тестуємого масиву, розмір більше очікуваного на 1. */

	testSize = expectedSize + 1;
	testPhoneArray = new Phone[testSize];

	_itoa_s(0, titleValue, TITLESTRLEN, 10);
	testPhoneArray[0].setPhoneInfo(titleValue, 0, 0, 0, 0);

	phoneDatabase.setPhoneDatabaseInfo(testSize, testPhoneArray);

	phoneDatabase.removePhone(0);

	testPhoneArray = phoneDatabase.getPhoneArray();
	testSize = phoneDatabase.getSize();

	bool onlyRemove;
	if (phoneDatabase.comparisonPhoneArray(expectedPhoneArray, testPhoneArray, expectedSize, testSize))
		onlyRemove = true;
	else
		onlyRemove = false;

	delete[] expectedPhoneArray;
	delete[] titleValue;


	/* Підсумкове визначення працездатності removePhone. */

	if (endRemove && beginRemove && onlyRemove)
		return true;
	else
		return false;
}

bool TestPhoneDatabase::testGetPhone()
{
	int size = 3;
	Phone * phoneArray = new Phone[size];

	const int TITLESTRLEN = 10;
	char * titleValue = new char[TITLESTRLEN];

	for (int i = 0; i < size; i++) {
		_itoa_s(i, titleValue, TITLESTRLEN, 10);
		phoneArray[i].setPhoneInfo(titleValue, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(size, phoneArray);

	Phone expectedPhone;
	_itoa_s(1, titleValue, TITLESTRLEN, 10);
	expectedPhone.setPhoneInfo(titleValue, 1, 1, 1, 1);

	Phone receivedPhone;
	receivedPhone = phoneDatabase.getPhone(1);

	bool result = receivedPhone == expectedPhone;

	delete[] titleValue;
	delete[] phoneArray;

	return result;
}

bool TestPhoneDatabase::testGetSmallestResolutPhone()
{
	int size = 3;
	Phone * phoneArray = new Phone[size];

	const int TITLESTRLEN = 10;
	char * titleValue = new char[TITLESTRLEN];

	for (int i = 0; i < size; i++) {
		_itoa_s(i, titleValue, TITLESTRLEN, 10);
		phoneArray[i].setPhoneInfo(titleValue, i, i, i, i);
	}

	phoneDatabase.setPhoneDatabaseInfo(size, phoneArray);

	Phone expectedPhone;
	_itoa_s(0, titleValue, TITLESTRLEN, 10);
	expectedPhone.setPhoneInfo(titleValue, 0, 0, 0, 0);

	Phone receivedPhone;
	receivedPhone = phoneDatabase.getSmallestResolutPhone();

	bool result = receivedPhone == expectedPhone;

	delete[] titleValue;
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