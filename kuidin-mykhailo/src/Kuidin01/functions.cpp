#include "Header.h"

void Functions::find(int x) {
	
	cout << "\nInformation about school that u find:\n";
	cout << "Number of school: " << s[x].getNumber() << endl << "Pupils: " << s[x].getPupils() << endl << "Cost per month: " << s[x].getCost() << endl << endl;
}

void Functions::delElem(int index) {
	count--;
	deltmp = (School*)operator new(sizeof(School)*count);
	int j = 0;
	for (int i = 0; i < count; i++) {
		if (i == index) {
			j++;
		}
			deltmp[i] = s[j];
			j++;
	}
	
	delete[] s;
	s = (School*) operator new (sizeof(School)*count);
	for (int i = 0; i < count; i++) {
		s[i] = deltmp[i];
	}
	
	delete [] deltmp;
}


void Functions::createObjects() {
	Functions t;

	cout << " How many objects you wnat to create: ";
	cin >> count;
		
 	s = (School*)operator new(sizeof(School) * count);

	for (int i = 0; i < count; i++) {
		new(&s[i])Functions();
	}

	for (int i = 0; i < count; i++) {
		s[i].setCost(rand()%100);
		s[i].setNumber(rand()%100);
		s[i].setPupils(rand()%100);
	}
}
void Functions::addObject(int index, int num, int pup, int cost) {
	tmp = (School*)operator new(sizeof(School) * 200);
	for (int i = 0; i < count; i++) {
		tmp[i] = s[i];
	}

	delete[] s;

	int j = 0;
	count++; // Потому что добавляем новый элемент
	newS = (School*)operator new(sizeof(School) * count);
	s = (School*)operator new (sizeof(School)*count);
	for (int i = 0; i < index; i++) {
		newS[i] = tmp[j];
		j++;
	}
	newS[index].setNumber(num);
	newS[index].setPupils(pup);
	newS[index].setCost(cost);
	for (int i = (index+1); i < count; i++) {
		newS[i] = tmp[j];
		j++;
	}

	for (int i = 0; i < count; i++) {
		s[i] = newS[i];
	}

	delete[] newS;
	delete[] tmp;
}

void Functions::printall() {
	cout << "All schools:----------------------------------------\n";
	for (int i = 0; i < count; i++) {
		cout << "Number of school: " << s[i].getNumber() << endl << "Pupils: " << s[i].getPupils() << endl << "Cost per month: " << s[i].getCost() << endl << endl;
	}
}

void Functions::deleteall() {
	delete [] s;
}

void Functions::test(){
	int snth = 0;
	sTest = (School*) operator new (sizeof(School) * 20);

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