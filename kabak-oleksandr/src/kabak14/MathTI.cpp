/**
* @file MathTI.cpp
* File assignment				| Ñlass methods
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/
#include "MathTI.h"

MathTI& MathTI::operator = (const MathTI& o) {
	this->num = o.num;
	this->works = o.works;
	this->pages = o.pages;
	this->mark = o.mark;
	this->surname = o.surname;
	this->arguments = o.arguments;
	this->graphs = o.graphs;

	return *this;
}
bool MathTI::operator == (const MathTI& o) {
	return this->works == o.works && this->pages == o.pages && this->arguments == o.arguments && this->graphs == o.graphs;
}
ostream& operator << (ostream& os, const MathTI& o) {
	os <<"ID:"<< o.num << " Surname:" << o.surname << " Works:" << o.works << " Pages:" << o.pages << " Graphs:" << o.graphs << " Arguments:" << o.arguments << " Mark" << o.mark << endl;
	return os;
}
istream& operator >> (istream& is, MathTI& o) {
	cout << "\nEnter the data in this order:\nID->surname->amount works->amount pages in work->amount graphs in work->amount grahs in work->Mark\n";
	is >> o.num;
	is >> o.surname;
	is >> o.works;
	is >> o.pages;
	is >> o.arguments;
	is >> o.graphs;
	is >> o.mark;

	return is;
}
bool operator < (const MathTI& o, const MathTI& o1) {
	return o.mark < o1.mark;
}


void MathTI::setInfo(int num, int works, int pages, string surname) {
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

	if (graphs == 5 || arguments == 3) { mark = 5; };

	this->surname = surname;
}

void MathTI::printInfo()const {
	cout << "\nStudent number:" << this->num << "\nNumber of completed works:" << this->works << "\nAverage volume of work:" << this->pages
		<< "\nNumber of graphs in work:" << this->graphs << "\nNumber of strong arguments:" << this->arguments << "\nGPA:" << this->mark << "\nSurname :" << this->surname << "\n\n";
}

int MathTI::getGraphs() { return graphs; }
int MathTI::getArguments() { return arguments; }
void  MathTI::setGraphs(int graphs) { this->graphs = graphs; }
void  MathTI::setArguments(int arguments) { this->arguments = arguments; }

