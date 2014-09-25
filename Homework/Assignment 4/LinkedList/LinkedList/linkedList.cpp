/* 
 * File:   linkedList.cpp
 * Author: Kory Brown
 * Created on September 24, 2014
 * Purpose:  Explore creation of a linked list class
 */

//System Libraries
#include <iostream>
using namespace std;

//Our Library
#include "LnkdLst.h"

int main()
{
    //Create a linked list
    LnkdLst list(0);
    
    //Append 3 more chains
    int clinks=3;
    
    for(int i=1;i<=clinks;i++)
    {
        list.append(i);
    }
    
    //Print the data
    list.toString();
    cout << endl;
    
    //Exit stage right!
    return 0;
}