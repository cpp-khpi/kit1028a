#pragma once

#include "phone.h"
#include "processing.h"

class Test : public PhoneDatabase {
public:
	void generateArray();
	void generateElem(Phone *);
	void testAddPhone(Phone *); //��������, �� ����� ��������� �������� �������� ����� 

};