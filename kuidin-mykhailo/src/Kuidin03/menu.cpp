#include "School.h"
#include "InfoStorge.h"

void InfoStorge::menu() {
	InfoStorge tmp;
	unsigned int coun = 0, num = 0, cos = 0, pup = 0, emp = 0, index = 0;
	string p="0";
	string fname = "start.txt";
	int i = 0;
	int a = 100;
	int b = 100;
	while (b != 0) {
		cout << "How many objects do u wnat to create?\n";
		cin >> coun;
		tmp.setCount(coun);
		tmp.createObjects();
		system("cls");
		cout << "Do u want take info: \n From file - 1 \n From keyboard - 2 \n Your choose: ";
		cin >> b;
		switch (b) {
		case 1:
			for (int i = 0; i < coun; i++) {
				tmp.readFromFile(fname, num, cos, pup, emp, p, i);
			}
			b = 0;
			break;
		case 2:
			for (int i = 0; i < coun; i++) {
				system("cls");
				cout << "Count of object: " << (i + 1) << endl;
				cout << "Enter cost per month: ";
				cin >> cos;
				fseek(stdin, 0, SEEK_END);

				cout << "Enter type (gymnasium, high, secondary, primary) if school: ";
				std::getline(cin, p);

				cout << "Enter number of school: ";
				cin >> num;

				cout << "Enter number of pupils: ";
				cin >> pup;

				cout << "Enter number of employers: ";
				cin >> emp;
				tmp.setAll(i, num, cos, pup, emp, p);
			}
			b = 0;
			break;
		}
		
		
		while (a != 0) {

			cout << "Menu: \n 1 - Add new objects \n 2 - Delete object \n 3 - Find by index \n 4 - Print all schools \n 5 - Print schools with employers more than average \n 0 - End program \n Your choose: ";
			cin >> a;
			switch (a)
			{
			case 1:
				system("cls");

				cout << "In which position u want add new school? Last position:" << tmp.count << endl;
				cin >> index;
				while (tmp.count < index || index < 1) {
					cout << "You can't put in this position, choose another! Last position: " << tmp.count << endl;
					cin >> index;
				}

				cout << "Enter cost per month: ";
				cin >> cos;
				fseek(stdin, 0, SEEK_END);

				cout << "Enter type (gymnasium, high, secondary, primary) if school: ";
				std::getline(cin, p);

				cout << "Enter number of school: ";
				cin >> num;

				cout << "Enter number of pupils: ";
				cin >> pup;

				cout << "Enter number of employers: ";
				cin >> emp;
				tmp.addObject((index-1), num, cos, pup, emp, p);
				break;
			case 2:
				system("cls");

				cout << "Enter index ";
				cin >> i;
				tmp.delElem(i);
				break;
			case 3:
				system("cls");

				cout << "Enter index ";
				cin >> i;
				tmp.find((i - 1));
				break;
			case 4:
				system("cls");
				tmp.printall();
				break;
			case 5:
				system("cls");
				tmp.average();
				break;
			case 0:

				a = 0;
				break;
			}
		}

		cout << "Do u want print all objects to file? \n Yes - 1 \n No - 2\n Your choose: ";
		cin >> a;
		if (a == 1) {
			tmp.clearFile("end");
			for (int i = 0; i < tmp.count; i++) {
				tmp.printToFile(i);
			}
		}
	}
	
	tmp.deleteall();
}