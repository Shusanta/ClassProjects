#pragma once
#include "header.h"
#include "List.h"
#include "listNode.h"
#include "Diet_Plan.h"
#include "Excericise_Plan.h"
#include <list>

class fitappwrapper
{

public:
	fitappwrapper();

	~fitappwrapper();
	void runapp(void);

	void loaddailyplan(ifstream & filestream, Diet_Plan &plan);
	void loaddailyplan(ifstream & filestream, Excericise_Plan &eplan);
	void loadWeeklyPlan(ifstream &fileStream, Excericise_Plan a[]);
	void loadWeeklyPlan(ifstream &fileStream, Diet_Plan a[]);
	void displaydailyplan(Diet_Plan &a);
	void displaydailyplan(Excericise_Plan &a);
	void displayweeklyplan(Excericise_Plan a[]);
	void displayweeklyplan(Diet_Plan p[]);
	void storedailyplan(ofstream &filestream, Diet_Plan &a);
	void storedailyplan(ofstream &filestream, Excericise_Plan &a);
	void storeweeklyplan(Diet_Plan a[], ofstream &filestream);
	void storeweeklyplan(Excericise_Plan a[], ofstream &filestream);
	int displaymenu();
private:
	Diet_Plan dplan[7];

	Excericise_Plan eplan[7];
};
int fitappwrapper::displaymenu()
{
	int choice = 0;
	cout << "1.    Load weekly diet plan from file." << "\n" << "2.    Load weekly exercise plan from file." << "\n" << "3.    Store weekly diet plan to file." << "\n"
		<< "4.    Store weekly exercise plan to file." << "\n" << "5.    Display weekly diet plan to screen." << "\n" << "6.    Display weekly exercise plan to screen." << "\n"
		<< "7.    Edit daily diet plan. " << "\n" << " 8.    Edit daily exercise plan." << " 9.Exit" << "\n";

	cin >> choice;

	return choice;
}



inline fitappwrapper::fitappwrapper()
{
}

inline fitappwrapper::~fitappwrapper()
{
}

void fitappwrapper::runapp(void)
{
	int uno = 1;
	int choice = 0;

	ifstream dp;
	ifstream ep;
	ofstream dpo;
	ofstream epo;
	
	while (choice != 9)
	{
		choice = displaymenu();
		switch (choice)
		{

		case 1:

			dp.open("Diet.txt");

			loadWeeklyPlan(dp, dplan);

			dp.close();

			break;
		case 2:
			ep.open("Exercise.txt");

			loadWeeklyPlan(ep, eplan);
			ep.close();
			break;
		case 3:
			dp.open("Diet.txt");

			loadWeeklyPlan(dp, dplan);

			dp.close();

			break;
		case 4:
			epo.open("Exercise.txt");

			storeweeklyplan(eplan, epo);

			ep.close();

			break;

		case 5:
			displayweeklyplan(dplan);
			break;

		case 6:
			displayweeklyplan(eplan);
			break;

		case 7:
			dplan[uno].edit_Plan();
			break;

		case 8:
			eplan[uno].edit_Plan();
			break;

		case 9:
			exit(0);
			break;

		}
	}
}

inline void fitappwrapper::loaddailyplan(ifstream & filestream, Diet_Plan & plan)
{
	filestream >> plan;
}

inline void fitappwrapper::loaddailyplan(ifstream & filestream, Excericise_Plan & eplan)
{
	filestream >> eplan;
}

inline void fitappwrapper::loadWeeklyPlan(ifstream & fileStream, Excericise_Plan a[])
{
	for(int i = 0; i<7; i++)
	{
		loaddailyplan(fileStream, a[i]);
	}
}

inline void fitappwrapper::loadWeeklyPlan(ifstream & fileStream, Diet_Plan a[])
{
	for (int i = 0; i<7; i++)
	{
		loaddailyplan(fileStream, a[i]);
	}
}

inline void fitappwrapper::displaydailyplan(Diet_Plan & a)
{
	cout << a;
}

inline void fitappwrapper::displaydailyplan(Excericise_Plan & a)
{
	cout << a;
}

inline void fitappwrapper::displayweeklyplan(Excericise_Plan a[])
{
	for(int i = 0; i<7;i++)
	{
		displaydailyplan(a[i]);
	}
}

inline void fitappwrapper::displayweeklyplan(Diet_Plan p[])
{
	for (int i = 0; i<7; i++)
	{
		displaydailyplan(p[i]);
	}
}

inline void fitappwrapper::storedailyplan(ofstream & filestream, Diet_Plan & a)
{
	filestream << a;
}

inline void fitappwrapper::storedailyplan(ofstream & filestream, Excericise_Plan & a)
{
	filestream << a;
}

inline void fitappwrapper::storeweeklyplan(Diet_Plan a[], ofstream & filestream)
{
	for(int i = 0; i<7;i++)
	{
		storedailyplan(filestream, a[i]);
		
	}
}

inline void fitappwrapper::storeweeklyplan(Excericise_Plan a[], ofstream & filestream)
{
	for (int i = 0; i<7; i++)
	{
		storedailyplan(filestream, a[i]);

	}
}

