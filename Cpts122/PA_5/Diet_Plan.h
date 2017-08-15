#pragma once
#include "header.h"
using namespace std;

class Diet_Plan
{
public:
	Diet_Plan();
	~Diet_Plan();
	Diet_Plan(string n, int g, string d);
	Diet_Plan(const Diet_Plan &copy_Plan);
	void set_Goal(int gl);
	 int get_Goal() const;
	 void edit_Plan();
	 void set_Date(string D);
	 string get_Date() const;
	 void set_Name(string N);
	 string get_Name() const;
private:
	int goal = 0 ;
	std::string name;
	std::string date;

};

ofstream & operator<<(ofstream & os, const Diet_Plan & instance);
ifstream & operator >>(ifstream &is, Diet_Plan & instance);
ostream & operator<<(ostream & os, const Diet_Plan & instance);
