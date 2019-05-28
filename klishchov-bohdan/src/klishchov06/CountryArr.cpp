#include"CountryArr.h"

int CountryArr::getSize() {
	return size;
}

void CountryArr::sortArea(bool(*comp)(int x, int y)) {
	Country temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (comp(countries[i].getArea(), countries[j].getArea())) {
				temp = countries[i];
				countries[i] = countries[j];
				countries[j] = temp;
			}
		}
	}
}

void CountryArr::newArray(std::string name) {
	size++;
	countries = new Country[size];
	countries[0].setInfo(name);
}

void CountryArr::print() {
	std::ofstream fout("result.txt");
	for (int i = 0; i < size; i++) {
		fout << "The name of country: " << countries[i].getName() << std::endl;
		fout << "Population: " << countries[i].getPopulation() << std::endl;
		fout << "Area: " << countries[i].getArea() << std::endl;
		fout << "Revenue: " << countries[i].getRevenue() << std::endl << std::endl;
	}
	fout.close();
	for (int i = 0; i < size; i++) {
		std::cout << "The name of country: " << countries[i].getName() << std::endl;
		std::cout << "Population: " << countries[i].getPopulation() << std::endl;
		std::cout << "Area: " << countries[i].getArea() << std::endl;
		std::cout << "Revenue: " << countries[i].getRevenue() << std::endl << std::endl;
	}
}
void CountryArr::addEl(int population, int area, int revenue, std::string name) {
	Country *temp = new Country[size + 1];

	for (int i = 0; i < size; i++) {
		temp[i] = CountryArr::countries[i];
	}

	size++;

	temp[size - 1].setData(population, area, revenue, name);

	delete[] countries;
	countries = temp;
}
void CountryArr::deleteEl(int index) {
	size--;
	Country* temp = new Country[size];
	int j = 0;
	for (int i = 0; j < size - 1; i++)
	{
		temp[i] = CountryArr::countries[j];
		j++;
	}
	j++;

	for (int i = index - 1; i < size; i++)
	{
		temp[i] = CountryArr::countries[i];
		j++;
	}
	delete[] countries;
	countries = temp;
}

void CountryArr::getByIndex(int index) {
	std::ofstream fout("resultID.txt");
	fout << "The name of country: " << countries[index - 1].getName() << std::endl;
	fout << "Population: " << countries[index - 1].getPopulation() << std::endl;
	fout << "Area: " << countries[index - 1].getArea() << std::endl;
	fout << "Revenue: " << countries[index - 1].getRevenue() << std::endl << std::endl;
	fout.close();
	std::cout << "The name of country: " << countries[index - 1].getName() << std::endl;
	std::cout << "Population: " << countries[index - 1].getPopulation() << std::endl;
	std::cout << "Area: " << countries[index - 1].getArea() << std::endl;
	std::cout << "Revenue: " << countries[index - 1].getRevenue() << std::endl << std::endl;
}

void CountryArr::deleteArray() {
	delete[] countries;
}

Country CountryArr::maxPop() {
	int max = countries[0].getPopulation();
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (max < countries[i].getPopulation()) {
			max = countries[i].getPopulation();
			index = i;
		}
	}
	return countries[index];
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