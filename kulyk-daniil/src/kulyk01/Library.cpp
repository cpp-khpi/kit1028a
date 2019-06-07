#pragma once
#include "Library.h"

Library::Library(int size) : size(size), backlist(0), new_textbook() {
	backlist = new Textbook[size];
	for (int i = 0; i < size; i++) {
		backlist[i].setNum(i + 1);
		backlist[i].setPages(rand() % 100 + 180);
		backlist[i].setGrade(rand() % 11 + 1);
		backlist[i].setCost(rand() % 120 + 200);
		backlist[i].setYearOfRelease(rand() % 15 + 2000);
	}
}

Library::~Library() {
	delete[]backlist;
	cout << endl << "Memory cleanup successful!";
}

int Library::getSize() { 
	return this->size; 
}

void Library::getNewTextbook() {
	Textbook new_textbook_tmp = new_textbook;
	new_textbook_tmp.printInfo();
}

void Library::addTextbook(Textbook & obj) {
	Textbook * tmp_backlist = new Textbook[size + 1];
	for (int i = 0; i < size; i++) {
		tmp_backlist[i].setNum(backlist[i].getNum());
		tmp_backlist[i].setPages(backlist[i].getPages());
		tmp_backlist[i].setGrade(backlist[i].getGrade());
		tmp_backlist[i].setCost(backlist[i].getCost());
		tmp_backlist[i].setYearOfRelease(backlist[i].getYearOfRelease());
	}

	tmp_backlist[size].setNum(obj.getNum());
	tmp_backlist[size].setPages(obj.getPages());
	tmp_backlist[size].setGrade(obj.getGrade());
	tmp_backlist[size].setCost(obj.getCost());
	tmp_backlist[size].setYearOfRelease(obj.getYearOfRelease());

	size++;

	delete[] backlist;
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
	backlist[num].printInfo();
}

void Library::printAll()const {
	cout << "Current libraries journal: " << endl << endl;
	for (int i = 0; i < size; i++)
		backlist[i].printInfo();
}
