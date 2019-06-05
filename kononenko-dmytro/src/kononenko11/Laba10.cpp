#include <iostream>
#include "Shablon.h"
#include "InfoWork.h"
using std::cout;
using std::cin;
using std::endl;



int main() {
	int choose;
	Shablon<InfoWork, 5> arr;
	InfoWork value;
	arr.fill();


	do {
		cin.ignore();
		cout << "\n";
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - sort vector" << endl;
		cout << "3 - find lowest" << endl;
		cout << "4 - find by value" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 0:
			break;
		case 1:
			arr.printOut();
			break;
		case 2:
			system("cls");
			arr.sort();
			break;
		case 3:
			system("cls");
			value = arr.lowest();
			cout << value;
			break;
		case 4:
			cout << "input value: ";
			cin >> value;
			system("cls");
			cout << arr.find(value);
			break;
		default:
			break;
		}
	} while (choose != 0);


	return 0;
 }