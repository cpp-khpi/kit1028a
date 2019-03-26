#include "phoneDatabase.h"

int PhoneDatabase::getSize() const { return size; }
void PhoneDatabase::setSize(int newSize) { size = newSize; }

Phone* PhoneDatabase::getPhoneArray() const { return phoneArray; }
void PhoneDatabase::setPhoneArray(Phone * newPhoneArray) { phoneArray = newPhoneArray; }

PhoneDatabase::PhoneDatabase() : size(1)
{
	phoneArray = new Phone[size];

	cout << "Default constructor! PhoneDatabase" << endl;
}

PhoneDatabase::PhoneDatabase(int newSize, Phone * newPhoneArray) : 
	size(newSize)
{
	delete[] phoneArray;
	phoneArray = new Phone[size];

	for (int i = 0; i < size; i++)
		phoneArray[i] = newPhoneArray[i];

	cout << "Constructor with param. PhoneDatabase" << endl;
}

PhoneDatabase::PhoneDatabase(const PhoneDatabase & copiedPhoneDatabase) :
	size(copiedPhoneDatabase.size)
{
	delete[] phoneArray;
	phoneArray = new Phone[size];

	for (int i = 0; i < size; i++)
		phoneArray[i] = copiedPhoneDatabase.phoneArray[i];

	cout << "Copy constructor. PhoneDatabase" << endl;
}

PhoneDatabase::~PhoneDatabase()
{
	delete[] phoneArray;
	phoneArray = nullptr;

	cout << "Destructor. PhoneDatabase" << endl;
}

bool PhoneDatabase::comparisonPhoneArray(const Phone* phoneArray1, const Phone* phoneArray2,
	int size1, int size2) const
{
	if (size1 != size2) {
		return false;
	}

	for (int i = 0; i < size1; i++) {
		if (phoneArray1[i] != phoneArray2[i]) {
			return false;
		}
	}

	return true;
}

int PhoneDatabase::inputSize()
{
	int size;
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

void PhoneDatabase::readPhone(Phone & newPhone) const
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
	cin.getline(title, TITLELEN);

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

	newPhone.setPhoneInfo(title, price, simCardsNumber, resolution, capacity);
}

void PhoneDatabase::addPhone(Phone & addedPhone)
{
	Phone * newPhoneArr = new Phone[size + 1];
	for (int i = 0; i < size; i++) {
		newPhoneArr[i] = phoneArray[i];
	}

	size++;

	newPhoneArr[size - 1] = addedPhone;

	delete[] phoneArray;
	phoneArray = newPhoneArr;
}

int PhoneDatabase::inputIndex() const
{
	int index;
	int maxTries = 2;
	int maxTriesLeft = maxTries;
	cout << endl << "Enter index of element that you want to remove.";
	cout << "You can choose from 0 to " << size - 1 << "." << endl;
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
	if (size == 0) {
		cout << "ERROR! The array is empty, addind a new object isn't possible!" << endl;
		return;
	}

	Phone * newArr = new Phone[size + 1];
	for (int i = 0; i < index; i++) {
		newArr[i] = phoneArray[i];
	}

	size--;

	for (int i = index; i < size; i++) {
		newArr[i] = phoneArray[i + 1];
	}

	delete[] phoneArray;
	phoneArray = newArr;
}

Phone& PhoneDatabase::getPhone(const int index)
{
	if (size == 0) {
		cout << "ERROR! The array is empty, addind a new object isn't possible!" << endl;
	}

	return phoneArray[index];
}

void PhoneDatabase::printPhone(Phone & printedPhone) const
{
	cout << "Phone title: " << printedPhone.getTitle() << endl;
	cout << "Cost, UAN: " << printedPhone.getPrice() << endl;
	cout << "Number of SIM-cards: " << printedPhone.getSimCardsNumber() << endl;
	cout << "Screen resolution, pixeles: " << printedPhone.getResolution() << endl;
	cout << "Batery capacity, mAh: " << printedPhone.getCapacity() << endl;
}

void PhoneDatabase::showAll() const
{
	if (size == 0) {
		cout << "The array is empty." << endl;
	}

	for (int i = 0; i < size; i++) {
		cout << endl << endl << "Phone with index: " << i << endl << endl;
		printPhone(phoneArray[i]);
	}
}

Phone& PhoneDatabase::getSmallestResolutPhone() const
{
	if (size == 0) {
		cout << "ERROR! The array is empty! You can't get element!";
	}

	int smallestResInd = 0;
	unsigned int smallestResolut = phoneArray[0].getResolution();
	for (int i = 1; i < size; i++) {
		if (phoneArray[i].getResolution() < smallestResolut) {
			smallestResolut = phoneArray[i].getResolution();
			smallestResInd = i;
		}
	}

	return phoneArray[smallestResInd];
}