#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include "InfoWork.h"
using namespace std;

template<class T>
void printList(const list<T> obj) {
	for (auto i = obj.cbegin(); i != obj.cend(); i++) {
		cout << *i;
	}
}

template<class T>
void list_func() {
	int j, choose;
	list<T> qual;
	T tmp;
	int size;
	cout << "Input size of vector: ";
	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> tmp;
		qual.push_back(tmp);
	}

	do {
		cout << "\n";
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - Find element by index" << endl;
		cout << "3 - Add element" << endl;
		cout << "4 - Delete element" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1: {
			printList(qual);
			break;
		}
		case 2: {
			cout << "input index: ";
			cin >> j;

			if (j<0 || j>qual.size()) {
				cout << "Error" << endl;
				break;
			}
	
			auto it = qual.begin();
			advance(it, j);

			cout << j;
			break;
		}
		case 3: {
			auto it = qual.begin();
			cout << "Input index: ";
			cin >> j;
			cout << "Input new element: ";
			cin >> tmp;
			advance(it, j);
			
			qual.insert(it, tmp);

			break;
		}
		case 4: {
			cout << "input delete point: ";
			cin >> j;
			auto it = qual.begin();

			advance(it, j);
			qual.erase(it);
			break;
		}
		default:
			break;
		}
	} while (choose != 0);

	qual.clear();
	return;
}

template<class T>
void vector_func() {
	int j, choose;
	vector<T> qual;
	T tmp;
	int size;
	cout << "Input size of vector: ";
	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> tmp;
		qual.push_back(tmp);
	}

	do {
		cout << "\n";
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
			for (int i = 0; i < qual.size(); i++) {
				cout << qual[i];
			}
			break;
		case 2:
			cout << "input index: ";
			cin >> j;

			if (j<0 || j>qual.size()) {
				cout << "Error" << endl;
				break;
			}

			cout << qual[j];
			break;
		case 3: {
			cout << "Input index: ";
			cin >> j;
			cout << "Input new element: ";
			cin >> tmp;
			qual.insert(qual.end() + j, tmp);
break;
		}
		case 4:
			cout << "input delete point: ";
			cin >> j;
			qual.erase(qual.begin() + j);
			break;
		default:
			break;
		}
	} while (choose != 0);

	qual.clear();
	return;
}

template<class T>
void set_func() {
	int j, choose;
	vector<T> qual;
	T tmp;
	int size;
	cout << "Input size of vector: ";
	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> tmp;
		qual.push_back(tmp);
	}

	do {
		cout << "\n";
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
			for (int i = 0; i < qual.size(); i++) {
				cout << qual[i];
			}
			break;
		case 2:
			cout << "input index: ";
			cin >> j;

			if (j<0 || j>qual.size()) {
				cout << "Error" << endl;
				break;
			}

			cout << qual[j];
			break;
		case 3: {
			cout << "Input index: ";
			cin >> j;
			cout << "Input new element: ";
			cin >> tmp;
			qual.insert(qual.end() + j, tmp);
			break;
		}
		case 4:
			cout << "input delete point: ";
			cin >> j;
			qual.erase(qual.begin() + j);
			break;
		default:
			break;
		}
	} while (choose != 0);

	return;
}


template<class T>
void map_func() {
	int key, choose;
	map<int, T> qual;
	T tmp;
	int size;

	do {
		cout << "\n";
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
			for (const auto& el : qual) {
				std::cout << el.first << "  " << el.second << "\n";
			}
			break;
		case 2:
			cout << "input index: ";
			cin >> key;

			if (key<0 || key>qual.size()) {
				cout << "Error" << endl;
				break;
			}

			cout << qual[key];
			break;
		case 3: {
			cout << "Input index: ";
			cin >> key;
			cout << "Input new element: " << endl;
			cin >> tmp;
			qual.emplace(key,tmp);
			break;
		}
		case 4:
			cout << "input delete point: ";
			cin >> key;

			if (key < 0 || key > qual.size()) {
				break;
			}

			qual.erase(key);
			break;
		default:
			break;
		}
	} while (choose != 0);

	return;
}

int main() {
	list_func<InfoWork>();
	vector_func<InfoWork>();
	map_func<InfoWork>();
}