#include "Main.h"

void menue() {
	int num;

	cout << "Enter type of container" << endl;
	cout << "(1)vector" << endl;
	cout << "(2)set" << endl;
	cout << "(3)list" << endl;
	cout << "(4)map" << endl;
	cin >> num;
	system("cls");
	InstalledProgram newObj, *erase;
	int index = -1;
	float hDisk;
	int amount = 0;
	string name;
	if (num == 1) {
		vector<InstalledProgram> arr;
		while (true) {
			cout << "Quantity of objects in container: " << arr.size() << endl;
			cout << "What function do you want to cause  the list?" << endl;
			cout << "(0)exit from program" << endl;
			cout << "(1)output array on display" << endl;
			cout << "(2)to delete objest from array" << endl;
			cout << "(3)to add new object to array" << endl;
			cout << "(4)take access to element by index" << endl;
			cout << "(5)to take the amount of programs by a given criterion" << endl;
			cout << "(6)search by name in container" << endl;
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "All elements: " << endl;
				for_each(arr.begin(), arr.end(), [](auto &n) { 
					cout << n; 
				});
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "Enter index of element for delete: ";
				cin >> index;
				if (index >= 0 && index < arr.size()) {
					arr.erase(arr.begin() + index);
					system("pause");
				}
				else {
					cout << "Thereis no element with this index" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 3:
				cin >> newObj;
				arr.push_back(newObj);
				system("pause");
				system("cls");
				break;
			case 4:
				cout << "Enter index of element for output: ";
				cin >> index;
				if (index >= 0 && index < arr.size()) {
					newObj = arr[index];
					cout << newObj;
					system("pause");
				} 
				else {
					cout << "Thereis no element with this index" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 5:
				cout << "Enter the amount of used memory on the hard disk fo search: ";
				cin >> hDisk;
				for (auto it : arr) {
					if (it.getHDisk() == hDisk) {
						amount++;
						cout << it;
					}
				}
				cout << "Amount of programs - " << amount << endl;
				amount = 0;
				system("pause");
				system("cls");
				break;
			case 6:
				cout << "Enter name of program for searching: " << endl;
				cin.ignore(1);
				getline(cin, name);
				for (auto it : arr) {
					if (name == it.getName()) {
						cout << it;
					}
				}
				system("pause");
				system("cls");
				break;
			case 0:
				arr.clear();
				system("cls");
				return;
			}
		}
	}
	if (num == 2) {
		set<InstalledProgram> arr;
		while (true) {
			cout << "Quantity of objects in container: " << arr.size() << endl;
			cout << "What function do you want to cause  the list?" << endl;
			cout << "(0)exit from program" << endl;
			cout << "(1)output array on display" << endl;
			cout << "(2)to delete objest from array" << endl;
			cout << "(3)to add new object to array" << endl;
			cout << "(4)to take the amount of programs by a given criterion" << endl;
			cout << "(5)search by name in container" << endl;
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "Elements in container: " << endl;
				for_each(arr.begin(), arr.end(), [](auto &n) {
					cout << n;
				});
				system("pause");
				system("cls");
				break;
			case 2:
				cin >> newObj;
				if(arr.find(newObj) != arr.end()) {
					arr.erase(newObj);
				}
				else {
				cout << "Doesn`t exist: " << newObj << endl;
				}

				break;
			case 3:
				cin >> newObj;
				arr.insert(newObj);
				system("pause");
				system("cls");
				break;
			case 4:
				cout << "Enter the amount of used memory on the hard disk fo search: ";
				cin >> hDisk;
				for (auto it : arr) {
					if (it.getHDisk() == hDisk) {
						amount++;
						cout << it;
					}
				}
				cout << "Amount of programs - " << amount << endl;
				amount = 0;
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "Enter name of program for searching: " << endl;
				cin.ignore(1);
				getline(cin, name);
				for (auto it : arr) {
					if (name == it.getName()) {
						cout << it;
					}
				}
				system("pause");
				system("cls");
				break;
			case 0:
				arr.clear();
				system("cls");
				return;
			}
		}
	}
	if (num == 3) {
		list<InstalledProgram> arr;
		while (true) {
			cout << "Quantity of objects in container: " << arr.size() << endl;
			cout << "What function do you want to cause  the list?" << endl;
			cout << "(0)exit from program" << endl;
			cout << "(1)output array on display" << endl;
			cout << "(2)to delete objest from array" << endl;
			cout << "(3)to add new object to array" << endl;
			cout << "(4)to take the amount of programs by a given criterion" << endl;
			cout << "(5)search by name in container" << endl;
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "Elements in container: " << endl;
				for_each(arr.begin(), arr.end(), [](auto &n) {
					cout << n;
				});
				system("pause");
				system("cls");
				break;
			case 2:
				if (arr.size() > 0) {
					arr.pop_back();
				}
				system("cls");
				break;
			case 3:
				cin >> newObj;
				arr.push_back(newObj);
				system("pause");
				system("cls");
				break;
			case 4:
				cout << "Enter the amount of used memory on the hard disk fo search: ";
				cin >> hDisk;
				for (auto it : arr) {
					if (it.getHDisk() == hDisk) {
						amount++;
						cout << it;
					}
				}
				cout << "Amount of programs - " << amount << endl;
				amount = 0;
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "Enter name of program for searching: " << endl;
				cin.ignore(1);
				getline(cin, name);
				for (auto it : arr) {
					if (name == it.getName()) {
						cout << it;
					}
				}
				system("pause");
				system("cls");
				break;
			case 0:
				arr.clear();
				system("cls");
				return;
			}
		}
	}
	if (num == 4) {
		map<int, InstalledProgram> arr;
		while (true) {
			cout << "Quantity of objects in container: " << arr.size() << endl;
			cout << "What function do you want to cause  the list?" << endl;
			cout << "(0)exit from program" << endl;
			cout << "(1)output array on display" << endl;
			cout << "(2)to delete objest from array" << endl;
			cout << "(3)to add new object to array" << endl;
			cout << "(4)to take the amount of programs by a given criterion" << endl;
			cout << "(5)search by name in container" << endl;
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "Elements in container: " << endl;
				for_each(arr.begin(), arr.end(), [](auto &it) {
					cout << "index: " << it.first << endl << it.second << endl;
				});
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "Enter index of element for delete: ";
				cin >> index;
				if (index >= 0 && index < arr.size()) {
					arr.erase(index);
				}
				else {
					cout << "Thereis no element with this index" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 3:
				cin >> newObj;
				index = arr.size();
				arr.emplace(index, newObj);
				system("pause");
				system("cls");
				break;
			case 4:
				cout << "Enter the amount of used memory on the hard disk fo search: ";
				cin >> hDisk;
				for (auto &it : arr) {
					if (it.second.getHDisk() == hDisk) {
						amount++;
						cout << it.second;
					}
				}
				cout << "Amount of programs - " << amount << endl;
				amount = 0;
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "Enter name of program for searching: " << endl;
				cin.ignore(1);
				getline(cin, name);
				for (auto it : arr) {
					if (name == it.second.getName()) {
						cout << it.second;
					}
				}
				system("pause");
				system("cls");
				break;
			case 0:
				arr.clear();
				system("cls");
				return;
			}
		}
	}
}