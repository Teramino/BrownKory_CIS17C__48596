    //
    //  WaitLine.h
    //  Assignment6
    //
    //  Created by Kory Brown on 12/9/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Assignment6_WaitLine_h
#define Assignment6_WaitLine_h

#include "Customer.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include <cstdlib>
#include <iomanip>

class WaitLine
{
private:
    int numberOfArrivals;
    int numberServed;
    int totalTimeWaited;
    Queue<Customer> line;
//    PriorityQueue<Customer> priorityline;
    PriorityQueue priorityline;
    
public:
    WaitLine ()
    {        
        srand (time(NULL));
        reset ();
    } // end default constructor
    
    void simulate (int duration, double arrivalProbability, int maxTransactionTime)
    {
        double random = 0;
        int transactionTimeLeft = 0;
        for (int clock = 0 ; clock < duration ; clock++)
        {
            random = ((double) rand() / (RAND_MAX));
            if (random <= arrivalProbability)
            {
                numberOfArrivals++;
                random = ((double) rand()/ (RAND_MAX));
                int transactionTime = (int) (random * maxTransactionTime + 1);
                
                Customer nextArrival (clock, transactionTime, numberOfArrivals);
                
                cout << "Customer " << numberOfArrivals << " enters line at time "
                     << clock << ". Transaction time is " << transactionTime << endl;

                line.Enqueue(nextArrival);
            } // end if
            if (transactionTimeLeft > 0)
            {
                transactionTimeLeft--;
            }
            else if (!line.isEmpty ())
            {
                Customer nextCustomer = (Customer)line.Dequeue();
                
                transactionTimeLeft = nextCustomer.getTransactionTime () - 1;
                int timeWaited = clock - nextCustomer.getArrivalTime ();
                totalTimeWaited = totalTimeWaited + timeWaited;
                numberServed++;
                
                cout << "Customer " << nextCustomer.getCustomerNumber() << " begins service at time "
                << clock << ". Time waited is "<< timeWaited << endl;
                
            } // end if
        } // end for
    } // end simulate
    
    void simulatePriorityLine (int duration, double arrivalProbability, int maxTransactionTime)
    {
        cout << "===================================================\n";
        cout << setw(35) << "Welcome to the Priority Line\n";
        cout << "===================================================\n\n";
        
        float random = 0;
        int transactionTimeLeft = 0;
        for (int clock = 0 ; clock < duration ; clock++)
        {
            random = ((float) rand() / (RAND_MAX));
            if (random <= arrivalProbability)
            {
                numberOfArrivals++;
                random = ((double) rand()/ (RAND_MAX));
                int priority = rand() % 10 + 1;
                int transactionTime = (int) (random * maxTransactionTime + 1);
                
                Customer nextArrival (clock, transactionTime, numberOfArrivals);
                
                cout << "Customer " << numberOfArrivals << " enters line at time "
                << clock << " with priority # " << priority << ". Transaction time is " << transactionTime << endl << endl;
                cout << "Time till next customer served: " << transactionTimeLeft << endl << endl;
                
                priorityline.Enqueue(nextArrival, priority);
            } // end if
            else
                cout << "No new customer\n\n";
            
            if (transactionTimeLeft > 0)
            {
                transactionTimeLeft--;
            }
            else if (!priorityline.isEmpty ())
            {
                Customer nextCustomer = (Customer)priorityline.Dequeue();
                
                transactionTimeLeft = nextCustomer.getTransactionTime () - 1;
                int timeWaited = clock - nextCustomer.getArrivalTime ();
                totalTimeWaited = totalTimeWaited + timeWaited;
                numberServed++;
                
                cout << "Customer " << nextCustomer.getCustomerNumber() << " begins service at time "
                << clock << ". Time waited is "<< timeWaited << endl;
                
            } // end if
        } // end for
    } // end simulate
    
    /** Initializes the simulation. */
        //
    void reset ()
    {
        line.clear ();
        numberOfArrivals = 0;
        numberServed = 0;
        totalTimeWaited = 0;
    } // end reset
};


#endif
