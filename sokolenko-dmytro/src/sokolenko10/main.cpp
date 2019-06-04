#include "Phone.h"
#include "arrayProcessing.hpp"

using arrayProcessing::output;
using arrayProcessing::find;
using arrayProcessing::sort;
using arrayProcessing::getLowest;

int main()
{
	{
		const size_t size = 3;

		/* Testing with integer's array. */

		int* testIntArray = new int[size];
		for (int i = 0; i < size; i++)
			testIntArray[i] = i;

		cout << "Index (int) = " << find(testIntArray, size, 1) << endl;
		cout << "Lowest (int) = " << getLowest(testIntArray, size) << endl;

		sort(testIntArray, size);
		output(testIntArray, size);

		/* Testing with Phone object's array. */

		Phone* testPhoneArray = new Phone[size];
		for (int i = 0; i < size; i++)
			testPhoneArray[i].setPhoneInfo("Name", i, i, i, i);

		Phone desired("Name", 2, 2, 2, 2);

		cout << "Index (Phone) = " << find(testPhoneArray, size, desired) << endl;
		cout << "Lowest (Phone) = " << getLowest(testPhoneArray, size) << endl;

		sort(testPhoneArray, size);
		output(testPhoneArray, size);

		delete[] testIntArray;
		delete[] testPhoneArray;

	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	return _CrtDumpMemoryLeaks();
}