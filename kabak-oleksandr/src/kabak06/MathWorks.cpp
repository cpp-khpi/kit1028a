#include "MathWorks.h"

MathWorks::MathWorks(int SIZE) : SIZE(SIZE), list(0), newStudent() {
	list = new MathTI[SIZE];
	string s;
	ifstream fin("G:\\Visual Studio (SAVES)\\Lab2.3\\Lab2.3\\TEST.txt");

	for (int i = 0; i < SIZE; i++) {
		getline(fin, s);
		list[i].setInfo(i + 1, rand() % 7 + 3, rand() % 4 + 1, s);
		list[i].setArguments(rand() % 3 + 1);
		list[i].setGraphs(rand() % 5 + 1);
	}

	getline(fin, s);
	newStudent.setInfo(SIZE + 1, rand() % 7 + 3, rand() % 4 + 1, s);
	newStudent.setArguments(rand() % 3 + 1);
	newStudent.setGraphs(rand() % 5 + 1);

	fin.close();
}
MathWorks::~MathWorks() {
	delete[]list;
	cout << "\nMemory cleanup successful!";
}

int MathWorks::getSIZE() { return SIZE; }

void MathWorks::infoArguments(const int num) {
	cout << "The number of argument is " << list[num].getWorks() << "/3\n";
}

void MathWorks::addStud(const int num) {
	SIZE++;
	MathTI* tmpList = new MathTI[SIZE];
	for (int i = 0; i < num - 1; i++)
		tmpList[i] = list[i];
	tmpList[num - 1] = newStudent;
	for (int i = num; i < SIZE; i++)
		tmpList[i] = list[i - 1];

	delete[]list;
	list = tmpList;
}
void MathWorks::removeStud(const int num) {
	SIZE--;
	MathTI* tmpList = new MathTI[SIZE];
	for (int i = 0; i < num; i++)
		tmpList[i] = list[i];
	for (int i = num; i < SIZE; i++)
		tmpList[i] = list[i + 1];

	delete[]list;
	list = tmpList;
}
void MathWorks::sortMarkStud(bool(*comp)(int x, int y)) {
	MathTI tmp;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (comp(list[i].getMark(), list[j].getMark())) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

void MathWorks::getStud(const int num)const {
	for (int i = 0; i < SIZE; i++) {
		if (list[i].getNum() == num) {
			list[i].printInfo();
			return;
		}
	}
	cout << "This student does not exist";
}
void MathWorks::getNewStud() {
	newStudent.printInfo();
}
void MathWorks::setNewStud() {
	string s;
	cout << "\nStudent's last name:";
	cin >> s;

	int works, pages, arguments, graphs;


	int i = 4;
	while (i > 3) {
		cout << "Enter the number of student works(0-10):";
		cin >> works;
		if (works < 0 || works > 10) {
			cout << "You entered an invalid value, try again\n";
		}
		else { i = 3; }
	}
	while (i > 3) {
		cout << "Enter the number of pages in works(1-5):";
		cin >> pages;
		if (pages < 1 || pages >5) {
			cout << "You entered an invalid value, try again\n";
		}
		else { i = 2; }
	}
	while (i > 2) {
		cout << "Enter the number of arguments(1-3):";
		cin >> arguments;
		if (pages < 1 || pages >3) {
			cout << "You entered an invalid value, try again\n";
		}
		else { i = 1; }
	}
	while (i > 1) {
		cout << "Enter the number of graphs(1-5):";
		cin >> graphs;
		if (pages < 1 || pages >5) {
			cout << "You entered an invalid value, try again\n";
		}
		else { i = 0; }
	}

	newStudent.setInfo(SIZE + 1, works, pages, s);
	newStudent.setArguments(arguments);
	newStudent.setGraphs(graphs);
}

void MathWorks::showAll()const {
	cout << "Current student journal:\n\n";
	for (int i = 0; i < SIZE; i++)
		list[i].printInfo();
}
