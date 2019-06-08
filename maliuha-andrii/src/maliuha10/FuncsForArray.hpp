#pragma once

#include <iostream>

namespace FuncsForArray {
	
	template < typename T>
	void showArray(T *arr, const int size) {
		std::cout << "Elements of array: " << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}


	template < typename T>
	int getIndex(T *arr, T elem, const int size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == elem) {
				return i;
			}
		}
		std::cout << "Element was not found in array." << std::endl;
		return -1;
	}

	template < typename T>
	void sort(T * arr, const int size)
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
	T getMin(T * arr, const int size) {
		T min = arr[0];
		for (int i = 0; i < size; i++) {
			if (min > arr[i]) {
				min = arr[i];
			}
		}
		return min;
	}
};