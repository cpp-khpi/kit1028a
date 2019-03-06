#include "School.h"
#include "InfoStorge.h"

void InfoStorge::find(int index) {
	cout << "\nInformation about school that u find:\n";
	print(index);
}

void InfoStorge::delElem(int index) {
	count--;
	School *deltmp = (School*)operator new(sizeof(School)*count);
	int j = 0;
	for (int i = 0; i < count; i++) {
		if (i == index) {
			j++;
		}
		deltmp[i] = s[j];
		j++;
	}

	s[index].deleteName();
	delete[] s;
	s = deltmp;
}

void InfoStorge::print(int i) {
			
	char *name_ = (char*) operator new (sizeof(char) * 20);
	s[i].getName(name_);
	cout << "Number of school: " << s[i].getNumber();
	printf("\nType:%s", name_);
	cout << endl << "Pupils: " << s[i].getPupils() << endl << "Cost per month: " << s[i].getCost() << "\nEmployers: " << s[i].getEmployers() << endl << endl;
	delete[] name_;         
}

void InfoStorge::addObject(int index, int num, int cos, int pup, int emp, char *p) {
	

	count++;
	int j = 0;
	School *tmp = (School*)operator new (sizeof(School)*count);
	for (int i = 0; i < count; i++) {
		new(&tmp[i])School();
	}
	for (int i = 0; i < index; i++) {
		tmp[i] = s[j];
		j++;
	}
	tmp[index].setCost(cos);
	tmp[index].setNumber(num);
	tmp[index].setEmployers(emp);
	tmp[index].setName(p);
	tmp[index].setPupils(pup);
	for (int i = index + 1; i < count; i++) {
		tmp[j] = s[i];
	}
	
	delete[] s;
	s = tmp;
	
}

void InfoStorge::createObjects() {

	s = (School *)operator new(sizeof(School) * count);

	for (int i = 0; i < count; i++) {
		new(&s[i])School();
	}

	for (int i = 0; i < count; i++) {
		char p[25];
		unsigned int tmp = 0;
		cout << "\n\nSchool number: " << i + 1 << endl;
		cout << "Enter cost per month: ";
		cin >> tmp;
		s[i].setCost(tmp);

		cout << "Enter type (gymnasium, high, secondary, primary) if school: ";
		cin >> p;
		s[i].setName(p);

		cout << "Enter number of school: ";
		cin >> tmp;
		s[i].setNumber(tmp);

		cout << "Enter number of pupils: ";
		cin >> tmp;
		s[i].setPupils(tmp);

		cout << "Enter number of employers: ";
		cin >> tmp;
		s[i].setEmployers(tmp);

	}

}

void InfoStorge::printall() {

	cout << "All schools:----------------------------------------\n";
	for (int i = 0; i < count; i++) {
		print(i);
	}
}

void InfoStorge::deleteall() {
	
	for (int i = 0; i < count; i++) {
		s[i].deleteName();
	}
	delete[] s;
}

void InfoStorge::average() {
	float average = 0;
	int sum = 0;
	int tmp = 0;
	for (int i = 0; i < count; i++) {
		tmp = s[i].getEmployers();
		sum = sum + tmp;
	}
	average = (sum / count);
	for (int i = 0; i < count; i++) {
		tmp = s[i].getEmployers();
		if (tmp > average) {
			cout << "\nThis school has more employer than avarege of all schools: " << endl;
			print(i);
		}
	}
}
