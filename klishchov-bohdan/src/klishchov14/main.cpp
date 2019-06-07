#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Country.h"


int main() {
	vector<Country> myVector1;
	vector<Country> myVector2;
	Country country;
	country.setData("Japan");
	myVector1.push_back(country);
	country.setData("USA");
	myVector2.push_back(country);
	country.setData("Ukraine");
	myVector2.push_back(country);
	country.setData("Russia");
	myVector2.push_back(country);
	for (const auto& el : myVector2) {
		myVector1.insert(myVector1.end(), el);
	}

	std::sort(myVector1.begin(), myVector1.end());

	for (int i = 0; i < myVector1.size(); i++) {
		cout << myVector1[i] << " ";
	}

	return 0;
}