#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <algorithm>
#include "Country.h"

using namespace std;

int main() {
	vector<Country> myVector;
	int choose, id;
	Country country;
	std::set<Country> mySet;
	std::list<Country> myList;

	cout << "Vector" << endl;
	do {
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - Find element by index" << endl;
		cout << "3 - Add element" << endl;
		cout << "4 - Delete element" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			for (int i = 0; i < myVector.size(); i++) {
				cout << myVector[i] << endl;
			}
			break;
		case 2:
			cout << "input index: ";
			cin >> id;
			cout << myVector.at(id);
			break;
		case 3: {
			country.setData("Japan");
			myVector.push_back(country);
			break;
		}
		case 4:
			myVector.clear();
			break;
		default:
			break;
		}
	} while (choose != 0);

	cout << "Set" << endl;

	do {
		cout << "0 - Exit" << endl;
		cout << "1 - Print" << endl;
		cout << "2 - Add element" << endl;
		cout << "3 - Delete element" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			for (auto &it : mySet) {//öèêë for_each
				cout << it << "\t";
			}
			break;
		case 2: {
			country.setData("Japan");
			mySet.insert(country);
			break;
		}
		case 3:
			mySet.erase(country);
			break;
		default:
			break;
		}
	} while (choose != 0);

	cout << "List" << endl;
	do {
		cout << "0 - Exit" << endl;
		cout << "1 - Print" << endl;
		cout << "2 - Find element by index" << endl;
		cout << "3 - Add element" << endl;
		cout << "4 - Delete element" << endl;
		cout << "Choose: ";
		cin >> choose;

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

			auto it = myList.begin();
			advance(it, id);

			cout << id;
			break;
		case 3: {
			auto it = myList.begin();
			cout << "Input index: ";
			cin >> id;
			advance(it, id);

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
		default:
			break;
		}
	} while (choose != 0);


	return 0;
}