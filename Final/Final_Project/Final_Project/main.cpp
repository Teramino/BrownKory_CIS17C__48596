    //
    //  main.cpp
    //  Midterm_Project
    //
    //  Created by Kory Brown on 12/17/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#include <iostream>
#include "Hospital.h"
#include "Bank.h"
#include "Grocery_Store.h"
#include "Patient.h"
#include "Customer.h"
#include "BusinessManager.h"
#include "WeightedGraph.h"


using namespace std;

void prompt();

Hospital *hospital = new Hospital(2, "hospital",30, true);
Bank *bank = new Bank(1, "bank",30, true);
Grocery_Store *gStore = new Grocery_Store(3, "grocGroceryery store", false);
Patient patient;
Customer customer;
BusinessManager *businessManager = new BusinessManager;
WeightedGraph transportation;

bool goToHospital = false;
bool goToBank = false;
int randomAccident;
int randomNumber;
int startingPoint = 0; // always starts at the car stop;
int totalDistanceTraveled = 0;


int main()
{
    srand(time(NULL));
    
    businessManager->addBusiness(gStore->getID(), gStore);
    businessManager->addBusiness(bank->getID(), bank);
    businessManager->addBusiness(hospital->getID(), hospital);
    
    prompt();
    
    return 0;
}

void prompt()
{
    int choice = 0;
    bool quit = false;
    
    cout << "Welcome to Alpha's Distance Traveler Simulator\n"
    << "=======================================\n\n";
    
    while(!quit)
    {
        if (totalDistanceTraveled > 0)
        {
            int distance = totalDistanceTraveled % 10;
            if(distance == 0)
            {
                randomAccident = (int) rand() % 10;
                if(randomAccident >= 0 && randomAccident <5)
                {
                    if (startingPoint != 1)
                    {
                        randomNumber = (int) rand() % 10;
                        switch((int)randomNumber)
                        {
                            case WINNING:
                                cout << "\nYou hit the lottery go straight to the bank\n\n";
                                goToBank = true;
                                customer = *new Customer(WINNING);
                                break;
                            case PAYDAY:
                                cout << "\nPay Day! Go cash your check\n";
                                goToBank = true;
                                customer = *new Customer(PAYDAY);
                                break;
                            case BROKE:
                                cout << "\nWhat were you thinking!? How are you going to eat now? "
                                << "Go pull out some money\n\n";
                                goToBank = true;
                                customer = *new Customer(BROKE);
                                break;
                            case ROBBED:
                                cout << "\nDang you just got robbed. Go get some money\n\n";
                                goToBank = true;
                                customer = *new Customer(ROBBED);
                                break;
                            default:
                                break;
                        }
                    }
                }
                else
                {
                    if (startingPoint != 2)
                    {
                        randomNumber = (int) rand() % 10;
                        switch((int)randomNumber)
                        {
                            case STROKE:
                                cout << "\nYou just had a Stroke. Go straight to the hospital\n\n";
                                goToHospital = true;
                                patient = *new Patient(STROKE);
                                break;
                            case SHOT:
                                cout << "\nWhat the heck were you doing. You been shot\n\n";
                                goToHospital = true;
                                patient = *new Patient(SHOT);
                                break;
                            case BROKEN_LEG:
                                cout << "\nWOW! Looked like that hurt. Your leg is broken\n\n";
                                goToHospital = true;
                                patient = *new Patient(BROKEN_LEG);
                                break;
                            case SICK:
                                cout << "\nYou came down with the flu. Get to the hospital\n1\n";
                                goToHospital = true;
                                patient = *new Patient(SICK);
                                break;
                            default:
                                break;
                        }
                    }
                    
                }
            }
        }
        cout << "You are here:  " << transportation.getDistance().getLocation(startingPoint) << endl << endl;
        
        cout << "Where would you like to travel to:<# corresponds to ID>\n"
        << "1) Bank \n"
        << "2) Hospital\n"
        << "3) Grocerry Store\n"
        << "0) Quit\n";
        
        cout << "choice: ";
        cin  >> choice;
        cin.ignore(99,'\n');
        cout << endl;
        
        totalDistanceTraveled += transportation.simulate(startingPoint, choice);
        
        Business b;
        if(goToHospital && choice != 2)
        {
            cout << "\nYou need to go to the hospital\n";
            choice = -1;
        }
        else if(goToBank && choice != 1)
        {
            cout << "\nYou need to go to the bank\n";
            choice = -1;
        }
        
        switch (choice)
        {
            case 0:
                quit = true;
                break;
            case 1:
                if (!goToBank)
                {
                    Business b = *businessManager->findBusiness(choice);
                    if (b.getID() == bank->getID())
                    {
                        randomNumber = (int) rand() % 10;
                        switch((int)randomNumber)
                        {
                            case WINNING:
                                customer = *new Customer(WINNING);
                                break;
                            case PAYDAY:
                                customer = *new Customer(PAYDAY);
                                break;
                            case BROKE:
                                customer = *new Customer(BROKE);
                                break;
                            case ROBBED:
                                customer = *new Customer(ROBBED);
                                break;
                            default:
                                if (randomNumber > 1 && randomNumber <= 6)
                                    customer = *new Customer(PAYDAY);
                                else if (randomNumber > 6 && randomNumber <= 8)
                                    customer = *new Customer(BROKE);
                                else
                                    customer = *new Customer(ROBBED);
                                break;
                        }
                        
                        bank->simulate(customer);
                        startingPoint = 1;
                    }
                }
                break;
                
            case 2:
                if (!goToHospital)
                {
                    b = *businessManager->findBusiness(choice);
                    if (b.getID() == hospital->getID())
                    {
                        randomNumber = (int) rand() % 10;
                        switch((int)randomNumber)
                        {
                            case STROKE:
                                patient = *new Patient(STROKE);
                                break;
                            case SHOT:
                                patient = *new Patient(SHOT);
                                break;
                            case BROKEN_LEG:
                                patient = *new Patient(BROKEN_LEG);
                                break;
                            case SICK:
                                patient = *new Patient(SICK);
                                break;
                            default:
                                if (randomNumber > 3 && randomNumber <= 5)
                                    patient = *new Patient(BROKEN_LEG);
                                else
                                    patient = *new Patient(SICK);
                                break;
                        }
                        
                        
                        hospital->simulate(patient);
                        startingPoint = 2;
                    }
                }
                break;
            case 3:
                b = *businessManager->findBusiness(choice);
                if (b.getID() == gStore->getID())
                {
                    gStore->simulate();
                    startingPoint = 3;
                }
                break;
            default:
                break;
        }
        cout << endl;
    }
}
