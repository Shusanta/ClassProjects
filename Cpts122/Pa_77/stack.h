#pragma once
#pragma once
#include "node.h"
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>

class List
{
public:
	List() { pHead = nullptr; }
	~List();

	Node* get_Head() { return  pHead; }

	bool isempty();

	void insert(Node *& data);
	void make_Node();
	void destroylist();
	void printnodes();
	void markabscences();
	void populate_master();
	void generate_Report();
	void edit();
private:
	Node *pHead;

};

inline List::~List()
{
	destroylist();
}

void List::insert(Node *& data)
{
	if (pHead == nullptr)
		pHead = data;
	else
	{
		data->set_next(pHead);
		pHead = data;
	}
}

void List::make_Node()
{
	std::ifstream infile;

	infile.open("records.txt");
	std::string temp;
	std::string temp2;
	int i = 0;

	if (i == 9)
	{
		int z = 0;
	}

	std::getline(infile, temp);

	while ((std::getline(infile, temp, ',')))
	{

		//recordnumber,ID,Name,Email,Units,Program,Level
		Node *new_node = new Node();
		new_node->setrecordnumber(std::stoi(temp));
		(std::getline(infile, temp, ','));
		new_node->setid(std::stoi(temp));
		(std::getline(infile, temp, ','));
		(std::getline(infile, temp2, ','));
		temp2 = temp2.append(temp);
		new_node->set_Name(temp2);
		(std::getline(infile, temp, ','));
		new_node->set_Email(temp);
		(std::getline(infile, temp, ','));
		if (temp == "AU")
			temp = "0";
		new_node->setunits(stoi(temp));
		(std::getline(infile, temp, ','));
		new_node->set_Major(temp);
		(std::getline(infile, temp));
		new_node->set_Level(temp);

		insert(new_node);

		i++;
		std::cout << i << std::endl;
	}

	infile.close();
}

inline void List::destroylist()
{
	while (pHead)
	{
		Node * ptemp = pHead;
		pHead = pHead->getnext();
		delete(ptemp);
	}
	pHead = nullptr;
}

inline void List::printnodes()
{
	std::ofstream outfile;
	std::string temp;
	outfile.open("master.txt");
	if (isempty())
		std::cout << "its empty\n";
	else {
		//recordnumber,ID,Name,Email,Units,Program,Level
		Node *ptop = pHead;
		while (ptop)
		{
			outfile << ptop->getrecordnumber() << "," << ptop->getid() << "," << ptop->get_Name() << "," << ptop->get_Email() << "," << ptop->getunits() << "," << ptop->get_Major() << "," << ptop->get_Level() << ","<< ptop->get_Num_Of_Abscences() << ",";
			while (!ptop->isempty())
			{
				temp = ptop->pop();
				outfile << temp << " ";
			}
			outfile << "\n";
			ptop = ptop->getnext();
		}
	}
	outfile.close();
}

inline bool List::isempty()
{
	if (pHead == nullptr)
		return true;
	else
		return false;
}

inline void List::populate_master()
{
	std::string temp;
	int i = 0;
	std::ifstream infile;
	
	infile.open("master.txt");


	while ((std::getline(infile, temp, ',')))
	{
		//recordnumber,ID,Name,Email,Units,Program,Level
		Node *new_node = new Node();
		new_node->setrecordnumber(std::stoi(temp));
		(std::getline(infile, temp, ','));
		new_node->setid(std::stoi(temp));
		(std::getline(infile, temp, ','));
		new_node->set_Name(temp);
		(std::getline(infile, temp, ','));
		new_node->set_Email(temp);
		(std::getline(infile, temp, ','));
		if (temp == "AU")
			temp = "0";
		new_node->setunits(stoi(temp));
		(std::getline(infile, temp, ','));
		new_node->set_Major(temp);
		(std::getline(infile, temp, ','));
		new_node->set_Level(temp);
		std::getline(infile, temp, ',');
		new_node->set_abscences(std::stoi(temp));
		std::getline(infile, temp, '\n');
		std::stringstream ss(temp);
		while (ss)
		{
			int z = 0;
			std::string temp2;
			ss >> temp2;
			new_node->push(temp2);
			ss >> temp2;
		}
		insert(new_node);
		i++;
	}
	infile.close();
}

inline void List::markabscences()
{
	int i = 0;
	std::string month;
	std::string day;
	std::string year;

	time_t t = time(0);
	struct tm * now = localtime(&t);

	month = std::to_string(now->tm_mon + 1);
	    
	year = std::to_string(now->tm_year + 1900);

	day = std::to_string(now->tm_mday);

	month = month + "/" + day + "/" + year;

	Node *ptop = pHead;

	int choice = 0;
	
	std::cout << "Enter whether the student was here 0 for here, 1 for not \n";
	while (ptop)
	{
		std::cout <<"Was "<< ptop->get_Name() <<" here\n";
		std::cin >> choice;
		if (choice == 1)
		{
			ptop->push(month);
		}
		ptop = ptop->getnext();

	}
}

inline void List::generate_Report()
{
	int choice;
	Node *ptop = pHead;
	std::string temp;
	std::cout << "Enter 0 to show most recent abscence for each student with one \n and 1 to see which students are over a number of abscences \n";
		std::cin >> choice;
	switch (choice)
	{
	case 0:
		while (ptop)
		{
			if (ptop->get_Num_Of_Abscences() > 0)
			{
				temp = ptop->peek();
				std::cout << ptop->get_Name() << " " << temp <<"\n";
			}
			
			ptop = ptop->getnext();
		}
		break;
	case 1:
		std::cout << "enter the number of abscences\n";
		std::cin >> choice;
		while (ptop)
		{
			if (ptop->get_Num_Of_Abscences() >= choice)
			{
				std::cout << ptop->get_Name()<< "\n";
			}

			ptop = ptop->getnext();
		}

		
	}


}

inline void List::edit()
{
	int id;
	std::string date;
	std::cout << "Enter the students id you would like to change \n";
	std::cin >> id;
	std::cout << "Enter the date\n";
	std::cin >> date;
	Node *ptop = pHead;
	
	while (ptop)
	{
		if (ptop->getid() == id)
		{
			ptop->remove(date);
			ptop->pop();

		}
	}

}