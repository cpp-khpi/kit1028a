#include "Textbook.h"

template <class T>
class TemplateFunctions {
private:
	T* backlist;
	size_t size;
public:
	TemplateFunctions() : size(0) {}

	TemplateFunctions(size_t size) : size(size) {
		backlist = new T[size];
	}

	~TemplateFunctions() {
		delete[] backlist;
	}

	void createBacklist() {
		cout << "Enter the number of pages: " << endl;
		for (int i = 0; i < size; i++) {
			cin >> backlist[i];
		}
	}

	void printAll() {
		for (int i = 0; i < size; i++) {
			cout << backlist[i] << endl;
		}
		cout << endl;
	}

	T minElem() {
		T min = backlist[0];
		for (int i = 0; i < size; i++) {
			if (backlist[i] < min) {
				min = backlist[i];
			}
		}
		return min;
	}

	void sortBacklist() {
		T tmp;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (backlist[i] < backlist[j]) {
					tmp = backlist[i];
					backlist[i] = backlist[j];
					backlist[j] = tmp;
				}
			}
		}
	}

	int getByIndex(T values) {
		for (int i = 0; i < size; i++) {
			if (backlist[i] == values) {
				return i;
			}
		}
		return -1;
	}
};