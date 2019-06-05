#include "Array.h"

template <typename T>
Array<T>::Array() : size(0)
{
	data = nullptr;
}

template <typename T>
Array<T>::Array(size_t newSize) : size(newSize)
{
	if (data != nullptr)
		delete[] data;

	data = new T[size];
}

template <typename T>
Array<T>::~Array()
{
	if (data != nullptr)
		delete[] data;
}

template <typename T>
void Array<T>::output()
{
	for (int i = 0; i < size; i++) {
		cout << "#" << i << " " << data[i] << endl;
	}
}

template <typename T>
int Array<T>::find(const T& desired)
{

	for (int i = 0; i < size; i++) {
		if (data[i] == desired)
			return i;
	}

	return -1;
}

template <typename T>
void Array<T>::sort()
{
	T temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

template <typename T>
T& Array<T>::getLowest()
{

	int smallestInd = 0;
	for (int i = 1; i < size; i++) {
		if (data[i] < data[smallestInd]) {
			smallestInd = i;
		}
	}

	return data[smallestInd];
}