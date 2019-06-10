#include "StudentsWorks.h"

StudentsWorks::StudentsWorks(string s) : list(nullptr) {
	int tmpSIZE;
	stringstream ss;
	ss << s;
	ss >> tmpSIZE;
	this->SIZE = 0;

	int lot;
	string k;
	ifstream fin("G:\\Visual Studio (SAVES)\\Lab2.4\\Lab2.4\\TEST.txt");

	regex reg("([A-Z])([a-z]+)"		  //Surname
		"( ([A-Z])([a-z]+))?"	  //Name
		" ?([0-9])?");		  //mb id

	for (int i = 0; i < tmpSIZE; i++) {
		getline(fin, k);
		if (regex_match(k, reg)) {
			cout << "\nEnter information about " <<k <<endl;
			setNewStud(k);
			addStud(SIZE+1);
		}
	}

	cout << "\nEnter information about new student " << k << endl;
	getline(fin, k);
	setNewStud(k);
	
	fin.close();
}
StudentsWorks::~StudentsWorks() {
	for (int i = 0; i < SIZE; i++) {
		delete list[i];
	}
	delete[] list;
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

void StudentsWorks::infoWorks(const int num) {
	for (int i = 0; i < SIZE; i++) {
		if ((*list[i]).getNum() == num) {
			cout << "The number of finished student works is " << (*list[num]).getWorks() << "/10\n";
			return;
		}
	}
	cout << "This student does not exist";
}
	
void StudentsWorks::addStud(const int num) {
	SIZE++;
	TestsInfo** tmp_list = new TestsInfo*[SIZE];
	for (int i = 0; i < num - 1; i++)
		tmp_list[i] = list[i];
	tmp_list[num - 1] = newStudent;
	for (int i = num; i < SIZE; i++)
		tmp_list[i] = list[i - 1];

	delete[]list;
	list = tmp_list;

}

void StudentsWorks::removeStud(const int num) {
	if (SIZE > 0) {
		SIZE--;
		TestsInfo** tmp_list = new TestsInfo * [SIZE];
		for (int i = 0; i < num; i++)
			tmp_list[i] = list[i];
		for (int i = num; i < SIZE; i++)
			tmp_list[i] = list[i + 1];

		delete[]list;
		list = tmp_list;
	}
	else {
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

void StudentsWorks::getStud(const int num)const {
	for (int i = 0; i < SIZE; i++) {
		if ((*list[i]).getNum() == num) {
			(*list[i]).printInfo();
			return;
		}
	}
	cout << "This student does not exist";
}
void StudentsWorks::getNewStud() {
	(*newStudent).printInfo();
}
void StudentsWorks::showAll()const {
	cout << "Current student journal:\n\n";
	for (int i = 0; i < SIZE; i++)
		 (*list[i]).printInfo();
}

void StudentsWorks::showAll2()const {

	regex ger("(([A-Z])([a-z]+) ([A-Z])([a-z]+)) ?([0-9])?");

	for (int i = 0; i < SIZE; i++) {
		if (regex_match((*list[i]).getSur(), ger)) {
			(*list[i]).getSur();
		}
	}
}
