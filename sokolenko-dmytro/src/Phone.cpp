#include "Phone.h"

void Processing::inputSize()
{
	int maxTries = 3;
	int maxTriesLeft = maxTries;
	rewind(stdin);
	cout << "Enter size of array!" << endl;
	for (int i = 0; i < maxTries; i++) {
		cout << "Size: ";
		cin >> size;
		if (size <= 0) {
			maxTriesLeft--;
			cout << "Incorrect size. Enter it again." << endl;
			cout << "You have " << maxTriesLeft << " attempts left." << endl << endl;
			if (maxTriesLeft == 0) {
				cout << "You have no attempts left. ERROR!" << endl;
				cout << "Press any key to exit.";
				system("color C");
				cin.get();
				cin.get();
				exit(1);
			}
		}
		else {
			break;
		}
	}
}

void Processing::readPhone(Phone * tmpPhone) const
{
	unsigned int cost;
	unsigned int numberOfSim;
	float display;
	unsigned int permission;
	unsigned int capacity;

	cout << endl << endl << "Enter information about phone." << endl;

	rewind(stdin);
	cout << endl << "Cost, UAN: ";
	cin >> cost;
	(*tmpPhone).setCost(cost);

	rewind(stdin);
	cout << "Number of SIM-cards: ";
	cin >> numberOfSim;
	(*tmpPhone).setNumberOfSim(numberOfSim);

	rewind(stdin);
	cout << "Display: ";
	cin >> display;
	(*tmpPhone).setDisplay(display);

	rewind(stdin);
	cout << "Camera permission: ";
	cin >> permission;
	(*tmpPhone).setPermission(permission);

	rewind(stdin);
	cout << "Batery capacity, mAh: ";
	cin >> capacity;
	(*tmpPhone).setCapacity(capacity);
}


void Processing::createArray()
{
	database = new Phone[size];
	for (int i = 0; i < size; i++) {
		readPhone(database + i);
	}
}


void Processing::addPhone(Phone * addedPhone)
{
	Phone * newArr = new Phone[size + 1];
	for (int i = 0; i < size; i++) {
		(newArr + i)->setCost((database + i)->getCost());
		(newArr + i)->setNumberOfSim((database + i)->getNumberOfSim());
		(newArr + i)->setDisplay((database + i)->getDisplay());
		(newArr + i)->setPermission((database + i)->getPermission());
		(newArr + i)->setCapacity((database + i)->getCapacity());
	}

	(newArr + size)->setCost(addedPhone->getCost());
	(newArr + size)->setNumberOfSim((addedPhone)->getNumberOfSim());
	(newArr + size)->setDisplay((addedPhone)->getDisplay());
	(newArr + size)->setPermission((addedPhone)->getPermission());
	(newArr + size)->setCapacity((addedPhone)->getCapacity());

	size++;

	delete[] database;
	database = newArr;
	newArr = nullptr;
}

int Processing::inputIndex() const
{
	int index;
	int maxTries = 2;
	int maxTriesLeft = maxTries;
	rewind(stdin);
	cout << endl << "Enter index of element that you want to remove. You can choose from 0 to " << size - 1 << "." << endl;
	cout << "(If you choose larger value, the last index will be selected)." << endl << endl;
	for (int i = 0; i < maxTries; i++) {
		rewind(stdin);
		cout << "Index: ";
		cin >> index;
		if (index < 0) {
			maxTriesLeft--;
			cout << "Incorrect index. Enter it again." << endl;
			cout << "You have " << maxTriesLeft << " attempts left." << endl << endl;
			if (maxTriesLeft == 0) {
				cout << "You have no attempts left. ERROR!" << endl;
				cout << "Press any key to exit.";
				system("color C");
				cin.get();
				cin.get();
				exit(1);
			}
		}
		else {
			break;
		}
	}

	if (index >= size) {
		index = size - 1;
	}

	return index;
}

void Processing::removePhone(const int index)
{
	Phone * newArr = new Phone[size + 1];
	for (int i = 0; i < index; i++) {
		(newArr + i)->setCost((database + i)->getCost());
		(newArr + i)->setNumberOfSim((database + i)->getNumberOfSim());
		(newArr + i)->setDisplay((database + i)->getDisplay());
		(newArr + i)->setPermission((database + i)->getPermission());
		(newArr + i)->setCapacity((database + i)->getCapacity());
	}

	size--;

	for (int i = index; i < size; i++) {
		(newArr + i)->setCost((database + i + 1)->getCost());
		(newArr + i)->setNumberOfSim((database + i + 1)->getNumberOfSim());
		(newArr + i)->setDisplay((database + i + 1)->getDisplay());
		(newArr + i)->setPermission((database + i + 1)->getPermission());
		(newArr + i)->setCapacity((database + i + 1)->getCapacity());
	}

	delete[] database;
	database = newArr;
	newArr = 0;

	cout << "Done! Element with index " << index << " is removed!" << endl;
}

void Processing::getPhone(const int index) const
{
	cout << endl << endl << "Phone with index: " << index << endl << endl;
	cout << "Cost, UAN: " << (database + index)->getCost() << endl;
	cout << "Number of SIM-cards: " << (database + index)->getNumberOfSim() << endl;
	cout << "Display: " << (database + index)->getDisplay() << endl;
	cout << "Camera permission: " << (database + index)->getPermission() << endl;
	cout << "Batery capacity, mAh: " << (database + index)->getCapacity() << endl;
}

void Processing::showAll() const
{
	for (int i = 0; i < size; i++)
		getPhone(i);
}

void Processing::deleteArray()
{
	delete[] database;
}