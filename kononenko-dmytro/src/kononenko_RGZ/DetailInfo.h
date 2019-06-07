/**
* @file DetailInfo.h
* Declaration of DetailInfo class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/

#pragma once
#include "InfoWork.h"

class DetailInfo : public InfoWork
{
private:
	int novelty;///< novelty of student`s work presented in years
public:
	/**
	* Overloaded comparison operator.
	* @param obj its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator== (const DetailInfo &obj);
	/**
	* Overloaded comparison operator.
	* @param obj: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator!= (const DetailInfo &obj);
	/**
	* Overloaded assignment operator.
	* @param obj: its fields initialize fields current object.
	* @return pointer to current object.
	*/
	DetailInfo& operator= (const DetailInfo &obj);
	/**
	* Overloaded output operator.
	* @param out - reference to output stream.
	* @param obj - reference to DetailInfo object.
	* @return reference to output stream.
	*/
	friend ostream& operator<< (ostream &out, const DetailInfo &obj);
	/**
	* Overloaded input operator.
	* @param in - reference to input stream.
	* @param obj - reference to DetailInfo object.
	* @return reference to input stream.
	*/
	friend istream& operator>> (istream &in, DetailInfo &obj);
	/**
	* Get copy of field DetailInfo::novelty.
	* @return current value DetailInfo::novelty.
	*/
	int getNovelty();
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
	* @param novelty is assigned the DetailInfo::novelty field.
	*/
	void set_data(int pages, int mark, int type,string name, int novelty);
	/**
	* Virtual function to generate values.
	*/
	virtual void set(string x);
	/**
	* Virtual data entry and output functions and file recording.
	*/
	virtual void input() override;
	virtual void output() override;
	virtual void output_to_file(std::ofstream& file) override;
	/**
	* Default constructor
	* Used initialization lists.
	*/
	DetailInfo();
	/**
    * Copie-constructor.
    * Used initialization lists.
    * @param obj: its fields initialize fields current object.
    */
	DetailInfo(const DetailInfo &obj);
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param size initializes InfoWork::pages.
	* @param points initializes InfoWork::mark.
	* @param type initializes InfoWork::type.
	* @param creator initializes InfoWork::name.
	* @param creator initializes CourseWork::novelty.
	*/
	DetailInfo(int pages, int mark, int type, string name, int novelty);
	/**
	* Destructor.
	*/
	~DetailInfo();
};