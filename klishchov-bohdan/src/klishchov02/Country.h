#pragma once
#include<iostream>
class Country
{


public:
	Country();
	Country(int Id, char Name[20], int population, int area, int revenue);
public:
	void CountryPrint() const;
	void CountryFill(int Id, char Name[20], int population, int area, int revenue);
	void setID(int ID);
	int getID();
	void setPopul(int population);
	int getPopul();
	void setArea(int area);
	int getArea();
	void setReven(int revenue);
	int getReven();
	void setName(char name[20]);
	char  *getName();
	void delChar();

private:
	int id; // ????, ??????? ???????? ?? ????? ?????? ? ??????
	char name[20];
	int population;
	int area;
	int revenue;
	int min;
};