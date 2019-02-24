#include "Header.h"

int InfoAuditoryLessons :: getType() {
	return InfoAuditoryLessons :: type;
}
int InfoAuditoryLessons :: getKoltype() {
	return InfoAuditoryLessons :: koltype;
}
int InfoAuditoryLessons :: getStudents() {
	return InfoAuditoryLessons :: students;
}
void InfoAuditoryLessons :: setData(int x, int y, int z) {
	InfoAuditoryLessons :: type = x;
	InfoAuditoryLessons :: koltype = y;
	InfoAuditoryLessons :: students = z;
}


void AuditoryLessons :: getSize(int s) {
	AuditoryLessons :: size = s;
}
void AuditoryLessons :: newArray() {
	arr = new InfoAuditoryLessons[size];
}
void AuditoryLessons :: print() {
	for (int i = 0; i < size; i++) {
		int t = arr[i].getType();
		int k = arr[i].getKoltype();
		int st = arr[i].getStudents();
		if (t == 1) {
			std::cout << "        LectureLessons" << std::endl; // Лекция
		}
		else if (t == 2) {
			std::cout << "        Workshops" << std::endl; // Практика
		}
		else {
			std::cout << "        LaboratoryWorks" << std::endl; // Лабы
		}
		std::cout << "Number of classes held: " << k << std::endl;
		std::cout << "Number of students (average): " << st << std::endl << std::endl ;
	}
}
void AuditoryLessons :: addElem() {
	int x, y, z;

	std::cout << "Enter your type (1) - LectureLessons, (2) - Workshops, (3) - LaboratoryWorks : ";
	std::cin >> x;
	std::cout << "Enter number of classes held : ";
	std::cin >> y;
	std::cout << "Enter number of students (average) : ";
	std::cin >> z;
	std::cout << std::endl;
	
	InfoAuditoryLessons *mas = new InfoAuditoryLessons[size];

	for (int i = 0; i < size; i++) {
		mas[i] = AuditoryLessons :: arr[i];
	}

	delete[] arr;
	size++;
	arr = new InfoAuditoryLessons[size];

	for (int i = 0, j = 0; i < size; i++) {
		if (i == size - 1) {
			AuditoryLessons :: arr[i].setData(x, y, z);
			i++;
		}
		AuditoryLessons :: arr[i] = mas[j];
		j++;
	}
	delete[] mas;
	print();
}
void AuditoryLessons :: deleteElem(int l) {
	InfoAuditoryLessons* mas = new InfoAuditoryLessons[size + 1];
	size--;
	for (int i = 0; i < size + 1 ; i++)
		mas[i] = AuditoryLessons :: arr[i];

	delete[] arr;
	arr = new InfoAuditoryLessons[size];

	for (int i = 0, j = 0; i < size; i++) {
		if (i == l - 1) {
			j++;
		}
		AuditoryLessons :: arr[i] = mas[j];
		j++;
	}
	delete[] mas;
	print();
}
void AuditoryLessons :: sbi(int index) {
	if (index >= size) {
		std::cout << std::endl << "Error" << std::endl << std::endl;
		return;
	}

	int t = arr[index].getType();
	int k = arr[index].getKoltype();
	int st = arr[index].getStudents();

	if (t == 1) {
		std::cout << std::endl << "        LectureLessons" << std::endl; // Лекция
	}
	else if (t == 2) {
		std::cout << std::endl << "        Workshops" << std::endl; // Практика
	}
	else {
		std::cout << std::endl << "        LaboratoryWorks" << std::endl; // Лабы
	}
	std::cout << "Number of classes held: " << k << std::endl;
	std::cout << "Number of students (average): " << st << std::endl << std::endl;
}
void AuditoryLessons::deleteArray() {
	delete[] AuditoryLessons :: arr;
}