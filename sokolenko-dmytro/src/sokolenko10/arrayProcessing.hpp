/**
* @file arrayProcessing.hpp
* Declaration and definition 
* namespace's arrayProcessing template functions.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.06.04
*/

#pragma once

#include <iostream>

using std::cout;
using std::endl;



namespace arrayProcessing {
	/**
	* Template function that display on the screen 
	* all elements of array.
	* @param array: object's array.
	* @param size: size of array.
	*/
	template <typename T>
	void output(T* array, size_t size)
	{
		for (int i = 0; i < size; i++) {
			cout << "#" << i << " " << array[i] << endl;
		}
	}

	/**
	* Template function that find index of needed element
	* by element.
	* @param array: object's array.
	* @param size: size of array.
	* @param desired: object which is sought.
	* @return index of sought element or -1 if there no this
	* element in the array.
	*/
	template <typename T>
	int find(T* array, size_t size, const T& desired)
	{

		for (int i = 0; i < size; i++) {
			if (array[i] == desired)
				return i;
		}

		return -1;
	}

	/**
	* Template function that sort array ascending.
	* @param array: object's array.
	* @param size: size of array.
	*/
	template <typename T>
	void sort(T* array, size_t size)
	{
		T temp;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (array[j] > array[j + 1]) {
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}

	/**
	* Template function that return lowest element.
	* @param array: object's array.
	* @param size: size of array.
	* @return reference to lowest element of array.
	*/
	template <typename T>
	T& getLowest(T* array, size_t size) {

		int smallestInd = 0;
		for (int i = 1; i < size; i++) {
			if (array[i] < array[smallestInd]) {
				smallestInd = i;
			}
		}

		return array[smallestInd];
	}
}