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
    LnkdLst()
    {
        firstNode = new Node;
        lastNode = new Node;
        worker = new Node;
    }
    LnkdLst(int i)
    {
        firstNode = new Node;
        firstNode->data = i;
        firstNode->id = 1;
        firstNode->next = NULL;
        lastNode = firstNode;
    }
    void append(int i) // add to the end of nodes
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
            cout << "There are currenly no nodes...\n";
            firstNode = new Node;
            firstNode->data = i;
            firstNode->id = 1;
            firstNode->next = NULL;
            cout << "First node created\n";
        }
        //delete prev;

    }
    
    void prepend(int i) // add to the front of nodes
    {
        worker = new Node;
        worker->data = i;
        worker->next = firstNode;
        firstNode = worker;
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
    void insertBefore(int data, int i)
    {
        Node *prev = firstNode;
        Node *temp = new Node;
        if (firstNode->data == data)
        {
            prepend(i);
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
                    worker->id = prev->id + 1;
                    lastNode = worker;
                    break;
                }
                else if (worker->data == data) // inserts a new node before indicted data
                {
                    temp->data = i;
                    temp->next = worker;
                    prev->next = temp;
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
//        delete prev;
//        delete temp;

    }
    
    void insertAfter(int data, int i)
    {
        Node *prev = firstNode;
        Node *temp = new Node;
        if (firstNode->data == data)
        {
            worker = new Node;
            worker->data = i;
            worker->next = firstNode;
            firstNode = worker;
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
                    worker->id = prev->id + 1;
                    lastNode = worker;
                    break;
                }
                else if (worker->data == data) // inserts a new node after indicted data
                {
                    Node *after = worker->next;
                    
                    temp->data = i;
                    temp->next = after;
                    worker->next = temp;
                    temp->id = worker->id + 1;
                    after->id =  temp->id + 1;
                    
                    // adjust id's
                    worker = temp;
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
                    
                    //                    delete after;
                    break;
                }
                else
                {
                    prev = worker;
                    worker = worker->next;
                }
            }
            
        }
        delete prev;
        delete temp;
    }
    
    int extract(int index)
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
    
    int length()
    {
        return lastNode->id;
    }
    
    void toString()
    {
        worker = firstNode;
        while(worker!= NULL)
        {
            
            cout << "Node ID: " << worker->id
                 << " data: " << worker->data << endl;
            worker = worker->next;
        }
        cout << endl;
    }
    virtual ~LnkdLst()
    {
        int node = 1;
        Node *temp;
        temp = firstNode;
        while(temp->next != NULL)
        {
            worker = temp;
            cout << "Node-" << worker->data << " deleted\n";
            delete worker;
            temp = temp->next;
            node++;
        }
        
    }
private:
    struct Node
    {
        int id;
        int data;
        Node *next;
    };
    
    Node *worker;
    Node *firstNode;
    Node *lastNode;
};

#endif	/* LNKDLST_H */

