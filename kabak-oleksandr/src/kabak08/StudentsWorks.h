 /**
* @file StudentsWorks.h
* File assignment				| Header file with StudentsWorks class
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/

#include "EconomicTI.h"
#include "MathTI.h"
#include "Exception.h"

/**
* Ñlass stores information about the list of students, a temporary student who wants to join the group and the size of the current group
*/
class StudentsWorks
{
private:
	int SIZE;					// Group size
	TestsInfo *newStudent;	    // New Student
	TestsInfo **list;			// Group

public:
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param s initializes StudentsWorks::SIZE.
	*/
	StudentsWorks(string s);
	/**
	* InfoIndependentsWork class destructor.
	*/
	~StudentsWorks();

	/**
	* Class overload methods
	*/
	friend ostream& operator<< (ostream& out, const StudentsWorks& o);
	friend istream& operator>> (istream& in, StudentsWorks& o);
	TestsInfo& operator[](int index);

	/**
	* Method that fills in information about a new student.
	*/
	void setNewStud(string s);

	/**
	* Getter SIZE.
	*/
	int getSIZE();

	void writeToFile();

	void infoWorks(const int num);

	/**
	* Methods add/remove students in/from list.
	*/
	void addStud(const int num);
	void removeStud(const int num);

	/**
	* Sorting methods
	*/
	void sortMarkStud (bool(*comp)(int x, int y));
	void sortNumStud  (bool(*comp)(int x, int y));
	void sortWorksStud(bool(*comp)(int x, int y));
	void sortPageStud (bool(*comp)(int x, int y));

	/**
	* Methods to display information on the screen.
	*/
	void printStudIndex(const int num)const;   //Print info about student by ID
	void printNewStud();
	void printAll()const;
	void printAll2()const;			  //display students who have 2 words in the *surname* field
};

