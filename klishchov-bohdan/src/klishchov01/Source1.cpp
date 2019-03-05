#include"Header1.h"
CountryArr::CountryArr() {
	count = 0;

}

void CountryArr::CountryAdd(Country countr) {
	if (count == 0)
		country = (Country*)malloc(sizeof(Country) * 1);
	if (count > 0)
		country = (Country*)realloc(country, sizeof(Country)*(count + 1));
	country[count] = countr;
	count++;



}

void CountryArr::CountryPrint() const {
	for (int i = 0; i < count; i++)
		CList(i).CountryPrint();
}

void CountryArr::CountryRemove(int id) {

	for (int i = id; i < count; i++)
		country[i] = country[i + 1];

	if (count > 0) {
		count--;
		country = (Country*)realloc(country, sizeof(Country)*(count + 1));

	}


}

Country & CountryArr::CList(int id) const {
	return country[id];

}