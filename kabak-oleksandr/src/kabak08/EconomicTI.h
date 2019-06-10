/**
* @file EconomicTI.h
* File assignment				| Header file with EconomicTI class(class heir TestsInfo)
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/
#include "TestsInfo.h"

/**
* Stores information about the works, their number, the average number of pages, evaluation and surname + availability of statistics and formuls
*/
class EconomicTI :
	public TestsInfo
{
public:
	/**
	* MathTI class constructors.
	*/
	EconomicTI() : TestsInfo(), statistics(0), formuls(0) {};
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param num     initializes  TestsInfo::num.
	* @param works   initializes  TestsInfo::works.
	* @param pages   initializes  TestsInfo::pages.
	* @param surname initializes  TestsInfo::surname.
	* @param stat    initializes  EconomicTI::statistics.
	* @param formuls initializes  EconomicTI::formuls.
	*/
	EconomicTI(int num, int works, int pages, string surname, int stat, int formuls) : TestsInfo(num, works, pages, surname), statistics(stat), formuls(formuls) {
		if (stat == 5 || formuls == 3) { setMark(5); };
	};
	~EconomicTI() {};

	/**
	* EconomicTI redefinition of TestsInfo class overloads.
	*/
	EconomicTI& operator = (const EconomicTI& o);
	bool operator == (const EconomicTI& o);
	friend ostream& operator << (ostream& os, const EconomicTI& o);
	friend istream& operator >> (istream& is, EconomicTI& o);

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
	int getStatistics();
	int getFormuls();
	void setStatistics(int statistics);
	void setFormuls(int formuls);

private:
	int statistics;	  //number of statistics in work
	int formuls;	  //the number of complex formulas in the work
};

