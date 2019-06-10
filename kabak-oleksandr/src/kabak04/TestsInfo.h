#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ifstream;
using std::regex;
using std::regex_match;

class TestsInfo {
private:
	int num;
	int works, pages, mark;
	string surname;
public:
	TestsInfo();
	TestsInfo(int num, int works, int pages, string surname);
	TestsInfo(const TestsInfo& o);
	~TestsInfo() {};

	void setInfo(int num, int works, int pages, string surname);
	int getNum()const;
	int getWorks()const;
	int getPages()const;
	int getMark()const;
	string getSur()const;

	string printInfo()const;
};