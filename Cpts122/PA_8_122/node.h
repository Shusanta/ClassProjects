#pragma once
#include <iostream>

//+virtual destructor // + denotes public
//+ constructor which accepts a string to set the data in the node; each pointer in the node is set to NULL
//+ setters – one for each data member(3 total should be defined)
//+ getters – one for each data member(3 total should be defined, the 2 defined to get the pointers should return a reference to the pointer, i.e.Node *&)
//+ pure virtual printData() function, which must be overridden in class TransactionNode

//Data members :
//# mData : std::string // # denotes protected
//# mpLeft : Node *
//# mpRight : Node *
class Node
{
public:
	Node(std::string &data) { mData = data; mpLeft = nullptr; mpRight = nullptr; }
	void set_Data(std::string &data) { mData = data; }
	void set_Left(Node*data) { mpLeft = data; }
	void set_right(Node*data) { mpRight = data; }
	virtual void printData() = 0;
	std::string get_Data() { return mData; }
	Node *& get_Left() { return mpLeft; } // gets left
	Node *& get_Right() { return mpRight; } // gets right
	virtual ~Node() {}


protected:
	std::string mData;
	Node * mpLeft = nullptr;
	Node * mpRight= nullptr;
};