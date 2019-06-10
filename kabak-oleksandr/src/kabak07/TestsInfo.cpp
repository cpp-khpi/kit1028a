/**
* @file TestsInfo.cpp
* File assignment				| Ñlass methods	+ An example of using a variable of type auto
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.06.06
*/

#include "TestsInfo.h"

TestsInfo::TestsInfo() :num(0), works(0), pages(0), mark(0), surname("0") {
	cout << "Here was designer by default\n";
}
TestsInfo::TestsInfo(int num, int works, int pages, string surname) :
	num(num), works(works), pages(pages), mark(0), surname(surname) {
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

	cout << "The constructor with parameters worked here.\n";
}
TestsInfo::TestsInfo(const TestsInfo& o) :num(o.num), works(o.works), pages(o.pages), mark(o.mark), surname(o.surname) {
	cout << "The copy constructor worked here.\n";
}

int TestsInfo::getNum()const { return this->num; }
int TestsInfo::getMark()const { return this->mark; }
int TestsInfo::getWorks()const { return this->works; }
int TestsInfo::getPages()const { return this->pages; }
string TestsInfo::getSur()const { return this->surname; }

void TestsInfo::setMark(int mark) { this->mark = mark; }