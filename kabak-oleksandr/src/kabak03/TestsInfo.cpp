#include "TestsInfo.h"

TestsInfo::TestsInfo():num(0),works(0),pages(0),mark(0) {
	cout << "Here was designer by default\n";
}
TestsInfo::TestsInfo(int num) : num(num), works(0), pages(0), mark(0) {
	this->works = rand() % 7 + 3;
	this->pages = rand() % 4 + 1;
	if (this->works < 5)
		this->mark = 2;
	else if (this->works > 5 && this->works <= 7 && this->pages < 3)
		this->mark = 3;
	else if (this->works >= 7 && this->works < 10 && this->pages >= 2 && this->pages < 4)
		this->mark = 4;
	else if (this->works >= 7 && this->works < 10 && this->pages <= 4 || this->works == 10 && this->pages >= 2)
		this->mark = 5;
	cout << "The constructor with parameters worked here.\n";
}

void TestsInfo::setSurname(string surname) {
	this->surname = surname;
}
void TestsInfo::setInfo(int num) {
	this->num = num;
	this->works = rand() % 7 + 3;
	this->pages = rand() % 4 + 1;
	if (this->works < 5)
		this->mark = 2;
	else if (this->works > 5 && this->works <= 7 && this->pages < 3)
		this->mark = 3;
	else if (this->works >= 7 && this->works < 10 && this->pages >= 2 && this->pages < 4)
		this->mark = 4;
	else if (this->works >= 7 && this->works < 10 && this->pages <= 4 || this->works == 10 && this->pages >= 2)
		this->mark = 5;
}
string TestsInfo::getInfo()const {
	stringstream ss;
	ss	<< " Student number:" << this->num << endl << "Number of completed works:" << this->works << endl
		<< "Average volume of work:" << this->pages << endl << "GPA:" << this->mark << endl << "Surname :" << this->surname << endl<<endl;
	string S = ss.str();
	return S;
}

int TestsInfo::getWorks()const {
	return this->works;
}
int TestsInfo::idInfo()const {
	return this->num;
}