#include "Shablon.h"
using std::cout;
using std::cin;
using std::endl;

void Shablon::printOut(int *arr,int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
}

int Shablon::lowest(int * arr,int size) {
	int low = arr[0];

	for (int i = 1; i < size; i++) {
		if (arr[i] < low) {
			low = arr[i];
		}
	}

	return low;
}

void Shablon::sort(int * arr,int size) {
	int temp;

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

int Shablon::find(int* arr, int size, int value) {

	for (int i = 0; i < size; i++) {
		if (arr[i] == value)return i;
	}

	return -1;
}