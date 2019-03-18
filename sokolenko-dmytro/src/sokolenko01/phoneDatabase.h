#pragma once

#include <iostream>
#include "Phone.h"

using std::cin;
using std::cout;
using std::endl;

class PhoneDatabase {
	int size;
	Phone * phoneArray;
public:
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
