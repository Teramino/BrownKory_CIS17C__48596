//
//  BusinessManager.h
//  Midterm_Project
//
//  Created by Kory Brown on 12/18/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Midterm_Project_BusinessManager_h
#define Midterm_Project_BusinessManager_h

#include "HashTable.h"
#include "Business.h"

class BusinessManager
{
    
private:
    
    HashTable<Business *> *businesses;
    
public:
    
    BusinessManager()
    {
        businesses = new HashTable<Business *>();
    }
    ~BusinessManager(){}
    
    HashTable<Business *>* getBusinesses() const
    {
        return businesses;
    }
    
    void addBusiness(int id, Business *business)
    {
        businesses->put(id, business);
    }
    
    void removeBusiness(int id)
    {
        businesses->remove(id);
    }
    
    Business* findBusiness(int id)
    {
        Business* business = businesses->get(id);
        if (business != NULL)
            return business;
        else
        {
            cout << "Customer not found.\n\n";
            return NULL;
        }
    }
};

#endif
