#pragma once
#include "TransactionNode.h"
#include <string>

class BST 
{
public:
	BST() { mpRoot = nullptr;}
	~BST();
	void setroot(Node*& data) { mpRoot = data;}
	Node*& getroot() { return mpRoot;}
	void insert(std::string mdata,int mUnits);
	void inorder();
	TransactionNode & find_Smallest();
	TransactionNode & find_Largest();
	bool isempty();

private:
	Node * mpRoot = nullptr;
	void insert(std::string mdata, int mUnits,Node*& root);
	void inorder(Node*& root);
	void delete_Nodes(Node*& mpRoot);
};

void BST::insert(std::string mdata, int mUnits) // public
{
	insert(mdata, mUnits, mpRoot);
}

inline void BST::insert(std::string mdata, int mUnits, Node *& root) //private
{
	if (root == nullptr)
	{
		 Node *temp = new TransactionNode(mdata, mUnits); //instantiates node

		 root = temp;

	}
	
	if ( mUnits> (dynamic_cast<TransactionNode*>(root))->getUnits()) //inserts
	{
		insert(mdata, mUnits, root->get_Right());
	}

	if (mUnits < (dynamic_cast<TransactionNode*>(root))->getUnits()) //inserts
	{
		insert(mdata, mUnits, root->get_Left());
	}
}

inline TransactionNode & BST::find_Smallest() //gets smallest
{
	auto *temp = this->getroot();
	if (!isempty())
	{
		while (temp->get_Left() != nullptr) //goes to end
		{
			temp = temp->get_Left();
		}

		return *(dynamic_cast<TransactionNode*>(temp));
	}
}

inline bool BST::isempty() //checks if empty
{
	if (mpRoot == nullptr)
		return true;
	else
	return false;
}
inline TransactionNode & BST::find_Largest() //goes most right
{
	Node *temp = this->getroot();
	if (!isempty())
	{
		while (temp->get_Right() != nullptr)
		{
			temp = temp->get_Right();
		}
	}
	return *(dynamic_cast<TransactionNode*>(temp));
}
inline void BST::inorder()
{
	inorder(mpRoot);	
}

inline void BST::inorder(Node *& root) //traverses in order
{
	if (root != nullptr)
	{
		
		inorder(root->get_Left());
		std::cout << root->get_Data() << " " << (dynamic_cast<TransactionNode*>(root))->getUnits() << "\n";
		inorder(root->get_Right());
	}

}

inline void BST::delete_Nodes(Node*& mProot) //deletes node for each tree
{
	
	if(mProot!=nullptr)
	{
		delete_Nodes(mProot->get_Left());
		delete_Nodes(mProot->get_Right()); 
		delete(mProot);
	}
}

inline BST::~BST() //calls delete
{
	delete_Nodes(mpRoot);
}