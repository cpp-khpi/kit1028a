#include "TestPhoneDatabase.h"

int main()
{
	{
		TestPhoneDatabase testPhoneDatabase;
		if (testPhoneDatabase.testAll())
			cout << "Class PhoneDatabase has been tested successfully." << endl;
		else
			cout << "Class PhoneDatabase has NOT been tested successfully." << endl;
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	return _CrtDumpMemoryLeaks();
}