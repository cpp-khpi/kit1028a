#pragma once

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::vector;
using std::map;
using std::for_each;
using std::cin;
using std::cout;
using std::endl;

template<class T>
void printElem(const T& printedObject)
{
	cout << printedObject << endl;
}

template<class T>
vector<T>& vectorConcatenation(vector<T>& fist, vector<T>& second){
	for (const auto& element: second) {
		first.insert(first.end(), elelemnt);
	}
	return t1;
}

template<class T>
class Ascending {
public:
	bool operator() (const T& first, const T& second) {
		return first < second;
	}
};

template<class T>
void vectorMenu()
{
	cout << "Hello! Start working with vector." << endl;
	vector<T> container;

	char choice = 0;
	T newElem;
	int index;
	int amount;
	Ascending<T> sortAscending;
	while (choice != '0') {
		cout << "What do you want to do?" << endl << "1 - Add new element" <<
			endl << "2 - Delete element" << endl << "3 - Show element by index" <<
			endl << "4 - Show all" << endl << "5 - Show amount elemnets by criteria." <<
			endl << "6 - Find element by criteria" << endl << "7 - Sort elements" << endl <<
			endl << "0 - Exit" << endl;

		choice = 0;
		while (choice != '0' &&
			choice != '1' &&
			choice != '2' &&
			choice != '3' &&
			choice != '4' &&
			choice != '5' &&
			choice != '6') {
			cout << endl << "Option: ";
			cin >> choice;
		}

		switch (choice) {
		case '1': {
			cout << "New elem: ";
			cin >> newElem;
			container.push_back(newElem);
			break;
		}
		case '2': {
			cout << "Enter index for delete: ";
			cin >> index;
			container.erase(container.begin() + index);
			break;
		}
		case '3': {
			cout << "Enter index for showing: ";
			cin >> index;
			cout << container[index];
			break;
		}
		case '4': {
			for_each(container.begin(), container.end(), printElem<T>);
			break;
		}
		case '5': {
			cout << "Enter object-criteria: ";
			cin >> newElem;

			amount = 0;

			for (auto &element:container)
				if (element == newElem)
					amount++;
			cout << "Amount = " << amount << endl;

			break;
		}
		case '6': {
			cout << "Enter object-criteria: ";
			cin >> newElem;

			for (auto &element :container)
				if (element == newElem)
					cout << element;
			break;
		}
		case '7': {
			sort(qual.begin(), qual.end(), sortAscending);
			break;
		}
		}

	}
}

template<typename T1, class T2>
void mapMenu()
{
	cout << "Hello! Start working with map." << endl;
	map<T1, T2> container;

	char choice = 0;
	T2 newElem;
	int index;
	int amount;
	while (choice != '0') {
		cout << "What do you want to do?" << endl << "1 - Add new element" <<
			endl << "2 - Delete element" << endl << "3 - Show element by index" <<
			endl << "4 - Show all" << endl << "5 - Show amount elemnets by criteria." <<
			endl << "6 - Find element by criteria" << endl << endl << "0 - Exit" << endl;

		choice = 0;
		while (choice != '0' &&
			choice != '1' &&
			choice != '2' &&
			choice != '3' &&
			choice != '4' &&
			choice != '5' &&
			choice != '6') {
			cout << endl << "Option: ";
			cin >> choice;
		}

		switch (choice) {
		case '1': {
			cout << "New elem: ";
			cin >> newElem;

			cout << "Enter index of new element: ";
			cin >> index;
			container.emplace(index, newElem);
			break;
		}
		case '2': {
			cout << "Enter index for delete: ";
			cin >> index;
			container.erase(index);
			break;
		}
		case '3': {
			cout << "Enter index for showing: ";
			cin >> index;
			cout << container[index];
			break;
		}
		case '4': {
			for (const auto& element:container) {
				cout << element.first << " | " << element.second << endl;
			}
			break;
		}
		case '5': {
			cout << "Enter object-criteria: ";
			cin >> newElem;

			amount = 0;

			for (auto &element : container)
				if (element.second == newElem)
					amount++;
			cout << "Amount = " << amount << endl;

			break;
		}
		case '6': {
			cout << "Enter object-criteria: ";
			cin >> newElem;

			for (auto &element:container)
				if (element.second == newElem)
					cout << element.first << " | " << element.second << endl;
			break;
		}
		}

	}
}
