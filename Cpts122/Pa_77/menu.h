#pragma once
#pragma once
#include "Stack.h"

class menu
{
public:
	menu() {};
	~menu() { };
	void opt();

private:
	List list;
};

int getoption()
{
	int z;
	std::cout << "Enter your option\n";
	std::cin >> z;
	return z;
}

void menu::opt()
{
	bool work = true;
	std::ifstream infile;
	while (work)
	{
		std::cout << "1. Import course list \n";
		std::cout << "2. Load master list \n ";
		std::cout << "3. Store master list \n";
		std::cout << "4. Mark abscences \n";
		std::cout << "5. BONUS: Edit abscences \n";
		std::cout << "6. generate report \n";
		std::cout << "7. exit \n";

		int choice = getoption();

		switch (choice)
		{
		case 1:
			infile.open("records.txt");
			list.make_Node(); // open the file in here.
			infile.close();
			break;
		case 2:
			list.destroylist();
			list.populate_master();
		
			break;
		case 3:
			list.printnodes();
			break;
		case 4:
			list.markabscences();
			break;
		case 5:
			break;
		case 6:
			list.generate_Report();
		case 7:
			work = false;
			break;

		}
	}
}