#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

class Textbook {
private:
	int pages;
	int grade;
public:
	Textbook();
	Textbook(int p, int g);
	Textbook(const Textbook &obj);
	~Textbook();

	Textbook& operator= (const Textbook obj) {
		pages = obj.pages;
		int grade = obj.grade;
		return *this;
	}
	friend istream& operator>> (istream &in, Textbook &obj) {
		cout << "Enter the amount of pages in textbook: " << endl;
		in >> obj.pages;
		cout << "Enter the grade this textbook for: " << endl;
		in >> obj.grade;
		return in;
	}
	friend ostream& operator<< (ostream &out, Textbook &obj) {
		out << "The amount of pages: " << obj.pages << "   The grade: " << obj.grade << endl;
		return out;
	}
	bool operator== (const Textbook obj) {
		return (pages == obj.pages);
	}
	bool operator< (const Textbook obj) {
		return (pages < obj.pages);
	}
};
