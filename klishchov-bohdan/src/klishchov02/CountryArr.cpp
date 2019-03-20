#include"CountryArr.h"
void CountryArr::getSize(int size) {
	CountryArr::size = size;
}
void CountryArr::newArray(char **name) {
	arr = new Country[size];
	for (int i = 0; i < size; i++) {
		arr[i].setInfo((*(name + i)));
	}
}
void CountryArr::print() {
	for (int i = 0; i < size; i++) {
		int population = arr[i].getPopulation();
		int area = arr[i].getArea();
		int revenue = arr[i].getRevenue();
		char *name = arr[i].getName();

		std::cout << "The name of country: " << name << std::endl;
		std::cout << "Population: " << population << std::endl;
		std::cout << "Area: " << area << std::endl;
		std::cout << "Revenue: " << revenue << std::endl << std::endl;
	}
}
void CountryArr::addElem(int population, int area, int revenue, char *name) {

	Country *mas = new Country[size + 1];

	for (int i = 0; i < size; i++) {
		mas[i] = CountryArr::arr[i];
	}

	size++;

	mas[size - 1].setData(population, area, revenue, name);

	arr = mas;
}
void CountryArr::deleteElem(int l) {
	Country* mas = new Country[size];

	int j = 0;
	for (int i = 0; i < l - 1; i++) {
		mas[i] = CountryArr::arr[j];
		j++;
	}
	j++;
	for (int i = l - 1; i < size; i++) {
		mas[i] = CountryArr::arr[j];
		j++;
	}
	size--;

	arr = mas;
}
void CountryArr::getByIndex(int index) {
	if (index - 1 >= size) {
		std::cout << std::endl << "Error" << std::endl << std::endl;
		return;
	}

	int population = arr[index - 1].getPopulation();
	int area = arr[index - 1].getArea();
	int revenue = arr[index - 1].getRevenue();
	char *name = arr[index - 1].getName();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "The name of country: " << name << std::endl;
	std::cout << "Population: " << population << std::endl;
	std::cout << "Area: " << area << std::endl;
	std::cout << "Revenue: " << revenue << std::endl << std::endl;
}
void CountryArr::deleteArray() {
	delete[] CountryArr::arr;
}

Country CountryArr::maxPop() {
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

void CountryArr::printMax(Country min) { {
		int population = min.getPopulation();
		int area = min.getArea();
		int revenue = min.getRevenue();
		char *name = min.getName();

		std::cout << "The name of country: " << name << std::endl;
		std::cout << "Population: " << population << std::endl;
		std::cout << "Area: " << area << std::endl;
		std::cout << "Revenue: " << revenue << std::endl << std::endl;
	}
}