#pragma once
#include"Header.h"
class CountryArr : public Country

{
public:
	CountryArr(); 
	void CountryAdd(Country country); 
	void CountryPrint() const; 
	void CountryRemove(int id); 
	Country &CList(int id)const;

private:
	Country *country;
	int count;




};
