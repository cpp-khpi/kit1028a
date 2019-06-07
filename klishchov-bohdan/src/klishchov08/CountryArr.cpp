#include"CountryArr.h"


void CountryArr::sortArea(bool(*comp)(int x, int y)) {
	Island temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (comp(island[i].getArea(), island[j].getArea())) {
				temp = island[i];
				island[i] = island[j];
				island[j] = temp;
			}
		}
	}
}

void CountryArr::newArray(std::string name) {
	size++;
	island = new Island[size];
	island[0].getInfo(name);
}

void CountryArr::print() {
	std::ofstream fout("result.txt");
	for (int i = 0; i < size; i++) {
		fout << "The name of country: " << island[i].getName() << std::endl;
		fout << "Population: " << island[i].getPopulation() << std::endl;
		fout << "Area: " << island[i].getArea() << std::endl;
		fout << "Revenue: " << island[i].getRevenue() << std::endl << std::endl;
	}
	fout.close();
	for (int i = 0; i < size; i++) {
		std::cout << "The name of country: " << island[i].getName() << std::endl;
		std::cout << "Population: " << island[i].getPopulation() << std::endl;
		std::cout << "Area: " << island[i].getArea() << std::endl;
		std::cout << "Revenue: " << island[i].getRevenue() << std::endl;
		info.Info(&island[i]);
		cout << std::endl << std::endl;
	}
}
void CountryArr::addEl(int population, int area, int revenue, string name) {
	Island *temp = new Island[size + 1];

	for (int i = 0; i < size; i++) {
		temp[i] = island[i];
	}

	size++;

	temp[size - 1].setData(population, area, revenue, name);

	delete[] island;
	island = temp;
}
void CountryArr::deleteEl(int index) {
	size--;
	Island* temp = new Island[size];
	int j = 0;
	for (int i = 0; j < size - 1; i++)
	{
		temp[i] = CountryArr::island[j];
		j++;
	}
	j++;

	for (int i = index - 1; i < size; i++)
	{
		temp[i] = CountryArr::island[i];
		j++;
	}
	delete[] island;
	island = temp;
}

void CountryArr::getByIndex(int index) {
	std::ofstream fout("resultID.txt");
	fout << "The name of country: " << island[index - 1].getName() << std::endl;
	fout << "Population: " << island[index - 1].getPopulation() << std::endl;
	fout << "Area: " << island[index - 1].getArea() << std::endl;
	fout << "Revenue: " << island[index - 1].getRevenue() << std::endl << std::endl;
	fout.close();
	std::cout << "The name of country: " << island[index - 1].getName() << std::endl;
	std::cout << "Population: " << island[index - 1].getPopulation() << std::endl;
	std::cout << "Area: " << island[index - 1].getArea() << std::endl;
	std::cout << "Revenue: " << island[index - 1].getRevenue() << std::endl;
	info.Info(&island[index]);
	cout << std::endl << std::endl;
}

void CountryArr::deleteArray() {
	delete[] island;
}

Island CountryArr::maxPop() {
	int max = island[0].getPopulation();
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (max < island[i].getPopulation()) {
			max = island[i].getPopulation();
			index = i;
		}
	}
	return island[index];
}

void CountryArr::printMax(Island min) {
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

std::ostream& operator<< (std::ostream &out, const CountryArr &obj) {
	out << obj.size << std::endl;
	for (int i = 0; i < obj.size; i++) {
		out << obj.island[i];
	}
	return out;
}
std::istream& operator>> (std::istream &in, CountryArr &obj) {
	in >> obj.size;
	for (int i = 0; i < obj.size; i++) {
		in >> obj.island[i];
	}
	return in;
}
Country& CountryArr::operator[] (const int index) {
	return island[index];
}