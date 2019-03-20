#include "TestsInfo.h"

void TestsInfo::setInfo(int num) {
	this->num = num;
	this->works = rand() % 7 + 3;
	this->pages = rand() % 4 + 1;
	if (this->works <= 3)
		this->mark = 2;
	else if (this->works > 3 && this->works <= 7 && this->pages >= 1)
		this->mark = 3;
	else if (this->works >= 7 && this->works < 10 && this->pages >= 1 && this->pages < 4)
		this->mark = 4;
	else if (this->works >= 7 && this->works < 10 && this->pages >= 3 || this->works == 10 && this->pages >= 2)
		this->mark = 5;
}

void TestsInfo::getInfo()const {
	cout << " Student number:" << this->num << endl << "Number of completed works:" << this->works << endl
		<< "Average volume of work:" << this->pages << endl << "GPA:" << this->mark << "\n\n";
}

int TestsInfo::idInfo()const {
	return this->num;
}