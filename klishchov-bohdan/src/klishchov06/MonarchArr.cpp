#include "MonarchArr.h"

int MonarchArr::getSize() {
	return size;
}

void MonarchArr::sortArea(bool(*comp)(int x, int y)) {
	Monarch temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (comp(arr[i].getArea(), arr[j].getArea())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void MonarchArr::newArray(std::string name, std::string type) {
	size++;
	arr = new Monarch[size];
	arr[0].setInfo(name);
	arr[0].setKind(type);
}

void MonarchArr::print() {
	std::ofstream fout("result.txt");
	for (int i = 0; i < size; i++) {
		fout << "The name of Monarch: " << arr[i].getName() << std::endl;
		fout << "Type of monarch: " << arr[i].getKind() << std::endl;
		fout << "Population: " << arr[i].getPopulation() << std::endl;
		fout << "Area: " << arr[i].getArea() << std::endl;
		fout << "Revenue: " << arr[i].getRevenue() << std::endl << std::endl;
	}
	fout.close();
	for (int i = 0; i < size; i++) {
		std::cout << "The name of Monarch: " << arr[i].getName() << std::endl;
		std::cout << "Type of monarch: " << arr[i].getKind() << std::endl;
		std::cout << "Population: " << arr[i].getPopulation() << std::endl;
		std::cout << "Area: " << arr[i].getArea() << std::endl;
		std::cout << "Revenue: " << arr[i].getRevenue() << std::endl << std::endl;
	}
}
void MonarchArr::addEl(int population, int area, int revenue, std::string name, std::string type) {
	Monarch *temp = new Monarch[size + 1];

	for (int i = 0; i < size; i++) {
		temp[i] = MonarchArr::arr[i];
	}

	size++;

	temp[size - 1].setData(population, area, revenue, name);
	temp[size - 1].setKind(type);

	delete[] arr;
	arr = temp;
}
void MonarchArr::deleteEl(int index) {
	size--;
	Monarch* temp = new Monarch[size];
	int j = 0;
	for (int i = 0; j < size - 1; i++)
	{
		temp[i] = MonarchArr::arr[j];
		j++;
	}
	j++;

	for (int i = index - 1; i < size; i++)
	{
		temp[i] = MonarchArr::arr[i];
		j++;
	}
	delete[] arr;
	arr = temp;
}

void MonarchArr::getByIndex(int index) {
	std::ofstream fout("resultID.txt");
	fout << "The name of Monarch: " << arr[index - 1].getName() << std::endl;
	fout << "Type of monarch: " << arr[index - 1].getKind() << std::endl;
	fout << "Population: " << arr[index - 1].getPopulation() << std::endl;
	fout << "Area: " << arr[index - 1].getArea() << std::endl;
	fout << "Revenue: " << arr[index - 1].getRevenue() << std::endl << std::endl;
	fout.close();
	std::cout << "The name of Monarch: " << arr[index - 1].getName() << std::endl;
	std::cout << "Type of monarch: " << arr[index - 1].getKind() << std::endl;
	std::cout << "Population: " << arr[index - 1].getPopulation() << std::endl;
	std::cout << "Area: " << arr[index - 1].getArea() << std::endl;
	std::cout << "Revenue: " << arr[index - 1].getRevenue() << std::endl << std::endl;
}

void MonarchArr::deleteArray() {
	delete[] arr;
}

Monarch MonarchArr::maxPop() {
	int max = arr[0].getPopulation();
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (max < arr[i].getPopulation()) {
			max = arr[i].getPopulation();
			index = i;
		}
	}
	return arr[index];
}

void MonarchArr::printMax(Monarch min) {
	std::ofstream fout("resultMax.txt");
	fout << "The name of Monarch: " << min.getName() << std::endl;
	fout << "Type of monarch: " << min.getKind() << std::endl;
	fout << "Population: " << min.getPopulation() << std::endl;
	fout << "Area: " << min.getArea() << std::endl;
	fout << "Revenue: " << min.getRevenue() << std::endl << std::endl;
	fout.close();
	std::cout << "The name of Monarch: " << min.getName() << std::endl;
	std::cout << "Type of monarch: " << min.getKind() << std::endl;
	std::cout << "Population: " << min.getPopulation() << std::endl;
	std::cout << "Area: " << min.getArea() << std::endl;
	std::cout << "Revenue: " << min.getRevenue() << std::endl << std::endl;
}