//
//  Patient.h
//  Midterm_Project
//
//  Created by Kory Brown on 12/17/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Midterm_Project_Patient_h
#define Midterm_Project_Patient_h

enum Condition {STROKE, SHOT, BROKEN_LEG=5, SICK=9};

#include "Customer.h"

class Patient : public Customer
{
private:
    
    int condition;
    
public:
    
    Patient(){}
    ~Patient(){};
    
    Patient(int condition)
    {
        this->condition = condition;
        this->clock = -1;
        this->transactionTime = -1;
        this->customerID = -1;
    }
    Patient(int condition, int clock, int transactionTime, int arrivalNumber) : Customer (clock, transactionTime, arrivalNumber)
    {
        this->condition = condition;
    }
    
    
    int getCondition()
    {
        return condition;
    }
    
    Patient& operator=(const Patient &right)
    {
        this->clock = right.clock;
        this->transactionTime = right.transactionTime;
        this->customerID = right.customerID;
        this->condition = right.condition;
        return *this;
    }
};

#endif
