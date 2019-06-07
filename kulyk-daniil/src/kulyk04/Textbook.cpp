#include "Textbook.h"

Textbook::Textbook() :num(0), pages(0), grade(0), cost(0), year_of_release(0) {
	cout << "Here was constructor by default\n";
}
Textbook::Textbook(int num, int pages, int grade, int cost, int year_of_release) {
	cout << "The constructor with parameters worked here." << endl;
}
Textbook::Textbook(const Textbook &obj) :num(obj.num), pages(obj.pages), grade(obj.grade), cost(obj.cost), year_of_release(obj.year_of_release), author(obj.author) {
	cout << "The copy constructor worked here." << endl;
}

int Textbook::getNum()const { return this->num; }
int Textbook::getPages()const { return this->pages; }
int Textbook::getGrade()const { return this->grade; }
int Textbook::getCost()const { return this->cost; }
int Textbook::getYearOfRelease()const { return this->year_of_release; }
string Textbook::getAuthor() {
	string s;
	this->author = s;
	return s;
}


void Textbook::setInfo(int num, int pages, int grade, int cost, int year_of_release, string author) {
	this->num = num;
	this->pages = pages;
	this->grade = grade;
	this->cost = cost;
	this->year_of_release = year_of_release;
	this->author = author;
}

string Textbook::printInfo()const {
	stringstream show;
	show << "The textbook number is " << this->num << endl << "The number of pages is " << this->pages << endl
		<< "The grade this textbook for is " << this->grade << endl << "The price of this textbook is " << this->cost << endl <<
		"The textbook's year of release is " << this->year_of_release << endl << "The textbook's author is " << Textbook::author << endl << endl;
	string g = show.str();
	return g;
}
