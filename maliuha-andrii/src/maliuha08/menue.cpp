#include "Main.h"

void menu() {
	int num;
	int ind;
	int sizeMas = 0;
	string n;
	string p;
	float om, mg;
	Time timer;
	string infoObj;
	WorkingProgram newObj;

	string endFile;
	Array ops;
	ifstream object;
	string endOfFile;
	while (true) {
		cout << "Quantity of objects in array: " << sizeMas << endl;
		cout << "What function do you want to cause  the list?" << endl;
		cout << "(0)exit from program" << endl;
		cout << "(1)output array on display" << endl;
		cout << "(2)name search" << endl;
		cout << "(3)to delete objest from array" << endl;
		cout << "(4)to add new object to array" << endl;
		cout << "(5)index output on display" << endl;
		cout << "(6)show programs, that take up more memory of a given size" << endl;
		cout << "(7)to delete suspicious programs from array" << endl;
		cout << "(8)to read inforamtion of objects from file" << endl;
		cout << "(9)to write array to file" << endl;
		cout << "(10)output objects from array with one word in name" << endl;
		cout << "(11)to sort array" << endl;
		cout << "(12)to count viruses" << endl;
		cin >> num;
		system("cls");

		switch (num) {
		case 1:
			cout << ops;
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cin.ignore();
			cout << "('0' exit from search)Enter name of program from array: ";
			getline(cin, n);

			if (n == "0") {
				system("cls");
				break;
			}
			else {
				ops.nameSearch(n);
				cout << endl;
				system("pause");
				system("cls");
				break;
			}
		case 3:
			cout << "Enter number of object for delete it: ";
			cin >> ind;
			sizeMas = ops.getSize();
			if (ind <= sizeMas + 1 && ind >= 1) {
				ops.removeProgram(ind);
				sizeMas = ops.getSize();
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
			cout << "Enter number of object for add it to array: ";
			cin >> ind;
			sizeMas = ops.getSize();

			cin.ignore();
			if (ind <= sizeMas + 1 && ind >= 1) {
				cin >> newObj;
				ops.addProgram(newObj, ind);
				sizeMas = ops.getSize();
				system("cls");
				break;
			}
			else {
				cout << "There is no object in the array with this index" << endl;

				system("pause");
				system("cls");
				break;
			}

			infoObj = "";
			break;
		case 5:
			cout << "Enter number of object from array: ";
			cin >> ind;
			sizeMas = ops.getSize();
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
		case 6:
			cout << "Enter size of memory: ";
			cin >> mg;
			ops.findProgram(mg);

			system("pause");
			system("cls");
			break;
		case 7:
			ops.removeViruses();
			sizeMas = ops.getSize();
			system("cls");
			break;
		case 8:
			ops.readFromFile(sizeMas, ops);
			system("cls");
			break;
		case 9:
			ops.writeToFile();
			system("cls");
			break;
		case 10:
			ops.sortOutput();
			system("pause");
			system("cls");
			break;
		case 11:
			ops.DirectMergeSort(0, sizeMas - 1);
			system("cls");
			break;
		case 12:
			ops.countElem();
			break;
		case 0:
			ops.delMas();
			return;
		}
	}
}