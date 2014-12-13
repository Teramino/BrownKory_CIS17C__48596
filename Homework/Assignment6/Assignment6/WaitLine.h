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
#include "LnkdLst.h"
#include <cstdlib>

class WaitLine
{
private:
    int numberOfArrivals;
    int numberServed;
    int totalTimeWaited;
    LnkdLst<Customer> line;
    
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
                    //                System.out.println ("Customer " + numberOfArrivals
                    //                                    + " enters line at time " + clock
                    //                                    + ". Transaction time is "
                    //                                    + transactionTime);
                line.Append(nextArrival);
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
                    //                System.out.println ("Customer "
                    //                                    + nextCustomer.getCustomerNumber ()
                    //                                    + " begins service at time " + clock
                    //                                    + ". Time waited is " + timeWaited);
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
