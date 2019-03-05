#include "test.h"

void TestPhoneDatabase::generateArray()
{
	size = 4;
	phoneArray = new Phone[size];
	for (int i = 0; i < size; i++) {
		phoneArray[i].setCost(i);
		phoneArray[i].setNumberOfSim(i);
		phoneArray[i].setDisplay((float)i);
		phoneArray[i].setPermission(i);
		phoneArray[i].setCapacity(i);
	}

}

void TestPhoneDatabase::generateElem(Phone * tmpPhone)
{
	(*tmpPhone).setCost(3);
	(*tmpPhone).setNumberOfSim(3);
	(*tmpPhone).setDisplay(3);
	(*tmpPhone).setPermission(3);
	(*tmpPhone).setCapacity(3);
}

void TestPhoneDatabase::testAddPhone(Phone * addedPhone)
{
	addPhone(addedPhone);

	/*
	int cost = (phoneArray + 3)->getCost();
	int numberOfSim = (phoneArray + 3)->getNumberOfSim();
	float display = (phoneArray + 3)->getDisplay();
	int permission = (phoneArray + 3)->getPermission();
	int capacity = (phoneArray + 3)->getCapacity();

	if (cost == 3 && numberOfSim == 3 && display == 3 && permission == 3 && capacity == 3)
		cout << endl << "testAddPhone is done!" << endl;
	*/

}