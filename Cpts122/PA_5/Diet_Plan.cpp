#include "Diet_Plan.h"

using namespace std;



Diet_Plan::Diet_Plan()
{
}


Diet_Plan::~Diet_Plan()
{
}

Diet_Plan::Diet_Plan(string n, int g, string d)
{
	name = n;
	goal = g;
	date = d;
}

Diet_Plan::Diet_Plan(const Diet_Plan & copy_Plan)
{
	goal = copy_Plan.get_Goal();
	name = copy_Plan.get_Name();
	date = copy_Plan.get_Date();
}


 void Diet_Plan::set_Goal(int gl)
{
	 goal = gl;
}

  int Diet_Plan::get_Goal() const
{
	return goal;
}

  void Diet_Plan::edit_Plan()
  {
	  int a = 0;
	  cout<<"enter what you want to set your new goal to \n";
	  cin >> a;
	  cout << "your new goal for calories is" << a << endl;
  }

  void Diet_Plan::set_Date(string D)
  {
	  date = D;
  }

  string Diet_Plan::get_Date() const
  {
	  return date;
  }

  void Diet_Plan::set_Name(string N)
  {
	  name = N;
  }

  string Diet_Plan::get_Name() const
  {
	  return name;
  }

  ostream & operator<<(ostream & os, const Diet_Plan & instance)
  {
	  os << instance.get_Name() << "\n" << instance.get_Goal() << "\n" << instance.get_Date() << "\n" << endl;
	  return os;
  }

  ofstream & operator <<(ofstream & os, const Diet_Plan & instance)
  {
	  os << instance.get_Name() << "\n" << instance.get_Goal() << "\n" << instance.get_Date() << "\n" << endl;
	  return os;
  }

  ifstream & operator >> (ifstream &is, Diet_Plan & instance)
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
 