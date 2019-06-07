/**
* @file CourseWork.cpp
* Implementation of all functions of CourseWork class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/


#include "CourseWork.h"

CourseWork::CourseWork() : sizeOfLabor(0), InfoWork() {}
CourseWork::CourseWork(const CourseWork &obj) : InfoWork(obj.pages, obj.mark, obj.type, obj.name), sizeOfLabor(obj.sizeOfLabor){};
CourseWork::CourseWork(int pages, int mark, int type, string name, int sizeOfLabor) : sizeOfLabor(sizeOfLabor),InfoWork(pages,mark,type,name) {}
CourseWork::~CourseWork(){}

void CourseWork::input() {
	cout << "Input student`s name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Input pages:  ";
	cin >> pages;
	cout << "Input type:  ";
	cin >> type;
	cout << "Input student`s mark:  ";
	cin >> mark;
	cout << "Input size of labor: ";
	cin >> sizeOfLabor;
	cout << endl;
}
void CourseWork::output() {
	cout << "Student`s name: " << name << endl;
	cout << "Size of works " << pages << endl;
	cout << "Student`s mark: " << mark << endl;
	cout << "Work`s type:";
	if (type == 1) {
			cout << " BACALAVR" <<endl;
	}
	else {
		cout << " MAGISTR" << endl;
	}
	cout << "Size of labor: " << sizeOfLabor << endl;
}

void CourseWork::set(string name) {
	mark = rand() % 5 + 1;
	pages = rand() % 336 + 100;
	type = rand() % 2 + 1;
	sizeOfLabor = rand() % 300 + 100;
	this->name = name;
}

void CourseWork::set_data(int a, int b, int c, string name, int sizeOfLabor) {
	mark = a;
	pages = b;
	type = c;
	this->name = name;
	this->sizeOfLabor = sizeOfLabor;
}

int CourseWork::getSizeOfLabor() {
	return sizeOfLabor;
}

void CourseWork::output_to_file(ofstream& fout) {
	fout << "Student`s name: " << name << endl;
	fout << "Size of works " << pages << endl;
	fout << "Student`s mark: " << mark << endl;
	fout << "Work`s type:";
	if (type == 1) {
		fout << " BACALAVR" << endl;
	}
	else {
		fout << " MAGISTR" << endl;
	fout << "Size of labor: " << sizeOfLabor << endl;
	}
}


bool CourseWork::operator== (const CourseWork &obj) {
	return (pages == obj.pages && type == obj.type && mark == obj.mark && name == obj.name);
}

bool CourseWork::operator!= (const CourseWork &obj) {
	return (pages != obj.pages && type != obj.type && mark != obj.mark && name != obj.name);
}

std::istream& operator>> (std::istream &in, CourseWork &obj) {
	in >> obj.pages;
	in >> obj.mark;
	in >> obj.type;
	in >> obj.name;

	return in;
}

std::ostream& operator<< (std::ostream &out, const CourseWork &obj) {
	out << "Name: " << obj.name << " Mark: " << obj.mark << endl;
	out << "Size: " << obj.pages;
	if (obj.type == 1) {
		out << " BACALAVR";
	}
	else {
		out << " MAGISTR";
	}
	return out;
}

CourseWork& CourseWork::operator= (const CourseWork &obj) {
	pages = obj.pages;
	mark = obj.mark;
	type = obj.type;
	name = obj.name;
	sizeOfLabor = sizeOfLabor;
	return *this;
}
