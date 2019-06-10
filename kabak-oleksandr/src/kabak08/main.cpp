/**
* @file main.cpp
* File assignment				| Main function	+ menu that works with a class object StudentsWorks
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/

#include "StudentsWorks.h"

bool sort(int a, int b) {
	return a < b;
}
bool sort2(int a, int b) {
	return a > b;
}

int main(){
try {
	int N, work=1;
	stringstream ss;
	string s;
	bool(*p)(int a, int b);

	cout << "Enter the number of students:";
	cin >> s;
	ss << s;
	ss >> N;


	if (N <= 0) {
		cout << "You entered incorrect number of students";
	}
	else {
		StudentsWorks Students(s);

		cout << "\nYour list\n";
		Students.printAll();
		getchar(); getchar();

		do{
			system("cls");
			cout << "________________________________________________________________________________";
			cout << "Menu:\n1.Check your list.\n2.Check new student information.\n3.Check student information by index\n4.Add a new student to the list.\n";
			cout << "5.Remove student from the list by number.\n6.Change new student.\n7.Number of completed student work.\n8.Surnames and names of students\n";
			cout << "9.Sort student list by grade.\n10.Write current list to file\n11.EXIT(press 0).\nYou choose:";
			cin >> N;
			cout << "________________________________________________________________________________";

			if (N < 0 || N>10) {
				cout << "You have chosen a nonexistent method";
				getchar(); getchar();
			}
			else {
				switch (N) {
				case 1:
					Students.printAll();
					break;

				case 2:
					Students.printNewStud();
					break;

				case 3:
					cout << " Select student index:";
					cin >> N;
						Students.printStudIndex(N);
					break;

				case 4:
					cout << " Choose a place in the journal for a new student:";
					cin >> N;
						Students.addStud(N);
						cout << "\nResult:\n";
						Students.printAll();
					
					break;

				case 5:
					cout << " Select the student number of which you want to remove from the list";
					cin >> N;
					Students.removeStud(N - 1);
					cout << "\nResult:\n";
					Students.printAll();
					
					break;

				case 6:
					cout << " Do you want another new student ?\nOk it's him:\n ";
					cout << "Enter student's last name:";
					cin >> s;
					Students.setNewStud(s);
					Students.printNewStud();
					break;
				case 7:
					cout << " Select student index:";
					cin >> N;
						cout << "\nResult:\n";
						Students.infoWorks(N + 1);
					break;

				case 8:
					cout << " Surnames and names of students:\n";
					Students.printAll2();
					break;

				case 9:
					cout << " How to sort? Ascending (0) or descending (1)?\n";
					cin >> N;
					cout << endl;

					if (N == 1) {
						p = sort;
					}
					else if (N == 0) {
						p = sort2;
					}
					else {
						std::cout << "You enter false variant" << std::endl;
						break;
					}

					Students.sortMarkStud(p);
					break;

				case 10:
					Students.writeToFile();
					cout << "Completed\n";
					break;

				case 0:
					cout << "Work with the list is over, thanks for the work!";
					work = 0;
					break;

				}
				getchar(); getchar();
			}
			getchar();
		}while (work);
	}

}
catch (Exception& exception) {
	cout << "An error has occurred in working." << exception.what() << endl << " Error in this function: " << exception.getFunc() << endl;
}
catch (exception& exception) {
	cout << "An error has occurred in working." << exception.what() << endl;
}
catch (...) {
	cout << "Unknown error!" << endl;
}

_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
_CrtDumpMemoryLeaks();


return _CrtDumpMemoryLeaks();
system("pause");

return 0;
}
