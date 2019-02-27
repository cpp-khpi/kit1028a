#include "tests.h"

void Test::generateArray()
{
	size = 3;
	database = new Phone[size];
	for (int i = 0; i < size; i++) {
		(database + i)->setCost(i);
		(database + i)->setNumberOfSim(i);
		(database + i)->setDisplay(i);
		(database + i)->setPermission(i);
		(database + i)->setCapacity(i);
	}

}

void Test::generateElem(Phone * tmpPhone)
{
	(*tmpPhone).setCost(3);
	(*tmpPhone).setNumberOfSim(3);
	(*tmpPhone).setDisplay(3);
	(*tmpPhone).setPermission(3);
	(*tmpPhone).setCapacity(3);
}

void Test::testAddPhone(Phone * addedPhone)
{
	addPhone(addedPhone);

	if ((database + 3)->getCost() == 3)
		cout << endl << "testAddPhone is done!" << endl;
}