#pragma once
#include "node.h"

//Next define a class TransactionNode, which publically inherits from abstract base class Node.Class TransactionNode must encapsulate the following :
//New Data members :
//-mUnits : int // - denotes private
//
//New Member functions :
//+destructor // + denotes public
//+ constructor which accepts a string to set the data and an integer to set the number of units in the node; should invoke class Node’s constructor
//+ setter
//+ getter
//+ printData(), which overrides the pure virtual function in class Node

class TransactionNode : public Node
{
public:
	TransactionNode(std::string data, int units) : Node(data) { mUnits = units;} //initializes everything
	~TransactionNode() {}
	void setUnits(int units) { mUnits = units; }
	int getUnits() { return mUnits; }
	void printData();


private:
	int mUnits = 0;
};

void TransactionNode::printData()
{
	std::cout << mUnits << std::endl;
}