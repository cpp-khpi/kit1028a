#include <algorithm>
#include <memory>
#include "Textbook.h"
#include "Pointers.h"


int main() {
	auto_ptr<Textbook> some_auto_ptr(new Textbook);
	auto_ptr<Textbook> copy1 = some_auto_ptr;

	unique_ptr<Textbook> some_unique_ptr(new Textbook[3]);
	unique_ptr<Textbook> copy2 = move(some_unique_ptr);

	shared_ptr<Textbook> some_shared_ptr(new Textbook);
	shared_ptr<Textbook> copy3(new Textbook[3]);
	some_shared_ptr = copy3;

	system("cls");
	useAutoPtr();
	useSharedPtr();
	useUniquePtr();


	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	
	return _CrtDumpMemoryLeaks();
}