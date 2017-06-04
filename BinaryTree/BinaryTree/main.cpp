#include <iostream>
#include <fstream>
#include <string>

#include "BinaryTree.h"

std::vector<std::string>* readTXTFile();

int main()
{
	/*
	BinaryTreeNode <std::string> *root = Insert(std::string("butt"));
	Insert(std::string("dick"), root);
	Insert(std::string("martin"), root);
	Insert(std::string("hat"), root);
	Insert(std::string("nose"), root);
	Insert(std::string("hello"), root);
	*/

	/*
	std::vector<int> dataVector = { 5,7,2,3,5,6,21,8 };
	BinaryTreeNode <int> *root = Insert(7);
	InsertFromVector(&dataVector, root);
	*/

	std::vector<std::string> *dataVector = readTXTFile();
	BinaryTreeNode <std::string> *root = Insert(std::string("n"));
	InsertFromVector(dataVector, root);

	PrintBST(root);

	std::cout << GetNumberOfData(std::string("bee"), root) << std::endl;

	std::cin.get();

	return 0;
}

std::vector<std::string>* readTXTFile()
{
	std::vector<std::string> *transcript = new (std::vector<std::string>);
	std::string currWord;
	std::ifstream txtFile;

	txtFile.open("bee.txt");

	while (txtFile >> currWord)
	{
		std::cout << currWord << std::endl;
		transcript->push_back(currWord);
	}

	return transcript;
}