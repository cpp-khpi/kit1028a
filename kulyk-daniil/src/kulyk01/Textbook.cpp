#include "Textbook.h"

Textbook::Textbook() :num(0), pages(0), grade(0), cost(0), year_of_release(0) {
	cout << "The constructor by default worked here" << endl;
}

Textbook::Textbook(int num, int pages, int grade, int cost, int year_of_release) :
	num(num), pages(pages), grade(grade), cost(cost), year_of_release(year_of_release) {
	this->num = num;
	this->pages = rand() % 100 + 180;
	this->grade = rand() % 11 + 1;
	this->cost = rand() % 120 + 200;
	this->year_of_release = rand() % 15 + 2000;
	cout << "The constructor with parameters worked here.\n";
}

Textbook::Textbook(const Textbook &obj) :pages(obj.pages), grade(obj.grade), cost(obj.cost), year_of_release(obj.year_of_release) {
	printf("The copy constructor worked here.\n");
}

void Textbook::setNum(int num) {
	this->num = num; 
}
int Textbook::getNum()const {
	return this->num;
}

void Textbook::setPages(int pages) {
	this->pages = rand() % 100 + 180;
}
int Textbook::getPages()const { 
	return this->pages; 
}

void Textbook::setGrade(int grade) {
	this->grade = rand() % 11 + 1;
}
int Textbook::getGrade()const {
	return this->grade;
}

void Textbook::setCost(int cost) {
	this->cost = rand() % 120 + 200;
}
int Textbook::getCost()const { 
	return this->cost; 
}

void Textbook::setYearOfRelease(int year_of_release) {
	this->year_of_release = rand() % 15 + 2000;
}
int Textbook::getYearOfRelease()const { 
	return this->year_of_release; 
}

void Textbook::printInfo()const {
	cout << "The textbook number is " << this->num << endl << "The number of pages is " << this->pages << endl
		<< "The grade this textbook for is " << this->grade << endl << "The price of this textbook is " << this->cost << endl << 
		"The textbook's year of release is " << this->year_of_release << endl << endl;
}