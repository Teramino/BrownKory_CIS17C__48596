    //
    //  Groccery_Store.h
    //  Midterm_Project
    //
    //  Created by Kory Brown on 12/18/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Midterm_Project_Grocery_Store_h
#define Midterm_Project_Grocery_Store_h

#include "Business.h"
#include "Customer.h"
#include "PriorityQueue.h"
#include "Grocery_Store_Inventory.h"
#include <iomanip>
#include <set>

using namespace std;

class Grocery_Store : public Business
{
private:
    
    PriorityQueue<Customer> line;
    set<Grocery_Store_Inventory *> inventory;
    set<Grocery_Store_Inventory *> shoppingList;
    
    Grocery_Store_Inventory *Milk;
    Grocery_Store_Inventory *Cereal;
    Grocery_Store_Inventory *Watermelon;
    
public:
    
    Grocery_Store(){}
    ~Grocery_Store()
    {
        delete Milk;
        delete Cereal;
        delete Watermelon;
        inventory.clear();
        shoppingList.clear();
    }
    
    Grocery_Store(int id, string name, bool priority): Business(id, name, -1, priority)
    {
        initializeInventory();
    }
    
    Grocery_Store& operator=(const Business &right)
    {
        this->id = right.getID();
        this->name = right.getName();
        this->priority = right.getPriority();
        this->initializeInventory();
        return *this;
        
    }
    
    virtual void simulate()
    {
        cout << setw(50) << "Welcome to the Groccery Store\n";
        cout << "=========== Clock starts from the service of first customer ===========\n\n";
        
        srand(time(NULL));
        lineLength = rand() % 50 + 1;
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
                
                Customer nextArrival (clock, transactionTime, numberOfArrivals);
                
                line.Enqueue(nextArrival);
            }
        } // end for
        
            // Create Customer data
        random = ((double) rand() / (RAND_MAX));
        int maxArrivalTime = 10;
        int lastKnownArrivalTime = line.peekLast().getArrivalTime();
        int arrivalTime = random * maxArrivalTime;
        arrivalTime += lastKnownArrivalTime;
        
        Customer customer = *new Customer(arrivalTime, 10, numberOfArrivals+1);
        line.Enqueue(customer);
        int spot = line.getSpotInLine(customer);
        
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
                
                if (nextPatient == customer)
                {
                    cout << "\nYou are now being serviced\n"
                    << "You are customer " << nextPatient.getCustomerNumber() << " and is being serviced at time from first Customer "
                    << clockInMinutes << ". Time you waited is "<< timeWaited << " minutes\n\n";
                    
                    cout << "=================================\n"
                    << "Cashier: What do we have here?\n\n"
                    << "Enter your grocceries:\n";
                    
                    int choice = 0;
                    bool quit = false;
                    
                    while(!quit)
                    {
                        cout << "1) Print Store Inventory\n"
                        << "2) Enter groccery\n"
                        << "3) Print Shopping List\n"
                        << "0) All Done\n";
                        cout << "choice: ";
                        cin  >> choice;
                        cout << endl;
                        
                        switch (choice)
                        {
                            case 1:
                                printList(inventory);
                                break;
                            case 2:
                                cout << "\nWhat is the ID: ";
                                cin  >> choice;
                                shoppingList.insert(findGroccery(choice));
                                break;
                            case 3:
                                printList(shoppingList);
                                break;
                            case 0:
                                quit = true;
                                break;
                                
                            default:
                                break;
                        }
                        cout << endl;
                    }
                    cout << "=================================\n"
                         << setw(25) << "Shopping List\n\n";
                    printList(shoppingList);
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
    
    void initializeInventory()
    {
        Milk = new Grocery_Store_Inventory("Dairy", "Milk", 1);
        Cereal = new Grocery_Store_Inventory("Grain", "Cereal", 2);
        Watermelon = new Grocery_Store_Inventory("Fruit", "Watermelon", 3);
        
        inventory.insert(Milk);
        inventory.insert(Cereal);
        inventory.insert(Watermelon);
    }
    
    Grocery_Store_Inventory* findGroccery(int id)
    {
        for (set<Grocery_Store_Inventory *>::iterator it = inventory.begin(); it != inventory.end(); ++it)
        {
            if (id == (*it)->getID())
            {
                cout << (*it)->getNameBrand() << " added to shopping list\n";
                return *it;
            }
        }
        
        cout << "Groccery not found.\n\n";
        
        return NULL;
    }
    
    void printList(set<Grocery_Store_Inventory *> list)
    {
        for (set<Grocery_Store_Inventory*>::iterator it = list.begin(); it != list.end(); ++it)
            (*it)->printInfo();
    }
    
};


#endif
