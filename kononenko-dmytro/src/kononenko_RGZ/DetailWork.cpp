/**
* @file DetailInfo.cpp
* Implementation of all functions of DetailInfo class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/

#include "DetailInfo.h"

DetailInfo::~DetailInfo(){}
DetailInfo::DetailInfo() : novelty(0), InfoWork(){}
DetailInfo::DetailInfo(const DetailInfo &obj) : InfoWork(obj.pages, obj.mark, obj.type, obj.name), novelty(obj.novelty) {};
DetailInfo::DetailInfo(int pages, int mark, int type, string name, int novelty) : novelty(novelty), InfoWork(pages, mark, type, name) {}

void DetailInfo::output_to_file(std::ofstream& fout) {
	fout << "Student`s name: " << name << endl;
	fout << "Size of works " << pages << endl;
	fout << "Student`s mark: " << mark << endl;
	fout << "Work`s type:";
	if (type == 1) {
		fout << " BACALAVR" << endl;
	}
	else {
		fout << " MAGISTR" << endl;
	}
	fout << "Novelty: " << novelty << endl;
}

void DetailInfo::input() {
	cout << "Input student`s name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Input pages:  ";
	cin >> pages;
	cout << "Input type:  ";
	cin >> type;
	cout << "Input student`s mark:  ";
	cin >> mark;
	cout << "Input novelty: ";
	cin >> novelty;
	cout << endl;
}

void DetailInfo::output() {
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
	cout << "Novelty: " << novelty << endl;
}

void DetailInfo::set_data(int a, int b, int c, string name, int novelty) {
	mark = a;
	pages = b;
	type = c;
	this->name = name;
	this->novelty = novelty;
}

int DetailInfo::getNovelty() {
	return novelty;
}

void DetailInfo::set(string name) {
	mark = rand() % 5 + 1;
	pages = rand() % 336 + 100;
	type = rand() % 2 + 1;
	novelty = rand() % 10 + 2010;
	this->name = name;
}

bool DetailInfo::operator== (const DetailInfo &obj) {
	return (pages == obj.pages && type == obj.type && mark == obj.mark && name == obj.name);
}

bool DetailInfo::operator!= (const DetailInfo &obj) {
	return (pages != obj.pages && type != obj.type && mark != obj.mark && name != obj.name);
}

std::istream& operator>> (std::istream &in, DetailInfo &obj) {
	in >> obj.pages;
	in >> obj.mark;
	in >> obj.type;
	in >> obj.name;

	return in;
}

std::ostream& operator<< (std::ostream &out, const DetailInfo &obj) {
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

DetailInfo& DetailInfo::operator= (const DetailInfo &obj) {
	pages = obj.pages;
	mark = obj.mark;
	type = obj.type;
	name = obj.name;
	novelty = novelty;
	return *this;
}
