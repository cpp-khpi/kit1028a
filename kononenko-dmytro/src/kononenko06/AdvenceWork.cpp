#include "DetailInfo.h"
#include "InfoWork.h"
#include "AdvenceWork.h"

void AdvenceWork::del(int x) {
	int j = 0;

	Size--;
	DetailInfo* arr = new DetailInfo[Size];
	for (int i = 0; i < x; i++) {
		arr[i] = this->works[j];
		j++;
	}
	j++;
	for (int i = x; i < Size; i++) {
		arr[i] = this->works[j];
		j++;
	}
	delete[] works;
	works = arr;
}

void AdvenceWork::add(DetailInfo obj,int n) {
	int i;
	int j = 0;

	Size++;
	DetailInfo* arr = new DetailInfo[Size];
	for (i = 0; i < n; i++) {
		arr[i] = this->works[j];
		j++;
	}

	arr[n] = obj;

	for (i = n + 1; i < Size; i++) {
		arr[i] = this->works[j];
		j++;
	}
	delete[] works;
	works = arr;
}

void AdvenceWork::search(int index) {
	cout << "Name: " << works[index].getName();
	cout << "Mark= " << works[index].getMark();
	cout << " Size= " << works[index].getPages();
	if (works[index].getType() == 1) {
		cout << " BACALAVR" ;
	}
	else {
		cout << " MAGISTR";
	}
	cout << " Novelty= " << works[index].getNovelty();
	cout << " Size of Labor" << works[index].getSizeLabor()<<endl;
}

void AdvenceWork::printArr() {
	for (int i = 0; i < Size; i++) {
		cout << "Name: " << works[i].getName();
		cout << " Mark: " << works[i].getMark();
		cout << " Size: " << works[i].getPages();
		if (works[i].getType() == 1) {
			cout << " BACALAVR";
		}
		else {
			cout << " MAGISTR";
		}
		cout << " Novelty: " << works[i].getNovelty();
		cout << " Size of Labor:" << works[i].getSizeLabor() << endl;
	}
}

void AdvenceWork::delArr() {
	if (works) delete[] works;
}

void AdvenceWork::setSize(int x) {
	Size = x;
}

void AdvenceWork::createArr(string* name) {
	works = new DetailInfo[Size];
	for (int i = 0; i < Size; i++) {
		works[i].set(name[i]);
	}
}