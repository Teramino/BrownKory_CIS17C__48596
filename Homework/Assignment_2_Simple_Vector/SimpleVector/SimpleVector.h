//
//  SimpleVector.h
//  SimpleVector
//
//  Created by Kory Brown on 9/12/14.
//

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

// Included Libraries
#include <iostream>
#include <new> // Needed for bad_alloc exception
#include <cstdlib> // Needed for the exit function

using namespace std;

template <class T>
class SimpleVector
{
private:
    T *aptr; // To point to the allocated array
    int arraySize; // Number of elements in the array
    void memError(); // Handles memory allocation errors
    void subError(); // Handles subscripts out of range
    bool keep=true;
    
public:
    // Default constructor
    SimpleVector() { aptr = 0; arraySize = 0;}
    
    // Constructor declaration
    SimpleVector(int);
    
    // Copy constructor declaration
    SimpleVector(const SimpleVector &);
    
    // Destructor declaration
    ~SimpleVector();
    
    // Accessor to return the array size
    int size() const { return arraySize; }
    
    // Accessor to return a specific element
    T getElementAt(int position);
    
    // Overloaded [] operator declaration
    T &operator[](const int &);
    
    // Adds one new value to the top of the array
    void pushToTop(T);
    
    // Removes one value from the top of the array
    void pullFromTop();
    
    void menuControl();
    
    void displayMenu();
    
    void setKeep(bool k){
        keep=k;
    }
    
    bool getKeep(){ return keep; }
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it. *
//***********************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    // Allocate memory for the array.
    try
    {
        aptr = new T[s];
    }
    catch (bad_alloc)
    {
        memError();
    }
    // Initialize the array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    // Copy the array size.
    arraySize = obj.arraySize;
    
    // Allocate memory for the array.
    aptr = new T[arraySize];
    
    if (aptr == 0)
        memError();
    
    // Copy the elements of obj's array.
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class. *
//**************************************
template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and *
// terminates the program when memory allocation fails. *
//*******************************************************
template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR:Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and *
// terminates the program when a subscript is out of range. *
//***********************************************************
template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript. *
// This function returns the value stored at the sub- *
// cript in the array. *
//*******************************************************
template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element *
// in the array indexed by the subscript. *
//*******************************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

//*******************************************************
//
//
//
//*******************************************************
template <class T>
void SimpleVector<T>::pushToTop(T insert)
{
    *(aptr+arraySize)=insert;
    arraySize++;
    cout<<"\nValue "<<insert<<" has been added to position ["
    <<arraySize<<"] of the vector\n";
}

//*******************************************************
//
//
//
//*******************************************************
template<class T>
void SimpleVector<T>::pullFromTop()
{
    cout<<"\nValue "<<getElementAt(arraySize-1)<<" has been"
    <<" removed from position ["<<arraySize<<"] of the vector\n";
    *(aptr+arraySize)=NULL;
    arraySize--;
}

//*******************************************************
//
//
//
//*******************************************************
template<class T>
void SimpleVector<T>::displayMenu(){
    
    cout<<"Options: \n"<<"1) Show\n"
    <<"2) Push\n"
    <<"3) Pull\n"
    <<"4) Clear\n"
    <<"5) Exit\n";
    
    menuControl();
}

//*******************************************************
//
//
//
//*******************************************************
template<class T>
void SimpleVector<T>::menuControl(){
    
    int choice;
    T value;
    
    cin>>choice;
    
    switch (choice) {
        case 1:
            if(arraySize>0){
                cout<<"\nThe elements you entered are:\n";
                for(int j=0;j<arraySize;j++) {
                    cout<<"\nElement "<<j+1<<") "<<aptr[j]<<" \n";
                }
            }
            else{
                cout<<"The Vector has no contents\n\n";
            }
            break;
        case 2:
            cout<<"What would you like to add to the Vector?\n";
            cout<<"Input: ";
            cin>>value;
            pushToTop(value);
            break;
        case 3:
            pullFromTop();
            break;
        case 4:
            arraySize=0;
            cout<<"Vector has been cleared of all contents\n\n";
            break;
        case 5:
            setKeep(false);
            break;
            
        default:
            exit(EXIT_FAILURE);
            break;
    }
}
#endif