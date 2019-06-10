#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include "Country.h"

using namespace std;

struct Print {
	Print(){}
	void operator()(Country printCountry) { cout << printCountry << " "; cout << endl; }

};

void Vector() {
	vector<Country> myVector;
	int choose, id;
	Country country;
	string name;
	cout << "Vector" << endl;
	do {
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - Find element by index" << endl;
		cout << "3 - Add element" << endl;
		cout << "4 - Delete element" << endl;
		cout << "5 - Number of elements" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			for_each(myVector.begin(), myVector.end(), Print());
			break;
		case 2:
			cout << "input index: ";
			cin >> id;
			cout << myVector.at(id);
			break;
		case 3: {
			cout << "Please, enter the name of country: ";
			cin >> name;
			cout << endl;
			country.setData(name);
			myVector.push_back(country);
			break;
		}
		case 4:
			myVector.clear();
			break;
		case 5:
			cout << "Number of elements is: " << myVector.size() << endl;
			break;
		default:
			break;
		}
	} while (choose != 0);
}

void Set() {
	int choose, id;
	set<Country> mySet;
	Country country;
	string name;
	cout << "Set" << endl;

	do {
		cout << "0 - Exit" << endl;
		cout << "1 - Print" << endl;
		cout << "2 - Add element" << endl;
		cout << "3 - Delete element" << endl;
		cout << "4 - Number of elements" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			for (auto &it : mySet) {
				cout << it << endl;
			}
			break;
		case 2: {
			cout << "Please, enter the name of country: ";
			cin >> name;
			cout << endl;
			country.setData(name);
			mySet.insert(country);
			break;
		}
		case 3:
			mySet.erase(country);
			break;
		case 4:
			cout << "Number of elements is: " << mySet.size() << endl;
			break;
		default:
			break;
		}
	} while (choose != 0);
}

void List() {
	int choose, id;
	list<Country> myList;
	Country country;
	string name;
	cout << "List" << endl;
	do {
		cout << "0 - Exit" << endl;
		cout << "1 - Print" << endl;
		cout << "2 - Find element by index" << endl;
		cout << "3 - Add element" << endl;
		cout << "4 - Delete element" << endl;
		cout << "5 - Number of elements" << endl;
		cout << "Choose: ";
		cin >> choose;

		auto it = myList.begin();

		switch (choose)
		{
		case 1:
			for (auto i = myList.cbegin(); i != myList.cend(); i++) {
				cout << *i;
			}
			break;
		case 2:
			cout << "input index: ";
			cin >> id;

			advance(it, id);

			cout << id;
			break;
		case 3: {
			it = myList.begin();
			cout << "Please, enter the name of country: ";
			cin >> name;
			cout << endl;
			country.setData(name);
			myList.insert(it, country);

			break;
		}
		case 4:
			cout << "input delete point: ";
			cin >> id;
			it = myList.begin();

			advance(it, id);
			myList.erase(it);
			break;
		case 5:
			cout << "Number of elements is: " << myList.size() << endl;
			break;
		default:
			break;
		}
	} while (choose != 0);
}

void Map() {
	int choose, id;
	map<int, Country> myMap;
	Country country;
	string name;
	cout << "Map" << endl;
	do {
		cout << "0 - Exit" << endl;
		cout << "1 - Print" << endl;
		cout << "2 - Find element by index" << endl;
		cout << "3 - Add element" << endl;
		cout << "4 - Delete element" << endl;
		cout << "5 - Number of elements" << endl;
		cout << "Choose: ";
		cin >> choose;

		auto it = myMap.begin();
		int k;

		switch (choose)
		{
		case 1:
			for (const auto& el : myMap) {
				std::cout << el.second << endl;
			}
			break;
		case 2:
			cout << "Input index: ";
			cin >> id;
			cout << myMap.at(id);
			break;
		case 3: {
			cout << "Please, enter key: ";
			cin >> k;
			cout << endl;
			cout << "Please, enter the name of country: ";
			cin >> name;
			cout << endl;
			country.setData(name);
			myMap.emplace(k, country);
			break;
		}
		case 4:
			cout << "input delete point: ";
			cin >> id;
			myMap.erase(id);
			break;
		case 5:
			cout << "Number of elements is: " << myMap.size() << endl;
			break;
		default:
			break;
		}
	} while (choose != 0);
}

int main() {
	int choose;

	do {
		cout << "0 - Exit" << endl;
		cout << "1 - Work with VECTOR" << endl;
		cout << "2 - Work with SET" << endl;
		cout << "3 - Work with LIST" << endl;
		cout << "4 - Work with MAP" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			Vector();
			break;
		case 2:
			Set();
			break;
		case 3: {
			List();
			break;
		}
		case 4:
			Map();
			break;
		default:
			break;
		}
	} while (choose != 0);

	vector<Country> myVector1;
	vector<Country> myVector2;
	Country country;
	country.setData("Japan");
	myVector1.push_back(country);
	country.setData("USA");
	myVector2.push_back(country);
	country.setData("Ukraine");
	myVector2.push_back(country);
	country.setData("Russia");
	myVector2.push_back(country);
	for (const auto& el : myVector2) {
		myVector1.insert(myVector1.end(), el);
	}

	std::sort(myVector1.begin(), myVector1.end());

	for_each(myVector1.begin(), myVector1.end(), Print());

	return 0;
}