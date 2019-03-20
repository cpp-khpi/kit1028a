#include "School.h"
#include "InfoStorge.h"

void InfoStorge::find(int index) {
	cout << "\nInformation about school that u find:\n";
	print(index);
}

void InfoStorge::delElem(int index) {
	int edit = 0;
	char ptr[20];

	count--;
	School *deltmp = (School*)operator new(sizeof(School)*count);
	int j = 0;
	for (int i = 0; i < index; i++) {
		edit = s[i].getCost();
		deltmp[j].setCost(edit);
		edit = s[i].getNumber();
		deltmp[j].setNumber(edit);
		edit = s[i].getPupils();
		deltmp[j].setPupils(edit);
		edit = s[i].getEmployers();
		deltmp[j].setEmployers(edit);
		s[i].getName(ptr);
		deltmp[j].setName(ptr);
		s[i].deleteName();
		j++;
		
	}

	j++;

	for (int i = index; i < count; i++) {
		edit = s[i].getCost();
		deltmp[j].setCost(edit);
		edit = s[i].getNumber();
		deltmp[j].setNumber(edit);
		edit = s[i].getPupils();
		deltmp[j].setPupils(edit);
		edit = s[i].getEmployers();
		deltmp[j].setEmployers(edit);
		s[i].getName(ptr);
		deltmp[j].setName(ptr);
		s[i].deleteName();
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
	int edit = 0;
	char ptr[20];
	
	count++;
	int j = 0;
	School *tmp = (School*)operator new (sizeof(School)*count);
	
	for (int i = 0; i < index; i++) {
		edit = s[i].getCost();
		tmp[j].setCost(edit);
		edit = s[i].getNumber();
		tmp[j].setNumber(edit);
		edit = s[i].getPupils();
		tmp[j].setPupils(edit);
		edit = s[i].getEmployers();
		tmp[j].setEmployers(edit);
		s[i].getName(ptr);
		tmp[j].setName(ptr);
		//tmp[j] = s[index];
		// �������� �������� ����� ����� ��������
		s[i].deleteName();
		j++;
	}
	tmp[index].setCost(cos);
	tmp[index].setNumber(num);
	tmp[index].setEmployers(emp);
	tmp[index].setName(p);
	tmp[index].setPupils(pup);
	for (int i = index + 1; i < count; i++) {
		edit = s[i].getCost();
		tmp[j].setCost(edit);
		edit = s[i].getNumber();
		tmp[j].setNumber(edit);
		edit = s[i].getPupils();
		tmp[j].setPupils(edit);
		edit = s[i].getEmployers();
		tmp[j].setEmployers(edit);
		s[i].getName(ptr);
		tmp[j].setName(ptr);
		s[i].deleteName();
	}
	
	delete[] s;
	s = tmp;
	
}

void InfoStorge::createObjects() {

	s = (School *)operator new(sizeof(School) * count);

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
