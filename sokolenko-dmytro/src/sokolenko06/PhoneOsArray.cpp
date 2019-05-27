#include "PhoneOsArray.h"

size_t PhoneOsArray::getSize() const { return size; }

const PhoneOs* PhoneOsArray::getPhoneOsArray() const { return phoneOsArray; }

PhoneOsArray::PhoneOsArray() : size(0)
{
	phoneOsArray = nullptr;
}

PhoneOsArray::PhoneOsArray(size_t newSize, PhoneOs* newPhoneOsArray) :
	size(newSize)
{
	delete[] phoneOsArray;
	phoneOsArray = new PhoneOs[size];

	for (int i = 0; i < size; i++)
		phoneOsArray[i] = newPhoneOsArray[i];
}

PhoneOsArray::PhoneOsArray(const PhoneOsArray& copiedPhoneOsArray) :
	size(copiedPhoneOsArray.size)
{
	delete[] phoneOsArray;
	phoneOsArray = new PhoneOs[size];

	for (int i = 0; i < size; i++)
		phoneOsArray[i] = copiedPhoneOsArray.phoneOsArray[i];
}

PhoneOsArray::~PhoneOsArray()
{
	if (phoneOsArray != nullptr) {
		delete[] phoneOsArray;
		phoneOsArray = nullptr;
	}
}

bool PhoneOsArray::isCorrectCheckRegex(string& checkString) const
{
	regex incorrectSymbols("[^\\w\\s.,;:\?!-\"()]*");
	regex repeatSymbols("(?<=([\s.,;:\?!-\"]))\1+");
	regex lowerCase("^[a-z]");

	if (!regex_search(checkString, incorrectSymbols) || !regex_search(checkString, repeatSymbols) || !regex_search(checkString, lowerCase))
		return true;
	else
		return 
false;
}

void PhoneOsArray::readFromConsole(PhoneOs& newPhoneOs) const
{
	string title;
	unsigned int price;
	unsigned int simCardsNumber;
	unsigned int resolution;
	unsigned int capacity;
	string osTitle;

	cout << endl << endl << "Enter information about phone." << endl;

	rewind(stdin);
	cout << "Phone title: ";
	getline(cin, title);

	if (!isCorrectCheckRegex(title))
		cout << "The string is NOT correct!" << endl;

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

	rewind(stdin);
	cout << "Phone OS title: ";
	getline(cin, osTitle);

	newPhoneOs.setPhoneOsInfo(title, price, simCardsNumber, resolution, capacity, osTitle);
}

void PhoneOsArray::readFromFile(string fileName)
{
	ifstream fin(fileName);

	if (!fin) {
		cout << "Error! File didn't open!" << endl;
		return;
	}

	if (phoneOsArray != nullptr) {
		delete[] phoneOsArray;
	}

	phoneOsArray = new PhoneOs[0];
	size = 0;

	PhoneOs newPhone;
	string phoneString;

	while (!fin.eof()) {
		getline(fin, phoneString);
		newPhone.stringToPhone(phoneString);
		addPhone(newPhone);
	}

	fin.close();
}

void PhoneOsArray::writeToFile(string fileName)
{
	ofstream fout(fileName);

	if (!fout) {
		cout << "Error! File didn't open!" << endl;
		return;
	}

	for (int i = 0; i < size - 1; i++) {
		fout << phoneOsArray[i].phoneToString() << endl;
	}
	fout << phoneOsArray[size - 1].phoneToString();


	fout.close();
}

void PhoneOsArray::addPhone(PhoneOs& addedPhone)
{
	PhoneOs * newPhoneOsArr = new PhoneOs[size + 1];
	for (int i = 0; i < size; i++) {
		newPhoneOsArr[i] = phoneOsArray[i];
	}

	size++;

	newPhoneOsArr[size - 1] = addedPhone;

	delete[] phoneOsArray;
	phoneOsArray = newPhoneOsArr;
}

int PhoneOsArray::inputIndex() const
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

void PhoneOsArray::removePhoneOs(const int index)
{
	if (size == 0 || index < 0) {
		cout << "ERROR! The array is empty, addind a new object isn't possible!" << endl;
		return;
	}

	PhoneOs * newArr = new PhoneOs[size - 1];
	for (int i = 0; i < index; i++) {
		newArr[i] = phoneOsArray[i];
	}

	size--;

	for (int i = index; i < size; i++) {
		newArr[i] = phoneOsArray[i + 1];
	}

	delete[] phoneOsArray;
	phoneOsArray = newArr;
}

PhoneOs& PhoneOsArray::getPhoneOs(const int index)
{
	if (size == 0 || index < 0) {
		cout << "ERROR! The array is empty, addind a new object isn't possible!" << endl;
	}

	return phoneOsArray[index];
}

void PhoneOsArray::showAll() const
{
	if (size == 0) {
		cout << "The array is empty." << endl;
	}

	for (int i = 0; i < size; i++) {
		cout << endl << "Phone with index: " << i << endl;
		cout << phoneOsArray[i].phoneToString() << endl;
	}
}