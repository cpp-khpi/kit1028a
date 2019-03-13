/**
* @author Klishchov B.
* @date 07-03-2019
* @version 1.2
*/
#include"Country.h"
#include"CountryArr.h"


int main()
{
	Country C1(555, (char*)"Poland", 21, 160, 190);
	CountryArr C2;
	C2.CountryAdd(C1);
	C1.CountryFill(111, (char*)"USA", 19, 152, 127);
	C2.CountryAdd(C1);
	C1.CountryFill(222, (char*)"Japan", 18, 140, 146);
	C2.CountryAdd(C1);
	C1.CountryFill(123, (char*)"Greese", 15, 195, 193);
	C2.CountryAdd(C1);
	C2.CountryPrint();
	printf("\n");

	C2.CountryRemove(0);
	Country minimum = C2.Min();
	C2.CountryPrint();
	system("pause");
	return 0;
}