#include "Header.h"

void menu() {
	int num;
	int ind;
	int sizeMas = 0;
	string n;
	float om, mg, twm;

	Array ops;

	while (true) {
		cout << "Quantity of objects in array: " << sizeMas << endl;
		cout << "What function do you want to cause  the list?" << endl;
		cout << "(0)Exit from program" << endl;
		cout << "(1)output array on display" << endl;
		cout << "(2)name search" << endl;
		cout << "(3)to delete objest from array" << endl;
		cout << "(4)to add new object to array" << endl;
		cout << "(5)index output on display" << endl;
		cin >> num;
		system("cls");
		switch (num) {
		case 1:
			ops.showAll();
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Instead of a space use '_'. It is a feature of the program." << endl;
			cout << "Otherwise the program will not work. You have been warned." << endl;
			cout << "('0' exit from search)Enter name of program from array: ";
			cin >> n;
			if (n == "0") {
				system("cls");
				break;
			}
			else {
				ops.searchProgram(n);
				cout << endl;
				system("pause");
				system("cls");
				break;
			}
		case 3:
			cout << "Enter index of object for delete it: ";
			cin >> ind;
			sizeMas = ops.getSize(sizeMas);
			if (sizeMas != 0 && ind > 0) {
				ops.removeProgram(ind);
				sizeMas = ops.getSize(sizeMas);
				system("cls");
				break;
			}
			else {
				cout << "There is no object in the array with this index" << endl;

				system("pause");
				system("cls");
				break;
			}
		case 4:
			cout << "Enter index of object for add it to array: ";
			cin >> ind;
			sizeMas = ops.getSize(sizeMas);
			if (ind > 0 && ind <= sizeMas + 1) {

				cout << "Instead of a space use '_'. It is a feature of the program." << endl;
				cout << "Otherwise the program will not work. You have been warned." << endl;
				cout << "Enter name of program:" << endl;
				cin >> n;
				cout << "Enter amount of consumed RAM(Mb):" << endl;
				cin >> om;
				cout << "Enter ocupied amount of hard disk memory(Mg):" << endl;
				cin >> mg;
				cout << "Enter time of work (in minutes):" << endl;
				cin >> twm;
				ops.addProgram(ind, n, mg, om, twm);

				sizeMas = ops.getSize(sizeMas);
				system("cls");
				break;
			}
			else {
				cout << "There is no object in the array with this index" << endl;

				system("pause");
				system("cls");
				break;
			}
			break;
		case 5:
			cout << "Enter index of object from array: ";
			cin >> ind;
			sizeMas = ops.getSize(sizeMas);
			if (ind <= sizeMas && ind >= 1) {
				ops.getProgram(ind);

				system("pause");
				system("cls");
				break;
			}
			else {
				cout << "There is no object in the array with this index" << endl;

				system("pause");
				system("cls");
				break;
			}
		case 0:
			ops.deleteArray();
			return;
		}
	}
}