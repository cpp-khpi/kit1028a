#pragma once
#include "Textbook.h"

class Grammarway : public Textbook {
private:
	int difficulty;
public:
	Grammarway();
	Grammarway(int num, int pages, int grade, int cost, int year_of_release, string author, int difficulty);
	Grammarway(const Grammarway &obj);
	~Grammarway();

	int getDifficulty();
	virtual void getInfo(string sur) override;
	void setData(int num, int pages, int grade, int cost, int year_of_release, string author, int difficulty);
	virtual void input() override;
	virtual void output() override;
	virtual void output_to_file(ofstream& file) override;
};
