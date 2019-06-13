/*
* @ mainpage
* @ author - Kotenko Sergey
* @ date - 12.06.19
* @ version - 1.0
*/

#include "IndependentsWork.h"
#include "Homework.h"


int main() {
	system("color A");
	{

		IndependentsWork* work_or_not = new Homework[2];
		delete[] work_or_not;

	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();
	system("pause");
	return _CrtDumpMemoryLeaks();	
}