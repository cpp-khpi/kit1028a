#include "InfoIndependentsWork.h"

int InfoIndependentsWork::getAmount() {
	return InfoIndependentsWork::amount;
}
int InfoIndependentsWork::getWritten() {
	return InfoIndependentsWork::written;
}
int InfoIndependentsWork::getMark() {
	return InfoIndependentsWork::mark;
}
char *InfoIndependentsWork::getSurname() {
	return InfoIndependentsWork::surname;
}
void InfoIndependentsWork::generation_values(char *s) {
	amount = 8 + rand() % 8;
	written = amount - rand() % 8;
	mark = 1 + rand() % 5;
	strcpy_s(surname, 256, s);
}
void InfoIndependentsWork::setData(int amount, int written, int mark,char *surname) {
	strcpy_s(InfoIndependentsWork::surname, 256, surname);
    InfoIndependentsWork::amount = amount;
	InfoIndependentsWork::written = written;
	InfoIndependentsWork::mark = mark;
}