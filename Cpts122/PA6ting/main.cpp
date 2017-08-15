#include "BST.h"

int main(void)
{
	char a = 'a';
	std::ifstream infile;
	infile.open("wcon.txt");
	BST<std::string> b; // b as in binary tree
	
	b.assemble(); // makes tree;
	b.print_In_Order(b.getroot());
	b.convert(infile);

	infile.close();
}
