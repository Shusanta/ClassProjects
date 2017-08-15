#pragma once
#pragma once

#include <iostream>

class Node
{

public:
	Node() { pNext = nullptr; }

	~Node() {}
	int getrecordnumber() { return recordnumber; }
	int getid() { return id; }
	int get_Num_Of_Abscences() { return numofabscences; }
	int getunits() { return units; }
	std::string get_Abscence_d8() { return abscences[0]; }
	Node * getnext() { return pNext; }

	std::string get_Name() { return name; }
	std::string get_Email() { return email; }
	std::string get_Major() { return major; }
	std::string get_Level() { return level; }

	void setrecordnumber(const int data) { recordnumber = data; }
	void setid(const int id) { this->id = id; }
	void set_Name(const std::string &data) { name = data; }
	void set_Email(const std::string &data) { email = data; }
	void set_Major(const std::string &data) { major = data; }
	void set_Level(const std::string &data) { level = data; }
	void set_next(Node*& pnext) { this->pNext = pnext; }
	void set_abscences(int n) { numofabscences = n; }
	void setunits(const int data) { units = data; }
	void edit_Abscences();
	void push(std::string data);
	void remove(std::string date);

	bool isempty();

	std::string peek();
	std::string pop();

private:
	int recordnumber = 0;
	int id = 0;
	std::string name;
	std::string email;
	int units = 0;
	std::string major;
	std::string level;

	std::string abscences[100];

	int msize = 0;

	int totsize = 100;

	int numofabscences = 0;

	Node  *pNext = nullptr;
};

void Node::edit_Abscences()
{

}

inline void Node::push(std::string data)
{

	abscences[msize] = data;
	msize++;
	numofabscences++;
}

inline std::string Node::pop()
{
	if (!isempty())
	{
		msize--;
		return abscences[msize];

	}
	else
	{
		return "\0";
	}

}

inline bool Node::isempty()
{
	if (msize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline std::string Node::peek()
{
	return abscences[msize - 1];
}

void Node::remove(std::string date)
{
	for (int i = 0; i < msize; i++)
	{
		if (abscences[i] == date)
		{
			std::string temp = abscences[i + 1];
			abscences[i + 1] = abscences[i];
			abscences[i] = temp;
		}
	}
}