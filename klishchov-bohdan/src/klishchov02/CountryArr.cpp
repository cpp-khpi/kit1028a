#include"CountryArr.h"
CountryArr::CountryArr() {
	count = 0;

}

void CountryArr::CountryAdd(Country countr) {
	if (count == 0) {
		country = new Country;
		country[count] = countr;
		count++;
	}
	else {
		count++;
		int j = 0;
		Country *tmp = (Country*)operator new (sizeof(Country)*count);
		for (int i = 0; i < count; i++) {
			new(&tmp[i])Country();
		}
		for (int i = 0; i < count; i++) {
			tmp[i] = country[j];
			j++;
		}
		tmp[count] = countr;
		for (int i = count + 1; i < count; i++) {
			tmp[j] = country[i];
		}

		delete[] country;
		country = tmp;
	}
}

void CountryArr::CountryPrint() const {
	for (int i = 0; i < count; i++)
		CList(i).CountryPrint();
}

void CountryArr::CountryRemove(int id) {

	count--;
	Country *deltmp = (Country*)operator new(sizeof(Country)*count);
	int j = 0;
	for (int i = 0; i < count; i++) {
		if (i == id) {
			j++;
		}
		deltmp[i] = country[j];
		j++;
	}

	delete[] country;
	country = deltmp;
}

Country & CountryArr::CList(int id) const {
	return country[id];

}

Country & CountryArr::Min() {
	int min = country[0].getPopul;
	int index = 0;
	for (int i = 0; i < count; i++) {
		if (min < country[i].getPopul) {
			min = country[i].getPopul;
			index = i;
		}
	}
	return country[index];
}