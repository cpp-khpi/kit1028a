/**
* @file Phone.h
* Declaration Phone class.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.06.06
*/

#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;
using std::ostream;
using std::istream;
using std::regex;
using std::regex_match;
using std::regex_search;

/**
* Declaration Phone class with fields and methods.
* Used Javadoc style comments to handle Doxygen.
*/
class Phone {
protected:
	/** Phone title. */
	string title;
	/** Phone price. */
	unsigned int price;
	/** Phone sim-cards number. */
	unsigned int simCardsNumber;
	/** Phone screen resolution. */
	unsigned int resolution;
	/** Phone battery capacity. */
	unsigned int capacity;
public:
	/**
	* Default constructor
	* Used initialization lists.
	*/
	Phone();

	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param newTitle initializes Phone::title.
	* @param newPrice initializes Phone::price.
	* @param newSimNum initializes Phone::simCardsNumber.
	* @param newResolution initializes Phone::resolution.
	* @param newCapacity initializes Phone::capacity.
	*/
	Phone(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity);

	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param copiedPhone: its fields initialize fields current object.
	*/
	Phone(const Phone& copiedPhone);

	/**
	* Destructor.
	*/
	virtual ~Phone();

	/**
	* Overloaded comparison operator.
	* @param otherPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator==(const Phone& otherPhone) const;

	/**
	* Overloaded comparison operator.
	* @param otherPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator!=(const Phone& otherPhone) const;

	/**
	* Overloaded comparison operator.
	* @param otherPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator==(const Phone* otherPhone) const;

	/**
	* Overloaded comparison operator.
	* @param otherPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator!=(const Phone* otherPhone) const;

	/**
	* Overloaded input operator.
	* @param in - reference to input stream.
	* @param inputPhone - reference to Phone object.
	* @return reference to input stream.
	*/
	friend istream& operator>>(istream& in, Phone& inputPhone);

	/**
	* Overloaded input operator.
	* @param in - reference to input stream.
	* @param inputPhone - reference to Phone object.
	* @return reference to input stream.
	*/
	friend istream& operator>>(istream& in, Phone* inputPhone);

	/**
	* Overloaded output operator.
	* @param out - reference to output stream.
	* @param outputPhone - reference to Phone object.
	* @return reference to output stream.
	*/
	friend ostream& operator<<(ostream& out, const Phone& outputPhone);

	/**
	* Overloaded output operator.
	* @param out - reference to output stream.
	* @param outputPhone - reference to Phone object.
	* @return reference to output stream.
	*/
	friend ostream& operator<<(ostream& out, const Phone* outputPhone);

	/**
	* Assignment to object new field value.
	* @param newTitle initializes Phone::title.
	* @param newPrice initializes Phone::price.
	* @param newSimNum initializes Phone::simCardsNumber.
	* @param newResolution initializes Phone::resolution.
	* @param newCapacity initializes Phone::capacity.
	*/
	void setPhoneInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity);

	/**
	* A method that checks the string for correctness using regular expressions.
	* @param checkString - the checked string.
	* @return the status of the correct line.
	*/
	bool isCorrectCheckRegex(string& checkString) const;

	/**
	* Reading from the console and filling in the fields of the Phone object. 
	*/
	virtual void input() = 0;

	/**
	* Converting information about the current object to a string.
	* @return a line with information about the current object.
	*/
	virtual string phoneToString() const = 0;

	/**
	* Fill the fields of the current object with
	* information contained in the line.
	* @param phoneString - the source line with information about the object.
	*/
	virtual void stringToPhone(const string phoneString) = 0;
	
	/**
	* Set the value of the variable Phone::title.
	* @param newTitle is assigned the Phone::title field.
	*/
	void setTitle(string newTitle);

	/**
	* Get copy of field Phone::title.
	* @return current value Phone::title.
	*/
	string getTitle() const;

	/**
	* Set the value of the variable Phone::price.
	* @param newPrice is assigned the Phone::title field.
	*/
	void setPrice(unsigned int newPrice);

	/**
	* Get copy of field Phone::price.
	* @return current value Phone::price.
	*/
	unsigned int getPrice() const;

	/**
	* Set the value of the variable Phone::simCardsNumber.
	* @param newSimCardsNumber is assigned the Phone::simCardsNumber field.
	*/
	void setSimCardsNumber(unsigned int newSimCardsNumber);

	/**
	* Get copy of field Phone::simCardsNumber.
	* @return current value Phone::simCardsNumber.
	*/
	unsigned int getSimCardsNumber() const;

	/**
	* Set the value of the variable Phone::resolution.
	* @param newCapacity is assigned the Phone::resolution field.
	*/
	void setResolution(unsigned int newCapacity);

	/**
	* Get copy of field Phone::resolution.
	* @return current value Phone::resolution.
	*/
	unsigned int getResolution() const;


	/**
	* Set the value of the variable Phone::capacity.
	* @param newCapacity is assigned the Phone::capacity field.
	*/
	void setCapacity(unsigned int newCapacity);

	/**
	* Get copy of field Phone::capacity.
	* @return current value Phone::capacity.
	*/
	unsigned int getCapacity() const;
};