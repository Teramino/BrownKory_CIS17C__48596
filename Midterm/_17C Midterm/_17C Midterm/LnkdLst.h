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
protected:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *firstNode;
    Node *worker;
    
public:
    LnkdLst()
    {
        firstNode = new Node;
        firstNode = NULL;
    }
    LnkdLst(int i)
    {
        firstNode = new Node;
        firstNode->data = i;
        firstNode->next = NULL;
    }
    void append(int i) // add to the end of node
    {
        if (firstNode != NULL)
        {
            worker = new Node;
            worker = firstNode->next;
            Node *temp = new Node;
            temp = firstNode;
            while(true)
            {
                if (worker == NULL)
                {
                    worker = new Node;
                    worker->data = i;
                    temp->next = worker;
                    break;
                }
                else
                {
                    temp = worker;
                    worker = worker->next;
                    
                }
            }
        }
        else
        {
            worker = new Node;
            worker->data = i;
            firstNode = worker;
        }
    }
    void toString()
    {
        worker = firstNode;
        while(worker != NULL)
        {
            
            cout << worker->data << " ";
            worker = worker->next;
        }
        cout << endl;
    }
    int getData(int index)
    {
        int count = 0;
        worker = firstNode;
        if(index != 0)
        {
            while(index > count)
            {
                
                if (worker->next)
                    worker = worker->next;
                else
                {
                    cout << "There's only "<< count << " nodes\n";
                    cout << "Error...\n";
                    exit(50);
                    return 0;
                }
                count++;
                
            }
        }
        return worker->data;
    }
    
   Node *getFirstNode()
    {
        return firstNode;
    }
    
    void setFirstNode(Node * n)
    {
        firstNode = n;
    }
    
    virtual ~LnkdLst()
    {
        int node = 1;
        Node *temp;
        temp = firstNode;
        while(temp->next != NULL)
        {
            worker = temp;
//            cout << "Node-" << node << " deleted\n";
            delete worker;
            temp = temp->next;
            node++;
        }
//        cout << endl;
        
    }

};

#endif	/* LNKDLST_H */

