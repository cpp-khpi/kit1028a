/**
* @file main.cpp
* File assignment				| Main function	+ menu that works with a class object StudentsWorks
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/

#include "MathWorks.h"

bool Test(int N, int SIZE);
bool comp(int x, int y);
bool comp2(int x, int y);

int main(){
int N, SIZE;
cout << "Enter the number of students:";
cin >> SIZE;


bool(*p)(int a, int b);

MathWorks* Students = new MathWorks(SIZE);

cout << "\nYour list for Math froup\n";
Students->showAll();
cout << "Student who wants to join the group:\n";
Students->getNewStud();
getchar(); getchar();

int i = 1;
while (i > 0) {
	SIZE = Students->getSIZE();

	system("cls");
	cout << "________________________________________________________________________________";
	cout << "Menu:\n1.Check your list.\n2.Check new student information.\n3.Check student information by index\n4.Add a new student to the list.\n";
	cout << "5.Remove student from the list by number.\n6.Change new student.\n7.Sort student list by grade.\n0.EXIT(press 0).\nYou choose:";
	cin >> N;
	cout << "________________________________________________________________________________";

	if (N < 0 || N>7) {
		cout << "You have chosen a nonexistent method";
		getchar(); getchar();
	}
	else {
		switch (N) {
		case 1:
			Students->showAll();
			break;

		case 2:
			Students->getNewStud();
			break;

		case 3:
			cout << " Select student index:";
			cin >> N;

			if (Test(N, SIZE + 1))
				Students->getStud(N);
			break;

		case 4:
			cout << " Choose a place in the journal for a new student:";
			cin >> N;

			if (Test(N, SIZE+1)) {
				Students->addStud(N);
				cout << "\nResult:\n";
				Students->showAll();
			}
			break;

		case 5:
			cout << " Select the student number of which you want to remove from the list";
			cin >> N;
			Students->removeStud(N - 1);

			if (Test(N, SIZE)) {
				cout << "\nResult:\n";
				Students->showAll();
			}
			break;

		case 6:
			cout << " Do you want another new student ?\nOk it's him:\n ";
			Students->setNewStud();
			Students->getNewStud();
			break;

		case 7:
			cout << " How to sort? Ascending (0) or descending (1)?\n";
			cin >> N;
			cout << endl;

			if (N == 1) {
				p = comp;
			}
			else if (N == 0) {
				p = comp2;
			}
			else {
				std::cout << "You enter false variant" << std::endl;
				break;
			}

			Students->sortMarkStud(p);
			break;

		case 0:
			cout << "Work with the list is over, thanks for the work!";
			i = 0;
			break;

		}
		getchar(); getchar();
	}
	getchar();
}

Students->~MathWorks();

_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);


return 0;
}

bool Test(int N, int SIZE) {
	if (N > 0 && N < SIZE)
		return true;
	else {
		cout << "You entered an invalid value, try again\n";
		return false;
	}
}

bool comp(int x, int y) {
	return x < y;
}

bool comp2(int x, int y) {
	return x > y;
}