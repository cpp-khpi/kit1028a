/**
* @author Klishchov B.
* @date 07-03-2019
* @version 1.2
*/
#include"Country.h"
#include"CountryArr.h"


int main() {

	CountryArr country;
	Country Max;

	int i = 1;
	country.getSize(i); //set size!!!

	std::string name;

	std::cout << "Enter name:  ";
	std::cin >> name;

	country.newArray(name);
	country.addElem(232142, 53423, 654321, "Ukraine");
	country.addElem(32142, 5323, 23321, "Poland");
	country.addElem(2422, 523423, 5654321, "Japan");
	country.deleteElem(1);
	country.getByIndex(3);
	country.print();
	Max = country.maxPop();
	country.printMax(Max);
	country.deleteArray();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();

	getchar();

	return 0;
}