/**
* @file CourseWork.h
* Declaration of CourseWork class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/
#pragma once
#include "InfoWork.h"

class CourseWork : public InfoWork
{
private:
	int sizeOfLabor; ///< size of labor which student did
public:
	/**
	* Default constructor
	* Used initialization lists.
	*/
	CourseWork();
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param size initializes CourseWork::pages.
	* @param points initializes CourseWork::mark.
	* @param type initializes CourseWork::type.
	* @param creator initializes CourseWork::name.
	@param creator initializes CourseWork::sizeOfLabor.
	*/
	CourseWork(int pages,int mark,int type,string name,int sizeOfLabor);
	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param obj: its fields initialize fields current object.
	*/
	CourseWork(const CourseWork &obj);	
	/**
	* Destructor.
	*/
	~CourseWork();
	/**
	* Overloaded comparison operator.
	* @param obj its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator== (const CourseWork &obj);
	/**
	* Overloaded comparison operator.
	* @param obj its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator!= (const CourseWork &obj);
	/**
	* Overloaded assignment operator.
	* @param obj: its fields initialize fields current object.
	* @return pointer to current object.
	*/
	CourseWork& operator= (const CourseWork &obj);
	/**
	* Overloaded output operator.
	* @param out - reference to output stream.
	* @param obj - reference to CourseWork object.
	* @return reference to output stream.
	*/
	friend ostream& operator<< (ostream &out, const CourseWork &obj);
	/**
	* Overloaded input operator.
	* @param in - reference to input stream.
	* @param obj - reference to CourseWork object.
	* @return reference to input stream.
	*/
	friend istream& operator>> (istream &in, CourseWork &obj);

	/**
	* Get copy of field DetailInfo::novelty.
	* @return current value DetailInfo::novelty.
	*/
	int getSizeOfLabor();
	/**
	* Virtual function to generate values.
	*/
	virtual void set(string s) override;
	/**
	* Set the value of the variable DetailInfo::pages.
	* Set the value of the variable DetailInfo::mark.
	* Set the value of the variable DetailInfo::type.
	* Set the value of the variable DetailInfo::name.
	* Set the value of the variable DetailInfo::novelty.
	* @param pages is assigned the DetailInfo::pages field.
	* @param mark is assigned the DetailInfo::mark field.
	* @param type is assigned the DetailInfo::type field.
	* @param name is assigned the DetailInfo::name field.
	* @param sizeOfLabor is assigned the DetailInfo::sizeOfLabor field.
	*/
	void set_data(int pages, int mark, int type, string name, int sizeOfLabor);
	/**
	 * Virtual data entry and output functions and file recording.
	*/
	virtual void input() override;
	virtual void output() override;
	virtual void output_to_file(std::ofstream& file) override;
};