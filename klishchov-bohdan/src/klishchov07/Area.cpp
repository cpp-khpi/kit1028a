#include "Area.h"

void Area::setArea(int area)
{
	this->area = area;
}
void Area::Info()
{
	cout << "The area of country is: " << area << endl;
}
int Area::getArea() 
{
	return area;
}