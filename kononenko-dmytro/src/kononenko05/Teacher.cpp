#include "Teacher.h"

Teacher::Teacher() {
	name = { "Molchanov" };
}

void Teacher::setName(string tmp) {
	name = tmp;
}
string Teacher::getName() {
	return name;
}