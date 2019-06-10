#include "EconomicTI.h"

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

int EconomicTI::getStatistics() { return statistics; }
int EconomicTI::getFormuls() { return formuls; }

void  EconomicTI::setStatistics(int statistics) { this->statistics = statistics; }
void  EconomicTI::setFormuls(int formuls) { this->formuls = formuls; }

void EconomicTI::printInfo()const {
	cout << "\nStudent number:" << this->num << "\nNumber of completed works:" << this->works << "\nAverage volume of work:" << this->pages
		<< "\nNumber of statistics in work:" << this->statistics << "\nNumber of strong formuls:" << this->formuls << "\nGPA:" << this->mark << "\nSurname :" << this->surname << "\n\n";
}