#include"CountryArr.h"
void CountryArr::getSize(int size) {
	CountryArr::size = size;
}
void CountryArr::newArray(std::string name) {
	arr = new Country[size];
	for (int i = 0; i < size; i++) {
		arr[i].setInfo(name);
	}
}
void CountryArr::print() {
	std::ofstream fout("result.txt");
	for (int i = 0; i < size; i++) {
		int population = arr[i].getPopulation();
		int area = arr[i].getArea();
		int revenue = arr[i].getRevenue();
		std::string name = arr[i].getName();

		fout << "The name of country: " << name << std::endl;
		fout << "Population: " << population << std::endl;
		fout << "Area: " << area << std::endl;
		fout << "Revenue: " << revenue << std::endl << std::endl;
	}
	fout.close();
}
void CountryArr::addElem(int population, int area, int revenue, std::string name) {

	Country *temp = new Country[size];

	for (int i = 0; i < size; i++) {
		temp[i] = CountryArr::arr[i];
	}

	delete[] arr;

	CountryArr::arr = new Country[size + 1];

	for (int i = 0; i < size; i++) {
		CountryArr::arr[i] = temp[i];
	}

	delete[] temp;

	CountryArr::arr[size].setData(population, area, revenue, name);

	size++;
}
void CountryArr::deleteElem(int index) {
	Country* temp = new Country[size - 1];
	
	for (int i = 0, j = 0; j < size; i++, j++)
	{
		if (j == index)
		{
			j++;
		}
		temp[i] = CountryArr::arr[j];
	}

	delete[] CountryArr::arr;

	CountryArr::arr = new Country[size - 1];

	for (int i = 0; i < size - 1; i++)
	{
		CountryArr::arr[i] = temp[i];
	}

	delete[] temp;

	size--;
}
void CountryArr::getByIndex(int index) {
	std::ofstream fout("resultID.txt");
	if (index >= size) {
		std::cout << std::endl << "Error" << std::endl << std::endl;
		return;
	}

	int population = arr[index].getPopulation();
	int area = arr[index].getArea();
	int revenue = arr[index].getRevenue();
	std::string name = arr[index].getName();

	fout << std::endl;
	fout << std::endl;
	fout << "The name of country: " << name << std::endl;
	fout << "Population: " << population << std::endl;
	fout << "Area: " << area << std::endl;
	fout << "Revenue: " << revenue << std::endl << std::endl;
	fout.close();
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

void CountryArr::printMax(Country min) {
	std::ofstream fout("resultMax.txt");
	int population = min.getPopulation();
	int area = min.getArea();
	int revenue = min.getRevenue();
	std::string name = min.getName();

	fout << "The name of country: " << name << std::endl;
	fout << "Population: " << population << std::endl;
	fout << "Area: " << area << std::endl;
	fout << "Revenue: " << revenue << std::endl << std::endl;
	fout.close();
}
