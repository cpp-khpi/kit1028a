#include "TestPhoneArray.h"

int main()
{
	{
		TestPhoneArray testPhoneArray;
		if (testPhoneArray.testAll())
			cout << "Class PhoneArray has been tested successfully." << endl;
		else
			cout << "Class PhoneArray has been tested UNsuccessfully." << endl;
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	return _CrtDumpMemoryLeaks();
}