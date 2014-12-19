    //
    //  PriorityQueue.h
    //  Assignment6
    //
    //  Created by Kory Brown on 12/17/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Assignment6_PriorityQueue_h
#define Assignment6_PriorityQueue_h

#include <iostream>
#include "Customer.h"
#include <iomanip>

using namespace std;

template<class T>
class PriorityQueue
{
private:
    
    struct Node
    {
        int priority;
        T data;
        Node *next;
    };
    
    Node *worker;
    Node *firstNode;
    Node *lastNode;
    
    
public:
    
    PriorityQueue() {  firstNode = lastNode = NULL;}
    ~PriorityQueue()
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
    
    void Enqueue(T i)
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
            firstNode->next = NULL;
            lastNode = firstNode;
        }
    }

    
    void Enqueue(T i, int p)
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
                    worker->next = NULL;
                    worker->priority = p;
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
            firstNode->next = NULL;
            firstNode->priority = p;
            lastNode = firstNode;
        }
        sort();
    }
    
        // i want this to have a return time of Patient inside my class
    T Dequeue() // retrieve front entry then remove it
    {
        T front;
        if (firstNode != NULL)
        {
            front = firstNode->data;
            firstNode = firstNode->next;
        }
        return front;
    }
    
    void sort()
    {
        Node *s, *ptr;
        T temp;
        int priority;
        
        if (firstNode == NULL)
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
                    if (s->priority > ptr->priority)
                    {
                        temp = s->data;
                        priority = s->priority;
                        s->data = ptr->data;
                        s->priority = ptr->priority;
                        ptr->data = temp;
                        ptr->priority = priority;
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
    
    T peekFirst()
    {
        return firstNode->data;
    }
    T peekLast()
    {
        return lastNode->data;
    }
    
    int getSpotInLine(T c)
    {
        worker = firstNode;
        int spot = 0;
        
        while(worker != NULL)
        {
            spot++;
            if (worker->data == c)
                break;
            else
                worker = worker->next;
        }
        if (worker == NULL)
            return -1;
        return spot;
        
    }
    
    bool isEmpty()
    {
        return (firstNode == NULL);
    }
    
    void toString()
    {
        
        worker = firstNode;
        while(worker!= NULL)
        {
            
            cout << "Node-"
            << setw(10) << "priority: " << worker->priority
            << setw(10) << " ->\n";
            worker = worker->next;
        }
        cout << endl;
    }
    
    void clear()
    {
        Node *temp;
        temp = firstNode;
        if( firstNode != NULL)
            while(temp != NULL);
            {
                worker = temp;
                delete worker;
                temp = temp->next;
            }
    }
};
#endif
