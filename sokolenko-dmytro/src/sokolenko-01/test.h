#pragma once

#include "phone.h"
#include "phoneDatabase.h"

class Test : public PhoneDatabase {
public:
	void generateArray();
	void generateElem(Phone *);
	void testAddPhone(Phone *); //работает, но нужно нормально оформить дейсвтие теста 
};