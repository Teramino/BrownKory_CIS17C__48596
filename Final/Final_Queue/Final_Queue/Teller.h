    //
    //  Tellers.h
    //  Assignment6
    //
    //  Created by Kory Brown on 12/11/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Assignment6_Teller_h
#define Assignment6_Teller_h

class Teller
{
private:
    int serviceTime;
    int customerLineCount;
    int id;
    bool serving;
    bool helping;
    
public:
    Teller()
    {
        serving = false;
        customerLineCount = 0;
        serviceTime = 0;
    }
    Teller(int id)
    {
        this->id = id;
        this->serviceTime = 0;
        customerLineCount = 0;
        serving = false;
        
    }
    Teller(int id, int serviceTime, int lineLength)
    {
        this->id = id;
        this->serviceTime = serviceTime;
        this->customerLineCount = lineLength;
        serving = false;
        helping = true;
        
    }
    ~Teller(){}
    
    void setCustomerServiceTime(int time)
    {
        this->serviceTime = time;
    }
    int getCustomerServiceTime()
    {
        return this->serviceTime;
    }
    
    int served(int serviceEnd)
    {
        this->serviceTime = serviceEnd - serviceTime;
        serving = false;
        return serviceTime;
    }
    int newClerkServed(int serviceEnd)
    {
        this->serviceTime = serviceEnd - serviceTime;
        serving = false;
        customerLineCount--;
        return serviceTime;
    }
    bool isServing()
    {
        return this->serving;
    }
    bool isHelping()
    {
        return this->helping;
    }
    int getID()
    {
        return this-> id;
    }
    int getCustomerLineCount()
    {
        return this->customerLineCount;
    }
};

#endif
