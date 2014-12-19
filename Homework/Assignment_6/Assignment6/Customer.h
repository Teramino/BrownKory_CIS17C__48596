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
private:
    int clock;
    int transactionTime;
    int customerID;
  
public:
    Customer(){}
    
    Customer (int clock, int transactionTime, int arrivalNumber)
    {
        this->clock = clock;
        this->transactionTime = transactionTime;
        this->customerID = arrivalNumber;
    }
    
    Customer& operator=(const Customer &right)
    {
        this->clock = right.clock;
        this->transactionTime = right.transactionTime;
        this->customerID = right.customerID;
        return *this;
    }
    
    int getTransactionTime()
    {
        return transactionTime;
    }
    
    int getArrivalTime()
    {
        return clock;
    }
    
    int getCustomerNumber()
    {
        return customerID;
    }
    
};


#endif
