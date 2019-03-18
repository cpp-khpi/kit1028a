#include "TestPhoneDatabase.h"

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
	int size = 4;
	phoneDatabase.setSize(size);

	Phone * testPhoneArray = new Phone[size];
	phoneDatabase.setPhoneArray(testPhoneArray);

	for (int i = 0; i < size; i++) {
		testPhoneArray[i].setPrice(i);
		testPhoneArray[i].setSimCardsNumber(i);
		testPhoneArray[i].setDisplay(i);
		testPhoneArray[i].setPermission(i);
		testPhoneArray[i].setCapacity(i);
	}

	Phone * newPhone = new Phone;
	newPhone->setPrice(size);
	newPhone->setSimCardsNumber(size);
	newPhone->setDisplay((size));
	newPhone->setPermission(size);
	newPhone->setCapacity(size);

	phoneDatabase.addPhone(*newPhone);
	size = phoneDatabase.getSize();
	testPhoneArray = phoneDatabase.getPhoneArray();

	bool result;
	if (phoneComparison(*newPhone, testPhoneArray[size - 1]) == true)
		result = true;
	else
		result = false;

	delete[] testPhoneArray;
	delete newPhone;

	return result;
}

bool TestPhoneDatabase::testRemovePhone()
{
	int size;
	Phone * testPhoneArray;
	int index;
	Phone * tmpTestPhone;

	/*
	* Тестування видалення елементу з середини масиву.
	*/

	size = 3;
	phoneDatabase.setSize(size);

	testPhoneArray = new Phone[size];
	phoneDatabase.setPhoneArray(testPhoneArray);

	for (int i = 0; i < size; i++) {
		testPhoneArray[i].setPrice(i);
		testPhoneArray[i].setSimCardsNumber(i);
		testPhoneArray[i].setDisplay(i);
		testPhoneArray[i].setPermission(i);
		testPhoneArray[i].setCapacity(i);
	}

	index = 1;

	tmpTestPhone = new Phone;

	tmpTestPhone->setPrice(testPhoneArray[2].getPrice());
	tmpTestPhone->setSimCardsNumber(testPhoneArray[2].getSimCardsNumber());
	tmpTestPhone->setDisplay(testPhoneArray[2].getDisplay());
	tmpTestPhone->setPermission(testPhoneArray[2].getPermission());
	tmpTestPhone->setCapacity(testPhoneArray[2].getCapacity());

	phoneDatabase.removePhone(index);
	testPhoneArray = phoneDatabase.getPhoneArray();

	bool isRemoveFromMid;
	if (phoneComparison(*tmpTestPhone, testPhoneArray[1]) == true) {
		isRemoveFromMid = true;
	}
	else {
		isRemoveFromMid = false;
	}

	delete[] testPhoneArray;
	delete tmpTestPhone;

	/*
	* Тестування видалення елементу на початку масиву.
	*/

	size = 2;
	phoneDatabase.setSize(size);

	testPhoneArray = new Phone[size];
	phoneDatabase.setPhoneArray(testPhoneArray);

	for (int i = 0; i < size; i++) {
		testPhoneArray[i].setPrice(i);
		testPhoneArray[i].setSimCardsNumber(i);
		testPhoneArray[i].setDisplay(i);
		testPhoneArray[i].setPermission(i);
		testPhoneArray[i].setCapacity(i);
	}

	index = 0;

	tmpTestPhone = new Phone;

	tmpTestPhone->setPrice(testPhoneArray[1].getPrice());
	tmpTestPhone->setSimCardsNumber(testPhoneArray[1].getSimCardsNumber());
	tmpTestPhone->setDisplay(testPhoneArray[1].getDisplay());
	tmpTestPhone->setPermission(testPhoneArray[1].getPermission());
	tmpTestPhone->setCapacity(testPhoneArray[1].getCapacity());

	phoneDatabase.removePhone(index);
	testPhoneArray = phoneDatabase.getPhoneArray();

	bool isRemoveFromBegin;
	if (phoneComparison(*tmpTestPhone, testPhoneArray[0]) == true)
		isRemoveFromBegin = true;
	else
		isRemoveFromBegin = false;

	delete[] testPhoneArray;
	delete tmpTestPhone;

	/*
	* Кінечне визначення повертаємого значення функції.
	*/ 
	
	bool result;
	if (isRemoveFromMid == true || isRemoveFromBegin == true)
		result = true;
	else
		result = false;

	return result;
}