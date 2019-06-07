#include "ElectronicLibrary.h"

bool comp(int x, int y) {
	return x < y;
}

bool comp2(int x, int y) {
	return x > y;
}

int main() {

	ElectronicLibrary textbooks;

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

	string *link;
	link = new string[4];
	link[0] = "http://cppstudio.com/post/10103/";
	link[1] = "https://metanit.com/cpp/tutorial/5.12";
	link[2] = "https://cpp-khpi.github.io/";
	link[3] = "https://www.twitch.tv/";
	int l = rand() % 4 + 0;

	textbooks.getSurname(surname, link[l]);
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
			l = rand() % 4 + 0;
			fin >> num >> pages >> grade >> cost >> year_of_release >> author;
			textbooks.addTextbook(num, pages, grade, cost, year_of_release, author, link[l]);
			l = rand() % 4 + 0;
			fin >> num >> pages >> grade >> cost >> year_of_release >> author;
			textbooks.addTextbook(num, pages, grade, cost, year_of_release, author, link[l]);
			l = rand() % 4 + 0;
			fin >> num >> pages >> grade >> cost >> year_of_release >> author;
			textbooks.addTextbook(num, pages, grade, cost, year_of_release, author, link[l]);
			l = rand() % 4 + 0;
			fin >> num >> pages >> grade >> cost >> year_of_release >> author;
			textbooks.addTextbook(num, pages, grade, cost, year_of_release, author, link[l]);
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