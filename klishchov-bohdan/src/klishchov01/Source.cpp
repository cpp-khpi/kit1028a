#include"Header.h"
Country::Country() {
	id = 0;
	strcpy_s(name, "Ukraine");
	area = 110;
	revenue = 120;
	population = 23;
}
void Country::setID(int ID) {

	id = ID;

}
int Country::getID() {

	return id;
}

void Country::setPopul(int popul) {

	population = popul;

}
int Country::getPopul() {

	return population;
}
void Country::setArea(int area1) {
	area = area1;
}
int Country::getArea() {
	return area;
}
void Country::setReven(int reven) {
	revenue = reven;
}
int Country::getReven() {
	return revenue;
}
void Country::setName(char Name[20]) {
	strcpy_s(name, Name);
}
char *Country::getName() {

	return (char*)name;
}



void Country::CountryPrint() const
{
	printf("%i\t%s\t%i\t%i\t%i\n", id, name, population, area, revenue);
}


void Country::CountryFill(int Id, char Name[20], int popul, int area1, int reven) {
	id = Id;
	strcpy_s(name, Name);
	population = popul;
	area = area1;
	revenue = reven;
	strcpy_s(name, Name);
}