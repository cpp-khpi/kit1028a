/**
* @file Controler.cpp
* Implementation of all functions of Controler class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/

#include "InfoWork.h"
#include "CourseWork.h"
#include "DetailInfo.h"
#include "Controler.h"
#include "Exception.h"

void Controler::setArray(size_t newSize, InfoWork **newArray)
{
	size = newSize;

	if (qual != nullptr) {
		for (int i = 0; i < size; i++)
			delete qual[i];

		delete[] qual;
	}

	qual = new InfoWork*[size];
	for (int i = 0; i < size; i++)
		qual[i] = newArray[i];

	delete[] newArray;
	newArray = nullptr;
}

bool Controler::comparisonArray(InfoWork **ArrayToTest, size_t otherSize) const
{
	if (size != otherSize)
		return false;

	for (int i = 0; i < size; i++)
		if (**(qual + i) != **(ArrayToTest + i))
			return false;

	return true;
}

float Controler::rate() {
	float counter = 0;
	for (int i = 0; i < size; i++) {
		int type = qual[i]->getType();
		if (type == 2) {
			counter++;
		}
	}
	counter = counter * 100 / this->size;
	return counter;
}

Controler::Controler() : size(0) {
	qual = nullptr;
}
Controler::~Controler() {
	for (int i = 0; i < size; i++) {
		delete qual[i];
	}
	delete[] qual;
}
void Controler::setSize(int size) {
	Controler::size = size;
}
void Controler::readFromFile(int newSize,string fName) {
	srand(time(NULL));
	string *names = new string[newSize];
	regex regex_repeat("^[a-z].*|.*\\s{2,}.*");
	ifstream fin;
	fin.open(fName);
	if (!fin.is_open()) {
		throw Exception(" Wrong address", __FILE__, __LINE__, __FUNCTION__);
	}

	InfoWork* array;
	int choice;
	int k =0;
	while(k < newSize) {
		getline(fin, names[k]);
		if (regex_search(names[k], regex_repeat)){
			cout << "Incorrect entry, writing with upper case: " << names[k] << std::endl;
			cin.ignore();
			getline(cin, names[k]);
		}
		choice = rand() % 2;
		switch (choice) {
		case 0:
			array = new CourseWork;
			array->set(names[k]);
			addElem(array);
			break;
		case 1:
			array = new DetailInfo;
			array->set(names[k]);
			addElem(array);
			break;
		}
		k++;
	}

	delete[] names;
	fin.close();
}
void Controler::print() {
	for (int i = 0; i < size; i++) {
		qual[i]->output();
	}
}
void Controler::addElem(InfoWork* new_work) {

	InfoWork **mas = new InfoWork*[size + 1];

	for (int i = 0; i < size; i++) {
		mas[i] = qual[i];
	}
	size++;

	mas[size - 1] = new_work;

	delete[] qual;
	qual = mas;
}
void Controler::delElem(int index) {

	if (index < 0 || index > size) {
		throw Exception(" Wrong index", __FILE__, __LINE__, __FUNCTION__);
	}

	size--;
	InfoWork** mas = new InfoWork*[size];

	int j = 0;
	for (int i = 0; i < index - 1; i++) {
		mas[i] = qual[j];
		j++;
	}
	j++;
	for (int i = index - 1; i < size; i++) {
		mas[i] = qual[j];
		j++;
	}
	delete qual[index - 1];
	delete[]qual;
	qual = mas;
}
void Controler::geByIndex(int index) {

	if (index < 0 || index > size) {
		throw Exception(" Wrong index", __FILE__, __LINE__, __FUNCTION__);
	}

	cout << endl;
	cout << "Searched element: ";
	qual[index - 1]->output();
	cout << endl << endl;
}
void Controler::writeToFile(string fName) {
	std::ofstream fout;
	fout.open(fName);
	if (!fout.is_open()) {
		throw Exception(" Wrong address", __FILE__, __LINE__, __FUNCTION__);
	}
	for (int i = 0; i < size; i++) {
		qual[i]->output_to_file(fout);
	}
	fout.close();
}
void Controler::sortByMark() {
	ForClass obj;
	InfoWork* temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (obj(qual[i]->getMark(), qual[j]->getMark())) {
				temp = qual[i];
				qual[i] = qual[j];
				qual[j] = temp;
			}
		}
	}
}

void Controler::sortBySize() {
	ForClass obj;
	InfoWork* temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (obj(qual[i]->getPages(), qual[j]->getPages())) {
				temp = qual[i];
				qual[i] = qual[j];
				qual[j] = temp;
			}
		}
	}
}

void Controler::sortByType() {
	ForClass obj;
	InfoWork* temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (obj(qual[i]->getType(), qual[j]->getType())) {
				temp = qual[i];
				qual[i] = qual[j];
				qual[j] = temp;
			}
		}
	}
}