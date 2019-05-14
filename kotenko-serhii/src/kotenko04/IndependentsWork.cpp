#include "IndependentsWork.h"

void IndependentsWork::setSize(int size) {
	IndependentsWork::size = size;
}
void IndependentsWork::readFromFile(std::string *person) {
	std::regex regex_firstSymbol("^[A-Z]");
	std::regex regex_spaces("[\\s]{2,}");
	std::ifstream fin;
	fin.open("StudentsSurname.txt");
	for (int k = 0; k < size; k++) {
		getline(fin, person[k]);
		if (!(regex_search(person[k], regex_firstSymbol)) || regex_search(person[k], regex_spaces)) {
			std::cout << "Incorrect entry, writing with large letters(A - Z) : " << person[k] << std::endl;
			std::cin.ignore();
			getline(std::cin, person[k]);
		}
	}
	fin.close();
}
void IndependentsWork::newArray(std::string *person) {
	arr = new InfoIndependentsWork[size];
	for (int i = 0; i < size; i++) {
		arr[i].generation_values(person[i]);
	}
}
void IndependentsWork::print() {
	for (int i = 0; i < size; i++) {
		std::cout << "Student info: " << arr[i].getPerson() << std::endl;
		std::cout << "Amount of independent works: " << arr[i].getAmount() << std::endl;
		std::cout << "Amount of written independent works: " << arr[i].getWritten() << std::endl;
		std::cout << "Student mark (average): " << arr[i].getMark() << std::endl << std::endl;
	}
}
void IndependentsWork::addElem(int amount, int written, int mark, std::string person) {
    
	InfoIndependentsWork *mas = new InfoIndependentsWork[size + 1];

	for (int i = 0; i < size; i++) {
		mas[i] = IndependentsWork::arr[i];
	}

    size++;

	mas[size - 1].setData(amount, written, mark, person);

	delete[] arr;
	arr = mas;
}
void IndependentsWork::deleteElem(int l) {
	if (size < 2) {
		std::cout << "                Error              " << std::endl;
		std::cout << " You cant delete last element " << std::endl;
		system("pause");
		return;
	}
	if (l - 1 >= size) {
		std::cout << "                Error              " << std::endl;
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
	delete[]arr;
	arr = mas;
}
void IndependentsWork::getByIndex(int index) {
	if (index - 1 >= size) {
		std::cout << std::endl << "Error" << std::endl << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "Student info: " << arr[index - 1].getPerson() << std::endl;
	std::cout << "Amount of independent works: " << arr[index - 1].getAmount() << std::endl;
	std::cout << "Amount of written independent works: " << arr[index - 1].getWritten() << std::endl;
	std::cout << "Student mark (average): " << arr[index - 1].getMark() << std::endl << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl << std::endl;
}
void IndependentsWork::writeToFile() {
	std::ofstream fout;
	fout.open("InfoStud.txt");
	for (int i = 0; i < size; i++) {
		fout << "Student info: " << arr[i].getPerson() << std::endl;
		fout << "Amount of independent works: " << arr[i].getAmount() << std::endl;
		fout << "Amount of written independent works: " << arr[i].getWritten() << std::endl;
		fout << "Student mark (average): " << arr[i].getMark() << std::endl << std::endl;
	}
	fout.close();
}
void IndependentsWork::deleteArray() {
	delete[]arr;
}
void IndependentsWork::searchBySurname(std::string search_person) {
	for (int i = 0; i < size; i++) {
		if (search_person == arr[i].getPerson()) {
			std::cout << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
			std::cout << "Student info: " << arr[i].getPerson() << std::endl;
			std::cout << "Amount of independent works: " << arr[i].getAmount() << std::endl;
			std::cout << "Amount of written independent works: " << arr[i].getWritten() << std::endl;
			std::cout << "Student mark (average): " << arr[i].getMark() << std::endl << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
		}
	}
}