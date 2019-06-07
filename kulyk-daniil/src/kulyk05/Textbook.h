#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::string;
using std::getline;
using std::ifstream;


class ReaderRating {
public:
	int getRate() {
		return rate;
	}
private:
	int rate = 10;
};

class Textbook {
private:
	int num, pages, grade, cost, year_of_release;
	string author;

	class Illustration {
	public:
		void printInfo() {
			cout << "Here are amazing illustrations in this book: )" << endl;
		}
	};

	Illustration picture;
	ReaderRating rate;

public:
	Textbook();
	Textbook(int num, int pages, int grade, int cost, int year_of_release, string author);
	Textbook(const Textbook &obj);
	int getNum();
	int getPages();
	int getGrade();
	int getCost();
	int getYearOfRelease();
	string getAuthor();
	void getInfo(string surname);
	void setInfo(int num, int pages, int grade, int cost, int year_of_release, string author);

	void printInfo();
	void RatingStats();
	~Textbook() {
	}
};
