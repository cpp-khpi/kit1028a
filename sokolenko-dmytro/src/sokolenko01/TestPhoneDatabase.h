#pragma once

#include "Phone.h"
#include "PhoneDatabase.h"

class TestPhoneDatabase {
private:
	PhoneDatabase phoneDatabase;
public:
	bool phoneComparison(Phone &, Phone &);
	bool testAddPhone();
	bool testRemovePhone();
};