#include"ElectronicLibrary.h"

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

int ElectronicLibrary::getSize() {
	return size;
}

void ElectronicLibrary::getSurname(string surname, string exile) {
	size++;
	backlist = new ElectronicTextbook[size];
	backlist[0].getInfo(surname);
	backlist[0].getInfo(exile);
}

void ElectronicLibrary::printAll() {
	std::ofstream fout("Array.txt");
	for (int i = 0; i < size; i++) {
		fout << "Textbook number: " << backlist[i].getNum() << endl;
		fout << "Textbook's number of pages: " << backlist[i].getPages() << endl;
		fout << "Textbook's grade: " << backlist[i].getGrade() << endl;
		fout << "Textbook's cost: " << backlist[i].getCost() << endl;
		fout << "Textbook's year of release: " << backlist[i].getYearOfRelease() << endl;
		fout << "The author of the textbook: " << backlist[i].getAuthor() << endl;
		fout << "The link to the electronic textbook: " << backlist[i].getLink() << endl;
	}
	fout.close();
	for (int i = 0; i < size; i++) {
		cout << "Textbook number: " << backlist[i].getNum() << endl;
		cout << "Textbook's number of pages: " << backlist[i].getPages() << endl;
		cout << "Textbook's grade: " << backlist[i].getGrade() << endl;
		cout << "Textbook's cost: " << backlist[i].getCost() << endl;
		cout << "Textbook's year of release: " << backlist[i].getYearOfRelease() << endl;
		cout << "The author of the textbook: " << backlist[i].getAuthor() << endl << endl;
		cout << "The link to the electronic textbook: " << backlist[i].getLink() << endl;
	}
}

void ElectronicLibrary::addTextbook(int num, int pages, int grade, int cost, int year_of_release, string author, string exile) {
	ElectronicTextbook* tmp_backlist = new ElectronicTextbook[size + 1];

	for (int i = 0; i < size; i++) {
		tmp_backlist[i] = ElectronicLibrary::backlist[i];
	}

	size++;

	tmp_backlist[size - 1].setInfo(num, pages, grade, cost, year_of_release, author);
	tmp_backlist[size - 1].setLink(exile);

	delete[] backlist;
	backlist = tmp_backlist;
}
void ElectronicLibrary::removeTextbook(int num) {
	size--;
	ElectronicTextbook* tmp_backlist = new ElectronicTextbook[size];
	int j = 0;
	for (int i = 0; j < size - 1; i++)
	{
		tmp_backlist[i] = ElectronicLibrary::backlist[j];
		j++;
	}
	j++;

	for (int i = num - 1; i < size; i++)
	{
		tmp_backlist[i] = ElectronicLibrary::backlist[i];
		j++;
	}
	delete[] backlist;
	backlist = tmp_backlist;
}

void ElectronicLibrary::getRequiredTextbook(int num) {
	std::ofstream fout("resultID.txt");
	fout << "Textbook number: " << backlist[num - 1].getNum() << endl;
	fout << "Textbook's number of pages: " << backlist[num - 1].getPages() << endl;
	fout << "Textbook's grade: " << backlist[num - 1].getGrade() << endl;
	fout << "Textbook's cost: " << backlist[num - 1].getCost() << endl;
	fout << "Textbook's year of release: " << backlist[num - 1].getYearOfRelease() << endl;
	fout << "The author of the textbook: " << backlist[num - 1].getAuthor() << endl;
	fout << "The link to the electronic textbook: " << backlist[num - 1].getLink() << endl;
	fout.close();
	cout << "Textbook number: " << backlist[num - 1].getNum() << endl;
	cout << "Textbook's number of pages: " << backlist[num - 1].getPages() << endl;
	cout << "Textbook's grade: " << backlist[num - 1].getGrade() << endl;
	cout << "Textbook's cost: " << backlist[num - 1].getCost() << endl;
	cout << "Textbook's year of release: " << backlist[num - 1].getYearOfRelease() << endl;
	cout << "The author of the textbook: " << backlist[num - 1].getAuthor() << endl;
	cout << "The link to the electronic textbook: " << backlist[num ].getLink() << endl;
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