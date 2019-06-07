#include "Library.h"

bool Test(int N, int size);

int main() {
	srand(time(NULL));
	int num, size;
	Textbook * tmp_backlist = new Textbook;

	cout << "Enter the number of textbooks: ";
	cin >> num;

	Library textbooks(num);
	size = textbooks.getSize();
	char** author = new char*[num];
	for (int i = 0; i < num; i++) {
		author[i] = new char[64];
	}
	for (int i = 0; i < num; i++) {
		std::cout << "Enter the textbook's author: ";
		std::cin >> author[i];
	}

	system("cls");
	textbooks.getSurname(author);
	for (int i = 0; i < num; i++) {
		delete[]author[i];
	}
	delete[] author;

	if (num <= 0) {
		cout << "You've entered incorrect number of textbooks" << endl;
	}
	else {
		textbooks.printAll();
		getchar(); getchar();

		int i = 1;
		while (i > 0) {
			size = textbooks.getSize();

			system("cls");
			cout << endl;
			cout << "Welcome to our library website. Please, choose your option:" << endl << "1.Show backlist." << endl;
			cout << "2.Search textbook information by index." << endl << "3.Add new textbook to the website." << endl;
			cout << "4.Remove required textbook from the website." << endl << "5.EXIT." << endl << "You choose : " << endl;
			cin >> num;
			cout << "________________________________________________________________________________";

			if (num < 1 || num > 5) {
				cout << "You have chosen a non-existent option" << endl;
			}
			else {
				switch (num) {
				case 1:
					textbooks.printAll();
					break;
				case 2:
					cout << "Select textbook's index:";
					cin >> num;


					if (Test(num, size))
						textbooks.getRequiredTextbook(num - 1);
					break;
				case 3:
					cout << "Choose a place in the backlist for a new textbook:";
					cin >> num;

					int pages, grade, cost, year_of_release;
					char surname[30];
					cout << "Enter textbook's surname: ";
					cin >> surname;
					cout << "Enter the number of pages:  ";
					cin >> pages;
					cout << "Enter the grade this textbook for:  ";
					cin >> grade;
					cout << "Enter the textbook's cost:  ";
					cin >> cost;
					cout << "Enter the textbook's year of release:  ";
					cin >> year_of_release;
					cout << std::endl;

						textbooks.addTextbook(num, pages, grade, cost, year_of_release, surname);
						cout << endl << "Current backlist: " << endl;
						textbooks.printAll();
					break;
				case 4:
					i = 2;
					while (i > 1) {
						if (textbooks.getSize() > 0) {
							cout << "Select the textbook number of which you want to remove from the backlist";
							cin >> num;
							if (num > textbooks.getSize() || num <= 0)
								cout << endl << "Sorry, you've entered a non-existent index." << endl;
							else {
								textbooks.removeTextbook(num - 1);
								cout << endl << "Current backlist:" << endl;
								textbooks.printAll();
								i = 1;
							}
						}
						else {
							cout << "Backlist is clear! Everything has been deleted" << endl;
							i = 1;
						}
					}
					break;
				case 5:
					cout << "Work with the backlist is over, thanks for the work! Have a nice day." << endl;
					i = 0;
					textbooks.averageAmountOfPages(pages);
					break;
				}
				getchar();
			}
			getchar();
		}
	}
	delete[] tmp_backlist;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();

	getchar(); getchar();
	return 0;
}

bool Test(int num, int SIZE) {
	if (num > 0 && num < SIZE + 1)
		return true;
	else {
		cout << "You've entered an invalid value, try again" << endl;
		return false;
	}
}