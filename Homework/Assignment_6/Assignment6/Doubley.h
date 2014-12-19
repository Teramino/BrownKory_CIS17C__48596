//
//  Doubley.h
//  Assignment6
//
//  Created by Kory Brown on 12/17/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Assignment6_Doubley_h
#define Assignment6_Doubley_h

#include "LnkdLst.h"

template<class T>
class Doubley : public LnkdLst<T>
{
private:
    struct Node
    {
        int id;
        T data;
        Node *next;
        Node *prevNode;
    };
    
    Node *worker;
    Node *firstNode;
    Node *lastNode;
    
public:
    Doubley(){   firstNode = lastNode = NULL; }
    ~Doubley(){}
    
    Doubley(T i)
    {
        firstNode = new Node;
        firstNode->data = i;
        firstNode->id = 1;
        firstNode->next = NULL;
        firstNode->prevNode = NULL;
        lastNode = firstNode;
        lastNode->next = firstNode;
    }
    
    void Append(T i) // add to the end of nodes
    {
        Node *prev = new Node;
        if (firstNode != NULL)
        {
            worker = firstNode;
            while(true)
            {
                if (worker == NULL)
                {
                    worker = new Node;
                    worker->data = i;
                    prev->next = worker;
                    worker->prevNode = prev;
                    worker->id = prev->id + 1 ;
                    worker->next = NULL;
                    lastNode = worker;
                    break;
                }
                else
                {
                    prev = worker;
                    worker = worker->next;
                }
            }
        }
        else
        {
            firstNode = new Node;
            firstNode->data = i;
            firstNode->id = 1;
            firstNode->next = NULL;
            lastNode = firstNode;
        }
    }
    
    void Prepend(T i) // add to the front of nodes
    {
        worker = new Node;
        worker->data = i;
        if (firstNode == NULL)
        {
            worker->id = 1;
            firstNode = worker;
        }
        else
        {
            worker->next = firstNode;
            firstNode->prevNode = worker;
            firstNode = worker;
            firstNode->prevNode = NULL;
            firstNode->id = 1;
            
                // adjust id's
            worker = firstNode->next;
            while(true)
            {
                if (worker != NULL)
                {
                    worker->id++;
                    worker = worker->next;
                }
                else
                    break;
            }
        }
    }
    
    void toString()
    {
        worker = firstNode;
        while(worker!= NULL)
        {
            if (worker == firstNode)
            {
                cout << "prevNode-"
                << setw(11) << "data: "
                << setw(12) << " ->"
                << setw(10) << "Node-" << worker->id
                << setw(10) << "data: " << worker->data
                << setw(10) << " ->\n";
            }
            else
            {
                cout << "prevNode-" << worker->prevNode->id
                << setw(10) << "data: " << worker->prevNode->data
                << setw(10) << " ->"
                << setw(10) << "Node-" << worker->id
                << setw(10) << "data: " << worker->data
                << setw(10) << " ->\n";
                
            }
            worker = worker->next;
        }
        cout << endl;
    }
    
    
    bool isEmpty()
    {
        return (firstNode == NULL) && (lastNode == NULL);
    }
};

#endif
