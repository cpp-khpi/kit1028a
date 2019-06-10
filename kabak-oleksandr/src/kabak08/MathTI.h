/**
* @file MathTI.h
* File assignment				| Header file with MathTI class(class heir TestsInfo)
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/
#include "TestsInfo.h"

/**
* Stores information about the works, their number, the average number of pages, evaluation and surname + availability of graphics and arguments
*/
class MathTI :
	public TestsInfo
{
public:
	/**
	* MathTI class constructors.
	*/
	MathTI() : TestsInfo(), graphs(0), arguments(0) {};
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param num       initializes  TestsInfo::num.
	* @param works     initializes  TestsInfo::works.
	* @param pages     initializes  TestsInfo::pages.
	* @param surname   initializes  TestsInfo::surname.
	* @param graphs    initializes  MathTI::graphs.
	* @param arguments initializes  MathTI::arguments.
	*/
	MathTI(int num, int works, int pages, string surname, int graphs, int arguments) : TestsInfo(num, works, pages, surname), graphs(graphs), arguments(arguments) {
		if (graphs == 5 || arguments == 3) { setMark(5); };
	};
	~MathTI() {};

	/**
	* MathTI redefinition of TestsInfo class overloads.
	*/
	MathTI& operator = (const MathTI& o);
	bool operator == (const MathTI& o);
	friend ostream& operator << (ostream& os, const MathTI& o);
	friend istream& operator >> (istream& is, MathTI& o);
	
	/**
	* Redefined virtual function fill information
	*/
	virtual void setInfo(int num, int works, int pages, string surname)override;

	virtual void outputToFile(ofstream& file) override;

	/**
	* Redefined virtual function to print info about object
	*/
	virtual void printInfo()const override;


	/**
	* Getters and setters.
	*/
	int getGraphs();
	int getArguments();
	void setGraphs(int graphs);
	void setArguments(int arguments);


private:
	int graphs;		//number of graphs in work
	int arguments;	//number of arguments in work
};

