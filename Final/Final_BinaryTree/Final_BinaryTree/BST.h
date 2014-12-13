#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

using namespace std;

class BST
{
	public:
	
    BST()
    {
        root = NULL;
    }
		struct BstNode{
			std::string data; 
			BstNode* left;
			BstNode* right;
		};
    BstNode* root;

    BstNode* GetNewNode(string data)
    {
        BstNode* newNode = new BstNode();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    
    BstNode* Insert(BstNode* root,string data)
    {
        if(root == NULL)
            root = GetNewNode(data);
        
        
        else if(data <= root->data)
            root->left = Insert(root->left,data);
        
            // else, insert in right subtree.
        else
            root->right = Insert(root->right,data);
        
        return root;
    }
    
    
    bool Search(BstNode* root,string data)
    {
        if(root == NULL)
            return false;
        
        else if(root->data == data)
            return true;
        
        else if(data <= root->data)
            return Search(root->left,data);
        
        else
            return Search(root->right,data);
    }

		
};
#endif
