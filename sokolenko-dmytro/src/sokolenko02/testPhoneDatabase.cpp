#include "testPhoneDatabase.h"

bool TestPhoneDatabase::testAddPhone()
{
	int expectedSize = 3;
	Phone * expectedPhoneArray = new Phone[expectedSize];

	const int TITLESTRLEN = 10;
	char * titleValue = new char[TITLESTRLEN];

	/* Створення очікуваного масиву. */
	
	for (int i = 0; i < expectedSize; i++) {
		_itoa_s(i, titleValue, TITLESTRLEN, 10);
		expectedPhoneArray[i].setPhoneInfo(titleValue, i, i, i, i);
	}

	/* Створення тестуємого масиву, розмір менше очікуваного на 1. */

	int testSize = expectedSize - 1;
	phoneDatabase.setSize(testSize);
	Phone * testPhoneArray = new Phone[testSize];
	phoneDatabase.setPhoneArray(testPhoneArray);

	for (int i = 0; i < testSize; i++) {
		_itoa_s(i, titleValue, TITLESTRLEN, 10);
		testPhoneArray[i].setPhoneInfo(titleValue, i, i, i, i);
	}

	/* Створення додаваємого об'єкту. */

	Phone * newPhone = new Phone;
	_itoa_s(testSize, titleValue, TITLESTRLEN, 10);
	newPhone->setPhoneInfo(titleValue, testSize, testSize, testSize, testSize);

	phoneDatabase.addPhone(*newPhone);

	testPhoneArray = phoneDatabase.getPhoneArray();
	testSize = phoneDatabase.getSize();

	/* Порівняння очікуваємого і тестового масивів. */

	bool result;
	if (phoneDatabase.comparisonPhoneArray(expectedPhoneArray, testPhoneArray, expectedSize, testSize)) {
		result = true;
	}
	else {
		result = false;
	}

	delete newPhone;
	delete[] expectedPhoneArray;
	delete[] testPhoneArray;
	delete[] titleValue;

	return result;
}

