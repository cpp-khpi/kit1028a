#include"functions.h"

int validate_file_name(string file_name)
{
	string message;
	const char *temp_file_name = file_name.c_str();

	if (file_name == "\\exit") {
		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
		_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
		_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
		_CrtDumpMemoryLeaks();
		exit(0);
	}
	else if (_access(temp_file_name, 0) == -1) {
		return 1;
	}

	return 0;
}

void read_file(string file_name, int ***file_data, int *rows_in_file, int **columns_in_file)
{
	try {
		int rows_number;
		int columns_number;

		ifstream file(file_name);

		file >> rows_number;

		*rows_in_file = rows_number;
		*columns_in_file = new int[rows_number]();
		*file_data = new int *[rows_number]();

		for (int i = 0; i < rows_number; i++)
		{
			file >> columns_number;

			(*columns_in_file)[i] = columns_number;
			(*file_data)[i] = new int[columns_number]();
			for (int j = 0; j < columns_number; j++)
			{
				file >> (*file_data)[i][j];
				cout << (*file_data)[i][j] << "\t";
			}
			cout << endl;
		}

		file.close();
	}
	catch (...) {
		cout << "Oh shit, here we go again..." << endl;
	}
}

void add_arrays(int ***file_data, int ***file_data1, int ***result, int *rows_in_file, int **columns_in_file, int *rows_in_file1, int **columns_in_file1)
{
	int biggest_row;
	int biggest_column;

	if (*rows_in_file >= *rows_in_file1)
	{
		biggest_row = *rows_in_file;
	}
	else
	{
		biggest_row = *rows_in_file1;
	}

	*result = new int *[biggest_row]();

	for (int i = 0; i < biggest_row; i++)
	{
		if ((*columns_in_file)[i] >= (*columns_in_file1)[i])
		{
			(*result)[i] = new int[(*columns_in_file)[i]]();
		}
		else
		{
			(*result)[i] = new int[(*columns_in_file1)[i]]();
		}
	}

	for (int i = 0; i < *rows_in_file; i++)
	{
		for (int j = 0; j < (*columns_in_file)[i]; j++)
		{
			(*result)[i][j] = (*file_data)[i][j];
		}
	}

	for (int i = 0; i < *rows_in_file1; i++)
	{
		for (int j = 0; j < (*columns_in_file1)[i]; j++)
		{
			(*result)[i][j] += (*file_data1)[i][j];
		}
	}

	for (int i = 0; i < biggest_row; i++)
	{
		if ((*columns_in_file)[i] >= (*columns_in_file1)[i])
		{
			biggest_column = (*columns_in_file)[i];
		}
		else
		{
			biggest_column = (*columns_in_file1)[i];
		}

		for (int j = 0; j < biggest_column; j++)
		{
			cout << (*result)[i][j] << "\t";
		}
		cout << endl;
	}
}

void write_file(string file_name, int ***result, int *rows_in_file, int **columns_in_file, int *rows_in_file1, int **columns_in_file1)
{
	int biggest_row;
	int biggest_column;
	ofstream file(file_name);

	if (*rows_in_file >= *rows_in_file1)
	{
		biggest_row = *rows_in_file;
	}
	else
	{
		biggest_row = *rows_in_file1;
	}

	for (int i = 0; i < biggest_row; i++)
	{
		if ((*columns_in_file)[i] >= (*columns_in_file1)[i])
		{
			biggest_column = (*columns_in_file)[i];
		}
		else
		{
			biggest_column = (*columns_in_file1)[i];
		}

		for (int j = 0; j < biggest_column; j++)
		{
			file << (*result)[i][j] << "\t";
		}
		file << endl;
	}

	file.close();
}
