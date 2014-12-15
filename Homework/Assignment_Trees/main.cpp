#include <cstdlib>
#include <iostream>
#include <ctime>

#include "BinarySearchTree.h"

int main(int argc, char* argv[])
{
	BST<int> *tree = new BST<int>();

	srand((unsigned int)time(0));
	int num = 0;
	int const SIZE = 10;
	int firstHalf = 5;
	int secondHalf = 10;
	int mArray[SIZE] = { 0 };


	////////////////////////////////////////////
	// DEMONSTRATE INSERT() WITHOUT BALANCING //
	////////////////////////////////////////////

	// Fill array with random data and insert()
	// this data into tree
	for (int i = 0; i < SIZE; i++)
	{
		num = rand() % 15;
		mArray[i] = num;
		tree->insert(num);
	}

	std::cout << "\nUNBALANCED TREE\n-----------------\n";
	std::cout << "Preorder:   "; tree->preorder();
	std::cout << "\nPostorder:  "; tree->postorder();
	std::cout << "\nInorder:    "; tree->inorder();
	std::cout << "\n\n";

	
	///////////////////////////////////
	//     DEMONSTRATE BALANCE()     //
	///////////////////////////////////

	// First clear tree of all data to start fresh
	// Then balance() the tree with the data
	tree->clear();
	tree->balance(mArray, 0, SIZE - 1);

	std::cout << "\nBALANCED TREE\n-----------------\n";
	std::cout << "Preorder:   "; tree->preorder();
	std::cout << "\nPostorder:  "; tree->postorder();
	std::cout << "\nInorder:    "; tree->inorder();
	std::cout << "\n\n";


	//////////////////////////////////
	//     DEMONSTRATE DELETE()     //
	//////////////////////////////////

	std::cout << "\n====================\n   DELETION DEMO\n====================\n";

	for (int i = 0; i < 5; i++)
	{
		num = rand() % 15;
		std::cout << "-----------------\nAttemping to delete a " << num << " from the tree...\n";
		tree->findAndDeleteByMerging(num);
		std::cout << "\nPreorder:   "; tree->preorder();
		std::cout << "\nPostorder:  "; tree->postorder();
		std::cout << "\nInorder:    "; tree->inorder();
		std::cout << "\n\n";
	}


	// We're done
	delete tree;

	return 0;
}
