#include "StudentsWorks.h"

bool Test(int N,int SIZE);

int main() {
	int N,SIZE;

	cout<<"Enter the number of students:";
	cin >> N;

	if (N <= 0) {
		printf("You entered incorrect number of students");
	}
	else {
		StudentsWorks Students(N);

		printf("\nYour list\n");
		Students.showAll();
		cout << "Student who wants to join the group:\n";
		Students.getNewStud();
		getchar(); getchar();

		int i = 1;
		while (i > 0) {
			SIZE=Students.getSIZE();

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
					Students.showAll();
					break;
				case 2:
					Students.getNewStud();
					break;
				case 3:
					cout << "Select student index:";
					cin >> N;


					if(Test(N,SIZE))
						Students.getStud(N);
					break;
				case 4:
					cout << "Choose a place in the journal for a new student:";
					cin >> N;
					
					if (Test(N, SIZE)) {
						Students.addStud(N);
						cout << "\nResult:\n";
						Students.showAll();
					}
					break;
				case 5:
					i = 2;
					while (i > 1) {
						if (Students.getSIZE() > 0) {
					cout << "Select the student number of which you want to remove from the list";
					cin >> N;
					if (N > Students.getSIZE() || N <= 0) {
						printf("\nSorry, you entered a non-existent index.\n");
					}
					else {
						Students.removeStud(N - 1);
						printf("\nResult:\n");
						Students.showAll();
						i = 1;
					}
						}
						else {
							cout << "List is clear!.-.\n";
							i = 1;
						}
					}
					break;
				case 6:
					printf("Do you want change info about new student ?\nOk:\n ");
					Students.setNewStud();
					Students.getNewStud();
					break;
				case 7:
					cout << "Select student index:";
					cin >> N;

					if (Test(N, SIZE)) {
						cout << "\nResult:\n";
						Students.infoWorks(N -1);
					}
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

bool Test(int N,int SIZE) {
	if (N > 0 && N < SIZE+1)
		return true;
	else {
		cout << "You entered an invalid value, try again\n";
		return false;
	}
}

