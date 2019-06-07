/**
* @file AndroidPhone.h
* Declaration AndroidPhone class.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.06.06
*/

#pragma once

#include "Phone.h"

/**
* Declaration AndroidPhone class with fields and methods.
* Used Javadoc style comments to handle Doxygen.
*/
class AndroidPhone : public Phone {
private:
	/** Company-manufacturer name. */
	string manufacturer;
	/** Is Android OS standard. */
	bool isStandardAndroid;
	/** Android version. */
	float androidVersion;
public:
	/**
	* Default constructor
	* Used initialization lists.
	*/ 
	AndroidPhone();

	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param newTitle initializes AndroidPhone::title.
	* @param newPrice initializes AndroidPhone::price.
	* @param newSimNum initializes AndroidPhone::simCardsNumber.
	* @param newResolution initializes AndroidPhone::resolution.
	* @param newCapacity initializes AndroidPhone::capacity.
	* @param newManufacturer initializes AndroidPhone::manufacturer.
	* @param newIsStandAndr initializes AndroidPhone::issStandardAndroid.
	* @param newAndroidVersion initializes AndroidPhone::androidVersion.
	*/
	AndroidPhone(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		string newManufacturer,
		bool newIsStandAndr,
		float newAndroidVersion);

	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param copiedPhone: its fields initialize fields current object.
	*/
	AndroidPhone(const AndroidPhone& copiedPhone);

	/**
	* Destructor.
	*/
	virtual ~AndroidPhone() override;

	/**
	* Assignment to object new field value.
	* @param newTitle initializes Phone::title.
	* @param newPrice initializes Phone::price.
	* @param newSimNum initializes Phone::simCardsNumber.
	* @param newResolution initializes Phone::resolution.
	* @param newCapacity initializes Phone::capacity.
	* @param newManufacturer initializes AndroidPhone::manufacturer,
	* @param newIsStandAndr initializes AndroidPhone::isStandardAndroid,
	* @param newAndroidVersion initializes AndroidPhone::androidVersion.
	*/
	void setPhoneInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		string newManufacturer,
		bool newIsStandAndr,
		float newAndroidVersion);

	/**
	* Overloaded comparison operator.
	* @param otherIosPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator==(const AndroidPhone& otherPhone) const;

	/**
	* Overloaded comparison operator.
	* @param otherIosPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator!=(const AndroidPhone& otherPhone) const;

	/**
	* Overloaded comparison operator.
	* @param otherIosPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator==(const AndroidPhone* otherPhone) const;

	/**
	* Overloaded comparison operator.
	* @param otherIosPhone: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator!=(const AndroidPhone* otherPhone) const;

	/**
	* Overloaded input operator.
	* @param in - reference to input stream.
	* @param inputPhone - reference to Phone object.
	* @return reference to input stream.
	*/
	friend istream& operator>>(istream& in, AndroidPhone& inputPhone);

	/**
	* Overloaded input operator.
	* @param in - reference to input stream.
	* @param inputPhone - reference to Phone object.
	* @return reference to input stream.
	*/
	friend istream& operator>>(istream& in, AndroidPhone* inputPhone);

	/**
	* Overloaded output operator.
	* @param out - reference to output stream.
	* @param outputPhone - reference to Phone object.
	* @return reference to output stream.
	*/
	friend ostream& operator<<(ostream& out, const AndroidPhone& outputPhone);

	/**
	* Overloaded output operator.
	* @param out - reference to output stream.
	* @param outputPhone - reference to Phone object.
	* @return reference to output stream.
	*/
	friend ostream& operator<<(ostream& out, const AndroidPhone* outputPhone);

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
	* Set the value of the variable AndroidPhone::manufacturer.
	* @param newManufacturer is assigned the AndroidPhone::manufacturer field.
	*/
	void setManufacturer(string newManufacturer);

	/**
	* Get copy of field AndroidPhone::manufacturer.
	* @return current value IosPhone::manufacturer.
	*/
	string getManufacturer() const;

	/**
	* Set the value of the variable AndroidPhone::isStandardAndroid.
	* @param newIsStandAndr is assigned the AndroidPhone::isStandardAndroid field.
	*/
	void setIsStandardAndroid(bool newIsStandAndr);

	/**
	* Get copy of field AndroidPhone::isStandardAndroid.
	* @return current value IosPhone::isStandardAndroid.
	*/
	bool getIsStandardAndroid() const;

	/**
	* Set the value of the variable AndroidPhone::androidVersion.
	* @param newAndroidVersion is assigned the AndroidPhone::androidVersion field.
	*/
	void setAndroidVersion(float newAndroidVersion);

	/**
	* Get copy of field AndroidPhone::androidVersion.
	* @return current value IosPhone::androidVersion.
	*/
	float getAndroidVersion() const;
};