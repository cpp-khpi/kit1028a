#pragma once

#include <fstream>
#include "Exception.h"

void read_from_file(std::string file_name, Arrays& Arrays);
int* get_by_max_values(Arrays& intArray, size_t& size);
void write_to_file(int* elemArray, const size_t& size, const std::string file_name);
void delete_array(Arrays& Arrays);
int& get_size(const size_t i, Arrays& Arrays);
void set_arr_by_index(const size_t i, int* newArray, Arrays& Arrays);
int& get_by_index(const size_t i, const size_t j, Arrays& Arrays);
int& get_max_value(int* arr, size_t size);