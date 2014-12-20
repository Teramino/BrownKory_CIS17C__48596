//
//  LinkedHashEntry.h
//  Midterm_Project
//
//  Created by Kory Brown on 12/18/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Midterm_Project_LinkedHashEntry_h
#define Midterm_Project_LinkedHashEntry_h


template <class T>
class LinkedHashEntry
{
private:
    int key;
    T value;
    LinkedHashEntry *next;
    
public:
    LinkedHashEntry(int key, T value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    
    int getKey()
    {
        return key;
    }
    
    T getValue()
    {
        return value;
    }
    
    void setValue(T value)
    {
        this->value = value;
    }
    
    LinkedHashEntry *getNext()
    {
        return next;
    }
    
    void setNext(LinkedHashEntry *next) 
    {
        this->next = next;
    }
};


#endif
