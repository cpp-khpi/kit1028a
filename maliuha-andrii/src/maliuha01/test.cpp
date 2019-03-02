#include "Header for test.h"
#include <cstdbool>


int main() {
	string n;
	funcsForArray ops;
	float om, mg, twm;
	n = "prog_1";
	om = 300;
	mg = 1000;
	twm = 20;
	int sizeMas = 1;
	ops.setSize(sizeMas);
	ops.createArrTest();
	ops.testAdd(n, om, mg, twm, ops);
	int ind = 2;
	ops.delObj(ind);
	ops.testDel(n, om, mg, twm);
	ops.delMas();

	system("pause");
}

bool funcsForArray::testAdd(string n, float om, float mg, float twm, funcsForArray ops) {
	workingProgram *Expected = new workingProgram[2];
	int myCount = 0;
	Expected[0].setName(n);
	Expected[0].setOpMemoryMb(om);
	Expected[0].setMemoryGb(mg);
	Expected[0].setTimeWorkMin(twm);

	n = "prog_2";
	om = 200;
	mg = 4000;
	twm = 50;
	
	Expected[1].setName(n);
	Expected[1].setOpMemoryMb(om);
	Expected[1].setMemoryGb(mg);
	Expected[1].setTimeWorkMin(twm);
	int ind = 2;

	string nE;
	float omE, mgE, twmE;
	ops.addObj(ind, n, mg, om, twm);
	for (int i = 0; i < 2; i++) {
		n = mas[i].getName(n);
		om = mas[i].getOpMemoryMb(om);
		mg = mas[i].getMemoryGb(mg);
		twm = mas[i].getTimeWorkMin(twm);
		nE = Expected[i].getName(nE);
		omE = Expected[i].getOpMemoryMb(omE);
		mgE = Expected[i].getMemoryGb(mgE);
		twmE = Expected[i].getTimeWorkMin(mgE);
		if (n == nE && om == omE && mg == mgE && twm == twmE) {
			myCount++;
		}
		else {
			cout << "The expected data does not agree with the received" << endl;
			cout << "Expwcted data:" << endl;
			cout << "Name of program: " << nE<< endl;
			cout << "Amount of consumed RAM: " << omE << endl;
			cout << "Ocupied amount of hard disk memory: " << mgE << endl;
			cout << "Time of work: " << twmE << endl;
			cout << "Received data:" << endl;
			cout << "Name of program: " << n << endl;
			cout << "Amount of consumed RAM: " << om << endl;
			cout << "Ocupied amount of hard disk memory: " << mg << endl;
			cout << "Time of work: " << twm << endl;
		}
	}
	if (myCount == 2) {
		cout << "Function addObj passed the test!" << endl;
	}
	else {
		cout << "Function addObj is not passed the test!" << endl;
	}
	delete[] Expected;
}

void funcsForArray::setSize(int sizeMas) {
	sizeMas = size;
}

void funcsForArray::createArrTest() {
	string n;
	float om, mg, twm;
	mas = new workingProgram[size];

	n = "prog_1";
	om = 300;
	mg = 1000;
	twm = 20;

	mas[0].setName(n);
	mas[0].setOpMemoryMb(om);
	mas[0].setMemoryGb(mg);
	mas[0].setTimeWorkMin(twm);
}

bool funcsForArray::testDel(string n, float om, float mg, float twm) {
	workingProgram *Expected = new workingProgram[2];
	int myCount = 0;
	Expected[0].setName(n);
	Expected[0].setOpMemoryMb(om);
	Expected[0].setMemoryGb(mg);
	Expected[0].setTimeWorkMin(twm);


	string nE;
	float omE, mgE, twmE;

	for (int i = 0; i < 1; i++) {
		n = mas[i].getName(n);
		om = mas[i].getOpMemoryMb(om);
		mg = mas[i].getMemoryGb(mg);
		twm = mas[i].getTimeWorkMin(twm);
		nE = Expected[i].getName(nE);
		omE = Expected[i].getOpMemoryMb(omE);
		mgE = Expected[i].getMemoryGb(mgE);
		twmE = Expected[i].getTimeWorkMin(mgE);
		if (n == nE && om == omE && mg == mgE && twm == twmE) {
			myCount++;
		}
		else {
			cout << "The expected data does not agree with the received" << endl;
			cout << "Expwcted data:" << endl;
			cout << "Name of program: " << nE << endl;
			cout << "Amount of consumed RAM: " << omE << endl;
			cout << "Ocupied amount of hard disk memory: " << mgE << endl;
			cout << "Time of work: " << twmE << endl;
			cout << "Received data:" << endl;
			cout << "Name of program: " << n << endl;
			cout << "Amount of consumed RAM: " << om << endl;
			cout << "Ocupied amount of hard disk memory: " << mg << endl;
			cout << "Time of work: " << twm << endl;
		}
	}
	if (myCount == 1) {
		cout << "Function delObj passed the test!" << endl;
	}
	else {
		cout << "Function delObj is not passed the test!" << endl;
	}
	delete[] Expected;
}
