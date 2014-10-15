//
//  Person.h
//  GuessWho
//
//  Created by Kory Brown on 9/26/14.
//  Copyright (c) 2014 AlphA. All rights reserved.


#ifndef GuessWho_Person_h
#define GuessWho_Person_h

//
//  main.cpp
//  GuessWho
//
//  Created by Kory Brown on 9/19/14.
//  Copyright (c) 2014 AlphA. All rights reserved.
//

#include <iostream>
using namespace std;

class Person
{
private:
    
    const string file = "Person Data";
    const int NUM_PEOPLE = 24;
    
    
    
    struct Basic
    {
        string name, skinColor, gender, eyeColor;
    };
    
    
    struct Hair
    {
        string hairType, hairColor, hairLength;
    };
    
    struct FacialHair
    {
        bool facialHair;
        string facialHairType, facialHairColor;
    };
    
    struct Accessories
    {
        bool hat;
        string hatColor;
        bool glasses, earrings;
    };
    
    // initialize structs
    Basic basic;
    Hair hair;
    FacialHair facialHair;
    Accessories accessories;
    
public:
    Person(){}
    ~Person(){}
    
    void operator =(const Person& right)
    {
        basic = right.basic;
        hair = right.hair;
        facialHair = right.facialHair;
        accessories = right.accessories;
        
    }
    
    // Basic
    void setName(string n)
    {
        
        basic.name = n;
    }
    
    void setSkinColor(string n)
    {
        basic.skinColor = n;
    }
    
    void setGender(string n)
    {
        
        basic.gender = n;
    }
    
    void setEyeColor(string s)
    {
        
        basic.eyeColor = s;
    }
    
    
    // Hair
    void setHairType(string n)
    {
        
        hair.hairType = n;
    }
    
    void setHairColor(string n)
    {
        
        hair.hairColor = n;
    }
    
    void setHairLength(string n)
    {
        hair.hairLength = n;
    }
    
    // Facial Hair
    void setFacialHair(bool n)
    {
        facialHair.facialHair = n;
    }
    
    void setFacialHairType(string n)
    {
        if (facialHair.facialHair)
            facialHair.facialHairType = n;
        else
            facialHair.facialHairType = "no facial hair";
    }
    
    void setFacialHairColor(string n)
    {
        if (facialHair.facialHair)
            facialHair.facialHairColor = n;
        else
            facialHair.facialHairColor = "no facial hair";
    }
    
    // Accessories
    void setHat(bool n)
    {
        accessories.hat = n;
    }
    void setHatColor(string n)
    {
        if (accessories.hat)
            accessories.hatColor = n;
        else
            accessories.hatColor = "no hat";
    }
    void setGlasses(bool n)
    {
        accessories.glasses = n;
    }
    void setEarrings(bool n)
    {
        accessories.earrings = n;
    }
    
    
    // Get Basic
    string getName()
    {
        
        return basic.name;
    }
    
    string getSkinColor()
    {
        return basic.skinColor;
    }
    
    string getGender()
    {
        
        return basic.gender;
    }
    
    string getEyeColor()
    {
        
        return basic.eyeColor;
    }
    
    
    // Get Hair
    string getHairType()
    {
        
        return hair.hairType;
    }
    string getHairColor()
    {
        
        return hair.hairColor;
    }
    
    string getHairLength()
    {
        return hair.hairLength;
    }
    
    // Get Facial Hair
    bool hasFacialHair()
    {
        return facialHair.facialHair;
    }
    string getFacialHairType()
    {
        return facialHair.facialHairType;
    }
    string getFacialHairColor()
    {
        return facialHair.facialHairColor;
    }
    
    // Get Accessories
    bool hasHat()
    {
        return accessories.hat;
    }
    string getHatColor()
    {
        return accessories.hatColor;
    }
    bool hasGlasses()
    {
        return accessories.glasses;
    }
    bool hasEarrings()
    {
        return accessories.earrings;
    }
    
    //    void Print()
    //    {
    //        cout << basic.name << " " << basic.gender << " " << basic.eyeColor << endl
    //             << hair.hairType << " " << hair.hairColor << " " << hair.hairLength << endl
    //             << facialHair.facialHairType << " " << facialHair.facialHairColor << endl
    //             << accessories.hat << " " << accessories.hatColor << accessories.glasses
    //             << accessories.earrings << endl;
    //    }
    Person GetPeopleData()
    {
        Person person;
        
        fstream personData(file, ios::in | ios::binary); // stream to read data from file.
        if (personData.fail())
        {
            cout << "File failed....\n";
            exit(1);
        }
        personData.read(reinterpret_cast<char *>(&person), // data is read into person class.
                        sizeof(person));
        return person;
    }
    
    
    
    
};



#endif
