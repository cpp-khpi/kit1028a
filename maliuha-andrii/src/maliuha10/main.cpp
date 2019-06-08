#include "FuncsForArray.hpp"

int main() {
	int arr[] = { 2, 7, 6, 0 };
	FuncsForArray::showArray(arr, 4);
	int ind = FuncsForArray::getIndex(arr, 6, 4);
	FuncsForArray::sort(arr, 4);
	FuncsForArray::showArray(arr, 4);
	int min = FuncsForArray::getMin(arr, 4);
	return 0;
}