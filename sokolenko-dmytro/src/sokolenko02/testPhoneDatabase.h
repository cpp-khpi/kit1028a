#pragma once

#include "phone.h"
#include "phoneDatabase.h"

class TestPhoneDatabase {
private:
	PhoneDatabase phoneDatabase;
public:
	bool testAddPhone();
};
