#include "PhoneArray.h"

size_t PhoneArray::getSize() const { return size; }

PhoneArray::PhoneArray() : size(0)
{
	data = nullptr;
}

PhoneArray::~PhoneArray() 
{
	if (data != nullptr) {
		for (int i = 0; i < size; i++)
			delete data[i];

		delete[] data;
		data = nullptr;
	}
}

Phone& PhoneArray::operator[] (const unsigned int index) 
{
	if (index >= size)
		throw MyException("Invalid index","overloaded operator[]");

	return **(data + index);
}

ostream& operator<<(ostream& out, const PhoneArray& outputPhoneArray)
{
	for (int i = 0; i < outputPhoneArray.size - 1; i++)
		out << outputPhoneArray.data[i] << endl;
	out << outputPhoneArray.data[outputPhoneArray.size - 1];

	return out;
}

void PhoneArray::setPhoneArrayInfo(size_t newSize, Phone** newPhoneArray)
{
	size = newSize;

	if (data != nullptr) {
		for (int i = 0; i < size; i++)
			delete data[i];

		delete[] data;
	}

	data = new Phone*[size];
	for (int i = 0; i < size; i++)
		data[i] = newPhoneArray[i];

	delete[] newPhoneArray;
	newPhoneArray = nullptr;
}

bool PhoneArray::comparisonPhoneArray(Phone** otherPhoneArr, size_t otherSize) const
{
	if (size != otherSize)
		return false;

	for (int i = 0; i < size; i++)
		if (**(data + i) != **(otherPhoneArr + i))
			return false;

	return true;
}

void PhoneArray::readFromFile(string fileName)
{
	ifstream fin(fileName);

	if (!fin)
		throw MyException("Can't open file for reading", "readFromFile");

	if (data != nullptr) {
		for (int i = 0; i < size; i++)
			delete data[i];

		delete[] data;
	}

	data = new Phone*[0];
	size = 0;


	Phone* newPhone;
	char phoneType;
	
	string checkedString;
	while (!fin.eof()) {
		phoneType = fin.get();
		switch (phoneType) {
		case'A': {
			newPhone = new AndroidPhone;
			fin >> newPhone;
			checkedString = newPhone->getTitle();
			/*if (!newPhone->isCorrectCheckRegex(checkedString))
				cout << "Incorrect string" << endl;*/
			addPhone(newPhone);
			break;
		}
		case'I': {
			newPhone = new IosPhone;
			fin >> newPhone;
			checkedString = newPhone->getTitle();
			/*if (!newPhone->isCorrectCheckRegex(checkedString))
				cout << "Incorrect string" << endl;*/
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

	if (!fout)
		throw MyException("Can't open file for writing", "writeToFile");

	fout << *this;

	fout.close();
}

void PhoneArray::addPhone(Phone* addedPhone)
{
	Phone ** newPhoneArr = new Phone*[size + 1];
	for (int i = 0; i < size; i++) {
		newPhoneArr[i] = data[i];
	}
	newPhoneArr[size] = addedPhone;

	size++;

	delete[] data;
	data = newPhoneArr;
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

void PhoneArray::removePhone(const unsigned int index)
{
	if (size == 0 )
		throw MyException("Array is empty", "removePhone");

	if (index >= size)
		throw MyException("Invalid index", "removePhone");


	Phone ** newArr = new Phone*[size - 1];
	for (int i = 0; i < index; i++) {
		newArr[i] = data[i];
	}

	delete data[index];

	for (int i = index; i < size - 1; i++) {
		newArr[i] = data[i + 1];
	}

	size--;

	delete[] data;
	data = newArr;
}

void PhoneArray::showAll() const
{
	if (size == 0) {
		cout << "The array is empty." << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		cout << endl << "Phone with index: " << i << endl;
		cout << **(data + i) << endl << endl;
	}
}

Phone* PhoneArray::getSmallestResolutPhone() const
{
	if (size == 0)
		throw MyException("Array is empty", "getSmallestResolutPhone");

	int smallestResInd = 0;
	unsigned int smallestResolut = data[0]->getResolution();
	for (int i = 1; i < size; i++) {
		if (data[i]->getResolution() < smallestResolut) {
			smallestResolut = data[i]->getResolution();
			smallestResInd = i;
		}
	}

	return data[smallestResInd];
}

void PhoneArray::sort(function<bool(Phone*, Phone*)> comparFunc)
{
	Phone* tmpPhome;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (comparFunc(data[j], data[j + 1])) {
				tmpPhome = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmpPhome;
			}
		}
	}
}

//Пока не нужен
//PhoneArray::PhoneArray(size_t newSize, Phone** newPhoneArray) : 
//	size(newSize)
//{
//	data = new Phone*[size];
//	
//	for (int i = 0; i < size; i++)
//		data[i] = newPhoneArray[i];
//}

//Пока не нужен
//PhoneArray::PhoneArray(const PhoneArray& copiedPhoneDatabase) :
//	size(copiedPhoneDatabase.size)
//{
//	delete[] data;
//	data = new Phone[size];
//
//	for (int i = 0; i < size; i++)
//		data[i] = copiedPhoneDatabase.data[i];
//}

//Пока не нужен
//void PhoneArray::setPhoneDatabaseInfo(size_t newSize, Phone* newPhoneArray)
//{
//	size = newSize;
//
//	delete[] data;
//	data = new Phone[size];
//
//	for (int i = 0; i < size; i++)
//		data[i] = newPhoneArray[i];
//}

//Пока не нужен
//bool PhoneArray::comparisonPhoneArray(const Phone* otherPhoneArr, size_t otherSize) const
//{
//	if (size != otherSize) {
//		return false;
//	}
//
//	for (int i = 0; i < size; i++) {
//		if (data[i] != otherPhoneArr[i]) {
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
//		if (regex_search(data[i].getTitle(), moreTwoWords)) {
//			cout << data[i].phoneToString() << endl;
//		}
//	}
//}