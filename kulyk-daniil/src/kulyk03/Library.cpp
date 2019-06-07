#pragma once
#include "Library.h"
using std::ifstream;

Library::Library(int size) : size(size), new_textbook(), backlist(0) {
	backlist = new Textbook[size];
		string str;
		ifstream fin("C:\\kulyk-daniil\\src\\kulyk02\\kulyk02\\Authors.txt");
		stringstream s1;
	
			for (int i = 0; i < size; i++) {
				fin >> str;
				backlist[i].setInfo(i + 1, rand() % 100 + 180, rand() % 11 + 1, rand() % 100 + 220, rand() % 15 + 2000, str);
			}
			fin >> str;
			new_textbook.setInfo(size + 1, rand() % 100 + 180, rand() % 11 + 1, rand() % 100 + 220, rand() % 15 + 2000, str);
	
			fin.close();
	}

Library::~Library() {
	delete backlist;
	cout << endl << "Memory cleanup successful!" << endl;
}

void Library::setNewTextbook() {
	string s1;
	cout << "Enter the textbook's author: ";
	cin >> s1;

	int pages, grade, cost, year_of_release;
	int i = 4;
	while (i > 3) {
		cout << "Enter the number of textbook pages (100-400): ";
		cin >> pages;
		if (pages < 100 || pages > 400) {
			cout << "You've entered an invalid value, try again" << endl;
		}
		else { i = 3; }
		i = 3;
	}
	while (i > 2) {
		cout << "Enter the grade this textbook for (1-11): ";
		cin >> grade;
		if (pages < 1 || pages > 11) {
			cout << "You entered an invalid value, try again" << endl;
		}
		else { i = 2; }
		i = 2;
	}
	while (i > 1) {
		cout << "Enter the cost of this textbook (100 - 400): ";
		cin >> cost;
		if (cost < 100 || cost > 400) {
			cout << "You entered an invalid value, try again" << endl;
		}
		else { i = 1; }
		i = 1;
	}
	while (i > 0) {
		cout << "Enter the yar of release of this textbook (2000-2019): ";
		cin >> year_of_release;
		if (year_of_release < 2000 || year_of_release > 2019) {
			cout << "You entered an invalid value, try again" << endl;
		}
		else { i = 0; }
		i = 0;
	}

	new_textbook.setInfo(size + 1, pages, grade, cost, year_of_release, s1);
}
int Library::getSize() { return this->size; }

float Library::averageAmountOfPages (int num) {
	float result = 0;
	for (int i = 0; i < size; i++) {
		result += backlist[i].getPages();
	}
	result = result / size;
	cout << "The average amount of pages is: " << result << endl;
	delete[]backlist;

	return result;
}

void Library::addTextbook(const int num) {
	size++;
	Textbook *tmp_backlist = new Textbook[size];
	for (int i = 0; i < num - 1; i++)
		tmp_backlist[i] = backlist[i];
	tmp_backlist[num - 1] = new_textbook;
	for (int i = num; i < size; i++)
		tmp_backlist[i] = backlist[i - 1];

	delete[]backlist;
	backlist = tmp_backlist;

}
void Library::removeTextbook(const int num) {
	size--;
	Textbook *tmp_backlist = new Textbook[size];
	for (int i = 0; i < num; i++)
		tmp_backlist[i] = backlist[i];
	for (int i = num; i < size; i++)
		tmp_backlist[i] = backlist[i + 1];

	delete[]backlist;
	backlist = tmp_backlist;

}


void Library::getRequiredTextbook(const int num)const {
	cout << backlist[num].printInfo();
}
void Library::getNewTextbook() {
	Textbook new_textbook_tmp = new_textbook;
	cout << new_textbook_tmp.printInfo();
}
void Library::printAll()const {
	cout << "Current student journal: " << endl << endl;
	for (int i = 0; i < size; i++)
		cout << backlist[i].printInfo();
}

