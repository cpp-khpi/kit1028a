#include "InfoIndependentsWork.h"

InfoIndependentsWork::InfoIndependentsWork():amount(0), written(0), mark(0) {
}
InfoIndependentsWork::InfoIndependentsWork(const InfoIndependentsWork &obj) : amount(obj.amount), written(obj.written), mark(obj.mark) {
}
InfoIndependentsWork::InfoIndependentsWork(int amount, int written, int mark, std::string surname) : amount(amount), written(written), mark(mark), surname(surname) {
}
int InfoIndependentsWork::getAmount() {
	return InfoIndependentsWork::amount;
}
int InfoIndependentsWork::getWritten() {
	return InfoIndependentsWork::written;
}
int InfoIndependentsWork::getMark() {
	return InfoIndependentsWork::mark;
}
std::string InfoIndependentsWork::getSurname() {
	return InfoIndependentsWork::surname;
}
void InfoIndependentsWork::generation_values(std::string s) {
	amount = 8 + rand() % 8;
	written = amount - rand() % 8;
	mark = 1 + rand() % 5;
	surname = s;
}
void InfoIndependentsWork::setData(int amount, int written, int mark, std::string surname) {
	InfoIndependentsWork::surname = surname;
	InfoIndependentsWork::amount = amount;
	InfoIndependentsWork::written = written;
	InfoIndependentsWork::mark = mark;
}