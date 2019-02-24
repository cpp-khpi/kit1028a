#include <iostream>
#include <ctime>

class InfoAuditoryLessons {
private:
	int type;
	int koltype;
	int students;
public:
	InfoAuditoryLessons() {
		InfoAuditoryLessons::type = rand() % 3;
		InfoAuditoryLessons::koltype = rand() % 16 + 1;
		InfoAuditoryLessons::students = rand() % 18;
	}
	int getType();
	int getKoltype();
	int getStudents();
	void setData(int x, int y, int z);
};


class AuditoryLessons {
private:
	int size;
	InfoAuditoryLessons *arr;
public:
	void getSize(int s);
	void newArray();
	void print();
	void addElem();
	void deleteElem(int l);
	void sbi(int index);
	void deleteArray();
};
