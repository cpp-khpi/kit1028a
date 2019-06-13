/**
* @file TestsInfo.cpp
* File assignment				| Ñlass methods
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/

#include "TestsInfo.h"

TestsInfo::TestsInfo() :num(0), works(0), pages(0), mark(0), surname("0") {
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
}
TestsInfo::TestsInfo(const TestsInfo& o) :num(o.num), works(o.works), pages(o.pages), mark(o.mark), surname(o.surname) {}

TestsInfo& TestsInfo::operator = (const TestsInfo& o){
	this->num = o.num;
	this->works = o.works;
	this->pages = o.pages;
	this->mark = o.mark;
	this->surname = o.surname;

	cout << "Operator = worked here.\n";
	return *this;
}
bool TestsInfo::operator == (const TestsInfo& o) {
	return this->works == o.works && this->pages == o.pages;
}

ostream& operator << (ostream& os, const TestsInfo& o) {
	os << o.num << " " << o.surname << " " << o.works << " " << o.pages << " " << o.mark << " ";
	return os;
}

istream& operator >> (istream& is, TestsInfo& o) {
	cout << "Enter the data in this order:ID->surname->number of works->number of pages in work->Mark\n";
	is >> o.num;
	is >> o.surname;
	is >> o.works;
	is >> o.pages;
	is >> o.mark;

	return is;
}

int TestsInfo::getNum()const { return this->num; }
int TestsInfo::getMark()const { return this->mark; }
int TestsInfo::getWorks()const { return this->works; }
int TestsInfo::getPages()const { return this->pages; }
string TestsInfo::getSur()const { return this->surname; }

void TestsInfo::setMark(int mark) { this->mark = mark; }