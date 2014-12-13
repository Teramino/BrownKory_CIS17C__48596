//
//  main.cpp
//  _17C Midterm
//
//  Created by Kory Brown on 11/7/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "LnkdLst.h"
#include "Organizer.h"

using namespace std;

//template <class T>
vector<int> getVectorElements(vector<int>,int);
LnkdLst getListElements(LnkdLst &, int);
void generateRandomNumbers();
void addArrayToVector();
void findVectorMode();
void showVector(vector<int>);
void returnTopVectorElements();
void returnTopListElements();
void addArrayToList();
void showList(LnkdLst&);
void findListMode();
void arrayClear();
void vectorPrompt();
void listPrompt();
void contains();
void prompt();

const int SIZE = 10;
int randomNumbers[SIZE];
int mode;
vector<int> v;
vector<int> otherV;
LnkdLst list;
LnkdLst otherL;
Organizer<int> organizer;

int main(int argc, const char * argv[])
{
    srand (time(NULL));
    cout << "17C Midterm::: 95:100\nElement's Integers\n\n";
    prompt();
    
    return 0;
}
void prompt()
{
    bool quit = false;
    int choice = 0;
    while(!quit)
    {
        cout << "1) Vector\n"
        << "2) List\n"
        << "3) Quit\n"
        << endl
        << "choice: ";
        cin  >> choice;
        cout << endl << endl;
        
        switch(choice)
        {
            case 1:
                vectorPrompt();
                break;
            case 2:
                listPrompt();
                break;
            case 3:
                quit = true;
                break;
            default:
                cout << "Invalid input...\n\n";
                break;
        }
    }
    cout << endl;
    exit(1);
    
}
void vectorPrompt()
{
    bool back = false;
    int choice = 0;
    while(!back)
    {
        cout << "1) Generate Random #'s\n"
        << "2) Add Random #'s to vector\n"
        << "3) Show Vector\n"
        << "4) Show Other Vector\n"
        << "5) Vector Mode\n"
        << "6) Transfer Elements to Other Vector\n"
        << "7) Clear Vector\n"
        << "8) Back\n"
        << endl
        << "choice: ";
        cin  >> choice;
        cout << endl;
        
        switch(choice)
        {
            case 1:
                arrayClear();
                generateRandomNumbers();
                break;
            case 2:
                addArrayToVector();
                break;
            case 3:
                showVector(v);
                break;
            case 4:
                showVector(otherV);
                break;
            case 5:
                findVectorMode();
                break;
            case 6:
                returnTopVectorElements();
                break;
            case 7:
                v.clear();
                showVector(v);
                break;
            case 8:
                back = true;
                break;
            default:
                cout << "Invalid input...\n\n";
                break;
        }
    }
    cout << endl;
    prompt();
    
}
void listPrompt()
{
    bool back = false;
    int choice = 0;
    while(!back)
    {
        cout << "1) Generate Random #'s\n"
        << "2) Add Random #'s to list\n"
        << "3) List Mode\n"
        << "4) Transfer Elements to Other List\n"
        << "5) Show List\n"
        << "6) Show Other List\n"
        << "7) Find\n"
        << "8) Back\n"
        << endl
        << "choice: ";
        cin  >> choice;
        cout << endl;
        
        switch(choice)
        {
            case 1:
                arrayClear();
                generateRandomNumbers();
                break;
            case 2:
                addArrayToList();
                break;
            case 3:
                findListMode();
                break;
            case 4:
                returnTopListElements();
                break;
                break;
            case 5:
                showList(list);
                break;
            case 6:
                showList(otherL);
                break;
            case 7:
                contains();
                break;
            case 8:
                back = true;
                break;
            default:
                cout << "Invalid input...\n\n";
                break;
                
        }
    }
    cout << endl;
    prompt();
    
}
void generateRandomNumbers()
{
    for(int i=0; i<SIZE; i++)
    {
        randomNumbers[i] = rand() % 21 + 1;
        cout << randomNumbers[i] << " ";
    }
    cout << endl << endl;
}

void arrayClear()
{
    for(int i=0; i<SIZE; i++)
    {
        randomNumbers[i] = NULL;
    }
}

//========================================= VECTOR =====================================

