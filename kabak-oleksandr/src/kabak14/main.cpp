#include "MathTI.h"
#include <vector>
#include <set>
#include <list>
#include <map>

#include <algorithm>

using std::vector;
using std::set;
using std::list;
using std::map;

using std::for_each;

template <class T1, class T2>
vector<T1> ContainerInsert(vector<T1> t1, vector<T2> t2){
	for (const auto& el : t2) {
		t1.insert(t1.end(), el);
	}
	return t1;
}

template<class T>
class forSort {
public:
	bool operator() (const T& a, const T& b) {
		return a < b;
	}
};

int main() {
	int num;

	cout << "Enter type of container" << endl << "1.Vector" << endl << "2.Set" << endl << "3.List" << endl << "4.Map" << endl;
	cin >> num;
	system("cls");


	MathTI newObj;
	forSort<MathTI> _sort;
	size_t index = -1;

	int mark;
	int amount = 0;
	string name;
	if (num == 1) {
		vector<MathTI> arr;
		vector<MathTI> arr2;
		while (true) {
			cout << "Quantity of objects in container: " << arr.size() << endl;
			cout << "What function do you want to cause  the list?" << endl;
			cout << "0.Exit from program" << endl;
			cout << "1.Print Array" << endl;
			cout << "2.Delete objest from array" << endl;
			cout << "3.Add new object to array" << endl;
			cout << "4.Access to element by index" << endl;
			cout << "5.Search for students by assessment" << endl;
			cout << "6.Search by name in container" << endl;
			cout << "7.Sort contaier" << endl;
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "All elements: " << endl;
				for_each(arr.begin(), arr.end(), [](auto& n) { cout << n; });
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
				arr2.push_back(newObj);
				arr = ContainerInsert(arr, arr2);
				arr2.clear();
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
				cout << "Enter grade for student search: ";
				cin >> mark;
				for (auto it : arr) {
					if (it.getMark() == mark) {
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
					if (name == it.getSur()) {
						cout << it;
					}
				}
				system("pause");
				system("cls");
				break;
			case 7:
				sort(arr.begin(), arr.end(), _sort);
				system("pause");
				system("cls");
				break;
			case 0:
				arr.clear();
				system("cls");
				return 0;
			}
		}
	}
	if (num == 2) {
		set<MathTI> arr;
		while (true) {
			cout << "Quantity of objects in container: " << arr.size() << endl;
			cout << "What function do you want to cause  the list?" << endl;
			cout << "0.Exit from program" << endl;
			cout << "1.Print Array" << endl;
			cout << "2.Delete objest from array" << endl;
			cout << "3.Add new object to array" << endl;
			cout << "4.Search for students by assessment" << endl;
			cout << "5.Search by name in container" << endl;
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "Elements in container: " << endl;
				for_each(arr.begin(), arr.end(), [](auto& n) { cout << n; });
				system("pause");
				system("cls");
				break;
			case 2:
				cin >> newObj;
				if (arr.find(newObj) != arr.end()) {
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
				cout << "Enter grade for student search: ";
				cin >> mark;
				for (auto it : arr) {
					if (it.getMark() == mark) {
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
					if (name == it.getSur()) {
						cout << it;
					}
				}
				system("pause");
				system("cls");
				break;
			case 0:
				arr.clear();
				system("cls");
				return 0;
			}
		}
	}
	if (num == 3) {
		list<MathTI> arr;
		while (true) {
			cout << "Quantity of objects in container: " << arr.size() << endl;
			cout << "What function do you want to cause  the list?" << endl;
			cout << "0.Exit from program" << endl;
			cout << "1.Print Array" << endl;
			cout << "2.Delete objest from array" << endl;
			cout << "3.Add new object to array" << endl;
			cout << "4.Search for students by assessment" << endl;
			cout << "5.Search by name in container" << endl;
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "Elements in container: " << endl;
				for_each(arr.begin(), arr.end(), [](auto& n) { cout << n; });
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
				cout << "Enter grade for student search: ";
				cin >> mark;
				for (auto it : arr) {
					if (it.getMark() == mark) {
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
					if (name == it.getSur()) {
						cout << it;
					}
				}
				system("pause");
				system("cls");
				break;
			case 0:
				arr.clear();
				system("cls");
				return 0;
			}
		}
	}
	if (num == 4) {
		map<int, MathTI> arr;
		while (true) {
			cout << "Quantity of objects in container: " << arr.size() << endl;
			cout << "What function do you want to cause  the list?" << endl;
			cout << "0.Exit from program" << endl;
			cout << "1.Print Array" << endl;
			cout << "2.Delete objest from array" << endl;
			cout << "3.Add new object to array" << endl;
			cout << "4.Search for students by assessment" << endl;
			cout << "5.Search by name in container" << endl;
			cin >> num;
			system("cls");
			switch (num) {
			case 1:
				cout << "Elements in container: " << endl;
				for_each(arr.begin(), arr.end(), [](auto& it) {
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
				cout << "Enter grade for student search: ";
				cin >> mark;
				for (auto& it : arr) {
					if (it.second.getMark() == mark) {
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
					if (name == it.second.getSur()) {
						cout << it.second;
					}
				}
				system("pause");
				system("cls");
				break;
			case 0:
				arr.clear();
				system("cls");
				return 0;
			}
		}
	}


	return 0;
}
