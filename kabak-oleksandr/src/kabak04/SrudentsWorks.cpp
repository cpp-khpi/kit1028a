#include "SrudentsWorks.h"

StudentsWorks::StudentsWorks(int SIZE) : SIZE(SIZE), list(0), new_student() {
	list = new TestsInfo[SIZE];
	string s;
	ifstream fin("G:\\Visual Studio (SAVES)\\Lab2.4\\Lab2.4\\TEST.txt");

	regex reg("([A-Z])([a-z]+)"//Surname
		"( ([A-Z])([a-z]+))?"  //Name
		" ?([0-9])?");		   //md ID

	for (int i = 0; i < SIZE; i++) {
		getline(fin,s);
		if(regex_match(s, reg))
			list[i].setInfo(i + 1, rand() % 8 + 3, rand() % 5 + 1, s);
	}
	getline(fin, s);
	if (regex_match(s, reg))
		new_student.setInfo(SIZE + 1, rand() % 8 + 3, rand() % 5 + 1, s);

	fin.close();
}

StudentsWorks::~StudentsWorks() {
	delete[]list;
	cout << "\nMemory cleanup successful!";
}

void StudentsWorks::setNewStud() {
	string s;
	cout << "\nStudent's last name:";
	cin >> s;

	int works, pages;
	int i = 2;
	while (i > 1) {
		cout << "Enter the number of student works(0-10):";
		cin >> works;
		if (works < 0 || works >10) {
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

	new_student.setInfo(SIZE + 1, works, pages, s);
}
int StudentsWorks::getSIZE() { return this->SIZE; }
void StudentsWorks::infoWorks(const int num) {
	cout << "The number of finished student works is " << list[num].getWorks() << "/10\n";
}

void StudentsWorks::addStud(const int num) {
	SIZE++;
	TestsInfo* tmp_list = new TestsInfo[SIZE];
	for (int i = 0; i < num - 1; i++)
		tmp_list[i] = list[i];
	tmp_list[num - 1] = new_student;
	for (int i = num; i < SIZE; i++)
		tmp_list[i] = list[i - 1];

	delete[]list;
	list = tmp_list;

}
void StudentsWorks::removeStud(const int num) {
	SIZE--;
	TestsInfo* tmp_list = new TestsInfo[SIZE];
	for (int i = 0; i < num; i++)
		tmp_list[i] = list[i];
	for (int i = num; i < SIZE; i++)
		tmp_list[i] = list[i + 1];

	delete[]list;
	list = tmp_list;

}


void StudentsWorks::getStud(const int num)const {
	cout << list[num].printInfo();
}
void StudentsWorks::getNewStud() {
	TestsInfo new_student_tmp = new_student;
	cout << new_student_tmp.printInfo();
}
void StudentsWorks::printAll()const {
	cout << "Current student journal:\n\n";
	for (int i = 0; i < SIZE; i++)
		cout << list[i].printInfo();
}
void StudentsWorks::printAll2()const {

	regex reg("([A-Z])([a-z]+)"	//Surname 100%
		"( ([A-Z])([a-z]+))"	//Name	100%
		" ?([0-9])?");			//ID  mb?
	for (int i = 0; i < SIZE; i++) {
		if (regex_match(list[i].getSur(), reg)) {
			cout << list[i].getSur() << endl;
		}
	}
}