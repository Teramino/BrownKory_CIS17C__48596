//
//  WaitLine.h
//  Final_Queue
//
//  Created by Kory Brown on 12/12/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Final_Queue_WaitLine_h
#define Final_Queue_WaitLine_h

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <queue>
#include <cmath>
#include <vector>
#include "Teller.h"

using namespace std;

class WaitLine
{
public:
    WaitLine(){};
    ~WaitLine(){};
    void simulate()
    {
        queue<int> serve;
        vector<Teller> clerks;
        int customer = 0;
        int customersServed=0;
        int timer = clock();
        int numOfclerks = 3;
        int totalWaitTime = 0;
        int i = 0;
        bool start = true;
        
        for (int clerk=0; clerk< numOfclerks; clerk++)
        {
            Teller temp((clerk+1));
            clerks.push_back(temp);
        }
        
        
        while (i < 1000)
        {
            if (start)
            {
                clerks[0].setCustomerServiceTime(0);
                clerks[1].setCustomerServiceTime(0);
                clerks[2].setCustomerServiceTime(0);
            }
            if(clock() > (timer + 1000))
            {
                timer = clock();
                if(serve.size() >= 5)
                {
                        //Add Another clerk
                    Teller temp((int)(clerks.size()+1),(timer/1000), (int) serve.size());
                    clerks.push_back(temp);
                    serve.pop();
                }
                if(!start && clerks.size() > 3)
                {
                        // Take away a clerk
                    for (int clerk=3; clerk< clerks.size(); clerk++)
                    {
                        if (clerks[clerk].getCustomerLineCount() == 0)
                        {
                            cout <<"Clerk " << clerks[clerk].getID() << " going in break\n";
                            clerks.erase(clerks.begin()+clerk);
                            serve.push(customer);
                        }
                    }
                    
                }
                if((timer/1000)%10 == 0)
                {
                    cout << "\nTime: " << timer/1000
                    << " seconds." << endl ;
                    cout << "Clerks: " << clerks.size() << endl;
                    cout << "Customers in line: "
                    << serve.size() << endl;
                    cout<<"Customers served: "
                    <<customersServed<<endl;
                }
                if((timer/1000)%60 == 0)
                {
                        // 3 customers go in line
                    serve.push(customer);
                    serve.push(customer);
                    serve.push(customer);
                    
                        // Clerk 1 serves 1 customer
                    int timeWaited = clerks[0].served((timer/1000));
                    totalWaitTime += timeWaited;
                    cout << "Clerk " << clerks[0].getID() << " serviced\n";
                    clerks[0].setCustomerServiceTime((timer/1000));
                    serve.pop();
                    customersServed++;
                    start = false;
                }
                if((timer/1000)%120 == 0)
                {
                        // Clerk 2 serves 1 customer
                    int timeWaited = clerks[1].served((timer/1000));
                    totalWaitTime += timeWaited;
                    cout << "Clerk " << clerks[1].getID() << " serviced\n";
                    clerks[1].setCustomerServiceTime((timer/1000));
                    serve.pop();
                    customersServed++;
                }
                if((timer/1000)%90 == 0)
                {
                        // Clerk 3 serves 1 customer
                    int timeWaited = clerks[2].served((timer/1000));
                    totalWaitTime += timeWaited;
                    cout << "Clerk " << clerks[2].getID() << " serviced\n";
                    clerks[2].setCustomerServiceTime((timer/1000));
                    serve.pop();
                    customersServed++;
                }
                if(clerks.size() >= 4 && (timer/1000)%60 == 0) // new clerks
                {
                    for (int clerk=3; clerk< clerks.size(); clerk++)
                    {
                        int timeWaited = clerks[clerk].newClerkServed((timer/1000));
                        totalWaitTime += timeWaited;
                        cout << "Clerk " << clerks[clerk].getID() << " serviced\n";
                        clerks[clerk].setCustomerServiceTime((timer/1000));
                        serve.pop();
                        customersServed++;
                    }
                }
                i++;
            }
        }
        cout << endl << endl;
        int avgWaited = totalWaitTime/customersServed;
        cout << "Avg wait time: " << avgWaited << endl;
    }
};

#endif
