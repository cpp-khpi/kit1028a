#include "Textbook.h"

Textbook::Textbook() :pages(rand() % 180 + 100), grade(rand() % 11 + 1) { 
	cout << "The constructor by default has worked!" << endl; 
}

Textbook::Textbook(int p, int g) : pages(p), grade(g) {
}

Textbook::Textbook(const Textbook &obj) : pages(obj.pages), grade(obj.grade) {
}

Textbook::~Textbook() {
}