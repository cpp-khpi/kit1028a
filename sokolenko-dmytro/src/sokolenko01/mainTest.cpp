#include "TestPhoneDatabase.h"

int main()
{
	TestPhoneDatabase testPhoneDatabase;
	if (testPhoneDatabase.testAll() == true)
		cout << "All tests are passed! Your program is working! Well done! :)";
	else
		cout << "Tests are not passed. I'm so sorry! :(";

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
TestPhoneDatabase * test = new TestPhoneDatabase;
	(*test).generatePhoneArray();

	Phone * tmpPhone = new Phone;
	(*test).generatePhone(*tmpPhone);
	(*test).testAddPhone(*tmpPhone);
	delete[1] tmpPhone;

	delete[1] test;
*/