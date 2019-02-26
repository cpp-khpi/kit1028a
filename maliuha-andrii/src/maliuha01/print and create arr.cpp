#include "Header.h"

void funcs::createArr() {
	string n;
	float om, mg, twm;

	cout << "Enter size of array: " << endl;
	cin >> size;
	mas = new programOn[size];

	cout << "Instead of a space use '_'. It is a feature of the program." << endl;
	cout << "Otherwise the program will not work. You have been warned." << endl;

	for (int i = 0; i < size; i++) {
		cout << "Enter name of program:" << endl;
		cin >> n;
		cout << "Enter amount of consumed RAM(Mb):" << endl;
		cin >> om;
		cout << "Enter ocupied amount of hard disk memory(Mg):" << endl;
		cin >> mg;
		cout << "Enter time of work (in minutes):" << endl;
		cin >> twm;

		mas[i].setName(n);
		mas[i].setOpMemoryMb(om);
		mas[i].setMemoryGb(mg);
		mas[i].setTimeWorkMin(twm);

	}
}

void const programOn::print() {
	cout << "Name of program: " << name << endl;
	cout << "Amount of consumed RAM(Mb): " << opMemoryMb << endl;
	cout << "Ocupied amount of hard disk memory(Gb): " << memoryGb << endl;
	cout << "Time of work (in minutes): " << timeWorkMin << endl;
}