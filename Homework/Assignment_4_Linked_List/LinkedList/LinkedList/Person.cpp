//
//  PersonData.cpp
//  GuessWho
//
//  Created by Kory Brown on 9/26/14.
//  Copyright (c) 2014 AlphA. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <stdlib.h>
#include "Person.h"
#include "LnkdLst.h"

using namespace std;


void CreatePeople(); // creates a txt file that contains specifed list of people from the person class
void DisplayPeople(); // read from text file the list of people and output to console
void AddDataToPerson(); // allows you to select which person you want edit and updates the changes to file
void Prompt(); // Allows to display or add data to a person continuously

Person person;
LnkdLst<Person> people;
const string file = "Person Data";
const int NUM_PEOPLE = 24;

int main()
{
    
    CreatePeople();
    //DisplayPeople();
    //AddDataToPerson();
    Prompt();
    
    return 0;
}

void Prompt()
{
    //    DisplayPeople();
    bool quit = false;
    int choice = 0;
    while(!quit)
    {
        cout << "1) Add data to a person\n"
        << "2) Display People\n"
        << "3) Quit\n"
        << "choice: ";
        cin  >> choice;
        cout << endl;
        
        switch(choice)
        {
            case 1:
                //system("clear"); // doesnt work in Xcode
                AddDataToPerson();
                break;
            case 2:
                //system("clear"); // doesnt work in Xcode
                DisplayPeople();
                break;
            case 3:
                quit = true;
                break;
        }
    }
    cout << endl;
}

void GetPeopleData()
{
    fstream personData(file, ios::in | ios::binary); // stream to read data from file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    personData.read(reinterpret_cast<char *>(&person), // data is read into person class.
                    sizeof(person));
    
    while(!personData.eof())
    {
        people.Append(person);
        
        personData.read(reinterpret_cast<char *>(&person),sizeof(person));
    }
    personData.close();
}
void DisplayPeople()
{
    fstream personData(file, ios::in | ios::binary); // stream to read data from file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    personData.read(reinterpret_cast<char *>(&person), // data is read into person class.
                    sizeof(person));
    int personCount = 0;
    while(!personData.eof())
    {
        personCount++;
        cout << "Person " << personCount
        << "\nName: " << person.getName()<< endl
        << "Gender: " << person.getGender()
        << " Skin Color: " << person.getSkinColor()
        << " Eye Color: " << person.getEyeColor() << endl;
        
        cout << "Hair Type: " << person.getHairType()
        << " Hair Color: " << person.getHairColor()
        << " Hair Length: " << person.getHairLength() << endl;
        
        cout << "Facial Hair: " << person.hasFacialHair()
        << "Facial Hair Type: " << person.getFacialHairType()
        << " Facial Hair Color: " << person.getFacialHairColor() << endl;
        
        cout << "Hat: " << person.hasHat()
        << " HatColor: " << person.getHatColor()
        << " Glasses: " << person.hasGlasses()
        << " Earrings: " << person.hasEarrings() << endl << endl;
        
        personData.read(reinterpret_cast<char *>(&person),sizeof(person));
    }
    personData.close();
}


void CreatePeople()
{
    // creating space in each memeber of the structs.
    person.setName("");
    person.setGender("");
    person.setSkinColor("");
    person.setEyeColor("");
    person.setHairType("");
    person.setHairColor("");
    person.setHairLength("");
    person.setFacialHair(false);
    person.setFacialHairType("");
    person.setFacialHairColor("");
    person.setHat(false);
    person.setHatColor("");
    person.setGlasses(false);
    person.setEarrings(false);
    
    fstream personData(file, ios::out | ios::binary); // stream to write data to a file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    
    for (int i=1; i<=NUM_PEOPLE; i++) // NUM_PEOPLE - can be changed to the desired amount of people we want to describe.
    {
        cout << "Now writing person " << i << endl;
        personData.write(reinterpret_cast<char *>(&person),sizeof(person));
        
    }
    cout << endl;
    personData.close();
}

