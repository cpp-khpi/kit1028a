#include "Functions.h"

int main()
{
	srand(time(NULL));
	string *gover = new string[2];
	gover[0] = "Monarchy";
	gover[1] = "Democracy";

	string *monarchy = new string[3];
	monarchy[0] = "Absolute";
	monarchy[1] = "Constitutional";
	monarchy[2] = "Theocracy";

	Functions functions;

	int size;
	cout << "Please, enter the size: ";
	cin >> size;
	cout << endl;
	functions.setSize(size);

	functions.newElements(gover, monarchy); 
	functions.addElement(gover, monarchy);
	int index;
	cout << "Please, enter the index for deleting: ";
	cin >> index;
	cout << endl;
	functions.deleteElement(index);
	functions.printCountries();
	cout << "Please, enter the index for geting country: ";
	cin >> index;
	cout << endl;
	functions.getByIndex(index);
	functions.freeCountries();

	delete[]gover;
	delete[]monarchy;
	

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();

	return 0;
}