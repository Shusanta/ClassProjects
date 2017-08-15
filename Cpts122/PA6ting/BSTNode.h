#pragma once
#ifndef BTNODE_

#define BTNODE_

#define START_ 0
#include <sstream>

#include <iostream>
template<typename Type>
class BSTNode
{

public:

	BSTNode(const Type& ldata, const Type& mdata, BSTNode<Type> *leftval = nullptr, BSTNode<Type> *rightval = nullptr) { letter = ldata; left = leftval; right = rightval;  morse = mdata; }
	Type getletter() { return letter; }
	Type getmorse() { return morse; }
	BSTNode*& getleft() { return left; }
	BSTNode*& getright() { return right; }
	virtual ~BSTNode();
private:
	Type letter;
	Type morse;
	BSTNode<Type> *left;
	BSTNode<Type> *right;
	// to string 
};
#endif

template<typename Type>
 BSTNode<Type>::~BSTNode()
{
}
