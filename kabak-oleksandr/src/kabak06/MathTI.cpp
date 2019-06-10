#include "MathTI.h"

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

int MathTI::getGraphs() { return graphs; }
int MathTI::getArguments() { return arguments; }

void  MathTI::setGraphs(int graphs) { this->graphs = graphs; }
void  MathTI::setArguments(int arguments) { this->arguments = arguments; }

void MathTI::printInfo() {
	cout << "\nStudent number:" << this->num << "\nNumber of completed works:" << this->works << "\nAverage volume of work:" << this->pages
		<< "\nNumber of graphs in work:" << this->graphs << "\nNumber of strong arguments:" << this->arguments << "\nGPA:" << this->mark << "\nSurname :" << this->surname << "\n\n";
}