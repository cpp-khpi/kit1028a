#include "TestsInfo.h"


TestsInfo::TestsInfo() :num(0), works(0), pages(0), mark(0), surname("") {}

TestsInfo::TestsInfo(int num, int works, int pages,string surname) :
	num(num), works(works), pages(pages),mark(0), surname(surname){
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
}
TestsInfo::TestsInfo(const TestsInfo &o) :num(o.num), works(o.works), pages(o.pages), mark(o.mark), surname(o.surname) {}

int TestsInfo::getNum()const { return this->num; }
int TestsInfo::getMark()const { return this->mark; }
int TestsInfo::getWorks()const { return this->works; }
int TestsInfo::getPages()const { return this->pages; }
string TestsInfo::getSurname()const { return this->surname; }

void TestsInfo::setInfo(int num, int works, int pages,string surname) {
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

	this->surname= surname;
}

string TestsInfo::printInfo()const {
	stringstream ss;
	ss << " Student number:" << this->num << endl << "Number of completed works:" << this->works << endl
	   << "Average volume of work:" << this->pages << endl << "GPA:" << this->mark << endl <<"Surname :" << this->surname <<"\n\n";
	string s = ss.str();
	
	return s;
}
