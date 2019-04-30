/**
* @author Klishchov B.
* @date 07-03-2019
* @version 1.2
*/
#include"Country.h"
#include"CountryArr.h"
#include <regex>

int main() {

	CountryArr *country = new CountryArr();
	Country *Max = new Country();
	
	country->setSize(1);
	
	std::ifstream fin("data.txt");

	int population;
	int area;
	int revenue;
	
	std::string name;
	
	std::cout << "Enter name:  ";
	std::cin >> name;

	std::regex regex_repeat("[\\s]{2,}");
	std::regex regex_firstSymbol("^[A-Z]");

	if (!(std::regex_search(name, regex_firstSymbol)) || std::regex_search(name, regex_repeat)) {
		std::cout << "Use upper case for first symbol" << std::endl;
	}
	country->newArray(name);
	fin >> population >> area >> revenue >> name;
	country->addElem(population, area, revenue, name);
	if (!(std::regex_search(name, regex_firstSymbol)) || std::regex_search(name, regex_repeat)) {
		std::cout << "Use upper case for first symbol" << std::endl;
	}
	fin >> population >> area >> revenue >> name;
	country->addElem(population, area, revenue, name);
	if (!(std::regex_search(name, regex_firstSymbol)) || std::regex_search(name, regex_repeat)) {
		std::cout << "Use upper case for first symbol" << std::endl;
	}
	fin >> population >> area >> revenue >> name;
	country->addElem(population, area, revenue, name);
	if (!(std::regex_search(name, regex_firstSymbol)) || std::regex_search(name, regex_repeat)) {
		std::cout << "Use upper case for first symbol" << std::endl;
	}
	country->deleteElem(0);
	country->getByIndex(1);
	country->print();
	*Max = country->maxPop();
	country->printMax(*Max);
	country->deleteArray();
	
	fin.close();
	
	delete Max;
	delete country;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	
	_CrtDumpMemoryLeaks();
	return 0;
}