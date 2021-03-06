#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <algorithm>

#include "IndependentsWork.h"

using namespace std;

template <typename T> 
void print_element(T el) {
	cout << el << endl;
}
template <class T1, class T2>
vector<T1> ContainerInsert(vector<T1> t1, vector<T2> t2) {
	for (const auto& el : t2) {
		t1.insert(t1.end(), el);
	}
	return t1;
}

template<class T>
class Sort_conteiner {
	bool operator() (const T &a, const T &b) {
		return a < b;
	}
};

int main() {
	int option = 0;
	typedef int work;
	do {
		cout << "Enter your template container: " << endl << "1 - Vector" << endl << "2 - Set" << endl << "3 - List" << endl << "4 - Map" << endl << endl;

		cout << "Option: ";
		cin >> option;

		switch (option) {
		case 1: {
			vector<work> container;
			vector<work> container2;
			Sort_conteiner<IndependentsWork> sort_cont;
			cout << "Choose option: " << endl << "0 - Exit" << endl << "1 - Add element" << endl << "2 - Delete element" << endl << "3 - Print" << endl << "4 - Search by index" << endl << "5 - Sort" << endl << "6 - Conteiner merge" << endl;
			option = 0;
			cout << "Option: ";
			cin >> option;
			work new_element;

			switch (option) {
			case 1: {
				cout << "Enter new element: ";
				cin >> new_element;
				container.push_back(new_element);
				break;
			}
			case 2: {
				int i;
				cout << "Enter index by delete element: ";
				cin >> i;
				container.erase(container.begin() + i);
				break;
			}
			case 3: {
				cout << endl;
				for_each(container.begin(), container.end(), print_element<int>);
				break;
			}
			case 4: {
				int k;
				cout << "Enter index by search element: ";
				cin >> k;
				if (k<0 || k>container.size()) {
					cout << "Error" << endl << "Index cant be larger than the size of the conteiner";
					break;
				}
				cout << container[k];
				break;
			}
			case 5: {
				sort(container.begin(), container.end(), sort_cont);
				break;
			}
			case 6: {
				container = ContainerInsert(container, container2);
				break;
			}
			}
			break;
		}
		case 2: {
			set<work> container;
			cout << "Choose option: " << endl << "0 - Exit" << endl << "1 - Add element" << endl << "2 - Delete element" << endl << "3 - Print" << endl;
			option = 0;
			cout << "Option: ";
			cin >> option;
			work new_element;

			switch (option) {
			case 1: {
				cout << "Enter new element: ";
				cin >> new_element;
				container.insert(new_element);
				break;
			}
			case 2: {
				int i;
				cout << "Enter index by delete element: ";
				cin >> i;
				container.erase(i);
				break;
			}
			case 3: {
				cout << endl;
				for (auto &it : container) {
					cout << it;
				}
				break;
			}
			}
			break;
		}
		case 3: {
			list<int> container;
			cout << "Choose option: " << endl << "0 - Exit" << endl << "1 - Add element" << endl << "2 - Delete element" << endl << "3 - Print" << endl;
			option = 0;
			cout << "Option: ";
			cin >> option;
			int new_element;

			switch (option) {
			case 1: {
				cout << "Enter new element: ";
				cin >> new_element;
				container.push_back(new_element);
				break;
			}
			case 2: {
				int i;
				cout << "Enter index by delete element: ";
				cin >> i;
				auto it = container.begin();
				advance(it, i);
				container.erase(it);
				break;
			}
			case 3: {
				cout << endl;
				for (auto &it : container) {
					cout << it;
				}
				break;
			}
			}
			break;
		}
		case 4: {
			map<int, work> container;
			cout << "Choose option: " << endl << "0 - Exit" << endl << "1 - Add element" << endl << "2 - Delete element" << endl << "3 - Print" << endl;
			option = 0;
			cout << "Option: ";
			cin >> option;
			work new_element;
			int i;

			switch (option) {
			case 1: {
				cout << "Enter index: ";
				cin >> i;
				cout << endl << "Enter new element: ";
				cin >> new_element;
				container.emplace(i, new_element);
				break;
			}
			case 2: {
				cout << "Enter index by delete element: ";
				cin >> i;
				container.erase(i);
				break;
			}
			case 3: {
				cout << endl;
				for (const auto &it : container) {
					cout << it.first << "  " << it.second << endl;
				}
				break;
			}
			}
			break;
		}
		}
	} while (option != 0);
}
