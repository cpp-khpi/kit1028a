#include "InfoWork.h"

InfoWork::InfoWork() :size(rand() % 100), points(rand() % 5 + 1) { cout << "Obj created" << endl; }
InfoWork::InfoWork(int a, int b) : size(a), points(b) {}
InfoWork::InfoWork(const InfoWork &obj) : size(obj.size), points(obj.points) {}