#include <iostream>
#include <algorithm>
#include <memory>
#include "InfoWork.h"
#include "Counter.h"
#include "Smart_Pointer.h"
using namespace std;

///This class was created on purpose to show problem of shared_ptr
class Obj_Shared
{
public:
	std::shared_ptr<Obj_Shared> m_ptr;

	Obj_Shared() { std::cout << "Item acquired\n"; }
	~Obj_Shared() { std::cout << "Item destroyed\n"; }
};

void func_auto_ptr() {
	std::auto_ptr<InfoWork> p1(new InfoWork(100,5));
	std::auto_ptr<InfoWork> p2;
	
	///p1 now point to NULL and p2 now point to p1
	p2 = p1;

	///if we try to print p1 now, we will got an exception
	if (p1.get() != NULL) {
		cout << "P1: " << *p1;
	}
	cout << "P2: " << *p2;

}

void func_unique_ptr() {
		unique_ptr<InfoWork> work1(new InfoWork(95,5));
		unique_ptr<InfoWork> work2;

		cout << "work1 is " << (static_cast<bool>(work1) ? "not null\n" : "null\n");
		cout << "work2 is " << (static_cast<bool>(work2) ? "not null\n" : "null\n");

		///unique_ptr has the same problem like auto_ptr, he can`t be appropriated to another unique_ptr
		///But we can use std::move to appropriat those two pointers, but work1 will be empty
		work2 = std::move(work1); 

		cout << "Ownership transferred to work2\n";

		cout << "work1 is " << (static_cast<bool>(work1) ? "not null\n" : "null\n");
		cout << "work2 is " << (static_cast<bool>(work2) ? "not null\n" : "null\n");

		//////////////////////////////////////////////////////////////////////////////////////////

		///Also unique_ptr can be used to create arrays

		auto array_work = make_unique<InfoWork[]>(3);

		for (int i = 0; i < 3; i++) {
			cout << array_work[i];
		}

		///At the end whole array will be deleted
}

void func_shared_ptr() {
	{	shared_ptr<InfoWork> obj_test;
		{
			auto pointer1 = make_shared<InfoWork>(60, 4);
			{
				obj_test = pointer1;
				auto pointer2 = pointer1;
				cout << "Amount of points to pointer1: " << pointer1.use_count();
				cout << " Pointer2: " << *pointer2;
	
			}
			cout << endl << "Pointer1: " << *pointer1 << endl;
			cout << "Amount of points to pointer1: " << pointer1.use_count();
		}
		///If we use ordinal pointer, we won`t be able to use memory which stored in pointer1, because it would be deleted
		///The memory for pointer1 still in use,because there still one more pointer obj_test which point to the same slot of memory
		///So we can use obj_test
		cout << " Pointer2: " << *obj_test;
	}

	int choose;
	{
		weak_ptr<InfoWork> pointer3;
		auto pointer1 = make_shared<InfoWork>(100, 5);
		{
			auto pointer2 = pointer1;
			cout << "Amount of points to pointer1: " << pointer1.use_count();
			pointer3 = pointer1;
			///The number of points to pointer1 won`t increase,because weak_ptr is not considered the owner
			cout << " Pointer2: " << *pointer2;

		}
		cout << endl << "Pointer1: " << *pointer1 << endl;
		cout << "Amount of points to pointer1: " << pointer1.use_count();
	}

	///The shared pointer has a pretty big problem, circular dependency, if this happens, shared_ptr will not be removed
	///And here such example
	///At the end we will see leak of memory
	cout << "Do you want to perfome an exception? : ";
	cin >> choose;
	if (choose == 1) {
		auto pointer1 = make_shared<Obj_Shared>();
		pointer1->m_ptr = pointer1;
	}
	///To handle this problem we need to use weak_ptr

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();
}

int main()
{
	{
		smart_pointer<InfoWork> pInt(new InfoWork);
		smart_pointer<InfoWork> pInt2(new InfoWork);
		smart_pointer<InfoWork> pInt3(new InfoWork);
		smart_pointer<InfoWork> pInt4(new InfoWork);
		smart_pointer<InfoWork> pInt5(new InfoWork);
		smart_pointer<InfoWork> pInt6(new InfoWork);
		cout << "Alive:" << Counter<InfoWork>::GetCount() << endl;
	}

	cout<<"Alive: " << Counter<InfoWork>::GetCount();

	system("cls");
	func_shared_ptr();
	func_auto_ptr();
	func_unique_ptr();
	system("cls");
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();
}
