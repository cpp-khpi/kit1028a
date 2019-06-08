#pragma once
#include <iomanip>
#include <iostream>

template < typename T>
class FuncsForArray {
private:
	T *arr;
	int size;
public:
	FuncsForArray();
	~FuncsForArray();
	void setArray(int size);
	void showArray();
	int getIndex(T elem);
	void sort();
	T getMin();
};

template < typename T>
FuncsForArray<T>::FuncsForArray() : arr(NULL), size(0) {}

template < typename T>
FuncsForArray<T>::~FuncsForArray() {
	delete[] arr;
}



template < typename T>
void FuncsForArray<T>::showArray() {
	std::cout << "Elements of array: " << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template < typename T>
int FuncsForArray<T>::getIndex(T elem) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == elem) {
			return i;
		}
	}
	std::cout << "Element was not found in array." << std::endl;
	return -1;
}

template < typename T>
void FuncsForArray<T>::sort()
{
	for (int i = 0; i < size - 1; ++i)
		for (int j = 0; j < size - i - 1; ++j)
			if (arr[j] > arr[j + 1]) {
				T tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
}

template < typename T>
T FuncsForArray<T>::getMin() {
	T min = arr[0];
	for (int i = 0; i < size; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return min;
}

template < typename T>
void FuncsForArray<T>::setArray(int size) {
	this->size = size;
	arr = new T[this->size];
	for (int i = 0; i < this->size; i++) {
		arr[i] = rand() % 101;
	}
}
