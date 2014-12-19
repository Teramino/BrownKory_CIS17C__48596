//
//  Circularly.h
//  Assignment6
//
//  Created by Kory Brown on 12/17/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Assignment6_Circularly_h
#define Assignment6_Circularly_h

#include "LnkdLst.h"

template<class T>
class Circularly : public LnkdLst<T>
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
    
    Circularly() {   firstNode = lastNode = NULL; }
    ~Circularly(){}
    
    void Append(T i) // add to the end of nodes
    {
        Node *prev = new Node;
        if (firstNode != NULL)
        {
            worker = firstNode;
            while(true)
            {
                if (worker == lastNode)
                {
                    worker = new Node;
                    worker->data = i;
                    lastNode->next = worker;
                    worker->prevNode = lastNode;
                    lastNode = worker;
                    lastNode->next = firstNode;
                    lastNode->id = lastNode->prevNode->id + 1;
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
            lastNode->next = firstNode;
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
            lastNode->next = firstNode;
            
                // adjust id's
            worker = firstNode->next;
            while(true)
            {
                if (worker != lastNode)
                {
                    worker->id++;
                    worker = worker->next;
                }
                else
                {
                    lastNode->id++;
                    break;
                }
            }
        }
    }
    
    void InsertBefore(T selection, T i)
    {
        Node *prev = firstNode;
        if (firstNode->data == selection)
        {
            Prepend(i);
        }
        else
        {
            worker = firstNode->next;
            while(true)
            {
                
                if (worker->data == selection) // inserts a new node before indicted data
                {
                    Node *temp = new Node;
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
                        if (worker != lastNode)
                        {
                            worker->id++;
                            worker = worker->next;
                        }
                        else
                        {
                            lastNode->id++;
                            break;
                        }
                    }
                    break;
                }
                else  if (worker == lastNode) // if no node with data exist, create new node with the new node
                {
                    worker = new Node;
                    worker->data = i;
                    lastNode->next = worker;
                    worker->prevNode = lastNode;
                    lastNode = worker;
                    lastNode->next = firstNode;
                    lastNode->id = lastNode->prevNode->id + 1;
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
                if (worker != lastNode)
                {
                    worker->id++;
                    worker = worker->next;
                }
                else
                {
                    lastNode->id++;
                    break;
                }
            }
            
        }
        else
        {
            worker = firstNode->next;
            while(true)
            {
                if (worker->data == selection) // inserts a new node after indicted data
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
                        if (worker != lastNode)
                        {
                            worker->id++;
                            worker = worker->next;
                        }
                        else
                        {
                            lastNode->id++;
                            break;
                        }
                    }
                    break;
                }
                else if (worker == lastNode) // if no node with data exist, create new node with the new node
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
                else
                {
                    prev = worker;
                    worker = worker->next;
                }
            }
            
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
                else if (worker == lastNode)
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
    
    void toString()
    {
        Node *s;
        if (lastNode == NULL)
        {
            cout<<"List is empty, nothing to display"<<endl;
            return;
        }
        s = lastNode->next;
        cout<<"Circular Link List: "<<endl;
        while (s != lastNode)
        {
            cout<<s->data<<"->";
            s = s->next;
        }
        cout<<s->data<<endl;
    }
    
    void Sort()
    {
        Node *s, *ptr;
        int temp;
        if (lastNode == NULL)
        {
            cout<<"List is empty, nothing to sort"<<endl;
            return;
        }
        s = lastNode->next;
        while (s != lastNode)
        {
            ptr = s->next;
            while (ptr != lastNode->next)
            {
                if (ptr != lastNode->next)
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

    bool isEmpty()
    {
        return (firstNode == NULL) && (lastNode == NULL);
    }
};

#endif
