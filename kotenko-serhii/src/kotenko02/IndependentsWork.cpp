#include "IndependentsWork.h"

void IndependentsWork::getSize(int size) {
	IndependentsWork::size = size;
}
void IndependentsWork::newArray(char **surname) {
	arr = new InfoIndependentsWork[size];
	for (int i = 0; i < size; i++) {
		arr[i].setInfo((*(surname + i)));
	}
}
void IndependentsWork::print() {
	for (int i = 0; i < size; i++) {
		int amount = arr[i].getAmount();
		int written = arr[i].getWritten();
		int mark = arr[i].getMark();
		char *surname = arr[i].getSurname();

		std::cout << "Student surname: " << surname << std::endl;
		std::cout << "Amount of independent works: " << amount << std::endl;
		std::cout << "Amount of written independent works: " << written << std::endl;
		std::cout << "Student mark (average): " << mark << std::endl << std::endl;
	}
}
void IndependentsWork::addElem(int amount, int written, int mark, char *surname) {
	
	InfoIndependentsWork *mas = new InfoIndependentsWork[size + 1];

	for (int i = 0; i < size; i++) {
		mas[i] = IndependentsWork::arr[i];
	}

	size++;

	mas[size - 1].setData(amount, written, mark, surname);

	arr = mas;
}
void IndependentsWork::deleteElem(int l) {
	InfoIndependentsWork* mas = new InfoIndependentsWork[size];

	int j = 0;
	for (int i = 0; i < l-1; i++) {
		mas[i] = IndependentsWork::arr[j];
		j++;
	}
	j++;
	for (int i = l-1; i < size; i++) {
		mas[i] = IndependentsWork::arr[j];
		j++;
	}
	size--;

	arr = mas;
}
void IndependentsWork::getByIndex(int index) {
	if (index-1 >= size) {
		std::cout << std::endl << "Error" << std::endl << std::endl;
		return;
	}

	int amount = arr[index-1].getAmount();
	int written = arr[index-1].getWritten();
	int mark = arr[index-1].getMark();
	char *surname = arr[index-1].getSurname();
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Student surname: " << surname << std::endl;
	std::cout << "Amount of independent works: " << amount << std::endl;
	std::cout << "Amount of written independent works: " << written << std::endl;
	std::cout << "Student mark (average): " << mark << std::endl << std::endl;
}
void IndependentsWork::deleteArray() {
	delete[] IndependentsWork::arr;
}