#pragma once
#include "BST.h"
#include <fstream>

class DataAnalysis
{
public:
	DataAnalysis() {}
	~DataAnalysis();
	void run_Analysis();
	void return_data();

private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCSVstream;
	void open_File_Stream();
	void parse();

};

// does functions
void DataAnalysis::run_Analysis()
{
	open_File_Stream();

	parse();

	return_data();
}

inline void DataAnalysis::open_File_Stream()
{
	mCSVstream.open("data.txt");
}

inline void DataAnalysis::parse()
{
	std::string temp_Units; //stores unitss and type/brand in next line
	std::string temp_Type;
	std::string order; // whether purchased or sold
	getline(mCSVstream, temp_Units); //gets the first line

	while (getline(mCSVstream, temp_Units, ',')) //gets per comma
	{
		getline(mCSVstream, temp_Type, ',');

		getline(mCSVstream, order);

		if (order == "Purchased") //decides which tree
		{
			mTreePurchased.insert(temp_Type, stoi(temp_Units)); // converts string
		}
		else
		{
			mTreeSold.insert(temp_Type, stoi(temp_Units)); //inserts into other tree
		}
		
	}
}

inline DataAnalysis::~DataAnalysis()
{
	mCSVstream.close();
}

inline void DataAnalysis::return_data()
{
	TransactionNode mostPurchased = mTreePurchased.find_Largest();
	TransactionNode mostSold = mTreeSold.find_Largest();
	TransactionNode leastPurchased = mTreePurchased.find_Smallest();
	TransactionNode leastSold = mTreeSold.find_Smallest();

	std::cout << "PURCHASED";
	std::cout << "\n\n\n";

	mTreePurchased.inorder();

	std::cout << "\n\n\n";

	std::cout << "Sold";
	std::cout << "\n\n\n";

	mTreeSold.inorder();

	std::cout << "\n\n\n";
	

	std::cout << "most Purchased " << mostPurchased.get_Data() << " " << mostPurchased.getUnits() << "\n";
	std::cout << "most Sold" << mostSold.get_Data() << " " << mostSold.getUnits() << "\n";
	std::cout << "least Purchased " << leastPurchased.get_Data() << " " << leastPurchased.getUnits() << "\n";
	std::cout << "least Sold" << leastSold.get_Data() << " " << leastSold.getUnits() << "\n";


}