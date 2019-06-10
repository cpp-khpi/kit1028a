#pragma once
#include "TestsInfo.h"
class MathTI :
	public TestsInfo
{
public:
	MathTI() : TestsInfo(), graphs(0), arguments(0) {};
	MathTI(int num, int works, int pages, string surname, int graphs, int arguments) : TestsInfo(num, works, pages, surname), graphs(graphs), arguments(arguments) {
		if (graphs == 5 || arguments == 3) { setMark(5); };
	};

	virtual void setInfo(int num, int works, int pages, string surname)override;

	int getGraphs();
	int getArguments();

	void setGraphs(int graphs);
	void setArguments(int arguments);

	virtual void printInfo()const override;

private:
	int graphs;
	int arguments;
};

