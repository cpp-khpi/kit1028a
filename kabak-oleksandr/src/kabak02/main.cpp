#include "StudentsWorks.h"
//Внимание, в файле "StudentsWorks.cpp" измените место расположение документа с фамалиями
int main() {
	int N;

	cout<<"Enter the number of students(1-20):";
	cin >> N;

	if (N <= 0||N>20) {
		printf("You entered incorrect number of students");
	}
	else {
		StudentsWorks Students(N);

		printf("\nYour list\n");
		Students.print_all();
		cout << "Student who wants to join the group:\n";
		Students.print_new_stud();
		getchar(); getchar();

		int i = 1;
		while (i > 0) {
			system("cls");
			cout << "________________________________________________________________________________";
			cout << "Menu:\n1.Check your list.\n2.Check new student information.\n3.Check student information by index\n4.Add a new student to the list.\n";
			cout << "5.Remove student from the list by number.\n6.Change new student.\n7.Number of completed student work.\n8.EXIT(press 0).\nYou choose:";
			cin >> N;
			cout << "________________________________________________________________________________";

			if (N < 0 || N>7) {
				printf("You have chosen a nonexistent method");
			}
			else {
				switch (N) {
				case 1:
					Students.print_all();
					break;
				case 2:
					Students.print_new_stud();
					break;
				case 3:
					cout << "Select student index:";
					cin >> N;
					Students.print_stud(N);
					break;
				case 4:
					cout << "Choose a place in the journal for a new student:";
					cin >> N;
					Students.add_Stud(N);
					cout << "\nResult:\n";
					Students.print_all();
					break;
				case 5:
					cout << "Select the student number of which you want to remove from the list";
					cin >> N;
					Students.del_Stud(N - 1);
					cout << "\nResult:\n";
					Students.print_all();
					break;
				case 6:
					Students.setNewStud(N);
					cout << "\nResult:\n";
					Students.print_new_stud();
					break;
				case 7:
					cout << "Select student index:";
					cin >> N;
					cout << "\nResult:\n";
					Students.infoWorks(N);
					break;
				case 0:
					cout << "Work with the list is over, thanks for the work!";
					i = 0;
					break;
				}
				getchar(); getchar();
			}
			getchar(); getchar();
		}
	}
	return 0;
}
