#include "phoneDatabase.h"

int PhoneDatabase::getSize() { return size; }
void PhoneDatabase::setSize(unsigned int newSize) { size = newSize; }

Phone* PhoneDatabase::getPhoneArray() { return phoneArray; }
void PhoneDatabase::setPhoneArray(Phone * newPhoneArray) { phoneArray = newPhoneArray; }

int PhoneDatabase::inputSize()
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

	return size;
}

void PhoneDatabase::readPhone(Phone * tmpPhone) const
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


void PhoneDatabase::createArray(int size)
{
	phoneArray = new Phone[size];
	for (int i = 0; i < size; i++) {
		readPhone(phoneArray + i);
	}
}


void PhoneDatabase::addPhone(Phone * addedPhone)
{
	Phone * newArr = new Phone[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i].setCost(phoneArray[i].getCost());
		newArr[i].setNumberOfSim(phoneArray[i].getNumberOfSim());
		newArr[i].setDisplay(phoneArray[i].getDisplay());
		newArr[i].setPermission(phoneArray[i].getPermission());
		newArr[i].setCapacity(phoneArray[i].getCapacity());
	}

	newArr[size].setCost(addedPhone->getCost());
	newArr[size].setNumberOfSim(addedPhone->getNumberOfSim());
	newArr[size].setDisplay(addedPhone->getDisplay());
	newArr[size].setPermission(addedPhone->getPermission());
	newArr[size].setCapacity(addedPhone->getCapacity());

	size++;

	delete[] phoneArray;
	phoneArray = newArr;
}

int PhoneDatabase::inputIndex() const
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

void PhoneDatabase::removePhone(const int index)
{
	Phone * newArr = new Phone[size + 1];
	for (int i = 0; i < index; i++) {
		newArr[i].setCost(phoneArray[i].getCost());
		newArr[i].setNumberOfSim(phoneArray[i].getNumberOfSim());
		newArr[i].setDisplay(phoneArray[i].getDisplay());
		newArr[i].setPermission(phoneArray[i].getPermission());
		newArr[i].setCapacity(phoneArray[i].getCapacity());
	}

	size--;

	for (int i = index; i < size; i++) {
		newArr[i].setCost(phoneArray[i + 1].getCost());
		newArr[i].setNumberOfSim(phoneArray[i + 1].getNumberOfSim());
		newArr[i].setDisplay(phoneArray[i + 1].getDisplay());
		newArr[i].setPermission(phoneArray[i + 1].getPermission());
		newArr[i].setCapacity(phoneArray[i + 1].getCapacity());
	}

	delete[] phoneArray;
	phoneArray = newArr;
}

Phone& PhoneDatabase::getPhone(const int index)
{
	return phoneArray[index];
}

void PhoneDatabase::printPhone(Phone * tmpPhone) const
{
	cout << "Cost, UAN: " << tmpPhone->getCost() << endl;
	cout << "Number of SIM-cards: " << tmpPhone->getNumberOfSim() << endl;
	cout << "Display: " << tmpPhone->getDisplay() << endl;
	cout << "Camera permission: " << tmpPhone->getPermission() << endl;
	cout << "Batery capacity, mAh: " << tmpPhone->getCapacity() << endl;
}

void PhoneDatabase::showAll() const
{
	for (int i = 0; i < size; i++) {
		cout << endl << endl << "Phone with index: " << i << endl << endl;
		printPhone(&phoneArray[i]);
	}
}

void PhoneDatabase::deleteArray()
{
	delete[] phoneArray;
}