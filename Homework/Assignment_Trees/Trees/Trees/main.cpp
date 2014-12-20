#include <cstdlib>
#include <iostream>
#include <ctime>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char* argv[])
{
	BST<int> *tree = new BST<int>();

	srand((unsigned int)time(0));
	int num = 0;
	int const SIZE = 10;
	int firstHalf = 5;
	int secondHalf = 10;
	int mArray[SIZE] = { 0 };



        // Insert un-balanced

	for (int i = 0; i < SIZE; i++)
	{
		num = rand() % 15;
		mArray[i] = num;
		tree->insert(num);
	}

	cout << "\nUNBALANCED TREE\n-----------------\n";
	cout << "Preorder:   "; tree->preorder();
	cout << "\nPostorder:  "; tree->postorder();
	cout << "\nInorder:    "; tree->inorder();
	cout << "\n\n";

	

        // Balance

	tree->clear();
	tree->balance(mArray, 0, SIZE - 1);

	cout << "\nBALANCED TREE\n-----------------\n";
	cout << "Preorder:   "; tree->preorder();
	cout << "\nPostorder:  "; tree->postorder();
	cout << "\nInorder:    "; tree->inorder();
	cout << "\n\n";


        // Delete

	cout << "\n====================\n   DELETION DEMO\n====================\n";

	for (int i = 0; i < 5; i++)
	{
		num = rand() % 15;
		cout << "-----------------\nAttemping to delete a " << num << " from the tree...\n";
		tree->findAndDeleteByMerging(num);
		cout << "\nPreorder:   "; tree->preorder();
		cout << "\nPostorder:  "; tree->postorder();
		cout << "\nInorder:    "; tree->inorder();
		cout << "\n\n";
	}


	// We're done
	delete tree;

	return 0;
}
