    //
    //  Customer.h
    //  Assignment6
    //
    //  Created by Kory Brown on 12/9/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Assignment6_Customer_h
#define Assignment6_Customer_h

class Customer
{
protected:
    
    int clock;
    int transactionTime;
    int customerID;
    int priority;
    
public:
    
    Customer(){}
    ~Customer(){}
    
    Customer(int priority)
    {
        this->priority = priority;
        this->clock = -1;
        this->transactionTime = -1;
        this->customerID = -1;
    }
    
    Customer (int clock, int transactionTime, int arrivalNumber)
    {
        this->clock = clock;
        this->transactionTime = transactionTime;
        this->customerID = arrivalNumber;
        this->priority = -1;
    }
    Customer (int priority, int clock, int transactionTime, int arrivalNumber)
    {
        this->clock = clock;
        this->transactionTime = transactionTime;
        this->customerID = arrivalNumber;
        this->priority = priority;
    }
    
    Customer& operator=(const Customer &right)
    {
        this->clock = right.clock;
        this->transactionTime = right.transactionTime;
        this->customerID = right.customerID;
        this->priority = right.priority;
        return *this;
    }
    
    bool operator==(const Customer &right)
    {
        if (this->clock == right.clock)
        {
            if (this->transactionTime == right.transactionTime)
            {
                if(this->customerID == right.customerID)
                {
                    return true;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
        return false;
    }
    
    int getTransactionTime()
    {
        return transactionTime;
    }
    
    int getArrivalTime()
    {
        return this->clock;
    }
    
    int getCustomerNumber()
    {
        return this->customerID;
    }
    
    int getPriority()
    {
        return this->priority;
    }
    
};


#endif
