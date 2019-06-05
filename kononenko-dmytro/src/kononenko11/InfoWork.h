#include <iostream>

using namespace std;

class InfoWork {
private:
	int size; // size of work
	int points; // points which student got
public:
	InfoWork();
	InfoWork(int a, int b);
	InfoWork(const InfoWork &obj);
	InfoWork& operator= (const InfoWork obj) {
		size = obj.size;
		points = obj.points;
		return *this;
	}
	friend std::istream& operator>> (std::istream &in, InfoWork &obj) {
		in >> obj.size;
		in >> obj.points;
		return in;
	}
	friend std::ostream& operator<< (std::ostream &out, InfoWork &obj) {
		out<<"Size: " << obj.size << "Points: " << obj.points;
		return out;
	}
	bool operator== (const InfoWork obj) {
		return (size == obj.size);
	}
	bool operator< (const InfoWork obj) {
		return (size < obj.size);
	}
	~InfoWork() {}
};