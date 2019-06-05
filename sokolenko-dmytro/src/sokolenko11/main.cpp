#include "Array.h"
#include "Phone.h"

int main() 
{
	{
		const size_t size = 3;

		/* Testing with integer's array. */
		Array<int> testInt(3);

		cout << "Index (int) = " << testInt.find(1) << endl;
		cout << "Lowest (int) = " << testInt.getLowest() << endl;

		testInt.sort();
		testInt.output();

		/* Testing with Phone object's array. */

		Array<Phone> testPhone(3);

		Phone desired("Name", 2, 2, 2, 2);

		cout << "Index (Phone) = " << testPhone.find(desired) << endl;
		cout << "Lowest (Phone) = " << testPhone.getLowest() << endl;

		testPhone.sort();
		testPhone.output();
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	return _CrtDumpMemoryLeaks();
}