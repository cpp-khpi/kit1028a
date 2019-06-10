#include "Containers.h"

int main() {
	Cmp<int>compare;
	vector<int>vec1;
	vector<int>vec2;
	vector<int>vec3;
	int size;
	int tmp;
	cout << "Enter the size of vector: ";
	cin >> size;

	for (int i = 0; i < size; i++) {
		tmp = rand() % 100;
		vec1.push_back(tmp);
		tmp = rand() % 100;
		vec2.push_back(tmp);
	}

	vec3 = InsertToContainer(vec1, vec2);

	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << " ";
	}
	sort(vec3.begin(), vec3.end(), compare);

	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << " ";
	}

	listMethod<Textbook>();
	system("cls");
	vectorMethod<Textbook>();
	system("cls");
	mapMethod<Textbook>();
	system("cls");
	setMethod<Textbook>();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	return _CrtDumpMemoryLeaks();
}