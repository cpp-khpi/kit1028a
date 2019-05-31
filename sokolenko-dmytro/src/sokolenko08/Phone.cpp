#include "Phone.h"

Phone::Phone() : 
	title(""), 
	price(0), 
	simCardsNumber(0), 
	resolution(0), 
	capacity(0) {}

Phone::Phone(string newTitle,
	unsigned int newPrice,
	unsigned int newSimNum,
	unsigned int newResolution,
	unsigned int newCapacity) :
	title(newTitle),
	price(newPrice),
	simCardsNumber(newSimNum),
	resolution(newResolution),
	capacity(newCapacity) {}

Phone::Phone(const Phone & copiedPhone) : 
	title(copiedPhone.title),
	price(copiedPhone.price),
	simCardsNumber(copiedPhone.simCardsNumber),
	resolution(copiedPhone.resolution),
	capacity(copiedPhone.capacity) {}

Phone::~Phone() {}

Phone& Phone::operator= (const Phone & copiedPhone)
{
	if (this == &copiedPhone) {
		return *this;
	}

	setPhoneInfo(copiedPhone.title,
		copiedPhone.price,
		copiedPhone.simCardsNumber,
		copiedPhone.resolution,
		copiedPhone.capacity);

	return *this;
}

bool Phone::operator==(const Phone& otherPhone) const
{
	bool isEqualTitle = this->title == title;
	bool isEqualPrice = this->price == otherPhone.price;
	bool isEqualSimNumb = this->simCardsNumber == otherPhone.simCardsNumber;
	bool isEqualResol = this->resolution == otherPhone.resolution;
	bool isEqualCapac = this->capacity == otherPhone.capacity;

	if (isEqualTitle && 
		isEqualPrice && 
		isEqualSimNumb && 
		isEqualResol && 
		isEqualCapac)
		return true;
	else
		return false;
}

istream& operator>>(istream& in, Phone& inputPhone)
{
	getline(in, inputPhone.title, '|');
	inputPhone.title.erase(inputPhone.title.end() - 1);
	in.ignore(1);

	in >> inputPhone.price;
	in.ignore(3);

	in >> inputPhone.simCardsNumber;
	in.ignore(3);

	in >> inputPhone.resolution;
	in.ignore(3);

	in >> inputPhone.capacity;

	return in;
}

ostream& operator<<(ostream& out, const Phone& outputPhone)
{
	out << outputPhone.title << " | " << outputPhone.price << " | " << outputPhone.simCardsNumber <<
		" | " << outputPhone.resolution << " | " << outputPhone.capacity;

	return out;
}

void Phone::setPhoneInfo(string newTitle, 
	unsigned int newPrice, 
	unsigned int newSimNum,
	unsigned int newResolution, 
	unsigned int newCapacity)
{
	title = newTitle;
	price = newPrice;
	simCardsNumber = newSimNum;
	resolution = newResolution;
	capacity = newCapacity;
}

void Phone::input()
{
	cout << "Enter information about phone." << endl;

	rewind(stdin);
	cout << "Phone title: ";
	getline(cin, title);

	rewind(stdin);
	cout << "Cost, UAN: ";
	cin >> price;

	rewind(stdin);
	cout << "Number of SIM-cards: ";
	cin >> simCardsNumber;

	rewind(stdin);
	cout << "Screen resolution, pixeles: ";
	cin >> resolution;

	rewind(stdin);
	cout << "Batery capacity, mAh: ";
	cin >> capacity;
}

void Phone::setTitle(string newTitle) { title = newTitle; }
string Phone::getTitle() const { return title; }

void Phone::setPrice(unsigned int newPrice) { price = newPrice; }
unsigned int Phone::getPrice() const { return price; }

void Phone::setSimCardsNumber(unsigned int newsimCardsNumber) { simCardsNumber = newsimCardsNumber; }
unsigned int Phone::getSimCardsNumber() const { return simCardsNumber; }

void Phone::setResolution(unsigned int newResolution) { resolution = newResolution; }
unsigned int Phone::getResolution() const { return resolution; }

void Phone::setCapacity(unsigned int newCapacity) { capacity = newCapacity; }
unsigned int Phone::getCapacity() const { return capacity; }