/**
* @file Phone.h
* Declaration Phone class.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.06.04
*/

#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;

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
	~Phone();

	/**
	* Overloaded assignment operator.
	* @param copiedPhone: its fields initialize fields current object.
	* @return pointer to current object.
	*/
	Phone& operator= (const Phone& copiedPhone);

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
	bool operator>(const Phone& otherPhone) const;

	/**
	* Overloaded comparison operator.
	* @param otherPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator<(const Phone& otherPhone) const;

	/**
	* Overloaded output operator.
	* @param out - reference to output stream.
	* @param outputPhone - reference to Phone object.
	* @return reference to output stream.
	*/
	friend ostream& operator<<(ostream& out, const Phone& outputPhone);

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
	* Get copy of field Phone::title.
	* @return current value Phone::title.
	*/
	string getTitle() const;

	/**
	* Assignment field value to Phone::title.
	* @param newTitle: initializes Phone::title.
	*/
	void setTitle(string newTitle);

	/**
	* Get copy of field Phone::price.
	* @return current value Phone::price.
	*/
	unsigned int getPrice() const;

	/**
	* Assignment field value to Phone::price.
	* @param newTitle: initializes Phone::price.
	*/
	void setPrice(unsigned int newPrice);

	/**
	* Get copy of field Phone::simCardsNumber.
	* @return current value Phone::simCardsNumber.
	*/
	unsigned int getSimCardsNumber() const;

	/**
	* Assignment field value to Phone::simCardsNumber.
	* @param newTitle: initializes Phone::simCardsNumber.
	*/
	void setSimCardsNumber(unsigned int newsimCardsNumber);

	/**
	* Get copy of field Phone::resolution.
	* @return current value Phone::resolution.
	*/
	unsigned int getResolution() const;

	/**
	* Assignment field value to Phone::resolution.
	* @param newTitle: initializes Phone::resolution.
	*/
	void setResolution(unsigned int newResolution);

	/**
	* Get copy of field Phone::capacity.
	* @return current value Phone::capacity.
	*/
	unsigned int getCapacity() const;

	/**
	* Assignment field value to Phone::capacity.
	* @param newTitle: initializes Phone::capacity.
	*/
	void setCapacity(unsigned int newCapacity);
};