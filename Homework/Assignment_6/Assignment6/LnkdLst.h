/*
 * File:   LnkdLst.h
 * Author: Kory Brown
 * Created on September 24, 2014
 * Purpose:  Explore creation of a linked list class
 */

#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
#include <iomanip>
#include "Customer.h"
using namespace std;

template <class T>
class LnkdLst
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
    LnkdLst()
    {
        firstNode = NULL;
        lastNode = NULL;
        worker = NULL;
    }
    LnkdLst(T i)
    {
        firstNode = new Node;
        firstNode->data = i;
        firstNode->id = 1;
        firstNode->next = NULL;
        firstNode->prevNode = NULL;
        lastNode = firstNode;
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
    
    void InsertBefore(T selection, T i)
    {
        Node *prev = firstNode;
        Node *temp = new Node;
        if (firstNode->data == selection)
        {
            Prepend(i);
        }
        else
        {
            worker = firstNode->next;
            while(true)
            {
                if (worker == lastNode) // if no node with data exist, create new node with the new node
                {
                    worker = new Node;
                    worker->data = i;
                    prev->next = worker;
                    worker->prevNode = prev;
                    worker->id = prev->id + 1;
                    lastNode = worker;
                    lastNode->next = firstNode;
                    break;
                }
                else if (worker->data == selection) // inserts a new node before indicted data
                {
                    temp->data = i;
                    temp->next = worker;
                    worker->prevNode = temp;
                    prev->next = temp;
                    temp->prevNode = prev;
                    temp->id = prev->id + 1;
                    worker->id = temp->id + 1;
                    
                        // adjust id's
                    worker = worker->next;
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
                    break;
                }
                else
                {
                    prev = worker;
                    worker = worker->next;
                }
            }
        }
    }
    
    void InsertAfter(T selection, T i)
    {
        Node *prev = firstNode;
        Node *newNode = new Node;
        if (firstNode->data == selection)
        {
            worker = new Node;
            worker->data = i;
            worker->next = firstNode->next;
            worker->next->prevNode = worker;
            firstNode->next = worker;
            worker->id = firstNode->id + 1;
            
                // adjust id's
            worker = worker->next;
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
        else
        {
            worker = firstNode->next;
            while(true)
            {
                if (worker == NULL) // if no node with data exist, create new node with the new node
                {
                    worker = new Node;
                    worker->data = i;
                    prev->next = worker;
                    worker->prevNode = prev;
                    worker->id = prev->id + 1;
                    lastNode = worker;
                    break;
                }
                else if (worker->data == selection) // inserts a new node after indicted data
                {
                    Node *after = worker->next;
                    
                    newNode->data = i;
                    newNode->next = after;
                    after->prevNode = newNode;
                    worker->next = newNode;
                    newNode->prevNode = worker;
                    newNode->id = worker->id + 1;
                    after->id =  newNode->id + 1;
                    
                    
                        // adjust id's
                    worker = after->next;
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
                    break;
                }
                else
                {
                    prev = worker;
                    worker = worker->next;
                }
            }
            
        }
    }
    
    void sort()
    {
        Node *s, *ptr;
        int temp;
        if (lastNode == NULL)
        {
            cout<<"List is empty, nothing to sort"<<endl;
            return;
        }
        s = firstNode;
        while (s != NULL)
        {
            ptr = s->next;
            while (ptr != NULL)
            {
                if (ptr != NULL)
                {
                    if (s->data > ptr->data)
                    {
                        temp = s->data;
                        s->data = ptr->data;
                        ptr->data = temp;
                    }
                }
                else
                {
                    break;
                }
                ptr = ptr->next;
            }
            s = s->next;
        }
    }
    
    T Extract(int index)
    {
        if (firstNode->id == index)
        {
            return firstNode->data;
        }
        else
        {
            worker = firstNode->next;
            while(true)
            {
                if (worker->id == index)
                {
                    return worker->data;
                }
                else if (worker == NULL)
                {
                    cout << "There is no node with that id\n";
                    return 0;
                }
                else
                {
                    worker = worker->next;
                }
            }
            
        }
        return 0;
    }
    
    
    void clear()
    {
        Node *temp;
        temp = firstNode;
        if( firstNode != NULL)
            while(temp->next != lastNode)
            {
                worker = temp;
                delete worker;
                temp = temp->next;
            }
        delete lastNode;
    }
    
    bool isEmpty()
    {
        return (firstNode == NULL) && (lastNode == NULL);
    }
    
    int ListLength()
    {
        return lastNode->id;
    }
    
    void toString()
    {
        worker = firstNode;
        while(worker!= NULL)
        {
            
            cout << "Node-" << worker->id
            << setw(10) << "data: " << worker->data
            << setw(10) << " ->\n";
            worker = worker->next;
        }
        cout << endl;
    }
    
    virtual ~LnkdLst()
    {
        Node *temp;
        temp = firstNode;
        if (temp != NULL)
            while(temp != NULL)
            {
                worker = temp;
                delete worker;
                temp = temp->next;
            }
    }
};

#endif	/* LNKDLST_H */

