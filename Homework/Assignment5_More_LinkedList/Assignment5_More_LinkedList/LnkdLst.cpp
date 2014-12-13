/*
 * File:   linkedList.cpp
 * Author: Kory Brown
 * Created on September 24, 2014
 * Purpose:  Explore creation of a linked list class
 */

//System Libraries
#include <iostream>
#include <stdlib.h>
using namespace std;

//Our Library
#include "LnkdLst.h"

//int data = 0;
string data = "";
template<class T>
void moreLinkedList(LnkdLst<T> & );

int main()
{
    cout << "Enter data for your first node: ";
    cin  >> data;
    //cin.clear();
    cout << endl;
    LnkdLst<string> list(data);
   

    moreLinkedList(list);
//
//    //Exit stage right!
    return 0;
}

template<class T>
void moreLinkedList(LnkdLst<T> &list)
{
    int choice = 0;
    bool quit = false;
//    system("clear");
    while(!quit)
    {
        cout << "1)Append\n"
             << "2)Prepend Node\n"
             << "3)Insert Before\n"
             << "4)Insert After\n"
             << "5)Extract\n"
             << "6)Show entered data\n"
             << "0)Quit\n";
        
        cout << "choice: ";
        cin  >> choice;
        cout << endl;
        
        string selection = "";
        
        switch (choice)
        {
                
            case 1:
                cout << "Enter data: ";
                cin  >> data;
                    //cin.clear();
                list.Append(data);
                break;
                
            case 2:
                cout << "Enter data: ";
                cin  >> data;
                    //cin.clear();
                list.Prepend(data);
                break;
                
            case 3:
                cout << "Enter the data you want to insert before (if data doesnt exist a new node will added at end of list): ";
                cin  >> selection;
                cin.clear();
                cout << "Enter data: ";
                cin  >> data;
                    //cin.clear();
                list.InsertBefore(selection, data);
                break;
                
            case 4:
                cout << "Enter the data you want to insert after (if data doesnt exist a new node will added at end of list): ";
                cin  >> selection;
                cin.clear();
                cout << "Enter data: ";
                cin  >> data;
                    //cin.clear();
                list.InsertAfter(selection, data);
                break;
                
            case 5:
                cout << "The length of the list is " << list.ListLength()
                << "\nWhat node do you want to extract: ";
                cin  >> choice;
                    //cin.clear();
                cout << "Node " << data << " contains " << list.Extract(choice) << endl;
                break;
                
            case 6:
                list.toString();
                break;
                
            case 0:
                quit = true;
                break;
                
            default:
                break;
        }
        cout << endl;
    }
}