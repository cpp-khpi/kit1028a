#include <vector>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <algorithm>
#include "Textbook.h"
using namespace std;

template<class T>
struct ForClass {
	void operator() (T obj)
	{
		cout << "  " << obj;
	}
};

template <class T1, class T2>
vector<T1> InsertToContainer(vector<T1> t1, vector<T2> t2)
{
	for (const auto& el : t2) {
		t1.insert(t1.end(), el);
	}
	return t1;
}

template<class T>
void printSet(set<T> qual) {
	for (auto &it : qual) {
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
struct CompClass {
	void operator() (T obj)
	{
		std::cout << "  " << obj;
	}
};

template<class T>
void show(T obj)
{
	std::cout << obj << "  ";
}

template<class T>
void printList(const list<T> obj) {
	for (auto i = obj.cbegin(); i != obj.cend(); i++) {
		cout << *i;
	}
}

template<class T>
void listMethod() {
	int index, choose;
	list<T> qual;
	T tmp;

	do {
		cout << endl;
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - Find a textbook by index" << endl;
		cout << "3 - Add a textbook" << endl;
		cout << "4 - Delete a textbook" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1: {
			printList(qual);
			break;
		}
		case 2: {
			cout << "Enter the index: ";
			cin >> index;

			if (index<0 || index>qual.size()) {
				cout << "Error: wrong index!" << endl;
				break;
			}

			auto it = qual.begin();
			advance(it, index);

			cout << index;
			break;
		}
		case 3: {
			auto it = qual.begin();
			cout << "Enter the index: ";
			cin >> index;
			cout << "Enter new textbook: " << endl;
			cin >> tmp;
			advance(it, index);

			qual.insert(it, tmp);

			break;
		}
		case 4: {
			cout << "Enter textbook index to remove it: ";
			cin >> index;
			auto it = qual.begin();

			advance(it, index);
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
void vectorMethod() {
	ForClass<Textbook> obj;
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
		cout << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - Find a textbook by index" << endl;
		cout << "3 - Add a textbook" << endl;
		cout << "4 - Delete a textbook" << endl;
		cout << "5 - Count the number of textbooks" << endl;
		cout << "6 - Search textbook by author's surname" << endl;
		cout << "7 - Exit from program" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			for_each(qual.begin(), qual.end(), obj);
			break;
		case 2:
			cout << "Enter the index: ";
			cin >> j;

			if (j<0 || j>qual.size()) {
				cout << "Error" << endl;
				break;
			}

			cout << qual[j];
			break;
		case 3: {
			cout << "Enter the index: ";
			cin >> j;
			cout << "Enter new textbook: " << endl;
			cin >> tmp;
			qual.insert(qual.begin() + j, tmp);
			break;
		}
		case 4:
			cout << "Enter the number of textbook you want to remove: ";
			cin >> j;
			qual.erase(qual.begin() + j);
			break;
		case 5:
		int amount = 0;
		cout << "Enter the number of pages to search: ";
		cin >> hDisk;
		for (auto it : qual) {
			if (it.getPages() == pages) {
				amount++;
				cout << it;
			}
		}
		cout << "Amount of textbooks - " << amount << endl;
		amount = 0;
		system("pause");
		system("cls");
		break;
			case 6:
				cout << "Enter name of the author: " << endl;
				cin.ignore(1);
				getline(cin, author);
				for (auto it : qual) {
					if (author == it.getAuthor()) {
						cout << it;
					}
				}
				system("pause");
				system("cls");
				break;
		default:
			break;
		}
	} while (choose != 7);

	qual.clear();
	qual2.clear();
	return;
}

template<class T>
void setMethod() {
	int i = 0;
	int j, choose;
	set<T> qual;
	T tmp;
	int size;

	do {
		cout << "\n";
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - Find a textbook by index" << endl;
		cout << "3 - Add a textbook" << endl;
		cout << "4 - Delete a textbook" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			for (auto &it : qual) {
				cout << it;
			}
			break;
		case 2:
			cout << "Enter the number of textbook: " << endl;
			cin >> tmp;

			if (qual.find(tmp) != qual.end()) {
				cout << "Yeah, it exists: " << tmp << endl;
			}
			else {
				cout << "Error: it doesn`t exist: " << tmp << endl;
			}

			break;
		case 3: {
			cout << "Enter the number of textbook: ";
			cin >> j;
			cout << "Enter new textbook: " << endl;
			cin >> tmp;
			qual.insert(tmp);
			break;
		}
		case 4:
			cout << "Enter the number of textbook you want to remove: " << endl;
			cin >> tmp;

			if (qual.find(tmp) != qual.end()) {
				qual.erase(tmp);
			}
			else {
				cout << "Error: doesn`t exist! " << tmp << endl;
			}
			break;
		case 5:
			cout << "Enter the textbook for compare: " << endl;
			cin >> tmp;
			for (auto &it : qual) {
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


template<class T>
void mapMethod() {
	int key, choose;
	map<int, T> qual;
	T tmp;
	int size;

	do {
		cout << endl;
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - Find a textbook by index" << endl;
		cout << "3 - Add textbook" << endl;
		cout << "4 - Delete textbook" << endl;
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
			cout << "Enter the textbook's index: ";
			cin >> key;

			if (key<0 || key>qual.size()) {
				cout << "Error" << endl;
				break;
			}

			cout << qual[key];
			break;
		case 3: {
			cout << "Enter the textbook's index: ";
			cin >> key;
			cout << "Enter new textbook: " << endl;
			cin >> tmp;
			qual.emplace(key, tmp);
			break;
		}
		case 4:
			cout << "Enter the number of textbook you want to remove: ";
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

void specialMap() {
	map<string, set<string>> firstAuthor;
	map<string, set<string>> secondAuthor;

	firstAuthor["Akutagawa"] = { "Ryunosuke", "Gin" };
	firstAuthor["Kunikida"] = { "Doppo" };
	secondAuthor["Mori"] = { "Ogai" };
	secondAuthor["Akutagawa"] = { "Ranpo" };
	secondAuthor["Kunikida"] = { "Ichiyo" };


	for (const auto& el : firstAuthor) {
		for (const auto& el2 : secondAuthor) {
			if (el.first == el2.first) {
				set<string> temp = mergeSet(el.second, el2.second);
				firstAuthor[el.first] = temp;
			}
			else {
				firstAuthor.emplace(el2.first, el2.second);
			}
		}
	}


	for (const auto& el : firstAuthor) {
		std::cout << el.first << ": ";
		printSet(el.second);
	}
}