// Can go through one by one giving a Person's decription by inputting the diesired person you want to provide data with.
void AddDataToPerson()
{
    int i;
    bool correctInput = false;
    
    // Open the file in binary mode for input and output
    fstream personData(file, ios::in | ios::out | ios::binary); // stream to read and write to file.
    if (personData.fail())
    {
        cout << "File failed....\n";
        exit(1);
    }
    do {
        // Get the person number of the desired record.
        cout << "Which person do you want to edit <1-" << NUM_PEOPLE <<">? ";
        cin >> i;
        if (i > 0 && i <= NUM_PEOPLE)
            correctInput = true;
    }while(!correctInput);
    cout << endl;
    
    if (i == 1)
        i--;
    else if (i == NUM_PEOPLE)
        i--;
    // Move to the person selected and read it.
    personData.seekg(i * sizeof(person), ios::beg);
    personData.read(reinterpret_cast<char *>(&person),
                    sizeof(person));
    
    // Display the person contents.
    cout << "\nName: " << person.getName()<< endl
    << "Gender: " << person.getGender()
    << " Skin Color: " << person.getSkinColor()
    << " Eye Color: " << person.getEyeColor() << endl;
    
    cout << "Hair Type: " << person.getHairType()
    << " Hair Color: " << person.getHairColor()
    << " Hair Length: " << person.getHairLength() << endl;
    
    cout << "Facial Hair: " << person.hasFacialHair()
    << "Facial Hair Type: " << person.getFacialHairType()
    << " Facial Hair Color: " << person.getFacialHairColor() << endl;
    
    cout << "Hat: " << person.hasHat()
    << " HatColor: " << person.getHatColor()
    << " Glasses: " << person.hasGlasses()
    << " Earrings: " << person.hasEarrings() << endl << endl;
    
    string name = "";
    string gender = "";
    string skinColor = "";
    string eyeColor = "";
    string hairType = "";
    string hairColor = "";
    string hairLength = "";
    string facialHairType = "";
    string facialHairColor = "";
    string hatColor = "";
    
    // Get the new person data.
    char answer = NULL;
    cout << "Enter the new data:\n";
    cout << "Person Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Gender: ";
    cin  >> gender;
    cout << "Skin Color: ";
    cin  >> skinColor;
    cout << "Eye Color: ";
    cin  >> eyeColor;
    cout << "Hair Type: ";
    cin >> hairType;
    cout << "Hair Color: ";
    cin  >> hairColor;
    cout << "Hair Length: ";
    cin  >> hairLength;
    do
    {
        cout << "Facial Hair <Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y')
        {
            correctInput = true;
            person.setFacialHair(true);
            cout <<  person.hasFacialHair() << endl;
        }
        else if (tolower(answer) == 'n')
        {
            correctInput = true;
            person.setFacialHair(false);
        }
        else
            correctInput = false;
    }while(!correctInput);
    
    if(person.hasFacialHair() == true)
    {
        cout << "Facial hair type: ";
        cin  >> facialHairType;
        cout << "Facial Hair Color: ";
        cin  >> facialHairColor;
        person.setFacialHairType(facialHairType);
        person.setFacialHairColor(facialHairColor);
    }
    else
    {
        person.setFacialHairType("none");
        person.setFacialHairColor("none");
    }
    do
    {
        cout << "Hat <Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y')
        {
            correctInput = true;
            person.setHat(true);
        }
        else if(tolower(answer) == 'n')
        {
            correctInput = true;
            person.setHat(false);
        }
        else
            correctInput = false;
    }while(!correctInput);
    if (person.hasHat() == true)
    {
        cout << "HatColor: ";
        cin  >> hatColor;
        person.setHatColor(hatColor);
    }
    else
        person.setHatColor("none");
    do
    {
        cout << "Glasses <Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y')
        {
            correctInput = true;
            person.setGlasses(true);
        }
        else if (tolower(answer) == 'n')
        {
            correctInput = true;
            person.setGlasses(false);
        }
        else
            correctInput = false;
    }while(!correctInput);
    
    do
    {
        cout << "Earrings <Y or N>: ";
        cin >> answer;
        if ( tolower(answer)== 'y')
        {
            correctInput = true;
            person.setEarrings(true);
        }
        else if(tolower(answer) == 'n')
        {
            correctInput = true;
            person.setEarrings(false);
        }
        else
            correctInput = false;
    }while(!correctInput);
    cout << endl;
    
    person.setName(name);
    person.setGender(gender);
    person.setSkinColor(skinColor);
    person.setEyeColor(eyeColor);
    person.setHairType(hairType);
    person.setHairColor(hairColor);
    person.setHairLength(hairLength);
    
    
    //     Move back to the beginning of this person's position.
    personData.seekp(i * sizeof(person), ios::beg);
    
    // Write the new person over the current person.
    personData.write(reinterpret_cast<char *>(&person),
                     sizeof(person));
    personData.close();
}

