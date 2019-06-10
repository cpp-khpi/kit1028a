#include "TestsInfo.h"

class StudentsWorks {
private:
	int SIZE;
	TestsInfo new_student;
	TestsInfo* list;

public:
	StudentsWorks(int SIZE);
	~StudentsWorks();

	void setNewStud();
	int getSIZE();
	void infoWorks(const int num);

	void removeStud(const int num);
	void addStud(const int num);

	void getStud(const int num)const;
	void getNewStud();
	void printAll()const;
	void printAll2()const;
};