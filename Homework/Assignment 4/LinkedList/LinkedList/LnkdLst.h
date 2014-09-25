/*
 * File:   LnkdLst.h
 * Author: Kory Brown
 * Created on September 24, 2014
 * Purpose:  Explore creation of a linked list class
 */

#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
using namespace std;

class LnkdLst
{
public:
    LnkdLst(int i)
    {
        firstNode = new Node;
        firstNode->data = i;
        firstNode->next = NULL;
    }
    void append(int i)
    {
        worker = new Node;
        worker->data = i;
        worker->next = firstNode;
        firstNode = worker;
    }
    void toString()
    {
        worker = firstNode;
       while(worker->next != NULL)
       {
           
           cout << worker->data << " ";
           worker = worker->next;
       }
    }
    virtual ~LnkdLst()
    {
        int node = 1;
        Node *temp;
        temp = firstNode;
        while(temp->next != NULL)
        {
            worker = temp;
            cout << "Node-" << node << " deleted\n";
            delete worker;
            temp = temp->next;
            node++;
        }
        
    }
private:
    struct Node
    {
         int data;
         Node *next;
    };
    Node *firstNode;
    Node *worker;
};

#endif	/* LNKDLST_H */

