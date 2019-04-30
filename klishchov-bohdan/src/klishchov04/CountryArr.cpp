#include"CountryArr.h"
void CountryArr::setSize(int size) {
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
	size++;
	Country *temp = new Country[size];

	for (int i = 0; i < size - 1; i++) {
		temp[i] = CountryArr::arr[i];
	}
	temp[size].setData(population, area, revenue, name);
	delete[] arr;
	arr = temp;
	delete[]temp;
}
void CountryArr::deleteElem(int index) {
	size--;
	Country* temp = new Country[size];
	int j = 0;
	for (int i = 0; j < size - 1; i++)
	{
		temp[i] = CountryArr::arr[j];
		j++;
	}
	j++;

	for (int i = index - 1; i < size; i++)
	{
	temp[i] = CountryArr::arr[i];
	j++;
	}
	delete[] arr;
	arr = temp;
	delete[]temp;
}
void CountryArr::getByIndex(int index) {
	std::ofstream fout("resultID.txt");
	if (index >= size) {
		std::cout << std::endl << "Error" << std::endl << std::endl;
		return;
	}


	fout << std::endl;
	fout << std::endl;
	fout << "The name of country: " << arr[index - 1].getName() << std::endl;
	fout << "Population: " << arr[index - 1].getPopulation() << std::endl;
	fout << "Area: " << arr[index - 1].getArea() << std::endl;
	fout << "Revenue: " << arr[index - 1].getRevenue() << std::endl << std::endl;
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
