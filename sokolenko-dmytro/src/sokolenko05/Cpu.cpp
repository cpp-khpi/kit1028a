#include "Cpu.h"

string Cpu::getTitle() const { return title; }
void Cpu::setTitle(string newTtitle) { title = newTtitle; }

unsigned int Cpu::getCoresNumber() const { return coresNumber; }
void Cpu::setCoresNumber(unsigned int newCoresNumber) { coresNumber = newCoresNumber; }

unsigned int Cpu::getFrequency() const { return frequency; }
void Cpu::setFrequency(unsigned int newFrequency) { frequency = newFrequency; }

Cpu::Cpu() : title(""), coresNumber(0), frequency(0) {}

Cpu::Cpu(string newTitle,
	unsigned int newCoresNumber,
	unsigned int newFrequency) :
	title(newTitle),
	coresNumber(newCoresNumber),
	frequency(newFrequency) {}

Cpu::Cpu(const Cpu& copiedCpu) : 
	title(copiedCpu.title),
	coresNumber(copiedCpu.coresNumber),
	frequency(copiedCpu.frequency) {}

Cpu& Cpu::operator= (const Cpu& copiedCpu)
{
	if (this == &copiedCpu) {
		return *this;
	}

	title = copiedCpu.title;
	coresNumber = copiedCpu.coresNumber;
	frequency = copiedCpu.frequency;

	return *this;
}

bool Cpu::operator==(const Cpu& otherCpu) const
{
	bool isEqualTitle = this->title == otherCpu.title;
	bool isEqualCoresNumb = this->coresNumber == otherCpu.coresNumber;
	bool isEqualFrequen = this->frequency == otherCpu.frequency;

	if (isEqualTitle && isEqualCoresNumb && isEqualFrequen)
		return true;
	else
		return false;
}

Cpu::~Cpu() {}