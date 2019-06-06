#include "pch.h"
#include "Arr.h"
#include "main.h"

Arr::~Arr() {
	if (arr != NULL) {
		delete[] sizes;
	}
	for (int i = 0; i < size; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void Arr::readFromFile(string address) {
	string tmp;
	stringstream ss;
	ifstream fin;
	delete[] arr;
	fin.open(address);

	if (!fin.is_open()) {
		throw Exception(" Wrong address", __FILE__, __LINE__, __FUNCTION__);
	}

	getline(fin, tmp);
	ss << tmp;
	ss >> size;

	arr = new int*[size];
	sizes = new int[size];

	for (int i = 0; i < size; i++) {
		getline(fin, tmp);
		istringstream tester(tmp);
		tester >> sizes[i];
		arr[i] = new int[sizes[i]];
		for (int j = 0; j < sizes[i]; j++) {
			tester >> arr[i][j];
		}
	}
}

void Arr::WriteMaxArray(string address){
	int* MaxArray = new int[size];

	for (int i = 0; i < size; i++) {
		MaxArray[i] = maxInArray(arr[i], sizes[i]);
	}

	ofstream fout;
	fout.open(address);

	if (!fout.is_open()) {
		throw Exception(" Wrong address", __FILE__, __LINE__, __FUNCTION__);
	}

	fout << "Array index: ";
	for (int i = 0; i < size; i++) {
		fout << MaxArray[i] << " ";
	}
	fout << endl;
	delete[] MaxArray;
}
void Arr::WriteToFile(string address) {

	ofstream fout;
	fout.open(address);

	if (!fout.is_open()) {
		throw Exception(" Wrong address", __FILE__, __LINE__, __FUNCTION__);
	}

	for (int i = 0; i < size; i++) {
		fout << "Array: ";
		for (int j = 0; j < sizes[i]; j++) {
			fout << arr[i][j] << " ";
		}
		fout << endl;
	}
}
int Arr::getIndex(int index, int index2) {
	if (index < 0 || index > size) {
		throw Exception(" Wrong index for first array", __FILE__, __LINE__, __FUNCTION__);
	}
	if (index2 < 0 || index2 > sizes[index]) {
		throw Exception(" Wrong index for second array", __FILE__, __LINE__, __FUNCTION__);
	}

	return arr[index][index2];
}
