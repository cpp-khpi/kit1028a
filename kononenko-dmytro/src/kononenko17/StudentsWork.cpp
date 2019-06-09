#include "pch.h"
#include "StudentsWork.h"
#include "InfoWork.h"
typedef bool(*fun)(int a, int b);

int StudentsWork::getSize() {
	return size;
}

void StudentsWork::createArr(string *name) {
	qual = new InfoWork[size];
	for (int i = 0; i < size; i++) {
		qual[i].set(name[i]);
	}
}
int StudentsWork::add(InfoWork obj, int n) {

	if (n >= size) {
		return 1;
	}
	int i;
	int j = 0;

	size++;
	InfoWork* arr = new InfoWork[size];
	for (i = 0; i < n; i++) {
		arr[i] = this->qual[j];
		j++;
	}

	arr[n] = obj;

	for (i = n + 1; i < size; i++) {
		arr[i] = this->qual[j];
		j++;
	}
	delete[] qual;
	qual = arr;
	return 0;
}
int StudentsWork::del(int n) {
	if (n >= size) {
		cout << "Error: invalid index" << endl;
		return 2;
	}
	if (size < 2) {
		cout << "Error: you can not delete last element" << endl;
		return 1;
	}
	int j = 0;

	size--;
	InfoWork* arr = new InfoWork[size];
	for (int i = 0; i < n; i++) {
		arr[i] = this->qual[j];
		j++;
	}
	j++;
	for (int i = n; i < size; i++) {
		arr[i] = this->qual[j];
		j++;
	}
	delete[] qual;
	qual = arr;
	return 0;
}
void StudentsWork::printArr(std::multimap<int, std::string, std::less<int>> tmp,int i) {
	for (const auto& el : tmp) {
		if (el.second == "Mark")
			cout << " Mark= " << qual[i].getMark();
		if (el.second == "Name")
			cout << "Name: " << qual[i].getName();
		if (el.second == "Type")
			if (qual[i].getType() == 1) {
				cout << " BACALAVR" << endl;
			}
			else {
				cout << " MAGISTR" << endl;
			}
		if (el.second == "Pages")
			cout << " Size= " << qual[i].getPages();
	}
	cout << endl;
}
void StudentsWork::printFile(string file, std::multimap<int, std::string, std::less<int>> tmp,int i) {
	ofstream fout;
	fout.open(file);
	for (const auto& el : tmp) {
		if (el.second == "Mark")
			fout << " Mark= " << qual[i].getMark();
		if (el.second == "Name")
			fout << "Name: " << qual[i].getName();;
		if (el.second == "Type")
			if (qual[i].getType() == 1) {
				fout << " BACALAVR" << endl;
			}
			else {
				fout << " MAGISTR" << endl;
			}
		if (el.second == "Pages")
			fout << " Size= " << qual[i].getPages();
	}
	fout.close();
}

void StudentsWork::setSize(int size) {
	this->size = size;
}

void StudentsWork::delArr() {
	delete[] qual;
}