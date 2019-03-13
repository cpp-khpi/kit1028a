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

void PhoneDatabase::readPhone(Phone & tmpPhone) const
{
	const int TITLELEN = 50;

	char * title = new char[TITLELEN];
	unsigned int price;
	unsigned int simCardsNumber;
	unsigned int resolution;
	unsigned int capacity;

	cout << endl << endl << "Enter information about phone." << endl;

	rewind(stdin);
	cout << "Phone title: ";
	fgets(title, TITLELEN, stdin);

	rewind(stdin);
	cout << "Cost, UAN: ";
	cin >> price;

	rewind(stdin);
	cout << "Number of SIM-cards: ";
	cin >> simCardsNumber;

	rewind(stdin);
	cout << "Screen resolution, pixeles: ";
	cin >> resolution;

	rewind(stdin);
	cout << "Batery capacity, mAh: ";
	cin >> capacity;

	tmpPhone.setData(title, price, simCardsNumber, resolution, capacity);
}

void PhoneDatabase::createArray(int size)
{
	phoneArray = new Phone[size];
	for (int i = 0; i < size; i++) {
		readPhone(phoneArray[i]);
	}
}

void PhoneDatabase::addPhone(Phone & addedPhone)
{
	Phone * newPhoneArr = new Phone[size + 1];
	for (int i = 0; i < size; i++) {
		newPhoneArr[i].setPrice(phoneArray[i].getPrice());
		newPhoneArr[i].setSimCardsNumber(phoneArray[i].getSimCardsNumber());
		newPhoneArr[i].setResolution(phoneArray[i].getResolution());
		newPhoneArr[i].setCapacity(phoneArray[i].getCapacity());
	}

	newPhoneArr[size].setPrice(addedPhone.getPrice());
	newPhoneArr[size].setSimCardsNumber(addedPhone.getSimCardsNumber());
	newPhoneArr[size].setResolution(addedPhone.getResolution());
	newPhoneArr[size].setCapacity(addedPhone.getCapacity());

	size++;

	delete[] phoneArray;
	phoneArray = newPhoneArr;
}

int PhoneDatabase::inputIndex() const
{
	int index;
	int maxTries = 2;
	int maxTriesLeft = maxTries;
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
		newArr[i].setPrice(phoneArray[i].getPrice());
		newArr[i].setSimCardsNumber(phoneArray[i].getSimCardsNumber());
		newArr[i].setResolution(phoneArray[i].getResolution());
		newArr[i].setCapacity(phoneArray[i].getCapacity());
	}

	size--;

	for (int i = index; i < size; i++) {
		newArr[i].setPrice(phoneArray[i + 1].getPrice());
		newArr[i].setSimCardsNumber(phoneArray[i + 1].getSimCardsNumber());
		newArr[i].setResolution(phoneArray[i + 1].getResolution());
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
	cout << "Cost, UAN: " << tmpPhone->getPrice() << endl;
	cout << "Number of SIM-cards: " << tmpPhone->getSimCardsNumber() << endl;
	cout << "Screen resolution, pixeles: " << tmpPhone->getResolution() << endl;
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