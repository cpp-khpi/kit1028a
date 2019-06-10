/**
* @file EconomicTI.cpp
* File assignment				| Ñlass methods
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/
#include "EconomicTI.h"

EconomicTI& EconomicTI::operator = (const EconomicTI& o) {
	this->num = o.num;
	this->works = o.works;
	this->pages = o.pages;
	this->mark = o.mark;
	this->surname = o.surname;
	this->statistics = o.statistics;
	this->formuls = o.formuls;

	return *this;
}
bool EconomicTI::operator == (const EconomicTI& o) {
	return this->works == o.works && this->pages == o.pages && this->formuls == o.formuls && this->statistics == o.statistics;
}

ostream& operator << (ostream& os, const EconomicTI& o) {
	os << o.num << " " << o.surname << " " << o.works << " " << o.pages << " " << o.formuls << " " << o.statistics << " " << o.mark << " ";
	return os;
}
istream& operator >> (istream& is, EconomicTI& o) {
	cout << "Enter the data in this order:ID->surname->amount works->amount pages in work->->amount formuls in work->amount statistics in work->Mark\n";
	is >> o.num;
	is >> o.surname;
	is >> o.works;
	is >> o.pages;
	is >> o.formuls;
	is >> o.statistics;
	is >> o.mark;

	return is;
}


void EconomicTI::setInfo(int num, int works, int pages, string surname) {
	this->num = num;
	this->works = works;
	this->pages = pages;

	if (this->works <= 3)
		this->mark = 2;
	else if (this->works > 3 && this->works <= 6 && this->pages >= 1 && this->pages <= 3)
		this->mark = 3;
	else if (this->works >= 3 && this->works <= 6 && this->pages > 3 ||
		this->works > 6 && this->works < 10 && this->pages <= 2 ||
		this->works == 10 && this->pages <= 2)
		this->mark = 4;
	else if (this->works >= 7 && this->works < 10 && this->pages >= 3 ||
		this->works == 10 && this->pages >= 3)
		this->mark = 5;

	if (statistics == 5 || formuls == 3) { mark = 5; };

	this->surname = surname;
}
void EconomicTI::outputToFile(ofstream& file) {
	file << "Info about: " << surname << endl;
	file << "ID " << num << endl;
	file << "Number of completed work: " << works << endl;
	file << "average number of pages in work: " << pages << endl;
	file << "Number of statistics in work : " << statistics << endl;
	file << "Òumber of weighty formuls in the work : " << formuls << endl;
	file << "Student mark (average): " << mark << endl << endl;
}
void EconomicTI::printInfo()const {
	cout << "\nStudent number:" << this->num << "\nNumber of completed works:" << this->works << "\nAverage volume of work:" << this->pages
		<< "\nNumber of statistics in work:" << this->statistics << "\nNumber of strong formuls:" << this->formuls << "\nGPA:" << this->mark << "\nSurname :" << this->surname << "\n\n";
}

int EconomicTI::getStatistics() { return statistics; }
int EconomicTI::getFormuls() { return formuls; }
void  EconomicTI::setStatistics(int statistics) { this->statistics = statistics; }
void  EconomicTI::setFormuls(int formuls) { this->formuls = formuls; }

