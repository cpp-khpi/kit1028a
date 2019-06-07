#include"Library.h"
#include "Grammarway.h"

Library::Library() : size(0) {
	info = nullptr;
}

Library::~Library() {
	for (int i = 0; i < size; i++) {
		delete info[i];
	}
	delete[] info;
}

void Library::sortByDifficulty(bool(*bubble)(int x, int y)) {
	Textbook *tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (bubble(info[i]->getCost(), info[j]->getCost())) {
				tmp = info[i];
				info[i] = info[j];
				info[j] = tmp;
			}
		}
	}
}

void Library::printAll(int size) {
	for (int i = 0; i < size; i++) {
		info[i]->output();
	}
}

void Library::setSize(int size) {
	Library::size = size;
}

void Library::addTextbook(Textbook* new_textbook) {
	Textbook **tmp_textbook = new Textbook*[size + 1];

	for (int i = 0; i < size; i++) {
		tmp_textbook[i] = info[i];
	}

	size++;

	tmp_textbook[size - 1] = new_textbook;

	delete[] tmp_textbook;
	tmp_textbook = info;
}
void Library::removeTextbook(int num) {
	size--;
	Textbook** tmp_textbook = new Textbook*[size];

	int j = 0;
	for (int i = 0; i < size - 1; i++) {
		tmp_textbook[i] = info[j];
		j++;
	}
	j++;
	for (int i = size - 1; i < size; i++) {
		tmp_textbook[i] = info[j];
		j++;
	}
	delete info[size - 1];
	delete[]info;
	tmp_textbook = info;
}

void Library::getRequiredTextbook(int index) {
	if (index - 1 >= size) {
		cout << std::endl << "Error" << endl << endl;
		return;
	}
	cout << std::endl;
	info[index - 1]->output();
	cout << endl;
}

void Library::deleteBacklist() {
	delete[] info;
}

float Library::averageAmountOfPages(int num) {
	float result = 0;
	for (int i = 0; i < size; i++) {
		result += info[i]->getPages();
	}
	result = result / size;
	cout << "The average amount of pages is: " << result << endl << endl;
	delete[]info;

	return result;
}

void Library::readFromFile(int new_size) {
	string *author = new string[new_size];
	regex regex_upperRegister("^[A-Z]");
	regex regex_space("[\\s]{2,}");
	ifstream fin;
	fin.open("AuthorsNames.txt");
	Textbook* new_textbook;;
	for (int i = 0; i < new_size; i++) {
		getline(fin, author[i]);
		if (!(regex_search(author[i], regex_upperRegister)) || regex_search(author[i], regex_space)) {
			cout << "You've entered wrong surname: " << author[i] << endl;
			cin.ignore();
			getline(cin, author[i]);
		}
		new_textbook = new Grammarway;
		new_textbook->getInfo(author[i]);
		addTextbook(new_textbook);
		break;
	}

	delete[] author;
	fin.close();
}

void Library::writeToFile() {
	ofstream fout;
	fout.open("Array.txt");
	for (int i = 0; i < size; i++) {
		info[i]->output_to_file(fout);
	}
	fout.close();
}