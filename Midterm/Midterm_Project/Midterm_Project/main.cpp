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


using namespace std;

void prompt();

Hospital *hospital = new Hospital(2, "hospital",30, true);
Bank *bank = new Bank(3, "bank",30, true);
Grocery_Store *gStore = new Grocery_Store(1, "grocGroceryery store", false);
Patient patient;
Customer customer;
BusinessManager *businessManager = new BusinessManager;

bool goToHospital = false;
float randomAccident = .01;
float randomNumber;


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
    
    cout << "Welcome to Alpha's Waitline Simulator\n"
    << "=======================================\n\n";
    
    while(!quit)
    {
        cout << "Where would you like to visit:<# corresponds to ID>\n"
        << "1) Grocerry Store\n"
        << "2) Hospital\n"
        << "3) Bank\n"
        << "0) Quit\n";
        
        cout << "choice: ";
        cin  >> choice;
        cin.ignore(99,'\n');
        cout << endl;
        Business b;
        switch (choice)
        {
            case 0:
                quit = true;
                break;
            case 1:
                b = *businessManager->findBusiness(choice);
                if (b.getID() == gStore->getID())
                    gStore->simulate();
                break;
            case 2:
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
                }
                hospital->simulate(patient);
                break;
            case 3:
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
                }
                break;
        }
        cout << endl;
    }
}
