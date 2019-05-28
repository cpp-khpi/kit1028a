#include "PhoneArray.h"

size_t PhoneArray::getSize() const { return size; }

Phone** PhoneArray::getPhoneArray() const { return phoneArray; }

PhoneArray::PhoneArray() : size(0)
{
	phoneArray = nullptr;
}

PhoneArray::~PhoneArray() 
{
	if (phoneArray != nullptr) {
		for (int i = 0; i < size; i++)
			delete phoneArray[i];

		delete[] phoneArray;
		phoneArray = nullptr;
	}
}

bool PhoneArray::isCorrectCheckRegex(string& checkString) const
{
	regex incorrectSymbols("[^\\w\\s.,;:\?!-\"()]*");
	regex repeatSymbols("(?<=([\s.,;:\?!-\"]))\1+");
	regex lowerCase("^[a-z]");

	if (!regex_search(checkString, incorrectSymbols) || !regex_search(checkString, repeatSymbols) || !regex_search(checkString, lowerCase))
		return true;
	else
		return false;
}

void PhoneArray::readFromFile(string fileName)
{
	ifstream fin(fileName);

	if (!fin) {
		cout << "Error! File didn't open!" << endl;
		return;
	}

	//Need I clear each element of array here? Ye
	if (phoneArray != nullptr) {
		for (int i = 0; i < size; i++)
			delete phoneArray[i];

		delete[] phoneArray;
	}

	phoneArray = new Phone*[0];
	size = 0;


	string phoneString;
	Phone* newPhone;
	
	while (!fin.eof()) {
		getline(fin, phoneString);

		switch (phoneString[0]) {
		case'A': {
			newPhone = new AndroidPhone;
			newPhone->stringToPhone(phoneString);
			addPhone(newPhone);
			break;
		}
		case'I': {
			newPhone = new IosPhone;
			newPhone->stringToPhone(phoneString);
			addPhone(newPhone);
			break;
		}
		}
	}

	fin.close();
}

void PhoneArray::writeToFile(string fileName)
{
	ofstream fout(fileName);

	if (!fout) {
		cout << "Error! File didn't open!" << endl;
		return;
	}

	for (int i = 0; i < size - 1; i++) {
		fout << phoneArray[i]->phoneToString() << endl;
	}
	fout << phoneArray[size - 1]->phoneToString();


	fout.close();
}

void PhoneArray::addPhone(Phone* addedPhone)
{
	Phone ** newPhoneArr = new Phone*[size + 1];
	for (int i = 0; i < size; i++) {
		newPhoneArr[i] = phoneArray[i];
	}
	newPhoneArr[size] = addedPhone;

	size++;

	delete[] phoneArray;
	phoneArray = newPhoneArr;
}

int PhoneArray::inputIndex() const
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

void PhoneArray::removePhone(unsigned int index)
{
	if (size == 0 ) {
		cout << "ERROR! The array is empty, removing an object isn't possible!" << endl;
		return;
	}

	Phone ** newArr = new Phone*[size - 1];
	for (int i = 0; i < index; i++) {
		newArr[i] = phoneArray[i];
	}

	delete phoneArray[index];

	for (int i = index; i < size - 1; i++) {
		newArr[i] = phoneArray[i + 1];
	}

	size--;

	delete[] phoneArray;
	phoneArray = newArr;
}

Phone* PhoneArray::getPhone(unsigned int index)
{
	if (size == 0) {
		cout << "ERROR! The array is empty, addind a new object isn't possible!" << endl;
	}

	return phoneArray[index];
}

void PhoneArray::showAll() const
{
	if (size == 0) {
		cout << "ERROR! The array is empty." << endl;
	}

	for (int i = 0; i < size; i++) {
		cout << endl << "Phone with index: " << i << endl;
		cout << phoneArray[i]->phoneToString() << endl;
	}
}

Phone* PhoneArray::getSmallestResolutPhone() const
{
	if (size == 0) {
		cout << "ERROR! The array is empty! You can't get element!";
	}

	int smallestResInd = 0;
	unsigned int smallestResolut = phoneArray[0]->getResolution();
	for (int i = 1; i < size; i++) {
		if (phoneArray[i]->getResolution() < smallestResolut) {
			smallestResolut = phoneArray[i]->getResolution();
			smallestResInd = i;
		}
	}

	return phoneArray[smallestResInd];
}

void PhoneArray::sort(function<bool(Phone*, Phone*)> comparFunc)
{
	Phone* tmpPhome;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (comparFunc(phoneArray[j], phoneArray[j + 1])) {
				tmpPhome = phoneArray[j];
				phoneArray[j] = phoneArray[j + 1];
				phoneArray[j + 1] = tmpPhome;
			}
		}
	}
}

//Пока не нужен
//PhoneArray::PhoneArray(size_t newSize, Phone** newPhoneArray) : 
//	size(newSize)
//{
//	phoneArray = new Phone*[size];
//	
//	for (int i = 0; i < size; i++)
//		phoneArray[i] = newPhoneArray[i];
//}

//Пока не нужен
//PhoneArray::PhoneArray(const PhoneArray& copiedPhoneDatabase) :
//	size(copiedPhoneDatabase.size)
//{
//	delete[] phoneArray;
//	phoneArray = new Phone[size];
//
//	for (int i = 0; i < size; i++)
//		phoneArray[i] = copiedPhoneDatabase.phoneArray[i];
//}

//Пока не нужен
//void PhoneArray::setPhoneDatabaseInfo(size_t newSize, Phone* newPhoneArray)
//{
//	size = newSize;
//
//	delete[] phoneArray;
//	phoneArray = new Phone[size];
//
//	for (int i = 0; i < size; i++)
//		phoneArray[i] = newPhoneArray[i];
//}

//Пока не нужен
//bool PhoneArray::comparisonPhoneArray(const Phone* otherPhoneArr, size_t otherSize) const
//{
//	if (size != otherSize) {
//		return false;
//	}
//
//	for (int i = 0; i < size; i++) {
//		if (phoneArray[i] != otherPhoneArr[i]) {
//			return false;
//		}
//	}
//
//	return true;
//}

//Пока не нужен
//void PhoneArray::printPhonesMoreTwoWords() const
//{
//	regex moreTwoWords("([\\w]+[\\s.,;-]+){1}[\\w]+");
//
//	cout << endl << "Phones with two or more words in the title:" << endl << endl;
//	for (int i = 0; i < size; i++) {
//		if (regex_search(phoneArray[i].getTitle(), moreTwoWords)) {
//			cout << phoneArray[i].phoneToString() << endl;
//		}
//	}
//}