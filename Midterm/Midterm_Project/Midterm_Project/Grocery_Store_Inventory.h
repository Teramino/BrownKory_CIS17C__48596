    //
    //  Groccery_Store_Inventory.h
    //  Midterm_Project
    //
    //  Created by Kory Brown on 12/18/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Midterm_Project_Grocery_Store_Inventory_h
#define Midterm_Project_Grocery_Store_Inventory_h

#include <iostream>

using namespace std;

class Grocery_Store_Inventory
{
private:
    
    char* type;
    char* nameBrand;
    int id;
    
public:
    
    Grocery_Store_Inventory();
    Grocery_Store_Inventory(char* type, char* nameBrand, int id)
    {
        this->type = type;
        this->nameBrand = nameBrand;
        this->id = id;
    }
    ~Grocery_Store_Inventory(){}
    
    char* getType() const
    {
        return type;
    }
    
    char* getNameBrand() const
    {
        return nameBrand;
    }
    
    int getID()
    {
        return id;
    }
    
    void printInfo() const
    {
        cout << "ID:                " << id << '\n'
        << "Type:              " << type << '\n'
        << "Name Brand:        " << nameBrand << '\n'
        << "-------------------------------\n\n";
    }
    
    friend bool operator<(const Grocery_Store_Inventory &a, const Grocery_Store_Inventory &b)
    {
        return a.id < b.id;
    }
    friend bool operator>(const Grocery_Store_Inventory &a, const Grocery_Store_Inventory &b)
    {
        return a.id > b.id;
    }
    friend bool operator==(const Grocery_Store_Inventory &a, const Grocery_Store_Inventory &b)
    {
        return a.id == b.id;
    }    
};

#endif
