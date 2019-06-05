/**
* @file Array.h
* Declaration Array class.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.06.05
*/

#pragma once

#include <iostream>

using std::cout;
using std::endl;

/**
* Declaration Phone class with fields and methods.
* Used Javadoc style comments to handle Doxygen.
*/
template <typename T>
class Array {
private:
	/** Pointer to data array. */
	T* data;
	/** Size of array. */
	size_t size;
public:
	/**
	* Default constructor
	* Used initialization lists.
	*/
	Array();

	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param newData is copied to Array::data.
	* @param newSize initializes Array::size.
	*/
	Array(size_t newSize);

	/**
	* Destructor.
	*/
	~Array();

	/**
	* Display on the screen
	* all elements of array.
	*/
	void output();

	/**
	* Find index of needed element
	* by element.
	* @param desired: object which is sought.
	* @return index of sought element or -1 if there no this
	* element in the array.
	*/
	int find(const T& desired);

	/**
	* Sort array ascending.
	*/
	void sort();

	/**
	* Return lowest element of array.
	* @return reference to lowest element of array.
	*/
	T& getLowest();
};

#include "Array.inl";

//template <typename T>
//Array<T>::Array() : size(0)
//{
//	data = nullptr;
//}
//
//template <typename T>
//Array<T>::Array(size_t newSize) : size(newSize)
//{
//	if (data != nullptr)
//		delete[] data;
//
//	data = new T[size];
//}
//
//template <typename T>
//Array<T>::~Array()
//{
//	if (data != nullptr)
//		delete[] data;
//}
//
//template <typename T>
//void Array<T>::output()
//{
//	for (int i = 0; i < size; i++) {
//		cout << "#" << i << " " << data[i] << endl;
//	}
//}
//
//template <typename T>
//int Array<T>::find(const T& desired)
//{
//
//	for (int i = 0; i < size; i++) {
//		if (data[i] == desired)
//			return i;
//	}
//
//	return -1;
//}
//
//template <typename T>
//void Array<T>::sort()
//{
//	T temp;
//	for (int i = 0; i < size - 1; i++) {
//		for (int j = 0; j < size - i - 1; j++) {
//			if (data[j] > data[j + 1]) {
//				temp = data[j];
//				data[j] = data[j + 1];
//				data[j + 1] = temp;
//			}
//		}
//	}
//}
//
//template <typename T>
//T& Array<T>::getLowest()
//{
//
//	int smallestInd = 0;
//	for (int i = 1; i < size; i++) {
//		if (data[i] < data[smallestInd]) {
//			smallestInd = i;
//		}
//	}
//
//	return data[smallestInd];
//}