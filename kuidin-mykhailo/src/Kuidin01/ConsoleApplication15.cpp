#include "Header.h"

 int main() {
	 int num = 0;
	 int cos = 0;
	 int pup = 0;

	 Functions tmp;
	 
	 tmp.createObjects();
	 cout << "\nEnter number of school: " << endl;
	 cin >> num;
	 cout << "How many pupils study in this school: " << endl;
	 cin >> pup;
	 cout << "Enter cost per month: " << endl;
	 cin >> cos;
	 tmp.addObject(2,num,pup,cos);

	 cout << "\nEnter number of school: " << endl;
	 cin >> num;
	 cout << "How many pupils study in this school: " << endl;
	 cin >> pup;
	 cout << "Enter cost per month: " << endl;
	 cin >> cos;
	 tmp.addObject(3,num,pup,cos);

	 tmp.delElem(2);
	 tmp.find(2);
	 tmp.printall();
	 tmp.deleteall();
	 
	 
	 _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	 _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	 _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	 _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	 _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	 _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	 _CrtDumpMemoryLeaks();

	return 0;
	
}

 
