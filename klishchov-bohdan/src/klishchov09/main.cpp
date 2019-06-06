#include"functions.h"

int main() 
{
	int **file_data = nullptr;
	int **file_data1 = nullptr;
	int **addition_result = nullptr;
	int rows_in_file;
	int *columns_in_file = nullptr;
	int rows_in_file1;
	int *columns_in_file1 = nullptr;
	int **result;
	int exception;
	string message;
	string file_name;
	do {
		try
		{
			cout << "Input name of the first file: ";
			cin >> file_name;
			exception = validate_file_name(file_name);
			if (exception == 1)
				throw message = "Invalid name";
			read_file(file_name, &file_data, &rows_in_file, &columns_in_file);

			cout << "Input name of the second file: ";
			cin >> file_name;
			exception = validate_file_name(file_name);
			if (exception == 1)
				throw message = "Invalid name";
			read_file(file_name, &file_data1, &rows_in_file1, &columns_in_file1);

			cout << "The result of addition is:" << endl;
			add_arrays(&file_data, &file_data1, &result, &rows_in_file, &columns_in_file, &rows_in_file1, &columns_in_file1);

			cout << "Input name of the file to write to: ";
			cin >> file_name;
			exception = validate_file_name(file_name);
			if (exception == 1)
				throw message = "Invalid name";
			write_file(file_name, &result, &rows_in_file, &columns_in_file, &rows_in_file1, &columns_in_file1);
		}
		catch (...)
		{
			cout << message << endl;
		}
	} while (true);


	return 0;
}