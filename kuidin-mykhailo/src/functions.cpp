#include "Header.h"

void functions::find(int index) {
	int i = 0;
	while (i != index) {
		i++;
	}

	cout << "\nInformation about school that u find:\n";
	s[i].print();
}

void functions::delElem(int index) {
	count--;
	deltmp = (functions*)operator new(sizeof(functions)*count);
	int j = 0;
	for (int i = 0; i < count; i++) {
		if (i == index) {
			j++;
		}
			deltmp[i] = s[j];
			j++;
	}
	
	delete[] s;
	s = (functions*) operator new (sizeof(functions)*count);
	for (int i = 0; i < count; i++) {
		s[i] = deltmp[i];
	}
	
	delete [] deltmp;
}

void functions::print() {
	int number = getNumber();
	int pupils = getPupils();
	int cost = getCost();
	cout << "Number of school: " << number << endl << "Pupils: " << pupils << endl << "Cost per month: " << cost << endl << endl;
}

void functions::addObject(int index) {
	tmp = (functions*)operator new(sizeof(functions)*200);
	for (int i = 0; i < count; i++) {
		tmp[i] = s[i];
	}
	
	delete [] s;
	
	int j = 0;
	count++; // Потому что добавляем новый элемент
	newS = (functions*)operator new(sizeof(functions) * count);
	s = (functions*)operator new (sizeof(functions)*count);
	for (int i = 0; i < count; i++) {
		if (i != index) {
			newS[i] = tmp[j];
			j++;
		}
		else {
			int a = 0;
			cout << "\nEnter number of school: " << endl;
			cin >> a;
			newS[i].setNumber(a);
			cout << "How many pupils study in this school: " << endl;
			cin >> a;
			newS[i].setPupils(a);
			cout << "Enter cost per month: " << endl;
			cin >> a;
			newS[i].setCost(a);
			
		}

	}
	for (int i = 0; i < count; i++) {
		s[i] = newS[i];
	}
	
	delete [] newS;
	delete [] tmp;
}

void functions::createObjects() {
	functions t;

	cout << " How many objects you wnat to create: ";
	cin >> count;
		
 	s = (functions*)operator new(sizeof(functions) * count);

	for (int i = 0; i < count; i++) {
		new(&s[i])functions();
	}

	for (int i = 0; i < count; i++) {
		s[i].setCost(rand()%100);
		s[i].setNumber(rand()%100);
		s[i].setPupils(rand()%100);
	}
}

void functions::printall() {
	cout << "All schools:----------------------------------------\n";
	for (int i = 0; i < count; i++) {
		s[i].print();
	}
}

void functions::deleteall() {
	delete [] s;
}

void functions::test(){
	int snth = 0;
	sTest = (functions*) operator new (sizeof(functions) * 20);

	sTest[0].setCost(41);
	sTest[0].setNumber(67);
	sTest[0].setPupils(34);

	sTest[1].setCost(400);
	sTest[1].setNumber(47);
	sTest[1].setPupils(600);

	for (int i = 0; i < 2; i++) {
		int sNum = s[i].getNumber();
		int sCost = s[i].getCost();
		int sPup = s[i].getPupils();

		int tNum = sTest[i].getNumber();
		int tCost = sTest[i].getCost();
		int tPup = sTest[i].getPupils();

		if (sNum == tNum && sCost == tCost && sPup == tPup) {
			cout << "Test " << i+1 << " passed!" << endl;
		}
		else cout << "Test" << i+1 << " failed" << endl;
	}
}