void addArrayToVector()
{
    for(int i=0; i<SIZE; i++)
    {
        cout << randomNumbers[i] << " ";
        v.push_back(randomNumbers[i]);
    }
    cout << endl << "Added to vector\n\n";
}

void showVector(vector<int> x)
{
    if (x.size() > 0)
    {
        for(int i=0; i<x.size(); i++)
        {
            
            cout << x[i] << " ";
        }
    }
    else
        cout << "No elements";
    
    cout << endl << endl;
}

void findVectorMode()
{
    bool isMode = false;
    int mode = -1;
    int tempMode = -1;
    int modeCount = 0;
    int prevModeCount = 0;
    for(int i=0; i<v.size(); i++)
    {
        modeCount = 0;
        for(int j=i+1; j<v.size(); j++)
        {
            if(v[i] == v[j])
            {
                tempMode = v[i];
                modeCount++;
                isMode = false;
            }
        }
        if (modeCount > prevModeCount)
        {
            mode = tempMode;
            prevModeCount = modeCount;
            isMode = true;
        }
        else if (modeCount == prevModeCount && !isMode)
            mode = -1;
        
    }
    cout << "Vector\n";
    showVector(v);
    if (mode != -1)
    {
        cout << "Mode: " << mode << endl << endl;
    }
    else
        cout << "No Mode " << endl << endl;
}

void returnTopVectorElements()
{
    vector<int> (*top)(vector<int> x, int p);
    top = getVectorElements;
    int x = 0;
    showVector(v);
    cout << "How many elements do you want: ";
    cin  >> x;
    otherV = top(v,x);
    showVector(otherV);
}

//template <class T>
vector<int> getVectorElements(vector<int> x,int p)
{
    vector<int> temp;
    cout << "Vector: ";
    for(int i=0; i<p; i++)
    {
        cout << x[i] << " ";
        temp.push_back(x[i]);
    }
    cout << endl;
    cout << "Transferred Vector: ";
    return temp;
}



//========================================= LIST =====================================
LnkdLst getListElements(LnkdLst & x, int p)
{
    LnkdLst temp;
    int count = 0;
    cout << "List: ";
    while(p > count)
    {
        
        cout << x.getData(count) << " ";
        temp.append(x.getData(count));
        count++;
        // need to figure out how to access node data from list
    }
    cout << endl;
    cout << "Transferred List: ";
    return temp;
    
    
}

void showList(LnkdLst & l)
{
    if(l.getFirstNode())
    {
        l.toString();
        cout << endl;
    }
    else
        cout << "No nodes\n\n";
}

void returnTopListElements()
{
    LnkdLst (*top)(LnkdLst & x, int p);
    top = getListElements;
    int x = 0;
    showList(list);
    cout << "How many elements do you want: ";
    cin  >> x;
    otherL = top(list,x);
    showList(otherL);
}

void addArrayToList()
{
    for(int i=0; i<SIZE; i++)
    {
        cout << randomNumbers[i] << " ";
        list.append(randomNumbers[i]);
    }
    cout << endl << "Added to list\n\n";
    
}

void findListMode()
{
    bool isMode = false;
    int mode = -1;
    int tempMode = -1;
    int modeCount = 0;
    int prevModeCount = 0;
    for(int i=0; i<SIZE; i++)
    {
        modeCount = 0;
        for(int j=i+1; j<SIZE; j++)
        {
            int first = list.getData(i);
            int second = list.getData(j);
            if(first == second)
            {
                tempMode = list.getData(i);
                modeCount++;
                isMode = false;
            }
        }
        if (modeCount > prevModeCount)
        {
            mode = tempMode;
            prevModeCount = modeCount;
            isMode = true;
        }
        else if (modeCount == prevModeCount && !isMode)
            mode = -1;
        
    }
    cout << "List\n";
    showList(list);
    if (mode != -1)
    {
        cout << "Mode: " << mode << endl << endl;
    }
    else
        cout << "No Mode " << endl << endl;
}

void contains()
{
    showList(list);
    
    int find;
    bool found;
    
    cout << "What element do you want to find: ";
    cin  >> find;
    cout << endl;
    found = organizer.seek(list, find);
    
    if (found)
        cout << "Found what your looking for\n\n";
    else
        cout << "No luck\n\n";
    
    showList(list);
}


