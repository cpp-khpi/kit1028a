#include "ElectronicLibrary.h"

void ElectronicLibrary::sortByCost(bool(*bubble)(int x, int y)) {
	ElectronicTextbook tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (bubble(backlist[i].getCost(), backlist[j].getCost())) {
				tmp = backlist[i];
				backlist[i] = backlist[j];
				backlist[j] = tmp;
			}
		}
	}
}

void ElectronicLibrary::printAll() {
	for (int i = 0; i < size; i++) {
		cout << endl;
		cout << "Textbook number is: " << backlist[i].getNum() << endl;
		cout << "The amount of charge of electronic textbook is: " << backlist[i].getAmountOfCharge() << endl;
		cout << "The number of pages in textbook is: " << backlist[i].getPages() << endl;
		cout << "The grade this textbook for is: " << backlist[i].getGrade() << endl;
		cout << "The cost of this textbook is: " << backlist[i].getCost() << endl;
		cout << "The year of release of this textbook is: " << backlist[i].getYearOfRelease() << endl;
		cout << "The author of this textbook is: " << backlist[i].getAuthor() << endl << endl;
	}

}

void ElectronicLibrary::setSize(int size) {
	ElectronicLibrary::size = size;
}

void ElectronicLibrary::addTextbook(int num, int pages, int grade, int cost, int year_of_release, int amount_of_charge, string author) {
	ElectronicTextbook *tmp_textbook = new ElectronicTextbook[size + 1];

	for (int i = 0; i < size; i++) {
		tmp_textbook[i] = ElectronicLibrary::backlist[i];
	}

	size++;

	tmp_textbook[size - 1].setInfo(amount_of_charge, num, pages, grade, cost, year_of_release, author);

	delete[] backlist;
	backlist = tmp_textbook;
}

void ElectronicLibrary::removeTextbook(int num) {
	if (size < 2) {
		cout << " You cant delete last element " << endl;
		system("pause");
		return;
	}
	if (num - 1 >= size) {
		std::cout << " You cant enter index more then size of array " << std::endl;
		system("pause");
		return;
	}

	size--;
	ElectronicTextbook* tmp_textbook = new ElectronicTextbook[size];

	int j = 0;
	for (int i = 0; i < num - 1; i++) {
		tmp_textbook[i] = ElectronicLibrary::backlist[j];
		j++;
	}
	j++;
	for (int i = num - 1; i < size; i++) {
		tmp_textbook[i] = ElectronicLibrary::backlist[j];
		j++;
	}
	delete[]backlist;
	backlist = tmp_textbook;
}

void ElectronicLibrary::getRequiredTextbook(int index) {
	if (index - 1 >= size) {
		cout << std::endl << "Error" << endl << endl;
		return;
	}
	cout << endl;
	cout << "Textbook number is: " << backlist[index - 1].getNum() << endl;
	cout << "The amount of charge of electronic textbook is: " << backlist[index - 1].getAmountOfCharge() << endl;
	cout << "The number of pages in textbook is: " << backlist[index - 1].getPages() << endl;
	cout << "The grade this textbook for is: " << backlist[index - 1].getGrade() << endl;
	cout << "The cost of this textbook is: " << backlist[index - 1].getCost() << endl;
	cout << "The year of release of this textbook is: " << backlist[index - 1].getYearOfRelease() << endl;
	cout << "The author of this textbook is: " << backlist[index - 1].getAuthor() << endl << endl;
}

void ElectronicLibrary::deleteBacklist() {
	delete[] backlist;
}

float ElectronicLibrary::averageAmountOfPages(int num) {
	float result = 0;
	for (int i = 0; i < size; i++) {
		result += backlist[i].getPages();
	}
	result = result / size;
	cout << "The average amount of pages is: " << result << endl << endl;
	delete[]backlist;

	return result;
}

void ElectronicLibrary::getSurname(string *author) {
	backlist = new ElectronicTextbook[size];
	for (int i = 0; i < size; i++) {
		backlist[i].getInfo(author[i]);
	}
}

void ElectronicLibrary::readFromFile(string *book) {
	std::regex regex_upperRegister("^[A-Z]");
	std::regex regex_space("[\\s]{2,}");
	std::ifstream fin;
	fin.open("Names.txt");
	for (int i = 0; i < size; i++) {
		getline(fin, book[i]);
		if (!(regex_search(book[i], regex_upperRegister)) || regex_search(book[i], regex_space)) {
			cout << "Incorrect entry, writing with large letters(A - Z) : " << book[i] << endl;
			cin.ignore();
			getline(cin, book[i]);
		}
	}
	fin.close();
}

void ElectronicLibrary::writeToFile() {
	ofstream fout;
	fout.open("Array.txt");
	for (int i = 0; i < size; i++) {
		fout << "Textbook number is: " << backlist[i].getNum() << endl;
		fout << "The number of pages in textbook is: " << backlist[i].getPages() << endl;
		fout << "The grade this textbook for is: " << backlist[i].getGrade() << endl;
		fout << "The cost of this textbook is: " << backlist[i].getCost() << endl;
		fout << "The year of release of this textbook is: " << backlist[i].getYearOfRelease() << endl;
		fout << "The author of this textbook is: " << backlist[i].getAuthor() << endl;
		fout << "The amount of charge of this electronic textbook is: " << backlist[i].getAmountOfCharge() << endl << endl;
	}
	fout.close();
}