#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template<class T,int size>
class Shablon {
private:
	T arr[size];
public:
	void printOut() { // ����� ������ ����������� �������
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	};

	void sort() { // ����� ������� ��������� ���������� ������
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
	}
	T lowest() { // ����� ������ ���������� �������� �������
		T low = arr[0];

		for (int i = 1; i < size; i++) {
			if (arr[i] < low) {
				low = arr[i];
			}
		}

		return low;
	};
	int find(T value) { // ����� ������ �������� � ���������� ������� �� �������� 

		for (int i = 0; i < size; i++) {
			if (arr[i] == value)return i;
		}

		return -1;
	};

	void fill() {
		for (int i = 0; i < size; i++) {
			cout << "Input size and points: ";
			cin >> arr[i];
		}
	}
};