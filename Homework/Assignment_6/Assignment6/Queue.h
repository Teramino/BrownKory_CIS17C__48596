//
//  Queue.h
//  Assignment6
//
//  Created by Kory Brown on 12/17/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Assignment6_Queue_h
#define Assignment6_Queue_h

template<class T>
class Queue
{
private:
    struct Node
    {
        int id;
        T data;
        Node *next;
    };
    
    Node *worker;
    Node *firstNode;
    
public:
    Queue()
    {
        firstNode = NULL;
    };
    ~Queue()
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
        }
    }
    
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
    
    T peek()
    {
        return firstNode->data;
    }
    
    bool isEmpty()
    {
        return (firstNode == NULL);
    }
    
    void clear()
    {
        Node *temp;
        temp = firstNode;
        if( firstNode != NULL)
            while(temp != NULL)
            {
                worker = temp;
                delete worker;
                temp = temp->next;
            }
    }
    
};

#endif
