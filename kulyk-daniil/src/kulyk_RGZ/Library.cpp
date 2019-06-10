#include "Library.h"
#include "Algebra.h"
#include "English.h"
#include "Exception.h"

Library::Library() : size(0) {
	arr = nullptr;
}
ostream& operator<< (ostream &out, const Library &obj) {
	out << obj.size << endl;
	for (int i = 0; i < obj.size; i++) {
		out << obj.arr[i];
	}
	return out;
}
istream& operator>> (istream &in, Library &obj) {
	in >> obj.size;
	for (int i = 0; i < obj.size; i++) {
		in >> obj.arr[i];
	}
	return in;
}
Library::~Library() {
	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	delete[] arr;
}
void Library::setSize(int size) {
	Library::size = size;
}
void Library::readFromFile(int new_size) {
	srand(time(NULL));
	string *person = new string[new_size];
	regex regex_upperRegister("^[A-Z]");
	regex regex_space("[\\s]{2,}");
	ifstream fin;
	fin.open("Textbook authors.txt");
	if (!fin) {
		throw Exception("Can't open file for reading", "readFromFile");
	}
	Textbook* new_textbook;
	int choice;
	for (int i = 0; i < new_size; i++) {
		getline(fin, person[i]);
		if (!(regex_search(person[i], regex_upperRegister)) || regex_search(person[i], regex_space)) {
			cout << "Incorrect entry, writing with large letters(A - Z): " << person[i] << endl;
			cin.ignore();
			getline(cin, person[i]);
		}
		choice = rand() % 2;
		switch (choice) {
		case 0:
			new_textbook = new Algebra;
			new_textbook->generateData(person[i]);
			addTextbook(new_textbook);
			break;
		case 1:
			new_textbook = new English;
			new_textbook->generateData(person[i]);
			addTextbook(new_textbook);
			break;
		}
	}

	delete[] person;
	fin.close();
}
void Library::printAll() {
	for (int i = 0; i < size; i++) {
		arr[i]->output();
	}
}
void Library::addTextbook(Textbook* new_textbook) {

	Textbook **mas = new Textbook*[size + 1];

	for (int i = 0; i < size; i++) {
		mas[i] = arr[i];
	}

	size++;

	mas[size - 1] = new_textbook;

	delete[] arr;
	arr = mas;
}
void Library::deleteTextbook(int ind) {
	if (size < 2) {
		throw Exception("You can't delete last element.", "deleteTextbook");
	}
	if (ind - 1 >= size) {
		throw Exception("You can't enter the index more then the size of array.", "deleteTextbook");
	}

	size--;
		Textbook** mas = new Textbook*[size];

	int j = 0;
	for (int i = 0; i < ind - 1; i++) {
		mas[i] = arr[j];
		j++;
	}
	j++;
	for (int i = ind - 1; i < size; i++) {
		mas[i] = arr[j];
		j++;
	}
	delete arr[ind - 1];
	delete[]arr;
	arr = mas;
}
void Library::getByIndex(int index) {
	if (index - 1 >= size) {
		throw Exception("The index cannot be larger than the array size.", "getByIndex");
	}
	cout << endl;
	arr[index - 1]->output();
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl << endl;
}
void Library::writeToFile() {
	ofstream fout;
	fout.open("Textbook array.txt");
	for (int i = 0; i < size; i++) {
		arr[i]->outputToFile(fout);
	}
	fout.close();
}
void Library::searchBySurname(string search_surname) {
	for (int i = 0; i < size; i++) {
		if (search_surname == arr[i]->getAuthor()) {
			cout << endl;
			arr[i]->output();
			cout << "--------------------------------------------------------------------------------" << endl;
		}
	}
}
void Library::sortByPages(bool(*sort)(int a, int b)) {
	Textbook *temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sort(arr[i]->getPages(), arr[j]->getPages())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void Library::sortByGrade(bool(*sort)(int a, int b)) {
	Textbook *temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sort(arr[i]->getGrade(), arr[j]->getGrade())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void Library::sortByCost(bool(*sort)(int a, int b)) {
	Textbook *temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sort(arr[i]->getCost(), arr[j]->getCost())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}