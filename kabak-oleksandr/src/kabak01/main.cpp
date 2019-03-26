#include "StudentsWorks.h"

int main() {
	int N;
	printf("Enter the number of students:");
	scanf_s("%d", &N);

	if (N <= 0) {
		printf("You entered incorrect number of students");
	}
	else {
		StudentsWorks Students(N);

		printf("\nYour list:\n");
		Students.showAll();

		printf("\n\nStudent who wants to join the group:\n\n");
		Students.getNewStud();
		getchar(); getchar();

		int i = 1;
		while (i > 0) {
			system("cls");
			printf("________________________________________________________________________________");
			printf("Menu:\n1.Check your list.\n2.Check new student information.\n3.Check student information by index\n4.Add a new student to the list.\n");
			printf("5.Remove student from the list by number.\n6.Change new student information\n7.EXIT(press 0)\nYou choose:");
			scanf_s("%d", &N);
			printf("________________________________________________________________________________");
			if (N < 0||N>6) {
				printf("You have chosen a nonexistent method");
			}else {
				switch (N) {
				case 1:
					Students.showAll();
					break;


				case 2:
					Students.getNewStud();
					break;


				case 3:
					i = 2;
					while (i > 1) {
							printf("Select student index:");
							scanf_s("%d", &N);

							if (N > Students.getSIZE() || N <= 0) {
								printf("\nSorry, you entered a non-existent index.\n");
							}
							else {
								Students.getStud(N - 1);
								i = 1;
							}
						
					}
										
					break;


				case 4:
					i = 2;
					while (i > 1) {
						printf("Choose a place in the journal for a new student:");
						scanf_s("%d", &N);

						if (N > Students.getSIZE() || N <= 0) {
							printf("\nSorry, you entered a non-existent index.\n");
						}
						else {
							Students.addStud(N);
							printf("\nResult:\n");
							Students.showAll();
							i = 1;
						}
					}
					break;

				case 5:
					i = 2;
					while (i > 1) {
						if (Students.getSIZE() > 0) {
							printf("Select the student number of which you want to remove from the list:");
							scanf_s("%d", &N);

							if (N > Students.getSIZE() || N <= 0) {
								printf("\nSorry, you entered a non-existent index.\n");
							}else {
								Students.removeStud(N - 1);
								printf("\nResult:\n");
								Students.showAll();
								i = 1;
							}
						}else {
							cout << "List is clear!.-.\n";
							i = 1;
						}
					}
					break;

				case 6:
					printf("Do you want changeinfo about new student ?\nOk:\n ");
					Students.setNewStud();
					Students.getNewStud();
					break;

				case 0:
					printf("Work with the list is over, thanks for the work!");
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
