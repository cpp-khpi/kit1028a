#include "Arrays.h"


std::stringstream Arrays::readFromFile(std::string nameFile) {
	std::ifstream file;
	std::string info;
	file.open(nameFile);
	std::stringstream arrays;
	if (!file.is_open()) {
		throw MyException("Can't open file for reading");
	}
	while (!file.eof()) {
		std::getline(file, info);
		arrays << info << " ";
	}
	file.close();
	return arrays;
}


void Arrays::createArrays1(std::stringstream &arrays) {
	arrays >> amountArr;
	this->arrays = new Array[amountArr];
	for (int i = 0; i < amountArr; i++) {
		arrays >> this->arrays[i].size;
		this->arrays[i].arr = new int[this->arrays[i].size];
		for (int j = 0; j < this->arrays[i].size; j++) {
			arrays >> this->arrays[i].arr[j];
		}
	}
}

void Arrays::ArrMaxValue(int *&arr) {
	arr = new int[amountArr];
	int max;
	for (int i = 0; i < amountArr; i++) {
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

void Arrays::writeArrToFile(int *arr, std::string nameFile) {
	std::ofstream file;
	file.open(nameFile);
	if (!file.is_open()) {
		throw MyException("Can't open file for reading");
	}
	file << "Array of max value: " << std::endl;
	for (int i = 0; i < amountArr; i++) {
		file << arr[i] << " ";
	}
	file.close();
}


void Arrays::delArrays() {
	arrays->delArr();
	delete[] arrays;
}