#include <iostream>

#include "Country.h"

void autoPtr() {
	string name;
	cout << "Please, enter the name of country: ";
	cin >> name;
	auto_ptr<Country> ptr1(new Country(name));
	cout << "Adres of first object: " << ptr1.get() << endl;
	auto_ptr<Country> ptr2 = move(ptr1);
	cout << "Adres of secound object: " << ptr2.get() << endl;
	cout << "Adres of first object after assignment: " << ptr1.get() << endl;
}

void uniquePtr() {
	string name;
	cout << "Please, enter the name of country: ";
	cin >> name;
	unique_ptr<Country> ptr1(new Country(name));
	cout << "Adres of first object: " << ptr1.get() << endl;
	unique_ptr<Country> ptr2 = move(ptr1);
	cout << "Adres of secound object: " << ptr2.get() << endl;
	cout << "Adres of first object after assignment: " << ptr1.get() << endl << endl;
}

void sharedPtr() {
	string name;
	cout << "Please, enter the name of country: ";
	cin >> name;
	shared_ptr<Country> ptr1(new Country(name));
	cout << "Adres of first object: " << ptr1.get() << endl;
	shared_ptr<Country> ptr2(ptr1);
	cout << "Adres of secound object: " << ptr2.get() << endl;
	cout << "Adres of first object after assignment: " << ptr1.get();
}

void weakPtr() {
	weak_ptr<Country> ptr;
	string name;
	cout << "Please, enter the name of country: ";
	cin >> name;
	auto sp = make_shared<Country>(name);
	ptr = sp;
	if (auto spt = ptr.lock()) {
		cout << *spt << endl;
	}
	else {
		cout << "Pointer is expired" << endl;
	}
}

int main() {

	int choose;

	do {
		cout << "0 - Exit" << endl;
		cout << "1 - Work with AUTO_PTR" << endl;
		cout << "2 - Work with UNIQUE_PTR" << endl;
		cout << "3 - Work with SHARED_PTR" << endl;
		cout << "4 - Work with WEAK_PTR" << endl;
		cout << "Choose: ";
		cin >> choose;
		system("cls");
		switch (choose)
		{
		case 1:
			cout << "auto_ptr" << endl;
			autoPtr();
			break;
		case 2:
			cout << "unique_ptr" << endl;
			uniquePtr();
			break;
		case 3: {
			cout << "sharet_ptr" << endl;
			sharedPtr();
			break;
		}
		case 4:
			cout << "weak_ptr" << endl;
			weakPtr();
			break;
		default:
			break;
		}
	} while (choose != 0);

	return 0;
}