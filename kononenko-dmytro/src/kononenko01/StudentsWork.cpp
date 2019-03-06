#include "StudentsWork.h"
#include "InfoWork.h"

void StudentsWork::search(int index) {
	if (index >= size) {
		cout << "imposible to find\n";
		return;
	}

	cout << "Name: " << qual[index].getName();
	cout << "Mark= " << qual[index].getMark();
	cout << " Size= " << qual[index].getPages();
	if (qual[index].getType() == 1) {
		cout << " BACALAVR" << endl;
	}
	else {
		cout << " MAGISTR" << endl;
	}
}
void StudentsWork::createArr(char **name) {
	qual = new InfoWork[size];
	for (int i = 0; i < size; i++) {
		qual[i].set((*(name + i)));
	}
}
InfoWork* StudentsWork::add(int n, int mark, int pages, int type, char * name) {

	if (n >= size) {
		cout << "Error: invalid index" << endl;
		return qual;
	}
	int i;
	int j = 0;
	 
	size++;
	InfoWork* arr = new InfoWork[size];
	for (i = 0; i < n; i++) {
		arr[i] = this->qual[j];
		j++;
	}

	arr[n].set_n(mark, pages, type, name);

	for (i = n + 1; i < size; i++) {
		arr[i] = this->qual[j];
		j++;
	}
	delete[] qual;
	qual = arr;
}
void StudentsWork::del(int n) {
	if (n >= size) {
		cout << "Error: invalid index" << endl;
		return;
	}
	if (size < 2) {
		cout << "Error: you can not delete last element" << endl;
		return;
	}
	int j = 0;

	size--;
	InfoWork* arr = new InfoWork[size + 1];
	for (int i = 0; i < n; i++) {
		arr[i] = this->qual[j];
		j++;
	}
	j++;
	for (int i = n; i < size; i++) {
		arr[i] = this->qual[j];
		j++;
	}
	
}
void StudentsWork::testDel()
{
	int n = 2;

	InfoWork tester;
	tester = qual[n];

	size--;

	InfoWork* arr = new InfoWork[size + 1];

	for (int i = 0; i < size + 1; i++)
		arr[i] = this->qual[i];

	delete[] qual;
	qual = new InfoWork[size];

	for (int i = 0, j = 0; i < size; i++) {
		if (i == n) {
			j++;
		}
		this->qual[i] = arr[j];
		j++;

	}
	delete[] arr;
	if (qual[n].getMark() == tester.getMark() && qual[n].getPages() == tester.getPages() && qual[n].getType() == tester.getType()) {
		cout << "Your programm is not bad" << endl;
	}
	else {
		cout << "your luck of skills" << endl;
	}
}
void StudentsWork::testAdd()
{
	int n = 2;
	char name[] = { "Kononenko" };
	int a = 4;
	int b = 377;
	int c = 2;
	InfoWork tester;
	tester.set_n(a, b, c, name);

	InfoWork* arr = new InfoWork[size];

	for (int i = 0; i < size; i++)
		arr[i] = this->qual[i];

	delete[] qual;
	size++;
	qual = new InfoWork[size];

	for (int i = 0, j = 0; i < size; i++) {
		if (i == n) {
			this->qual[i].set_n(a, b, c, name);
			i++;
		}
		this->qual[i] = arr[j];
		j++;
	}

	delete[] arr;

	if (qual[n].getMark() == tester.getMark() && qual[n].getPages() == tester.getPages() && qual[n].getType() == tester.getType()) {
		cout << "working" << endl;
	}
	else {
		cout << "Your programm is not working well" << endl;
	}
}
void StudentsWork::delArr() {
	delete[size] qual;
}
void StudentsWork::printArr() {
	for (int i = 0; i < size; i++) {
		cout << "Name: " << qual[i].getName();;
		cout << " Mark= " << qual[i].getMark();
		cout << " Size= " << qual[i].getPages();
		if (qual[i].getType() == 1) {
			cout << " BACALAVR" << endl;
		}
		else {
			cout << " MAGISTR" << endl;
		}
	}
}
void StudentsWork::rate() { //найти процент магистров
	float counter = 0;
	for (int i = 0; i < size; i++) {
		int type = qual[i].getType();
		if (type == 2) {
			counter++;
		}
	}
	counter = counter * 100 / this->size;
	cout << "There your persent: ";
	cout << counter;
}
void StudentsWork::setSize(int size) {
	this->size = size;
}