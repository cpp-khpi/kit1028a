#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class TestInfo {
private:
	int tasks;
	int mark;
public:
	TestInfo();
	TestInfo(int mark, int tasks);
	TestInfo(const TestInfo& obj);
	~TestInfo();

	TestInfo& operator = (const TestInfo& obj);
	bool operator == (const TestInfo obj);
	friend std::ostream& operator << (ostream& out, const TestInfo& obj);
	friend std::istream& operator >> (istream& in, TestInfo& obj);
	bool operator > (const TestInfo o);
	bool operator < (const TestInfo o);

	int getMark();
	int getTasks();
	void randValues();
	void setInfo(int mark, int tasks);

};