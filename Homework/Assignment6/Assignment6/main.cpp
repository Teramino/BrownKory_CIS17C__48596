/*
 * File:   linkedList.cpp
 * Author: Kory Brown
 * Created on September 24, 2014
 * Purpose:  Explore creation of a linked list class
 */

//System Libraries
#include <iostream>
#include <stdlib.h>
#include "WaitLine.h"

using namespace std;

//Our Library
#include "LnkdLst.h"

int data = 0;
//string data = "";
template<class T>
void DoubleLinkedList(LnkdLst<T> & );
template<class T>
void QueueLinkedList(LnkdLst<T> & );
template<class T>
void CircularlyLinkedList(LnkdLst<T> &list);

int main()
{
    cout << "Enter data for your first node: ";
    cin  >> data;
    //cin.clear();
    cout << endl;
    LnkdLst<int> list(data, " ");
//

//    DoubleLinkedList(list);
    CircularlyLinkedList(list);
    
//    WaitLine line;
//    line.simulate ( 2000,  0.1,  40);
//    //Exit stage right!
    return 0;
}

template<class T>
void DoubleLinkedList(LnkdLst<T> &list)
{
    int choice = 0;
    bool quit = false;
//    system("clear");
    T selection;
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
                list.doubleyToString();
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
void QueueLinkedList(LnkdLst<T> &list)
{
    int choice = 0;
    bool quit = false;
        //    system("clear");
    T que;
    while(!quit)
    {
        cout << "1)Enqueue\n"
        << "2)Dequeue\n"
        << "0)Quit\n";
        
        cout << "choice: ";
        cin  >> choice;
        cout << endl;
        
        switch (choice)
        {
                
            case 1:
                cout << "Enter data: ";
                cin  >> data;
                    //cin.clear();
                list.Prepend(data);
                break;
            case 2:
                que = list.Dequeue();
//                cout << "
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
void CircularlyLinkedList(LnkdLst<T> &list)
{
    int choice = 0;
    bool quit = false;
        //    system("clear");
    T selection;
    while(!quit)
    {
        cout << "1)Append\n"
        << "2)Prepend Node\n"
        << "3)Insert Before\n"
        << "4)Insert After\n"
        << "5)Extract\n"
        << "6)Sort\n"
        << "7)Show entered data\n"
        << "0)Quit\n";
        
        cout << "choice: ";
        cin  >> choice;
        cout << endl;
        
        
        switch (choice)
        {
                
            case 1:
                cout << "Enter data: ";
                cin  >> data;
                    //cin.clear();
                list.circularlyAppend(data);
                break;
                
            case 2:
                cout << "Enter data: ";
                cin  >> data;
                    //cin.clear();
                list.circularlyPrepend(data);
                break;
                
            case 3:
                cout << "Enter the data you want to insert before (if data doesnt exist a new node will added at end of list): ";
                cin  >> selection;
                cin.clear();
                cout << "Enter data: ";
                cin  >> data;
                    //cin.clear();
                list.circularlyInsertBefore(selection, data);
                break;
                
            case 4:
                cout << "Enter the data you want to insert after (if data doesnt exist a new node will added at end of list): ";
                cin  >> selection;
                cin.clear();
                cout << "Enter data: ";
                cin  >> data;
                    //cin.clear();
                list.circularlyInsertAfter(selection, data);
                break;
                
            case 5:
                cout << "The length of the list is " << list.ListLength()
                << "\nWhat node do you want to extract: ";
                cin  >> choice;
                    //cin.clear();
                cout << "Node " << data << " contains " << list.circularlyExtract(choice) << endl;
                break;
              
            case 6:
                 list.circularSort();
                break;
            case 7:
                list.circularlyToString();
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