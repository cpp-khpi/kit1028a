#pragma once

#include "Phone.h"
#include "PhoneDatabase.h"

class TestPhoneDatabase {
private:
	PhoneDatabase phoneDatabase;
	bool phoneComparison(Phone &, Phone &);
	bool testAddPhone();
	bool testRemovePhone();
	bool testGetPhone();
public:
	bool testAll();
};