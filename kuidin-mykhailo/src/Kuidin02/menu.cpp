#include "School.h"
#include "InfoStorge.h"
void InfoStorge::menu() {
	InfoStorge tmp;
	int coun, num, cos, pup, emp, index;
	char p[30];
	cout << "Hi! How many School do u want to create:\n";
	cin >> coun;
	
	// поменять имена переменных, доделать метод createObjects
	tmp.setCount(coun);
	tmp.createObjects();
	int i = 0;
	int a = 100;
	while (a != 0) {

		cout << "Menu: \n 1 - Add new objects \n 2 - Delete object \n 3 - Find by index \n 4 - Print all schools \n 5 - Print schools with employers more than average \n 0 - End program \n Your choose: ";
		cin >> a;
		switch (a)
		{
		case 1:
			system("cls");
			
			cout << "In which position u want add new school? Last position:" << tmp.count << endl;
			cin >> index;
			
			cout << "Enter cost per month: ";
			cin >> cos;

			cout << "Enter type (gymnasium, high, secondary, primary) if school: ";
			cin >> p;

			cout << "Enter number of school: ";
			cin >> num;

			cout << "Enter number of pupils: ";
			cin >> pup;

			cout << "Enter number of employers: ";
			cin >> emp;
			tmp.addObject(index,num,cos,pup,emp,p);
			break;
		case 2:
			system("cls");

			cout << "Enter index ";
			cin >> i;
			tmp.delElem(i);
			break;
		case 3:
			system("cls");

			cout << "Enter index ";
			cin >> i;
			tmp.find((i-1));
			break;
		case 4:
			system("cls");
			tmp.printall();
			break;
		case 5:
			system("cls");
			tmp.average();
			break;
		case 0: 
			a = 0;
			break;
		}
	}
	tmp.deleteall();
}