#pragma once

#include "BSTNode.h"

#include "fstream"

#include <string>



template<typename Type>
class BST
{
public:
	BST();

	virtual ~BST() { destroytree(this->getroot()); }
	virtual bool insert(const Type &letter, const Type &morse);

	void print_In_Order(BSTNode<Type>*&root);

	std::string find(BSTNode<Type>*& local_root,char a);

	void convert(std::ifstream & infile);
	BSTNode<Type>*& getroot();

	bool destroytree(BSTNode<Type>*& local_root);

	void assemble();
protected:
	BST(BSTNode<Type> * new_root): root(new_root) {}
	BSTNode<Type>*root;
	bool insert(BSTNode<Type>*&local_root, const Type &letter, const Type &morse);

};

template<typename Type>
BST<Type>::BST()
{
	root = nullptr;
}

template<typename Type>
 bool BST<Type>::insert(const Type & letter, const Type & morse)
{
	 return insert(root,letter, morse);
}
 template<typename Type>
//prints it 
 void BST<Type>::print_In_Order(BSTNode<Type>*& root)
 {
	 if(root == nullptr)
	 {
		 return;
	 }
	 print_In_Order(root->getleft());
	 std::cout << root->getletter() << "   " << root->getmorse() << "\n";
	 print_In_Order(root->getright());
 }

 template<typename Type>
//finds the character in the tree
 std::string BST<Type>::find(BSTNode<Type>*& local_root, char a)
 {
	 std::string temp;
	 temp[0] = a;

	 a = toupper(a);
 
	  if (a < local_root->getletter()[0])
		  return find(local_root->getleft(), a);
	  if (a >local_root->getletter()[0])
		  return find(local_root->getright(), a);
	  if (a == local_root->getletter()[0])
		  return (local_root->getmorse());
	  else
		  return temp;

	  
 }

 template<typename Type>
//converts letters in file to morse
 inline void BST<Type>::convert(std::ifstream & infile)
 {
	 std::ofstream of;
	 std::string temp;
	 of.open("Convert.txt");
	 while (std::getline(infile,temp))
	 {
		 for(int i = 0; i<temp.length();i++)
		 {
			 if (temp[i] == ' ')
				 of << " ";
			 else
			 of << find(root,temp[i]) <<" ";
		 }
	 }
	 
 }

 template<typename Type>
//returns root
  BSTNode<Type>*& BST<Type>::getroot()
 {
	 return root;
 }

  template<typename Type>
//destroys the tree
  bool BST<Type>::destroytree(BSTNode<Type>*& local_root)
  {
		  if (local_root == nullptr) return true;

		  
		  destroytree(local_root->getleft());
		  destroytree(local_root->getright());

		  /* then delete the node */
		  std::cout << "deleting " << local_root->getletter() << " \n";
		  delete(local_root);
		  
  }

  template<typename Type>
//makes the tree
  void BST<Type>::assemble()
  {
	   std::ifstream infile;
	   std::string tempL; //temporary line
	   std::string L; //letter
	   std::string Morse;
	   infile.open("decode.txt"); //reading from el file
	   while (true)
	   {
		   getline(infile, tempL); // gets line
		   L = toupper(tempL[0]);
		   if (infile.eof()) // if there is stuff to read
			   break;
		   Morse = tempL.substr(2, tempL.length());
		   insert(L, Morse);
	   }
	   infile.close();
  }

template<typename Type>
//inserts to file
bool BST<Type>::insert(BSTNode<Type>*&local_root, const Type &letter, const Type &morse)
{
	if(local_root == nullptr)
	{
		local_root = new BSTNode<Type>(letter, morse);
		return true;
	}
	else
	{
		if(letter > local_root->getletter())
		{
			return insert(local_root->getright(), letter, morse);
		}
		if(letter < local_root->getletter())
		{
			return insert(local_root->getleft(), letter, morse);
		}
		else
		{
			return false;
		}
	}
}



