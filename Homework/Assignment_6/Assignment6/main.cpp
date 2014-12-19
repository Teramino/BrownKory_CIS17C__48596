/*
 * File:   linkedList.cpp
 * Author: Kory Brown
 * Created on September 24, 2014
 * Purpose:  Explore creation of a linked list class
 */

    //System Libraries
#include <iostream>
#include <stdlib.h>


    // Our Library
#include "LnkdLst.h"
#include "Doubley.h"
#include "Circularly.h"
#include "Queue.h"
#include "WaitLine.h"

using namespace std;

int data = 0;
    //string data = "";

void DoubleLinkedList();
void QueueLinkedList();
template<class T>
void CircularlyLinkedList();
void prompt();

LnkdLst<int> l;
Doubley<int> d;
Circularly<int> c;
Queue<int> q;

int main()
{
    prompt();
    
        // Exit stage right!
    return 0;
}

void prompt()
{
    int choice = 0;
    bool quit = false;
    while(!quit)
    {
        cout << "1) Doubley Linked List\n"
        << "2) Circulary Linked List\n"
        << "3) Queue\n"
        << "0) Quit\n";
        
        cout << "choice: ";
        cin  >> choice;
        cout << endl;
        
        switch (choice)
        {
                
            case 1:
                DoubleLinkedList();
                break;
                
            case 2:
                CircularlyLinkedList<int>();
                break;
                
            case 3:
                QueueLinkedList();
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

void DoubleLinkedList()
{
    int choice = 0;
    bool quit = false;
    
    while(!quit)
    {
        cout << "1) Append\n"
        << "2) Prepend Node\n"
        << "3) Show entered data\n"
        << "0) Quit\n";
        
        cout << "choice: ";
        cin  >> choice;
        cout << endl;
        
        switch (choice)
        {
                
            case 1:
                cout << "Enter data: ";
                cin  >> data;
                d.Append(data);
                break;
                
            case 2:
                cout << "Enter data: ";
                cin  >> data;
                d.Prepend(data);
                break;
            case 3:
                d.toString();
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

void QueueLinkedList()
{
    int choice = 0;
    bool quit = false;
    while(!quit)
    {
        cout << "1) Queue\n"
        << "2) Priority Queue\n"
        << "0) Quit\n";
        
        cout << "choice: ";
        cin  >> choice;
        cout << endl;
        
        WaitLine line;
        switch (choice)
        {
                
            case 1:
                
                line.simulate ( 2000,  0.1,  40);
                break;
            case 2:
                    //                WaitLine line;
                line.simulatePriorityLine ( 2000,  0.1,  40);
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

template<class T>
void CircularlyLinkedList()
{
    int choice = 0;
    bool quit = false;
        //    system("clear");
    T selection;
    while(!quit)
    {
        cout << "1) Append\n"
        << "2) Prepend Node\n"
        << "3) Insert Before\n"
        << "4) Insert After\n"
        << "5) Extract\n"
        << "6) Sort\n"
        << "7) Show entered data\n"
        << "0) Quit\n";
        
        cout << "choice: ";
        cin  >> choice;
        cout << endl;
        
        
        switch (choice)
        {
                
            case 1:
                cout << "Enter data: ";
                cin  >> data;
                c.Append(data);
                break;
                
            case 2:
                cout << "Enter data: ";
                cin  >> data;
                c.Prepend(data);
                break;
                
            case 3:
                cout << "Enter the data you want to insert before (if data doesnt exist a new node will added at end of list): ";
                cin  >> selection;
                cin.clear();
                cout << "Enter data: ";
                cin  >> data;
                c.InsertBefore(selection, data);
                break;
                
            case 4:
                cout << "Enter the data you want to insert after (if data doesnt exist a new node will added at end of list): ";
                cin  >> selection;
                cin.clear();
                cout << "Enter data: ";
                cin  >> data;
                c.InsertAfter(selection, data);
                break;
                
            case 5:
                cout << "The length of the list is " << c.ListLength()
                << "\nWhat node do you want to extract: ";
                cin  >> choice;
                    //cin.clear();
                cout << "Node " << data << " contains " << c.Extract(choice) << endl;
                break;
                
            case 6:
                c.Sort();
                break;
            case 7:
                c.toString();
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