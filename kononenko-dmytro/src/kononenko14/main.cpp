#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <algorithm>
#include "InfoWork.h"
using namespace std;

template<class T>
struct ForClass {           // Функция объектного типа:
	void operator() (T obj)
	{
		std::cout << "  " << obj;
	}
};

template <class T1, class T2>
vector<T1> ContainerInsert(vector<T1> t1, vector<T2> t2)
{
	for (const auto& el : t2) {
		t1.insert(t1.end(), el);
	}
	return t1;
}

template<class T>
void printSet(set<T> qual) {
	for (auto &it : qual) {//цикл for_each
		cout << it << "\t";
	}
}

template<class T>
set<T> mergeSet(set<T> myset, set<T> myset2) {
	set<T> myset3;
	myset3.insert(myset.begin(), myset.end());
	auto it = myset3.begin();
	for (auto& v : myset2)
	{
		it = myset3.insert(it, v);
	}
	return myset3;
}

template<class T>
struct CompClass {           // Функция объектного типа:
	void operator() (T obj)
	{
		std::cout << "  " << obj;
	}
};

template<class T>
void show(T obj) //Функция, которая будет передаваться в алгоритм
{
	std::cout << obj << "  "; //просто выводит параметр на экран
}

template<class T>
void printList(const list<T> obj) {
	for (auto i = obj.cbegin(); i != obj.cend(); i++) {
		cout << *i;
	}
}

///*Readlization of STL::list*/
template<class T>
void list_func() {
	int j, choose;
	list<T> qual;
	T tmp;

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
			cout << "Input new element: " << endl;
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

///*Readlization of STL::vaecto*/
template<class T>
void vector_func() {
	ForClass<InfoWork> obj;
	int j, choose;
	vector<T> qual;
	vector<T> qual2;
	T tmp;
	int size;
	cout << "Input size of vector: ";
	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> tmp;
		qual2.push_back(tmp);
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
			for_each(qual.begin(), qual.end(), obj);///function for_each
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
			cout << "Input new element: " << endl;
			cin >> tmp;
			qual.insert(qual.begin() + j, tmp);
		break;
		}
		case 4:
			cout << "input delete point: ";
			cin >> j;
			qual.erase(qual.begin() + j);
			break;
		case 5:
			qual = ContainerInsert(qual, qual2);
			break;
		default:
			break;
		}
	} while (choose != 0);

	qual.clear();
	qual2.clear();
	return;
}
/*Readlization of STL::set*/
template<class T>
void set_func() {
	int i = 0;
	int j, choose;
	set<T> qual;
	T tmp;
	int size;

	do {
		cout << "\n";
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - Find element" << endl;
		cout << "3 - Add element" << endl;
		cout << "4 - Delete element" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			for (auto &it :qual) {//цикл for_each
				cout << it;
			}
			break;
		case 2:
			cout << "Input search element: " << endl;
			cin >> tmp;

			if (qual.find(tmp) != qual.end()) {
				cout << "Exist: " << tmp << endl;
			}
			else {
				cout << "Doesn`t exist: " << tmp << endl;
			}

			break;
		case 3: {
			cout << "Input index: ";
			cin >> j;
			cout << "Input new element: " << endl;
			cin >> tmp;
			qual.insert(tmp);
			break;
		}
		case 4:
			cout << "Input erase element: " << endl;
			cin >> tmp;

			if (qual.find(tmp) != qual.end()) {
				qual.erase(tmp);
			}
			else {
				cout << "Doesn`t exist: " << tmp << endl;
			}
			break;
		case 5:
			cout << "Input obj for compare: " << endl;
			cin >> tmp;
			for (auto &it : qual) {//цикл for_each
				if (tmp > it) i++;
			}
			cout << i;
			break;
		default:
			break;
		}
	} while (choose != 0);

	return;
}

/*Readlization of STL::map*/
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

void special_map() {
	map<string, set<string>> mymap;
	map<string, set<string>> mymap2;

	mymap["Ukrain"] = { "Kharkiv", "Odesa" };
	mymap["Russia"] = { "Moskow" };
	mymap2["Poland"] = { "Krakov" };
	mymap2["Ukrain"] = { "Kiev" };
	mymap2["Russia"] = { "Piter" };


	for (const auto& el : mymap) {
		for (const auto& el2 : mymap2) {
			if (el.first == el2.first) {
				set<string> temp = mergeSet(el.second, el2.second);
				mymap[el.first] = temp;
			}
			else {
				mymap.emplace(el2.first, el2.second);
			}
		}
	}


	for (const auto& el : mymap) {
		std::cout << el.first << ": ";
		printSet(el.second);
	}
}

int main() {
	list_func<InfoWork>();
	system("cls");
	vector_func<InfoWork>();
	system("cls");
	map_func<InfoWork>();
	system("cls");
	set_func<InfoWork>();
}