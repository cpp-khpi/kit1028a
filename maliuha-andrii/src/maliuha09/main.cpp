#include "Arrays.h"


int main() {
	{
	std::string command;
	std::cout << "Enter command" << std::endl;
	std::cout << "(/exit) to close the program" << std::endl;
	std::cout << "(1) to read information of arrays from txt file and create array whit max values of arrays" << std::endl;
	Arrays arr;
	std::string fileW, fileR;
	int *newArr = NULL;
	std::stringstream arrays1;
	
	while (command != "/exit") {
		std::cout << "Enter name of file for reading: ";
		std::getline(std::cin, fileR);
		std::cout << "Enter name of file for writing: ";
		std::getline(std::cin, fileW);
		system("cls");
		try {
			arrays1 = arr.readFromFile(fileR);
			arr.createArrays1(arrays1);
			arr.ArrMaxValue(newArr);
			arr.writeArrToFile(newArr, fileW);
			arr.delArrays();

			delete[] newArr;
		}
		catch (MyException& exception) {
			std::cerr << "An array exception occurred (" << exception.what() << std::endl;
		}
		catch (std::exception& exception) {
			std::cerr << "An array exception occurred (" << exception.what() << ")" << std::endl;
		}
		catch (...) {
			std::cerr << "Unknown error!" << std::endl;
		}

		std::cout << "Enter command" << std::endl;
		std::cout << "(/exit) to close the program" << std::endl;
		std::cout << "(1) to read information of arrays from txt file and create array whit max values of arrays" << std::endl;
		std::getline(std::cin, command);
	}
}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	return _CrtDumpMemoryLeaks();
}