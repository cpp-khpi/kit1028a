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
		Students.print_all();

		printf("Student who wants to join the group:\n");
		Students.print_new_stud();
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
					Students.print_all();
					break;

				case 2:
					Students.print_new_stud();
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
							Students.print_stud(N - 1);
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
							Students.add_Stud(N);
							printf("\nResult:\n");
							Students.print_all();
							i = 1;
						}
					}
					break;

				case 5:
					i = 2;
					while (i > 1) {
						printf("Select the student number of which you want to remove from the list:");
						scanf_s("%d", &N);
						if (N > Students.getSIZE() || N <= 0) {
							printf("\nSorry, you entered a non-existent index.\n");
						}
						else {
							Students.del_Stud(N - 1);
							printf("\nResult:\n");
							Students.print_all();
							i = 1;
						}
					}
					break;

				case 6:
					printf("Choose a number for a new student(the last one is logical c: )");
					scanf_s("%d", &N);
					Students.setStud(N);
					printf("\nResult:\n");
					Students.print_all();
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
	getchar(); getchar();
	return 0;
}
