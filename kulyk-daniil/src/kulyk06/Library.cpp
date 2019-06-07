#include"Library.h"

void Library::sortByCost(bool(*bubble)(int x, int y)) {
	Textbook tmp;
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

int Library::getSize() {
	return size;
}

void Library::getSurname(string surname) {
	size++;
	backlist = new Textbook[size];
	backlist[0].getInfo(surname);
}

void Library::printAll() {
	std::ofstream fout("Array.txt");
	for (int i = 0; i < size; i++) {
		fout << "Textbook number: " << backlist[i].getNum() << endl;
		fout << "Textbook's number of pages: " << backlist[i].getPages() << endl;
		fout << "Textbook's grade: " << backlist[i].getGrade() << endl;
		fout << "Textbook's cost: " << backlist[i].getCost() << endl;
		fout << "Textbook's year of release: " << backlist[i].getYearOfRelease() << endl;
		fout << "The author of the textbook: " << backlist[i].getAuthor() << endl;
	}
	fout.close();
	for (int i = 0; i < size; i++) {
		cout << "Textbook number: " << backlist[i].getNum() << endl;
		cout << "Textbook's number of pages: " << backlist[i].getPages() << endl;
		cout << "Textbook's grade: " << backlist[i].getGrade() << endl;
		cout << "Textbook's cost: " << backlist[i].getCost() << endl;
		cout << "Textbook's year of release: " << backlist[i].getYearOfRelease() << endl;
		cout << "The author of the textbook: " << backlist[i].getAuthor() << endl << endl;
	}
}

void Library::addTextbook(int num, int pages, int grade, int cost, int year_of_release, string author) {
	Textbook* tmp_backlist = new Textbook[size + 1];

	for (int i = 0; i < size; i++) {
		tmp_backlist[i] = Library::backlist[i];
	}

	size++;

	tmp_backlist[size - 1].setInfo(num, pages, grade, cost, year_of_release, author);

	delete[] backlist;
	backlist = tmp_backlist;
}
void Library::removeTextbook(int num) {
	size--;
	Textbook* tmp_backlist = new Textbook[size];
	int j = 0;
	for (int i = 0; j < size - 1; i++)
	{
		tmp_backlist[i] = Library::backlist[j];
		j++;
	}
	j++;

	for (int i = num - 1; i < size; i++)
	{
		tmp_backlist[i] = Library::backlist[i];
		j++;
	}
	delete[] backlist;
	backlist = tmp_backlist;
}

void Library::getRequiredTextbook(int num) {
	std::ofstream fout("resultID.txt");
	fout << "Textbook number: " << backlist[num - 1].getNum() << endl;
	fout << "Textbook's number of pages: " << backlist[num - 1].getPages() << endl;
	fout << "Textbook's grade: " << backlist[num - 1].getGrade() << endl;
	fout << "Textbook's cost: " << backlist[num - 1].getCost() << endl;
	fout << "Textbook's year of release: " << backlist[num - 1].getYearOfRelease() << endl;
	fout << "The author of the textbook: " << backlist[num - 1].getAuthor() << endl;
	fout.close();
	cout << "Textbook number: " << backlist[num - 1].getNum() << endl;
	cout << "Textbook's number of pages: " << backlist[num - 1].getPages() << endl;
	cout << "Textbook's grade: " << backlist[num - 1].getGrade() << endl;
	cout << "Textbook's cost: " << backlist[num - 1].getCost() << endl;
	cout << "Textbook's year of release: " << backlist[num - 1].getYearOfRelease() << endl;
	cout << "The author of the textbook: " << backlist[num - 1].getAuthor() << endl;
}

void Library::deleteBacklist() {
	delete[] backlist;
}

float Library::averageAmountOfPages(int num) {
	float result = 0;
	for (int i = 0; i < size; i++) {
		result += backlist[i].getPages();
	}
	result = result / size;
	cout << "The average amount of pages is: " << result << endl << endl;
	delete[]backlist;

	return result;
}