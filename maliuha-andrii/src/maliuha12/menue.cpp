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
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "All elements: " << endl;
				for (auto it : arr) {
					cout << it;
				}
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
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "Elements in container: " << endl;
				for (auto it : arr) {
					cout << it;
				}
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
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "Elements in container: " << endl;
				for (auto it : arr) {
					cout << it;
				}
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
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "Elements in container: " << endl;
				for (const auto &it : arr) {
					cout << "index: " << it.first << endl << it.second << endl;
				}
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
			case 0:
				arr.clear();
				system("cls");
				return;
			}
		}
	}
}