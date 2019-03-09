#include "AuditoryLessons.h"

void AuditoryLessons :: getSize(int s) {
	AuditoryLessons :: size = s;
}
void AuditoryLessons :: newArray() {
	arr = new InfoAuditoryLessons[size];
}
void AuditoryLessons :: print() {
	for (int i = 0; i < size; i++) {
		int type = arr[i].getType();
		int koltype = arr[i].getKoltype();
		int students = arr[i].getStudents();
		if (type == 1) {
			std::cout << "        LectureLessons" << std::endl; 
		}
		else if (type == 2) {
			std::cout << "        Workshops" << std::endl; 
		}
		else {
			std::cout << "        LaboratoryWorks" << std::endl; 
		}
		std::cout << "Number of classes held: " << koltype << std::endl;
		std::cout << "Number of students (average): " << students << std::endl << std::endl ;
	}
}
void AuditoryLessons::addElem() {
	int x, y, z;
	std::cout << "Enter your type (1) - LectureLessons, (2) - Workshops, (3) - LaboratoryWorks : ";
	std::cin >> x;
	std::cout << "Enter number of classes held : ";
	std::cin >> y;
	std::cout << "Enter number of students (average) : ";
	std::cin >> z;
	std::cout << std::endl;

	InfoAuditoryLessons *mas = new InfoAuditoryLessons[size + 1];

	for (int i = 0; i < size; i++) {
		mas[i] = AuditoryLessons::arr[i];
	}

	size++;
	delete[] arr;

	mas[size - 1].setData(x, y, z);

	arr = mas;
	print();
}
void AuditoryLessons::deleteElem(int l) {
	InfoAuditoryLessons* mas = new InfoAuditoryLessons[size];

	int j = 0;
	for (int i = 0; i < l; i++) {
		mas[i] = AuditoryLessons::arr[j];
		j++;
	}
	j++;
	for (int i = l; i < size; i++) {
		mas[i] = AuditoryLessons::arr[j];
		j++;
	}
	delete[] arr;
	size--;

	arr = mas;
	print();
}
void AuditoryLessons :: getByIndex(int index) {
	if (index >= size) {
		std::cout << std::endl << "Error" << std::endl << std::endl;
		return;
	}

	int type = arr[index].getType();
	int koltype = arr[index].getKoltype();
	int students = arr[index].getStudents();

	if (type == 1) {
		std::cout << std::endl << "        LectureLessons" << std::endl; 
	}
	else if (type == 2) {
		std::cout << std::endl << "        Workshops" << std::endl; 
	}
	else {
		std::cout << std::endl << "        LaboratoryWorks" << std::endl; 
	}
	std::cout << "Number of classes held: " << koltype << std::endl;
	std::cout << "Number of students (average): " << students << std::endl << std::endl;
}
void AuditoryLessons::deleteArray() {
	delete[] AuditoryLessons :: arr;
}