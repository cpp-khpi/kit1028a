#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::endl;

int validate_file_name(string file_name);
void read_file(string file_name, int ***file_data, int *rows_in_file, int **columns_in_file);
void add_arrays(int ***file_data, int ***file_data1, int ***result, int *rows_in_file, int **columns_in_file, int *rows_in_file1, int **columns_in_file1);
void write_file(string file_name, int ***result, int *rows_in_file, int **columns_in_file, int *rows_in_file1, int **columns_in_file1);