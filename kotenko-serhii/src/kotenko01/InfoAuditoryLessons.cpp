#include "InfoAuditoryLessons.h"

InfoAuditoryLessons::InfoAuditoryLessons() {
	type = rand() % 3;
	koltype = rand() % 16 + 1;
	students = rand() % 18;
}
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