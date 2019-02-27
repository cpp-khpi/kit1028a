#pragma once

#include "Phone.h"

class Test : public Processing {
public:
	void generateArray();
	void generateElem(Phone *);
	void testAddPhone(Phone *); //работает, но нужно нормально оформить дейсвтие теста 
	
};