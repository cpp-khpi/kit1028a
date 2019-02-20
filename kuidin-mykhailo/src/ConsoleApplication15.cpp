#include "Header.h"

 int main() {
	 functions tmp;
	 
	 tmp.createObjects();
	 tmp.addObject(2);
	 tmp.addObject(3);
	 tmp.delElem(2);
	 tmp.find(2);
	 tmp.printall();
	 tmp.deleteall();
	 //for (int i = 0; i < 4; ++i) s[i].~School();
	 
	 _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	 _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	 _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	 _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	 _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	 _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	 _CrtDumpMemoryLeaks();

	return 0;
	//Исправить проблему с утечкой памяти и сделать доксиген
}

 
