#include "FuncsForArray.h"

int main() {
	FuncsForArray<int> Arr;
	Arr.setArray(10);
	Arr.showArray();

	int elem;
	std::cout << "Enter elem for take an index: ";
	std::cin >> elem;
	int index = -1;
	index = Arr.getIndex(elem);
	if (index != -1) {
		std::cout << "Index of element: " << index << std::endl;
	}
	Arr.sort();
	Arr.showArray();
	int min = Arr.getMin();
	std::cout << "Min element from array: " << min << std::endl;
	return 0;
}