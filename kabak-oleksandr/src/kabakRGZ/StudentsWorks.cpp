/**
* @file StudentsWorks.cpp
* File assignment				| Ñlass methods
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/
#include "StudentsWorks.h"

StudentsWorks::StudentsWorks(string s) :SIZE(0), newStudent(nullptr), list(nullptr) {
	int tmpSIZE;
	stringstream ss;
	ss << s;
	ss >> tmpSIZE;

	ifstream fin("G:\\Visual Studio (SAVES)\\Lab2.4\\Lab2.4\\TEST.txt");

	regex reg("([A-Z])([a-z]+)"		  //Surname
		"( ([A-Z])([a-z]+))?"	  //Name
		" ?([0-9])?");		  //mb id
	if (fin.is_open()) {
		for (int i = 0; i < tmpSIZE; i++) {
			getline(fin, s);
			if (regex_match(s, reg)) {
				cout << "\nEnter information about " << s << endl;
				setNewStud(s);
				addStud(SIZE + 1);
			}
		}

		cout << "\nEnter information about new student " << s << endl;
		getline(fin, s);
		setNewStud(s);

		this->SIZE = tmpSIZE;
	}
	else { cout << "File not open."; }
	fin.close();
}
StudentsWorks::~StudentsWorks() {
	if (list) {
		for (int i = 0; i < SIZE; i++) {
			if(list[i])delete list[i];
		}
		delete[] list;
	}
	delete newStudent;
}

TestsInfo& StudentsWorks::operator[](int index){
	return *list[index];
}

ostream& operator<< (ostream& os, const StudentsWorks& o) {
	os << o.SIZE << endl;
	for (int i = 0; i < o.SIZE; i++) {
		os << o.list[i];
	}
	return os;
}
istream& operator>> (istream& is, StudentsWorks& o) {
	is >> o.SIZE;
	for (int i = 0; i < o.SIZE; i++) {
		is >>  *o.list[i];
	}
	return is;
}

void StudentsWorks::setNewStud(string s) {

	regex reg("([A-Z])([a-z]+)"		  //Surname
		"( ([A-Z])([a-z]+))?"	  //Name
		" ?([0-9])?");		  //mb id

	if (regex_match(s, reg)) {

		int works, pages, a, b;

		int i = 2;
		while (i > 1) {
			cout << "Enter the number of student works(0-10):";
			cin >> works;
			if (works < 0 || works > 10) {
				cout << "You entered an invalid value, try again\n";
			}
			else { i = 1; }
		}
		while (i > 0) {
			cout << "Enter the number of pages in works(1-5):";
			cin >> pages;
			if (pages < 1 || pages >5) {
				cout << "You entered an invalid value, try again\n";
			}
			else { i = 0; }
		}

		cout << "From which group is the student?(Math-0,Economic-1)\n";
		bool z;
		cin >> z;

		if (z) {
			i = 2;
			while (i > 1) {
				cout << "Enter the number of statistics(1-5):";
				cin >> a;
				if (a < 0 || a > 5) {
					cout << "You entered an invalid value, try again\n";
				}
				else { i = 1; }
			}
			while (i > 0) {
				cout << "Enter the number of formuls(1-3):";
				cin >> b;
				if (b < 1 || b >3) {
					cout << "You entered an invalid value, try again\n";
				}
				else { i = 0; }
			}
			newStudent = new EconomicTI(SIZE + 1, works, pages, s, a, b);

		}
		else {
			i = 2;
			while (i > 1) {
				cout << "Enter the number of graphs (1-5):";
				cin >> a;
				if (a < 0 || a > 5) {
					cout << "You entered an invalid value, try again\n";
				}
				else { i = 1; }
			}
			while (i > 0) {
				cout << "Enter the number of arguments(1-3):";
				cin >> b;
				if (b < 1 || b >3) {
					cout << "You entered an invalid value, try again\n";
				}
				else { i = 0; }
			}

			newStudent = new MathTI(SIZE + 1, works, pages, s, a, b);
		}
	}
	else {
		cout << "Surname entered incorrectly\n";
	}
}

int StudentsWorks::getSIZE() { return this->SIZE; }

void StudentsWorks::writeToFile(){
	ofstream fout;
	fout.open("InfoStud.txt");
	for (int i = 0; i < SIZE; i++) {
		list[i]->outputToFile(fout);
	}
	fout.close();
	}

void StudentsWorks::infoWorks(const int num) {
	cout << "The number of finished student works is " << (*list[num]).getWorks() << "/10\n";
}

void StudentsWorks::addStud(const int num) {
	SIZE++;
	TestsInfo** tmpList = new TestsInfo*[SIZE];
	for (int i = 0; i < num - 1; i++)
		tmpList[i] = list[i];
	tmpList[num - 1] = newStudent;
	for (int i = num; i < SIZE; i++)
		tmpList[i] = list[i - 1];

	delete[] list;
	list = tmpList;

}
void StudentsWorks::removeStud(const int num) {
	if (SIZE > 1) {
		SIZE--;
		TestsInfo** tmpList = new TestsInfo * [SIZE];
		for (int i = 0; i < num; i++)
			tmpList[i] = list[i];
		for (int i = num; i < SIZE; i++)
			tmpList[i] = list[i + 1];

		delete list[num];
		delete[]list;

		list = tmpList;
	}
	else if (SIZE == 1) {
		SIZE--;
		delete list[0];
		delete[]list;
		list = nullptr;
	}
	else{
		cout << "Mass havn't students :| \n";
	}
}

void StudentsWorks::sortMarkStud(bool(*comp)(int x, int y)) {
	TestsInfo* tmp;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (comp((*list[i]).getMark(), (*list[j]).getMark())) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}
void StudentsWorks::sortNumStud(bool(*comp)(int x, int y)) {
	TestsInfo* tmp;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (comp((*list[i]).getNum(), (*list[j]).getNum())) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}
void StudentsWorks::sortWorksStud(bool(*comp)(int x, int y)) {
	TestsInfo* tmp;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (comp((*list[i]).getWorks(), (*list[j]).getWorks())) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}
void StudentsWorks::sortPageStud(bool(*comp)(int x, int y)) {
	TestsInfo* tmp;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (comp((*list[i]).getPages(), (*list[j]).getPages())) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}


void StudentsWorks::printStudIndex(const int num)const {
	for (int i = 0; i < SIZE; i++) {
		if ((*list[i]).getNum() == num) {
			(*list[i]).printInfo();
			return;
		}
	}
	cout << "This student does not exist";
}
void StudentsWorks::printNewStud() {
	(*newStudent).printInfo();
}

void StudentsWorks::printAll()const {
	cout << "Current student journal:\n\n";
	for (int i = 0; i < SIZE; i++)
		 (*list[i]).printInfo();
}

void StudentsWorks::printAll2()const {

	regex reg("([A-Z])([a-z]+)"//Surname
		"( ([A-Z])([a-z]+))?"  //Name
		" ?([0-9])?");		   //mb id
	for (int i = 0; i < SIZE; i++) {
		if (regex_match((*list[i]).getSur(), reg)) {
			cout << (*list[i]).getSur();
		}
	}
}
