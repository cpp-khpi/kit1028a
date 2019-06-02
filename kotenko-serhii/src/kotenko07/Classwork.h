#pragma once

#include "InfoIndependentsWork.h"
class Classwork : public InfoIndependentsWork {
private:
	int classwork_count;
public:
	Classwork();
	Classwork(int amount, int written, int mark, std::string person, int classwork_count);
	Classwork(const Classwork &obj);

	int get_classwork();
	virtual void generation_values(std::string s) override;
	void set_data(int classwork_count, int amount, int written, int mark, std::string person);
	virtual void input() override;
	virtual void output() override;
	virtual void output_to_file(std::ofstream& file) override;

	~Classwork();
};


