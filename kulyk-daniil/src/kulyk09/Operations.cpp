#include "Operations.h"

stringstream Operations::readFromFile(string nameFile) {
	ifstream file;
	string info;
	file.open(nameFile);
	stringstream arrays;
	if (!file.is_open()) {
		throw Exception("Can't open file for reading");
	}
	while (!file.eof()) {
		std::getline(file, info);
		arrays << info << " ";
	}
	file.close();
	return arrays;
}


void Operations::createArrays1(stringstream &arrays) {
	arrays >> amount_of_arrays;
	this->arrays = new SomeArray[amount_of_arrays];
	for (int i = 0; i < amount_of_arrays; i++) {
		arrays >> this->arrays[i].size;
		this->arrays[i].arr = new int[this->arrays[i].size];
		for (int j = 0; j < this->arrays[i].size; j++) {
			arrays >> this->arrays[i].arr[j];
		}
	}
}

void Operations::ArrMaxValue(int *&arr) {
	arr = new int[amount_of_arrays];
	int max;
	for (int i = 0; i < amount_of_arrays; i++) {
		max = arrays[i].arr[0];
		for (int j = 0; j < arrays[i].size; j++) {
			//std::cout << arrays[i].arr[j + 1] << std::endl;
			if (max < arrays[i].arr[j]) {
				max = arrays[i].arr[j];
			}
		}
		arr[i] = max;
	}
}

void Operations::writeToFile(int *arr, string nameFile) {
	std::ofstream file;
	file.open(nameFile);
	if (!file.is_open()) {
		throw Exception("Can't open file for reading");
	}
	file << "Array of max value: " << endl;
	for (int i = 0; i < amount_of_arrays; i++) {
		file << arr[i] << " ";
	}
	file.close();
}


void Operations::delArrays() {
	arrays->delArr();
	delete[] arrays;
}