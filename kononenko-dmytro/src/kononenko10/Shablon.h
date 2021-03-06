#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

namespace shablon {
	template <class T>
	void printOut(T* arr, int size) { // ����� ������ ����������� �������
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	};
	template <class T>
	void sort(T * arr, int size) { // ����� ������� ��������� ���������� ������
		T temp;

		for (int i = 0; i < size; i++) {
			for (int y = 0; y < size; y++) {
				if (arr[i] < arr[y]) {
					temp = arr[i];
					arr[i] = arr[y];
					arr[y] = temp;
				}
			}
		}
	};
	template <class T>
	T lowest(T * arr, int size) { // ����� ������ ���������� �������� �������
		T low = arr[0];

		for (int i = 1; i < size; i++) {
			if (arr[i] < low) {
				low = arr[i];
			}
		}

		return low;
	};
	template <class T>
	int find(T *arr, int size, T value) { // ����� ������ �������� � ���������� ������� �� �������� 

		for (int i = 0; i < size; i++) {
			if (arr[i] == value)return i;
		}

		return -1;
	};
};