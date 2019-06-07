#include"Textbook.h"
#include"Library.h"

bool comp(int x, int y) {
	return x < y;
}

bool comp2(int x, int y) {
	return x > y;
}

int main() {

	Library textbooks;
	Textbook figure;
	figure.printInfo();
	Textbook stats;
	stats.RatingStats();

	regex regex_UpperRegister("^[A-Z]");
	regex regex_space("[\\s]{2,}");

	int size;
	string surname;
	cout << "Enter the author's name: ";
	getline(cin, surname);
	if (!(regex_search(surname, regex_UpperRegister)) || regex_search(surname, regex_space)) {
		cout << "You've entered incorrect surname. Please, try again. " << endl;
		cout << "Enter the author's name: ";
		getline(std::cin, surname);
	}
	cout << "Enter the number of textbooks: " << endl;
	cin >> size;

	textbooks.getSurname(surname);
	textbooks.printAll();

	bool(*bubble)(int a, int b);

	int option = 0;
	do {
		cout << "Welcome to our libraries website. Please, choose your option: " << endl << "1 - Add new textbook." << endl << "2 - Delete some textbook" << endl
		<< "3 - Find required texbook." << endl << "4 - Show average amount of textbook's pages in our library. " << endl << "5 - Sort textbooks by cost." << endl << "6 - Exit " << endl;
		cout << endl;
		cin >> option;

		switch (option) {
		case 1: {
			int num, pages, grade, cost, year_of_release;
			string author;
			ifstream fin("Textbook info.txt");
			fin >> num >> pages >> grade >> cost >> year_of_release >> author;
			textbooks.addTextbook(num, pages, grade, cost, year_of_release, author);
			fin >> num >> pages >> grade >> cost >> year_of_release >> author;
			textbooks.addTextbook(num, pages, grade, cost, year_of_release, author);
			fin >> num >> pages >> grade >> cost >> year_of_release >> author;
			textbooks.addTextbook(num, pages, grade, cost, year_of_release, author);
			fin >> num >> pages >> grade >> cost >> year_of_release >> author;
			textbooks.addTextbook(num, pages, grade, cost, year_of_release, author);
			system("cls");
			textbooks.printAll();
			break;
		}
		case 2: {
			auto num = 0;
			cout << endl << "Enter number of textbook which you want to remove: ";
			cin >> num;
			cout << endl;
			textbooks.removeTextbook(num);
			system("cls");
			textbooks.printAll();
			break;
		}
		case 3: {
			auto index = 0;
			cout << endl << "Enter index : ";
			cin >> index;
			cout << endl;
			system("cls");
			textbooks.getRequiredTextbook(index);
			break;
		}
		case 4: {
			textbooks.averageAmountOfPages(size);
			break;
		}
		case 5: {
			int op;
			cout << "Please, choose the type of sort" << endl << "1 - up, 0 - down: ";
			cin >> op;
			cout << endl;
			if (op == 1) {
				bubble = comp;
			}
			else if (op == 0) {
				bubble = comp2;
			}
			else {
				cout << "You enter false variant" << endl;
				break;
			}
			textbooks.sortByCost(bubble);
			textbooks.printAll();
			break;
		}
		case 6: {
			break;
		}
		}
	} while (option != 6);

	textbooks.deleteBacklist();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	_CrtDumpMemoryLeaks();
	return 0;
}