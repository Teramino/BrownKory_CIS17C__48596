//
//  Bank.h
//  Midterm_Project
//
//  Created by Kory Brown on 12/18/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Midterm_Project_Bank_h
#define Midterm_Project_Bank_h

enum Wallet {WINNING, PAYDAY=6, BROKE=8, ROBBED=10};

#include "Business.h"
#include "Customer.h"
#include "PriorityQueue.h"
#include <iomanip>


class Bank : public Business
{
private:
    
    PriorityQueue<Customer> line;
    
public:
    
    Bank (int id, string name, int approxLineLength, bool priority): Business(id, name, approxLineLength, priority){}
    ~Bank(){}
    
    virtual void simulate(Customer c)
    {
         cout << setw(45) << "Welcome to the Bank\n";
         cout << "=========== Clock starts from the service of first customer ===========\n\n";
        
        srand(time(NULL));
        line = *new PriorityQueue<Customer>();
        
        float random = 0;
        int transactionTimeLeft = 0;
        int numberOfArrivals = 0;
        int maxTransactionTime = 60;
        float arrivalProbability = .7;
        
        for (int clock = 0 ; clock < lineLength ; clock++)
        {
            random = ((float) rand() / (RAND_MAX));
            if (random < arrivalProbability)
            {
                numberOfArrivals++;
                random = ((double) rand()/ (RAND_MAX));
                int priority = rand() % 10 + 1;
                int transactionTime = (int) (random * maxTransactionTime + 1);
                
                if (numberOfArrivals % 2 == 0)
                    priority = rand() % 6;
                
                Customer nextArrival (priority, clock, transactionTime, numberOfArrivals);
                
                line.Enqueue(nextArrival, nextArrival.getPriority());
            }
        } // end for
        
            // Create Customer data
        random = ((double) rand() / (RAND_MAX));
        int maxArrivalTime = 10;
        int lastKnownArrivalTime = line.peekLast().getArrivalTime();
        int arrivalTime = random * maxArrivalTime;
        arrivalTime += lastKnownArrivalTime;
        
        c = *new Customer(c.getPriority(), arrivalTime, 10, numberOfArrivals+1);
        
        string wallet = "";
        switch(c.getPriority())
        {
            case 0:
                wallet = "Rich";
                cout << "You entered the bank with your wallet looking like your " << wallet << ".\nYou will be seen immediately\n";
                break;
            case 6:
                wallet = "Just got payed";
                cout << "You entered the bank with your wallet looking like you " << wallet << ".\nWe will try and see you as soon as we can\n";
                break;
            case 8:
                wallet = "Broke";
                cout << "You entered the bank with your wallet looking like your " << wallet << ".\nWait until a clerk can see you\n";
                break;
            case 10:
                wallet = "Robbed";
                cout << "You entered the bank with your wallet looking like you been " << wallet << ".\nGet to the back\n";
                break;
        }
        
        
        line.Enqueue(c, c.getPriority());
        int spot = line.getSpotInLine(c);
        
        cout << "You are the " << spot << " spot in line\n";
        cout << "Press Enter to continue\n\n";
        cin.ignore();
        
            // set clock
        int clock = line.peekFirst().getArrivalTime();
        while(!line.isEmpty())
        {
            if (transactionTimeLeft > 0)
            {
                transactionTimeLeft--;
            }
            else
            {
                Customer nextPatient = (Customer)line.Dequeue();
                transactionTimeLeft = nextPatient.getTransactionTime () - 1;
                float timeWaited = (float)(clock - nextPatient.getArrivalTime()) / 60;
                float clockInMinutes = (float) clock/60;
                
                if (nextPatient == c)
                {
                    cout << "\nYou are now being serviced\n"
                    << "You are customer " << nextPatient.getCustomerNumber() << " and is being serviced at time from first Customer "
                    << clockInMinutes << ". Time you waited is "<< timeWaited << " minutes\n\n";
                    break;
                }
                else
                {
                    cout << "Customer " << nextPatient.getCustomerNumber() << " begins service at time from first Customer "
                    << clockInMinutes << " minutes. Time waited is "<< timeWaited << " minutes\n\n";
                }
            }
            clock++;
        }
    }

};

#endif
