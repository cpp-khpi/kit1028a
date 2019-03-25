#include "IndependentsWork.h"

void IndependentsWork::getSize(int size) {
	IndependentsWork::size = size;
}
void IndependentsWork::newArray(char **surname) {
	arr = new InfoIndependentsWork[size];
	for (int i = 0; i < size; i++) {
		arr[i].generation_values((*(surname + i)));
	}
}
void IndependentsWork::print() {
	for (int i = 0; i < size; i++) {

		std::cout << "Student surname: " << arr[i].getSurname() << std::endl;
		std::cout << "Amount of independent works: " << arr[i].getAmount() << std::endl;
		std::cout << "Amount of written independent works: " << arr[i].getWritten() << std::endl;
		std::cout << "Student mark (average): " << arr[i].getMark() << std::endl << std::endl;

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
	if (size < 2) {
		std::cout << "              Error              " << std::endl;
		std::cout << " You cant delete last element " << std::endl;
		system("pause");
		return;
	}
	if (l - 1 >= size) {
		std::cout << "              Error              " << std::endl;
		std::cout << " You cant enter index more then size of array " << std::endl;
		system("pause");
		return;
	}

	size--;
	InfoIndependentsWork* mas = new InfoIndependentsWork[size];

	int j = 0;
	for (int i = 0; i < l - 1; i++) {
		mas[i] = IndependentsWork::arr[j];
		j++;
	}
	j++;
	for (int i = l - 1; i < size; i++) {
		mas[i] = IndependentsWork::arr[j];
		j++;
	}
	
	arr = mas;
}
void IndependentsWork::getByIndex(int index) {
	if (index-1 >= size) {
		std::cout << std::endl << "Error" << std::endl << std::endl;
		return;
	}
	
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "Student surname: " << arr[index - 1].getSurname() << std::endl;
	std::cout << "Amount of independent works: " << arr[index - 1].getAmount() << std::endl;
	std::cout << "Amount of written independent works: " << arr[index - 1].getWritten() << std::endl;
	std::cout << "Student mark (average): " << arr[index - 1].getMark() << std::endl << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl << std::endl;
}
void IndependentsWork::deleteArray() {
	delete[] arr;
}