#pragma once
#include "header.h"
class Excericise_Plan
{
public:
	Excericise_Plan();
	~Excericise_Plan();
	Excericise_Plan(string n, int g, string d);
	Excericise_Plan(const Excericise_Plan &copy_Plan);
	void set_Date(string D);
	string get_Date() const; 
	void set_Name(string D);
	string get_Name() const;
	void set_Goal(int gl);
	int get_Goal() const;
	void edit_Plan();
private:
	int goal = 0;
	std::string name;
	std::string date;
};


ofstream& operator <<(ofstream& os, const Excericise_Plan& instance);
ifstream& operator >>(ifstream& os, Excericise_Plan& instance);
ostream& operator <<(ostream& os, const Excericise_Plan& instance);
