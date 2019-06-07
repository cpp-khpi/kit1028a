/**
* @file IosPhone.h
* Declaration IosPhone class.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.06.06
*/

#pragma once

#include "Phone.h"

/**
* Declaration IosPhone class with fields and methods.
* Used Javadoc style comments to handle Doxygen.
*/
class IosPhone : public Phone {
private:
	/** Company-manufacturer name. */
	const string manufacturer = "Apple";
	/** Ios version. */
	float iosVersion;
public:
	/**
	* Default constructor
	* Used initialization lists.
	*/
	IosPhone();

	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param newTitle initializes IosPhone::title.
	* @param newPrice initializes IosPhone::price.
	* @param newSimNum initializes IosPhone::simCardsNumber.
	* @param newResolution initializes IosPhone::resolution.
	* @param newCapacity initializes IosPhone::capacity.
	* @param newIosVersion initializes IosPhone::iosVersion.
	*/
	IosPhone(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		float newIosVersion);

	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param copiedPhone: its fields initialize fields current object.
	*/
	IosPhone(const IosPhone& copiedPhone);

	/**
	* Destructor.
	*/
	virtual ~IosPhone() override;

	/**
	* Overloaded comparison operator.
	* @param otherIosPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator==(const IosPhone& otherPhone) const;

	/**
	* Overloaded comparison operator.
	* @param otherIosPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator!=(const IosPhone& otherPhone) const;

	/**
	* Overloaded comparison operator.
	* @param otherIosPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator==(const IosPhone* otherPhone) const;

	/**
	* Overloaded comparison operator.
	* @param otherIosPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator!=(const IosPhone* otherPhone) const;

	/**
	* Overloaded input operator.
	* @param in - reference to input stream.
	* @param inputPhone - reference to Phone object.
	* @return reference to input stream.
	*/
	friend istream& operator>>(istream& in, IosPhone& inputPhone);

	/**
	* Overloaded input operator.
	* @param in - reference to input stream.
	* @param inputPhone - reference to Phone object.
	* @return reference to input stream.
	*/
	friend istream& operator>>(istream& in, IosPhone* inputPhone);

	/**
	* Overloaded output operator.
	* @param out - reference to output stream.
	* @param outputPhone - reference to Phone object.
	* @return reference to output stream.
	*/
	friend ostream& operator<<(ostream& out, const IosPhone& outputPhone);

	/**
	* Overloaded output operator.
	* @param out - reference to output stream.
	* @param outputPhone - reference to Phone object.
	* @return reference to output stream.
	*/
	friend ostream& operator<<(ostream& out, const IosPhone* outputPhone);

	/**
	* Assignment to object new field value.
	* @param newTitle initializes Phone::title.
	* @param newPrice initializes Phone::price.
	* @param newSimNum initializes Phone::simCardsNumber.
	* @param newResolution initializes Phone::resolution.
	* @param newCapacity initializes Phone::capacity.
	* @param newIosVersion initializes IosPhone::iosVersion.
	*/
	void setPhoneInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		float newIosVersion);

	/**
	* Reading from the console and filling in the fields of the Phone object.
	*/
	virtual void input() override;

	/**
	* Converting information about the current object to a string.
	* @return a line with information about the current object.
	*/
	virtual string phoneToString() const override;

	/**
	* Fill the fields of the current object with
	* information contained in the line.
	* @param phoneString - the source line with information about the object.
	*/
	virtual void stringToPhone(const string phoneString) override;

	/**
	* Get copy of field IosPhone::manufacturer.
	* @return current value IosPhone::manufacturer.
	*/
	string getManufacturer() const;

	/**
	* Set the value of the variable IosPhone::iosVersion.
	* @param newIosVersion is assigned the IosPhone::iosVersion field.
	*/
	void setIosVersion(float newIosVersion);

	/**
	* Get copy of field IosPhone::iosVersion.
	* @return current value IosPhone::iosVersion.
	*/
	float getIosVersion() const;
};