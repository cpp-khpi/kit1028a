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

void Library::addTextbook(int num, int pages, int grade, int cost, int year_of_release, char* author) {
	Textbook *tmp_backlist = new Textbook[size + 1];

	for (int i = 0; i < size; i++) {
		tmp_backlist[i] = Library::backlist[i];
	}

	size++;

	tmp_backlist[size - 1].setNum(num);
	tmp_backlist[size - 1].setPages(pages);
	tmp_backlist[size - 1].setGrade(grade);
	tmp_backlist[size - 1].setCost(cost);
	tmp_backlist[size - 1].setYearOfRelease(year_of_release);
	tmp_backlist[size - 1].setAuthor(author);

	backlist = tmp_backlist;
}

void Library::removeTextbook(const int num) {
	size--;
	Textbook *tmp_backlist = new Textbook[size];
	for (int i = 0; i < num; i++)
		tmp_backlist[i] = backlist[i];
	for (int i = num; i < size; i++) {
		tmp_backlist[i] = backlist[i + 1];
	}

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

void Library::getSurname(char** author) {
	backlist = new Textbook[size];
	for (int i = 0; i < size; i++) {
		backlist[i].setAuthor((*(author + i)));
	}
}

float Library::averageAmountOfPages(int pages) {
	float result = 0;
	for (int i = 0; i < size; i++) {
		result += backlist[i].getPages();
	}
	result = result / size;
	cout << "The average amount of pages is: " << result << endl;
	delete[]backlist;

	return result;
}