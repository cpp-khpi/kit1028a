#include"Library.h"

std::ostream& operator<< (std::ostream &out, const Library &obj) {
	out << obj.size << endl;
	for (int i = 0; i < obj.size; i++) {
		out << obj.info[i];
	}
	return out;
}
std::istream& operator>> (std::istream &in, Library &obj) {
	in >> obj.size;
	for (int i = 0; i < obj.size; i++) {
		in >> obj.info[i];
	}
	return in;
}
Textbook& Library::operator[] (const int index) {
	return info[index];
}


void Library::sortByCost(bool(*bubble)(int x, int y)) {
	Textbook tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (bubble(info[i].getCost(), info[j].getCost())) {
				tmp = info[i];
				info[i] = info[j];
				info[j] = tmp;
			}
		}
	}
}

void Library::printAll(int size) {
	for (int i = 0; i < size; i++) {
		cout << endl;
		cout << "Textbook number is: " << info[i].getNum() << endl;
		cout << "The number of pages in textbook is: " << info[i].getPages() << endl;
		cout << "The grade this textbook for is: " << info[i].getGrade() << endl;
		cout << "The cost of this textbook is: " << info[i].getCost() << endl;
		cout << "The year of release of this textbook is: " << info[i].getYearOfRelease() << endl;
		cout << "The author of this textbook is: " << info[i].getAuthor() << endl << endl;
	}

}

void Library::setSize(int size) {
	Library::size = size;
}

void Library::addTextbook(int num, int pages, int grade, int cost, int year_of_release, string author) {
	Textbook *tmp_textbook = new Textbook[size + 1];

	for (int i = 0; i < size; i++) {
		tmp_textbook[i] = Library::info[i];
	}

	size++;

	tmp_textbook[size - 1].setInfo(num, pages, grade, cost, year_of_release, author);

	delete[] info;
	info = tmp_textbook;
}

void Library::removeTextbook(int num) {
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
	Textbook* tmp_textbook = new Textbook[size];

	int j = 0;
	for (int i = 0; i < num - 1; i++) {
		tmp_textbook[i] = Library::info[j];
		j++;
	}
	j++;
	for (int i = num - 1; i < size; i++) {
		tmp_textbook[i] = Library::info[j];
		j++;
	}
	delete[]info;
	info = tmp_textbook;
}

void Library::getRequiredTextbook(int index) {
	if (index - 1 >= size) {
		cout << std::endl << "Error" << endl << endl;
		return;
	}
	cout << endl;
	cout << "Textbook number is: " << info[index - 1].getNum() << endl;
	cout << "The number of pages in textbook is: " << info[index - 1].getPages() << endl;
	cout << "The grade this textbook for is: " << info[index - 1].getGrade() << endl;
	cout << "The cost of this textbook is: " << info[index - 1].getCost() << endl;
	cout << "The year of release of this textbook is: " << info[index - 1].getYearOfRelease() << endl;
	cout << "The author of this textbook is: " << info[index -1].getAuthor() << endl << endl;
}

void Library::deleteBacklist() {
	delete[] info;
}

float Library::averageAmountOfPages(int num) {
	float result = 0;
	for (int i = 0; i < size; i++) {
		result += info[i].getPages();
	}
	result = result / size;
	cout << "The average amount of pages is: " << result << endl << endl;
	delete[]info;

	return result;
}

void Library::getSurname(string *person) {
	info = new Textbook[size];
	for (int i = 0; i < size; i++) {
		info[i].getInfo(person[i]);
	}
}

void Library::readFromFile(string *book) {
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

void Library::writeToFile() {
	ofstream fout;
	fout.open("Array.txt");
	for (int i = 0; i < size; i++) {
		fout << "Textbook number is: " << info[i].getNum() << endl;
		fout << "The number of pages in textbook is: " << info[i].getPages() << endl;
		fout << "The grade this textbook for is: " << info[i].getGrade() << endl;
		fout << "The cost of this textbook is: " << info[i].getCost() << endl;
		fout << "The year of release of this textbook is: " << info[i].getYearOfRelease() << endl;
		fout << "The author of this textbook is: " << info[i].getAuthor() << endl << endl;
	}
	fout.close();
}