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
    LnkdLst(T i, string type)
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
                //            cout << "There are currenly no nodes...\n";
            firstNode = new Node;
            firstNode->data = i;
            firstNode->id = 1;
            firstNode->next = NULL;
            lastNode = firstNode;
                //            cout << "First node created\n";
        }
            //delete prev;
        
    }
    void circularlyAppend(T i) // add to the end of nodes
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
    
    T Dequeue() // retrieve front entry then remove it
    {
        T front;
        if (lastNode != NULL)
        {
            front = firstNode->data;
            firstNode = firstNode->next;
            if (firstNode == NULL)
                lastNode = NULL;
        }
        return front;
    }
    void circularlyPrepend(T i) // add to the front of nodes
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
    
    void circularyPrepend(T i) // add to the front of nodes
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
            //        delete prev;
            //        delete temp;
        
    }
   
    void circularlyInsertBefore(T selection, T i)
    {
        Node *prev = firstNode;
        if (firstNode->data == selection)
        {
            circularyPrepend(i);
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
            //        delete prev;
            //        delete temp;
        
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
            //        delete prev;
            //        delete temp;
    }
    
    void circularlyInsertAfter(T selection, T i)
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
    void sort()
    {
        Node *s, *ptr;
        int temp;
        if (lastNode == NULL)
        {
            cout<<"List is empty, nothing to sort"<<endl;
            return;
        }
        s = lastNode->next;
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
    
    void circularSort()
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
    
    T circularlyExtract(int index)
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
    void circularlyToString()
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
    void doubleyToString()
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
    virtual ~LnkdLst()
    {
        int node = 1;
        Node *temp;
        temp = firstNode;
        if (temp != NULL)
            while(temp->next != lastNode)
            {
                worker = temp;
                    //                cout << "Node-" << worker->id << " deleted\n";
                delete worker;
                temp = temp->next;
                node++;
            }
        delete  lastNode;
        
    }
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
};

#endif	/* LNKDLST_H */

