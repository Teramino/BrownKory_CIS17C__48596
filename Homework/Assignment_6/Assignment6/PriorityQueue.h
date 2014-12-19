    //
    //  PriorityQueue.h
    //  Assignment6
    //
    //  Created by Kory Brown on 12/17/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Assignment6_PriorityQueue_h
#define Assignment6_PriorityQueue_h

#include "Customer.h"

//template<class Customer>
class PriorityQueue
{
private:
    struct Node
    {
        int priority;
        Customer data;
        Node *next;
    };
    
    Node *worker;
    Node *firstNode;
    
    
public:
    
    PriorityQueue() {  firstNode = NULL;}
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
    
    void Enqueue(Customer i, int p)
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
        }
        sort();
    }
    
    Customer Dequeue() // retrieve front entry then remove it
    {
        Customer front;
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
        Customer temp;
        int priority;
        
//        cout << endl;
//        cout << "Before\n";
//        toString();
        
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
                        cout << "\nCustomer " << s->data.getCustomerNumber() << " has lower priority than Customer " << ptr->data.getCustomerNumber() << " \n";
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
        cout << endl;
        
//        cout << "After\n";
//        toString();
    }
    
    Customer peek()
    {
        return firstNode->data;
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
