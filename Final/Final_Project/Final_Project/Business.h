//
//  Business.h
//  Midterm_Project
//
//  Created by Kory Brown on 12/17/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Midterm_Project_Business_h
#define Midterm_Project_Business_h

#include <iostream>
using namespace std;

class Business
{
protected:
    
    string name;
    bool priority;
    int lineLength;
    int id;
    
    
public:
    Business(){}
    
    Business(int id, string name, int lineLength, bool priority)
    {
        this->id = id;
        this->name = name;
        this->lineLength = lineLength;
        this->priority = priority;
    }
    
    int getID() const
    {
        return id;
    }
    
    string getName() const
    {
        return name;
    }
    
    bool getPriority() const
    {
        return priority;
    }
    
    ~Business(){}
};

#endif
