#include "Main.h"

void menu() {
	int num;
	int ind;
	int sizeMas = 0;
	string n;
	string p;
	float om, mg;
	Time *timer = new Time;
	timer->hours = 0;
	timer->minutes = 0;
	timer->seconds = 0;
	string infoObj;
	Program *pObj;
	WorkingProgram newObj1;
	InstalledProgram newObj2;
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
		cout << "(10)output objects from array with more than one word in name" << endl;
		cout << "(11)to sort array" << endl;
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
			cout << "Enter type of program ((1)working programm, (other numbers)installed program) - ";
			cin >> ind;
			if (ind == 1) {
				cout << "Enter number of object for add it to array: ";
				cin >> ind;
				sizeMas = ops.getSize();

				cin.ignore();
				if (ind <= sizeMas + 1 && ind >= 1) {

					ops.setInfoObj(infoObj);
					newObj1.setObj(infoObj);
					pObj = &newObj1;
					ops.addProgram(pObj, ind);
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
			}
			else {
				cout << "Enter number of object for add it to array: ";
				cin >> ind;
				sizeMas = ops.getSize();

				cin.ignore();
				if (ind <= sizeMas + 1 && ind >= 1) {

					ops.setInfoObj(infoObj);
					newObj2.setObj(infoObj);
					pObj = &newObj1;
					ops.addProgram(pObj, ind);

					newObj2.setName("");
					newObj2.setPublisher("");
					newObj2.setRAM(0);
					newObj2.setHDisk(0);
					newObj2.setTimer(timer);

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
			object.open("maliuha03.txt");

			if (!object.is_open()) {
				cout << "File was not opened" << endl;
				system("pause");
				break;
			}

			while (true) {
				ind = sizeMas + 1;
				ops.readFromFile(object, infoObj, endFile);
				if (endFile == "end") {
					break;
				}
				ops.setInfoObj(infoObj);
				newObj1.setObj(infoObj);
				pObj = &newObj1;
				ops.addProgram(pObj, ind);

				newObj1.setName("");
				newObj1.setPublisher("");
				newObj1.setRAM(0);
				newObj1.setHDisk(0);
				newObj1.setTimer(timer);

				sizeMas = ops.getSize();
				system("cls");
				infoObj = "";
				sizeMas = ops.getSize();
			}
			object.close();
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
		case 0:
			ops.delMas();
			return;
		}
	}
}