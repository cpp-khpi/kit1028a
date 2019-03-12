#include "test.h"

bool TestPhoneDatabase::phoneComparison(Phone & firstPhone, Phone & secondPhone)
{
	bool isEqualPrice = firstPhone.getPrice() == secondPhone.getPrice();
	bool isEqualSimNumb = firstPhone.getSimCardsNumber() == secondPhone.getSimCardsNumber();
	bool isEqualDisp = firstPhone.getDisplay() == secondPhone.getDisplay();
	bool isEqualPermis = firstPhone.getPermission() == secondPhone.getPermission();
	bool isEqualCapac = firstPhone.getCapacity() == secondPhone.getCapacity();

	if (isEqualPrice && isEqualSimNumb && isEqualDisp && isEqualPermis && isEqualCapac)
		return true;
	else
		return false;
}


bool TestPhoneDatabase::testAddPhone()
{
	int expectedSize = 4;
	Phone * expectedPhoneArray = new Phone[expectedSize];
	for (int i = 0; i < expectedSize; i++) {
		expectedPhoneArray[i].setPrice(i);
		expectedPhoneArray[i].setSimCardsNumber(i);
		expectedPhoneArray[i].setDisplay(static_cast<float>(i));
		expectedPhoneArray[i].setPermission(i);
		expectedPhoneArray[i].setCapacity(i);
	}

	Phone * testPhoneArray = new Phone[expectedSize - 1];

	for (int i = 0; i < expectedSize - 1; i++) {
		testPhoneArray[i].setPrice(i);
		testPhoneArray[i].setSimCardsNumber(i);
		testPhoneArray[i].setDisplay(static_cast<float>(i));
		testPhoneArray[i].setPermission(i);
		testPhoneArray[i].setCapacity(i);
	}

	phoneDatabase.setSize(expectedSize - 1);
	phoneDatabase.setPhoneArray(testPhoneArray);

	Phone newPhone;
	newPhone.setPrice(expectedSize - 1);
	newPhone.setSimCardsNumber(expectedSize - 1);
	newPhone.setDisplay(static_cast<float>(expectedSize - 1));
	newPhone.setPermission(expectedSize - 1);
	newPhone.setCapacity(expectedSize - 1);

	phoneDatabase.addPhone(newPhone);

	bool result;
	if (phoneComparison(testPhoneArray[expectedSize - 1], testPhoneArray[expectedSize - 1]) == true)
		result = true;
	else
		result = false;

	testPhoneArray = phoneDatabase.getPhoneArray();
	delete[] testPhoneArray;

	return result;
}

bool TestPhoneDatabase::testAddPhone()
{
	int size = 4;
	phoneDatabase.setSize(size);
	
	Phone * testPhoneArray = new Phone[size];

	for (int i = 0; i < size; i++) {
		testPhoneArray[i].setPrice(i);
		testPhoneArray[i].setSimCardsNumber(i);
		testPhoneArray[i].setDisplay(static_cast<float>(i));
		testPhoneArray[i].setPermission(i);
		testPhoneArray[i].setCapacity(i);
	}

	Phone newPhone;
	newPhone.setPrice(size);
	newPhone.setSimCardsNumber(size);
	newPhone.setDisplay(static_cast<float>(size));
	newPhone.setPermission(size);
	newPhone.setCapacity(size);
	
	phoneDatabase.setPhoneArray(testPhoneArray);

	phoneDatabase.addPhone(newPhone);
	size = phoneDatabase.getSize();

	bool result;
	if (phoneComparison(newPhone, testPhoneArray[4]) == true)
		result = true;
	else
		result = false;

	testPhoneArray = phoneDatabase.getPhoneArray();
	delete[] testPhoneArray;

	return result;
}