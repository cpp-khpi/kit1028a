#pragma once
#include <iostream>

typedef unsigned int ID;

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class TestInfo {
private:
	ID mark;
public:	
	TestInfo();
	TestInfo(int mark);
	TestInfo(const TestInfo& obj);
	~TestInfo();
	
	TestInfo& operator = (const TestInfo& obj);
	friend ostream& operator << (ostream& out, const TestInfo& obj);
	friend istream& operator >> (istream& in, TestInfo& obj);
	bool operator == (const TestInfo obj);

	int getMark();
	void randValues();
	void setInfo(int mark);
};

template <class T>
class Template {
private:
	T* arr;
	size_t size;
public:
	Template() : size(0) {}
	Template(size_t size) : size(size) {
		arr = new T[size];
	}
	~Template() {
		delete[] arr;
	}

	void fillArr() {
		cout << "Enter marks: ";
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 5 + 1;
		}
	}

	void printArr() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}

	T minValues() {
		T min = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		return min;
	}

	void sortArr() {
		T temp;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (arr[i] < arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

	int searchEl(T values) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == values) {
				return i;
			}
		}
		return -1;
	}


};