#include "WorkArray.h"

void read_from_file(const std::string file_name, Arrays& Arrays) {
	std::ifstream fin(file_name);

	if (!fin) {
		throw Exception("Can't open file for reading", "read_from_file");
	}

	fin >> Arrays.size;
	Arrays.array_of_sizes = new int[Arrays.size];
	Arrays.array = new int*[Arrays.size];

	int* point;
	for (int i = 0; i < Arrays.size; i++) {
		fin >> get_size(i, Arrays);
		Arrays.array[i] = new int[get_size(i, Arrays)];

		for (int j = 0; j < get_size(i, Arrays); j++) {
			fin >> get_by_index(i, j, Arrays);
			fin.ignore();
		}
	}
	fin.close();
}

int* get_by_max_values(Arrays& Arrays, size_t& size) {
	size = Arrays.size;
	int* max_values = new int[size];
	int k = 0;
	for (int i = 0; i < Arrays.size; i++) {
		max_values[i] = get_max_value(Arrays.array[i], Arrays.array_of_sizes[i]);
	}
	return max_values;
}

int& get_max_value(int* arr, size_t size) {
	int max_elem_index = 0;
	for (int i = 1; i < size; i++) {
		if (arr[i] > arr[max_elem_index]) {
			max_elem_index = i;
		}
	}
	return arr[max_elem_index];
}

void write_to_file(int* elemArray, const size_t& size, const std::string file_name) {
	std::ofstream fout(file_name);

	if (!fout) {
		throw Exception("Can't open file for writing", "write_to_file");
	}

	fout << "Array of max elements: " << std::endl;
	for (int i = 0; i < size; i++) {
		fout << elemArray[i] << " ";
	}
	fout.close();
}

void delete_array(Arrays& Arrays) {
	for (int i = 0; i < Arrays.size; i++) {
		delete[] Arrays.array[i];
	}
	delete[] Arrays.array_of_sizes;
	delete[] Arrays.array;
}

void set_arr_by_index(const size_t i,	int* newArray, Arrays& Arrays) {
	if (i >= Arrays.size) {
		throw Exception("Invalid index", "set_arr_by_index");
	}
	Arrays.array[i] = newArray;
}

int& get_size(const size_t i,	Arrays& Arrays) {
	if (i >= Arrays.size) {
		throw Exception("Invalid index", "get_size");
	}
	return Arrays.array_of_sizes[i];
}

int& get_by_index(const size_t i, const size_t j, Arrays& Arrays) {
	if (i >= Arrays.size || j >= get_size(i, Arrays)) {
		throw Exception("Invalid index", "get_by_index");
	}
	return Arrays.array[i][j];
}