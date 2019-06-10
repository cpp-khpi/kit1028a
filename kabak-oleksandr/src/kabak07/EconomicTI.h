#pragma once
#include "TestsInfo.h"


class EconomicTI :
	public TestsInfo
{
public:
	EconomicTI() : TestsInfo(), statistics(0), formuls(0) {};
	EconomicTI(int num, int works, int pages, string surname, int stat, int formuls) : TestsInfo(num, works, pages, surname), statistics(stat), formuls(formuls) {
		if (stat == 5 || formuls == 3) { setMark(5); };
	};

	virtual void setInfo(int num, int works, int pages, string surname)override;

	int getStatistics();
	int getFormuls();

	void setStatistics(int statistics);
	void setFormuls(int formuls);

	virtual void printInfo()const override;

private:
	int statistics;
	int formuls;
};

