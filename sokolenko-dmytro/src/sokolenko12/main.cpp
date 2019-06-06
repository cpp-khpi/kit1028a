#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>

#include "IosPhone.h"

using std::vector;
using std::set;
using std::list;
using std::map;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	cout << "Hello, please enter a template container" << endl << "1 - Vector" << endl << 
		"2 - Set" << endl << "3 - List" << endl << "4 - Map" << endl;
	
	char choice = 0;
	int index;
	while (choice != '1' &&
		choice != '2' &&
		choice != '3' &&
		choice != '4') {
		cout << endl << "Option: ";
		cin >> choice;
	}

	cout << "Enter an object type" << endl << "1 - Int" << endl << "2 - Phone" << endl <<
		"3 - IosPhone" << endl;

	choice = 0;
	while (choice != '1' &&
		choice != '2' &&
		choice != '3') {
		cout << endl << "Option: ";
		cin >> choice;
	}

	typedef int element;
	switch (choice) {
	case('1'): {
		typedef int element;
		break;
	}
	case('2'): {
		typedef Phone element;
		break;
	}
	case('3'): {
		typedef IosPhone element;
		break;
	}
	}

	switch (choice) {
	case('1'): {
		vector<element> container;

		cout << "What do you want to do?" << endl << "1 - Add" << endl << "2 - Delete"  <<
			endl << "3 - Show All" << endl << "0 - Exit" << endl;

		choice = 0;
		while (choice != '1' &&
			choice != '2' &&
			choice != '3' && 
			choice != '0') {
			cout << endl << "Option: ";
			cin >> choice;
		}

		element newElem;
		switch (choice) {
		case('1'): {
			cin >> newElem;
			container.push_back(newElem);
			break;
		}
		case('2'): {
			cout << "Enter index for delete: ";
			cin >> index;
			container.erase(container.begin() + index);
			break;
		}
		case('3'): {
			cout << "All elements: " << endl;
			for (auto &it:container) {
				cout << it;
			}
			break;
		}
		}
		break;
	}
	case('2'): {
		set<element> container;
		cout << "What do you want to do?" << endl << "1 - Add" << endl << "2 - Delete" <<
			endl << "3 - Show All" << endl << "0 - Exit" << endl;

		choice = 0;
		while (choice != '1' &&
			choice != '2' &&
			choice != '3'&&
			choice != '0') {
			cout << endl << "Option: ";
			cin >> choice;
		}

		element newElem;
		switch (choice) {
		case('1'): {
			cin >> newElem;
			container.insert(newElem);
			break;
		}
		case('2'): {
			cout << "Enter index for delete: ";
			cin >> index;
			container.erase(index);
			break;
		}
		case('3'): {
			cout << "All elements: " << endl;
			for (auto &it : container) {
				cout << it;
			}
			break;
		}
		}
		break;
	}
	case('3'): {
		list<element> container;

		cout << "What do you want to do?" << endl << "1 - Add" << endl << "2 - Delete" <<
			endl << "3 - Show All" << endl << "0 - Exit" << endl;

		choice = 0;
		while (choice != '1' &&
			choice != '2' &&
			choice != '3'&&
			choice != '0') {
			cout << endl << "Option: ";
			cin >> choice;
		}

		element newElem;
		switch (choice) {
		case('1'): {
			cin >> newElem;
			container.push_back(newElem);
			break;
		}
		case('2'): {
			cout << "Enter index for delete: ";
			cin >> index;
			auto it = container.begin();
			advance(it, index);
			container.erase(it);
			break;
		}
		case('3'): {
			cout << "All elements: " << endl;
			for (auto &it : container) {
				cout << it;
			}
			break;
		}
		}
		break;
	}
	case('4'): {
		map<int, element> container;
		cout << "What do you want to do?" << endl << "1 - Add" << endl << "2 - Delete" <<
			endl << "3 - Show All" << endl << "0 - Exit" << endl;

		choice = 0;
		while (choice != '1' &&
			choice != '2' &&
			choice != '3'&&
			choice != '0') {
			cout << endl << "Option: ";
			cin >> choice;
		}

		element newElem;
		switch (choice) {
		case('1'): {
			cout << "Input index: ";
			cin >> index;
			cout << "Input new element: " << endl;
			cin >> newElem;
			container.emplace(index, newElem);
			break;
		}
		case('2'): {
			cout << "Enter index for delete: ";
			cin >> index;
			container.erase(index);
			break;
		}
		case('3'): {
			cout << "All elements: " << endl;
			for (const auto& it : container) {
				cout << it.first << "  " << it.second << endl;
			}
			break;
		}
		}
		break;
	}
	}
}