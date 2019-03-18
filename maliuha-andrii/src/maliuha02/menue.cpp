#include "Header.h"

void menu() {
	int num;
	int ind;
	int sizeMas = 0;
	char* n = new char[50];
	char* p = new char[50];
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
		cout << "(6)show programs, that take up more memory of a given size" << endl;
		cout << "(7)to delete suspicious programs from array" << endl;
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
			cout << "('0' exit from search)Enter name of program from array: ";
			
			while (getchar() != '\n') {
				continue;
			}

			gets_s(n, 49);
			
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
			cout << "Enter index of object for delete it: ";
			cin >> ind;
			sizeMas = ops.getSize(sizeMas);
			if (ind <= sizeMas + 1 && ind >= 1) {
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
			if (ind <= sizeMas + 1 && ind >= 1) {

				while (getchar()!='\n'){
					continue;
				}

				cout << "Enter name of program:" << endl;
				gets_s(n, 49);

				cout << "Enter name of publisher(if you don't know, enter 'unknown'):" << endl;
				gets_s(p, 49);

				cout << "Enter amount of consumed RAM(Mb):" << endl;
				cin >> om;
				cout << "Enter ocupied amount of hard disk memory(Mg):" << endl;
				cin >> mg;
				cout << "Enter time of work (in minutes):" << endl;
				cin >> twm;
				ops.addProgram(ind, n, p, mg, om, twm);

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
		case 6:
			cout << "Enter size of memory: ";
			cin >> mg;
			ops.findProgram(mg);
			
			system("pause");
			system("cls");
			break;
		case 7:
			ops.removeViruses();
			sizeMas = ops.getSize(sizeMas);

			break;
		case 0:
			ops.delMas();
			delete[] n;
			delete[] p;
			return;
		}
	}
}