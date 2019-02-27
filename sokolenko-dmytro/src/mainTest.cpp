#include "tests.h"

//в принципе, это сносно?

int main()
{
	Test test;
	test.generateArray();

	Phone * tmpPhone = new Phone;
	test.generateElem(tmpPhone);
	test.testAddPhone(tmpPhone);
	delete tmpPhone;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();

	return 0;
}

/*
Test * test = new Test;
	test->memoryArray();
	test->generateArray(test);

	delete test;
*/