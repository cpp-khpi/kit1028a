#include <iostream>
#include "WorkArray.h"

int main() {
	{
		system("color A");
		std::string option;

		system("cls");
		std::cout << "Enter the address of the file to read data:" << std::endl << "Enter ""/exit"" to exit. " << std::endl;
		getline(std::cin, option);

		Arrays new_array;

		int* array_by_max_values = nullptr;
		size_t size_search_array;

		while (option != "/exit") {
			try {
				read_from_file(option, new_array);
				array_by_max_values = get_by_max_values(new_array, size_search_array);

				std::cout << "Enter the address to create the data file: " << std::endl;
				getline(std::cin, option);

				write_to_file(array_by_max_values, size_search_array, option);
				delete[] array_by_max_values;
				delete_array(new_array);
			}
			catch (Exception& exception) {
				std::cout << "An error has occurred in working with arrays." << exception.what() << std::endl << " Error in this function: " << exception.get_func() << std::endl;
				
				system("pause");
				delete[] array_by_max_values;
				delete_array(new_array);
			}
			catch (std::exception& exception) {
				std::cout << "An error has occurred in working with arrays." << exception.what() << std::endl;

				system("pause");
				delete[] array_by_max_values;
				delete_array(new_array);
			}
			catch (...) {
				std::cout << "Unknown error!" << std::endl;

				system("pause");
				delete[] array_by_max_values;
				delete_array(new_array);
			}
			system("cls");
			std::cout << "Enter the address of the file to read data:" << std::endl << "Enter ""/exit"" to exit. " << std::endl;
			getline(std::cin, option);
		}
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	system("pause");
	return _CrtDumpMemoryLeaks();
}