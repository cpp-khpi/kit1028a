#include "IndependentTesting.h"

IndependentTesting::IndependentTesting() : ZNO(175) {
}

void IndependentTesting::set_ZNO(int ZNO) {
	this->ZNO = ZNO;
}

int IndependentTesting::get_ZNO() {
	return IndependentTesting::ZNO;
}
