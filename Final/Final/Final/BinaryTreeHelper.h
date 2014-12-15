//
//  BinaryTreeHelper.h
//  Final_BinaryTree
//
//  Created by Kory Brown on 12/13/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Final_BinaryTree_BinaryTreeHelper_h
#define Final_BinaryTree_BinaryTreeHelper_h

#include <iostream>
#include <string>
using namespace std;
class BinaryTreeHelper
{
    public:
    BinaryTreeHelper(){root = NULL;}
    ~BinaryTreeHelper(){}

    struct Node
    {
        string data;
        Node* left;
        Node* right;
    };
    Node* root;
    
    
    
        // Function to create a new Node in heap
    Node* GetNewNode(string data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
        // To insert data in BST, returns address of root node
    Node* Insert(Node* root, string data)
    {
        if(root == NULL)// empty tree
            root = GetNewNode(data);
        
            // if data to be inserted is lesser, insert in left subtree.
        else if(data <= root->data)
            root->left = Insert(root->left,data);
        
            // else, insert in right subtree.
        else
            root->right = Insert(root->right,data);
        
        return root;
    }
    
        //To search an element in BST, returns true if element is found
    bool Search(Node* root, string data)
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
