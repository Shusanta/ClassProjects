#include "Excericise_Plan.h"

Excericise_Plan::Excericise_Plan()
{
}
Excericise_Plan::~Excericise_Plan()
{
}

Excericise_Plan::Excericise_Plan(string n, int g, string d)
{
	name = n;
	goal = g;
	date = d;
}

Excericise_Plan::Excericise_Plan(const Excericise_Plan & copy_Plan)
{
	goal = copy_Plan.get_Goal();
	name = copy_Plan.get_Name();
	date = copy_Plan.get_Date();
}

void Excericise_Plan::set_Date(string D)
{
	date = D;
}

string Excericise_Plan::get_Date() const
{
	return date;
}

void Excericise_Plan::set_Name(string D)
{
	name = D;
}

string Excericise_Plan::get_Name() const
{
	return name;
}

void Excericise_Plan::set_Goal(int gl)
{
	goal = gl;
}

int Excericise_Plan::get_Goal() const
{
	return goal;
}

void Excericise_Plan::edit_Plan()
{
	int a = 0;
	cout << "enter what you want to set your new goal to \n";
	cin >> a;
	set_Goal(a);
	cout << "your new goal for steps is" << a << endl;
}

ostream & operator<<(ostream & os, const Excericise_Plan & instance)
{
	os << instance.get_Name() << "\n" << instance.get_Goal() << "\n" << instance.get_Date() << "\n"  << endl;
	return os;
}

ofstream & operator <<(ofstream & os, const Excericise_Plan & instance)
{
	os << instance.get_Name() << "\n" << instance.get_Goal() << "\n" << instance.get_Date() << "\n" << endl;
	return os;
}

ifstream & operator >> (ifstream &is, Excericise_Plan & instance)
{
	string cool;

	getline(is, cool);

	instance.set_Name(cool);

	int G = 0;

	is >> G;

	getline(is, cool);

	instance.set_Goal(G);

	getline(is, cool);

	instance.set_Date(cool);

	getline(is, cool);

	return is;
}

