#include"CountryArr.h"

void CountryArr::newArray(std::string name) {
	size++;
	arr = new Country[size];
	arr[0].getInfo(name);
}

void CountryArr::print() {
	std::ofstream fout("result.txt");
	for (int i = 0; i < size; i++) {
		fout << "The name of country: " << arr[i].getName() << std::endl;
		fout << "Population: " << arr[i].getPopulation() << std::endl;
		fout << "Area: " << arr[i].getArea() << std::endl;
		fout << "Revenue: " << arr[i].getRevenue() << std::endl << std::endl;
	}
	fout.close();
	for (int i = 0; i < size; i++) {
		std::cout << "The name of country: " << arr[i].getName() << std::endl;
		std::cout << "Population: " << arr[i].getPopulation() << std::endl;
		std::cout << "Area: " << arr[i].getArea() << std::endl;
		std::cout << "Revenue: " << arr[i].getRevenue() << std::endl << std::endl;
	}
}
void CountryArr::addEl(int population, int area, int revenue, std::string name) {
	Country *temp = new Country[size + 1];

	for (int i = 0; i < size; i++) {
		temp[i] = CountryArr::arr[i];
	}

	size++;

	temp[size - 1].setData(population, area, revenue, name);

	delete[] arr;
	arr = temp;
}
void CountryArr::deleteEl(int index) {
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
}

void CountryArr::getByIndex(int index) {
	std::ofstream fout("resultID.txt");
	fout << "The name of country: " << arr[index - 1].getName() << std::endl;
	fout << "Population: " << arr[index - 1].getPopulation() << std::endl;
	fout << "Area: " << arr[index - 1].getArea() << std::endl;
	fout << "Revenue: " << arr[index - 1].getRevenue() << std::endl << std::endl;
	fout.close();
	std::cout << "The name of country: " << arr[index - 1].getName() << std::endl;
	std::cout << "Population: " << arr[index - 1].getPopulation() << std::endl;
	std::cout << "Area: " << arr[index - 1].getArea() << std::endl;
	std::cout << "Revenue: " << arr[index - 1].getRevenue() << std::endl << std::endl;
}

void CountryArr::deleteArray() {
	delete[] arr;
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
	fout << "The name of country: " << min.getName() << std::endl;
	fout << "Population: " << min.getPopulation() << std::endl;
	fout << "Area: " << min.getArea() << std::endl;
	fout << "Revenue: " << min.getRevenue() << std::endl << std::endl;
	fout.close();
	std::cout << "The name of country: " << min.getName() << std::endl;
	std::cout << "Population: " << min.getPopulation() << std::endl;
	std::cout << "Area: " << min.getArea() << std::endl;
	std::cout << "Revenue: " << min.getRevenue() << std::endl << std::endl;
}