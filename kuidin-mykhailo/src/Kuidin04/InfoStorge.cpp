#include "School.h"
#include "InfoStorge.h"
#include "Header.h"

void InfoStorge::find(int index) {
	cout << "\nInformation about school that u find:\n";
	print(index);
}

void InfoStorge::delElem(int index) {
	int edit = 0;
	string ptr;
	
	
	School* deltmp = new School[count-1];
	int j = 0;
	for (int i = 0; i < index; i++) {
		deltmp[j] = s[i];
	
		j++;
	}

	for (int i = (index+1); i < count; i++) {
		deltmp[j] = s[i];
		
		j++;
	}
	
	count--;
	delete[] s;
	s = deltmp;
}

void InfoStorge::print(int i) {
			
	cout << "Number of school: " << s[i].getNumber();
	cout << "\nType of school: " << s[i].getName();
	cout << endl << "Pupils: " << s[i].getPupils() << endl << "Cost per month: " << s[i].getCost() << "\nEmployers: " << s[i].getEmployers() << endl << endl;
	        
}

void InfoStorge::addObject(int index, int num, int cos, int pup, int emp, string p) {
	int edit = 0;
	string ptr;
	
	count++;
	int j = 0;
	School *tmp =  new School[count];
		
	for (int i = 0; i < index; i++) {
		tmp[i] = s[j];
		
		j++;
	}

	tmp[index].setCost(cos);
	tmp[index].setNumber(num);
	tmp[index].setEmployers(emp);
	tmp[index].setName(p);
	tmp[index].setPupils(pup);

	for (int i = index+1; i < count; i++) {
		tmp[i] = s[j];
		
		j++;
	}

	delete[] this->s;
	s = tmp;


}

void InfoStorge::createObjects() {

	s = new School[count];

}

void InfoStorge::printall() {

	cout << "All schools:----------------------------------------\n";
	for (int i = 0; i < count; i++) {
		print(i);
	}
}

void InfoStorge::deleteall() {
		
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

void InfoStorge::readFromFile(string file, int fnum, int fcost, int fpupils, int femployers, string fname, int index) {

	ifstream fin;
	fin.open("start.txt", ios_base::in);
	if (fin.is_open()){
	}
	else {
		cout << "Can't open this file\n";
		exit(-1);
	}
	fin >> fnum >> fcost >> fpupils >> femployers;
	getline(fin, fname);

	regexCheck(fname);



	s[index].setCost(fcost);
	s[index].setNumber(fnum);
	s[index].setPupils(fpupils);
	s[index].setEmployers(femployers);
	s[index].setName(fname);
}

void InfoStorge::setAll(int index, int num, int cos, int pup, int emp, string p) {
	s[index].setCost(cos);
	s[index].setNumber(num);
	s[index].setPupils(pup);
	s[index].setEmployers(emp);
	s[index].setName(p);
}

void InfoStorge::printToFile(int index) {

	int cos = s[index].getCost();
	int num = s[index].getNumber();
	int pup = s[index].getPupils();
	int emp = s[index].getEmployers();
	string p = s[index].getName();
	
	ofstream fout;
	fout.open("end.txt", ios::app);
	if (fout.is_open()) {
	}
	else {
		cout << "Can't open this file\n";
		exit(-1);
	}
	fout << "Cost per month: " << cos << endl;
	fout << "Type of School: " << p << endl;
	fout << "Number of School: " << num << endl;
	fout << "Pupils: " << pup << endl;
	fout << "Employers: " << emp << endl << endl;
}

void InfoStorge::clearFile(string fname) {
	std::ofstream ic("end.txt", std::ios::out);
	ic.close();
}


void InfoStorge::regexCheck(string str) {
	
	regex regular("^[A-Z]");
	regex space("[\\s]{2,}");
	
	while (regex_search(str, space)||!regex_search(str, regular)) {
		cout << "Name: " << str << endl;
		cout << " Name does not match the format, first letter need to be big or u put 2 of more symbols\n Enter new name that match format: ";
		getline(cin, str);
		system("cls");
	}

}

void InfoStorge::countWords() {
	regex regular("[A-Z][a-z]+[\\s][a-z]+");

	for (int i = 0; i < count; i++) {
		string tmp = s[i].getName();
		if (regex_search(tmp, regular)) {
			print(i);
		}
	
	}
}