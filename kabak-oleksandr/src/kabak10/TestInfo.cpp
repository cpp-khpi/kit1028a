#include "TestInfo.h"


TestInfo::TestInfo() : mark(0), tasks(0) {
}
TestInfo::TestInfo(int mark, int size) : mark(mark), tasks(size) {
}
TestInfo::TestInfo(const TestInfo& o) : mark(o.mark), tasks(o.tasks) {
}
TestInfo::~TestInfo() {
}

TestInfo& TestInfo::operator= (const TestInfo& o) {
	mark = o.mark;
	return *this;
}
std::ostream& operator<< (ostream& out, const TestInfo& o) {
	out << "This mark is " << o.mark << ". Task completed "<< o.tasks << endl;
	return out;
}
std::istream& operator>> (istream& in, TestInfo& o) {
	in >> o.mark;
	o.tasks = o.mark + rand() % 5;
	return in;
}
bool TestInfo::operator == (const TestInfo o) {
	return (mark == o.mark);
}
bool TestInfo::operator > (const TestInfo o) {
	return (mark > o.mark);
}bool TestInfo::operator < (const TestInfo o) {
	return (mark < o.mark);
}



int TestInfo::getMark() {
	return this->mark;
}
int TestInfo::getTasks() {
	return this->tasks;
}
void TestInfo::randValues() {
	tasks = rand() % 10 + 1;
	mark  = rand() % 5 + 1;
}
void TestInfo::setInfo(int mark, int tasks) {
	this->tasks = tasks;
	this->mark = mark;
}