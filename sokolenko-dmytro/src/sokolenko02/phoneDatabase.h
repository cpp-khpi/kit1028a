#pragma once

#include <iostream>
#include "phone.h"

using std::cin;
using std::cout;
using std::endl;

class PhoneDatabase {
	int size;
	Phone * phoneArray;
public:
	PhoneDatabase()
	{
		size = 0;
		phoneArray = new Phone[size];

		cout << "Default constructor! PhoneDatabase" << endl;
	}

	PhoneDatabase(int newSize, Phone * newPhoneArray)
	{
		size = newSize;
		phoneArray = newPhoneArray;

		cout << "Constructor with param. PhoneDatabase" << endl;
	}

	PhoneDatabase(const PhoneDatabase & copiedPhoneDatabase)
	{
		size = copiedPhoneDatabase.size;
		phoneArray = copiedPhoneDatabase.phoneArray;

		cout << "Copy constructor. PhoneDatabase" << endl;
	}

	~PhoneDatabase()
	{
		delete[] phoneArray;

		cout << "Destructor. PhoneDatabase" << endl;
	}

	int getSize();
	void setSize(unsigned int);

	Phone * getPhoneArray();
	void setPhoneArray(Phone *);

	int inputSize();
	void readPhone(Phone &) const;
	void createArray(int);
	void addPhone(Phone &);
	int inputIndex() const;
	void removePhone(const int);
	Phone& getPhone(const int);
	void printPhone(Phone *) const;
	void showAll() const;
	void deleteArray();
};

