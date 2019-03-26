#include "TestsInfo.h"

void TestsInfo::setInfo(int num, int works, int pages) {
	this->num = num;
	this->works = works;
	this->pages = pages;
	if (this->works <= 3)
		this->mark = 2;
	else if (this->works > 3 && this->works <= 6 && this->pages >= 1 && this->pages <= 3)
		this->mark = 3;
	else if (this->works >= 3 && this->works <= 6 && this->pages > 3 ||
			 this->works > 6  && this->works < 10 && this->pages <= 2 ||
			 this->works ==10 && this->pages <= 2)
		this->mark = 4;
	else if (this->works >= 7 && this->works < 10 && this->pages >= 3 ||
			 this->works == 10 && this->pages >= 3)
		this->mark = 5;
}

int TestsInfo::getNum()const { return this->num; }
int TestsInfo::getMark()const { return this->mark; }
int TestsInfo::getWorks()const { return this->works; }
int TestsInfo::getPages()const { return this->pages; }

void TestsInfo::printInfo()const {
	cout << " Student number:" << this->num << endl << "Number of completed works:" << this->works << endl
		<< "Average volume of work:" << this->pages << endl << "GPA:" << this->mark << "\n\n";
}
