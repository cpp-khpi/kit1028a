#pragma once
#include"Country.h"
class CountryArr : Country

{
public:
	CountryArr();
	void CountryAdd(Country country);
	void CountryPrint() const;
	void CountryRemove(int id);
	Country & CList(int id)const;
	Country & Min();

private:
	Country *country;
	int count;




};