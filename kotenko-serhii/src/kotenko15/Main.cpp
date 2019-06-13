/*
* @ mainpage
* @ author - Kotenko Sergey
* @ date - 12.06.19
* @ version - 1.0
*/

#include "IndependentsWork.h"

int main() {
	system("color A");
	{
		std::auto_ptr<IndependentsWork> auto_prt_test(new IndependentsWork);
		std::auto_ptr<IndependentsWork> copy;
		copy = auto_prt_test;
		// В copy находится указатель на auto_prt_test , а сам auto_prt_test теперь обнулён.


		std::unique_ptr<IndependentsWork> uniq_ptr_test(new IndependentsWork);
		// uniq_ptr_test владеет IndependentsWork
		std::unique_ptr<IndependentsWork> copy_1(std::move(uniq_ptr_test));
		// владение IndependentsWork перешло к copy_1
		uniq_ptr_test = std::move(copy_1);
		// владение возвращено uniq_ptr_test


		std::shared_ptr<IndependentsWork> shared_ptr_test(new IndependentsWork);
		std::shared_ptr<IndependentsWork> copy_2;
		copy_2 = shared_ptr_test;
		// copy_2 и shared_ptr_test указывают на один объект, а счётчик ссылок равен 2


		std::weak_ptr<int> weak_ptr_test;
		auto copy_3 = std::make_shared<int>(2);
		weak_ptr_test = copy_3;
		// получение данных не входя во владение
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