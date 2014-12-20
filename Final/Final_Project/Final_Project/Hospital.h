    //
    //  Hospital.h
    //  Midterm_Project
    //
    //  Created by Kory Brown on 12/17/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Midterm_Project_Hospital_h
#define Midterm_Project_Hospital_h

#include <iostream>
#include "Business.h"
#include "PriorityQueue.h"
#include "Patient.h"
#include <iomanip>

using namespace std;

class Hospital : public Business
{
    private :
    
    PriorityQueue<Patient> line;
    
public:
    
    Hospital(int id, string name, int approxLineLength, bool priority): Business(id, name, approxLineLength, priority){}
    ~Hospital(){}
    
    virtual void simulate(Patient p)
    {
        cout << setw(48) << "Welcome to the Hospital\n";
         cout << "=========== Clock starts from the service of first customer ===========\n\n";
        
        srand(time(NULL));
        line = *new PriorityQueue<Patient>();
        
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
                
                Patient nextArrival (priority, clock, transactionTime, numberOfArrivals);
                
                line.Enqueue(nextArrival, nextArrival.getCondition());
            }
        } // end for
        
            // Create Patient data
        random = ((double) rand() / (RAND_MAX));
        int maxArrivalTime = 10;
        int lastKnownArrivalTime = line.peekLast().getArrivalTime();
        int arrivalTime = random * maxArrivalTime;
        arrivalTime += lastKnownArrivalTime;
        
        p = *new Patient(p.getCondition(), arrivalTime, 10, numberOfArrivals+1);
        
        string condition = "";
        switch(p.getCondition())
        {
            case 0:
                condition = "Stroke";
                cout << "You entered the hospital with a " << condition << ".\nWe will see you right now!\n" ;
                break;
            case 1:
                 condition = "Shot";
                cout << "You entered the hospital " << condition << ".\nHolly Molly we will put near the front of the line\n";
                break;
            case 5:
                 condition = "Broken Leg";
                cout << "You entered the hospital with a " << condition << ".\nWait to be seen\n";
                break;
            case 9:
                 condition = "Sick";
                cout << "You entered the hospital " << condition << ".\nGet to the back of the line there's no rush\n";
                break;
        }
        
        line.Enqueue(p, p.getCondition());
        int spot = line.getSpotInLine(p);
        
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
                Patient nextPatient = (Patient)line.Dequeue();
                transactionTimeLeft = nextPatient.getTransactionTime () - 1;
                float timeWaited = (float)(clock - nextPatient.getArrivalTime()) / 60;
                float clockInMinutes = (float) clock/60;
                
                if (nextPatient == p)
                {
                    cout << "You are now being serviced\n"
                    << "You are Patient " << nextPatient.getCustomerNumber() << " and is being serviced at time from first Patient "
                    << clockInMinutes << ". Time you waited is "<< timeWaited << " minutes\n";
                    cout << "You are now recovered\n";
                    break;
                }
                else
                {
                    cout << "Patient " << nextPatient.getCustomerNumber() << " begins service at time from first Patient "
                    << clockInMinutes << " minutes. Time waited is "<< timeWaited << " minutes\n\n";
                }
            }
            clock++;
        }
    }
};

#endif
