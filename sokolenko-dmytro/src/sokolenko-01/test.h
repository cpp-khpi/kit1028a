#pragma once

#include "phone.h"
#include "phoneDatabase.h"
#include <ctime>


class TestPhoneDatabase {
private:
	PhoneDatabase phoneDatabase;
public:
	bool phoneComparison(Phone &, Phone &);
	bool testAddPhone();
};