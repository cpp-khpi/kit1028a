#include "TestPhoneDatabase.h"

int main()
{
	{
		TestPhoneDatabase testPhoneDatabase;
		if (testPhoneDatabase.testAll())
			cout << "All tests are passed! Your program is working! My be... Well done! :)" << endl;
		else
			cout << "Tests are not passed. I'm so sorry! :(" << endl;
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	return _CrtDumpMemoryLeaks();
}