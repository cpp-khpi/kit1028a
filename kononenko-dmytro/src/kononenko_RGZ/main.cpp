/**
* @file main.cpp
* Contain main function.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/

#include "Controler.h"
#include "Exception.h"
#include "InfoWork.h"
#include "Dialog.h"
#include "Tester.h"

int main() {
	{
		try {
			Tester obj;
			cout << "Perfoming test............................" << endl;
			if (obj.testAll()) {
				cout << "_____________________________Test passed_________________________" << endl;
			}
			else {
				cout << "__________________________________Error________________________" << endl;
			}
		}
		catch (Exception e) {
			cout << e.display() << endl;
		}
		catch (...) {
			cout << "Unknown error";
		}

		try {
			Dialog obj;
			obj.createArr();
			obj.print();
			obj.sortArr();
			obj.print();
		}
		catch (Exception e) {
			cout << e.display() << endl;
		}
		catch (...) {
			cout << "Unknown error";
		}
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();

	return 0;
}
