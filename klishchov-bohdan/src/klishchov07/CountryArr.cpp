#include"CountryArr.h"


void CountryArr::sortArea(bool(*comp)(int x, int y)) {
	Republic temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (comp(republic[i].getArea(), republic[j].getArea())) {
				temp = republic[i];
				republic[i] = republic[j];
				republic[j] = temp;
			}
		}
	}
}

void CountryArr::newArray(string name, string pres) {
	size++;
	republic = new Republic[size];
	republic[0].getInfo(name);
	republic[0].setPresident(pres);
}

void CountryArr::print() {
	std::ofstream fout("result.txt");
	for (int i = 0; i < size; i++) {
		fout << "The name of country: " << republic[i].getName() << std::endl;
		fout << "Population: " << republic[i].getPopulation() << std::endl;
		fout << "Area: " << republic[i].getArea() << std::endl;
		fout << "Revenue: " << republic[i].getRevenue() << std::endl << std::endl;
	}
	fout.close();
	for (int i = 0; i < size; i++) {
		std::cout << "The name of country: " << republic[i].getName() << std::endl;
		std::cout << "Population: " << republic[i].getPopulation() << std::endl;
		std::cout << "Area: " << republic[i].getArea() << std::endl;
		std::cout << "Revenue: " << republic[i].getRevenue() << std::endl;
		info.Info(&republic[i]);
		cout << std::endl << std::endl;
	}
}
void CountryArr::addEl(int population, int area, int revenue, string name, string pres) {
	Republic *temp = new Republic[size + 1];

	for (int i = 0; i < size; i++) {
		temp[i] = CountryArr::republic[i];
	}

	size++;

	temp[size - 1].setData(population, area, revenue, name);
	temp[size - 1].setPresident(pres);

	delete[] republic;
	republic = temp;
}
void CountryArr::deleteEl(int index) {
	size--;
	Republic* temp = new Republic[size];
	int j = 0;
	for (int i = 0; j < size - 1; i++)
	{
		temp[i] = CountryArr::republic[j];
		j++;
	}
	j++;

	for (int i = index - 1; i < size; i++)
	{
		temp[i] = CountryArr::republic[i];
		j++;
	}
	delete[] republic;
	republic = temp;
}

void CountryArr::getByIndex(int index) {
	std::ofstream fout("resultID.txt");
	fout << "The name of country: " << republic[index - 1].getName() << std::endl;
	fout << "Population: " << republic[index - 1].getPopulation() << std::endl;
	fout << "Area: " << republic[index - 1].getArea() << std::endl;
	fout << "Revenue: " << republic[index - 1].getRevenue() << std::endl << std::endl;
	fout.close();
	std::cout << "The name of country: " << republic[index - 1].getName() << std::endl;
	std::cout << "Population: " << republic[index - 1].getPopulation() << std::endl;
	std::cout << "Area: " << republic[index - 1].getArea() << std::endl;
	std::cout << "Revenue: " << republic[index - 1].getRevenue() << std::endl;
	info.Info(&republic[index]);
	cout << std::endl << std::endl;
}

void CountryArr::deleteArray() {
	delete[] republic;
}

Republic CountryArr::maxPop() {
	int max = republic[0].getPopulation();
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (max < republic[i].getPopulation()) {
			max = republic[i].getPopulation();
			index = i;
		}
	}
	return republic[index];
}

void CountryArr::printMax(Republic min) {
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
	info.Info(&min);
}