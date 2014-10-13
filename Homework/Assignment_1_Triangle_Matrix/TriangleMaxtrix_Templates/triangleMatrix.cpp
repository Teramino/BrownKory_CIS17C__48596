
//  main.cpp
//  Create_A_Class
//
//  Created by Kory Brown on 9/4/14.
//  Copyright (c) 2014 ALPHA. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

template<class T>
class Array
{
private:
    int rows;
    int nCols;
    int perLine;
    T **array;
    T *colAry;
    T **triAry;

public:
    Array(int, int, int);
    ~Array();
    void buildArray();
    void fillArray();
    void printArray();
};

template<class T>
void Array<T>:: buildArray()
{
    fillArray();
    printArray();
}

template<class T>
Array<T>::Array(int r, int c, int p)
{
    rows = r;
    nCols = c;
    perLine = p;
}

template<class T>
Array<T>:: ~Array()
{
    //Destroy row pointer
    delete []colAry;
    cout << "array deleted\n\n";

    //Destroy cols
    for(int row=0;row<rows;row++){
        delete []array[row];
    }
    //Destroy row pointer
    delete []array;
    cout << "2-D array deleted\n\n";

    //Destroy cols
    for(int row=0;row<rows;row++){
        delete []triAry[row];
    }
    //Destroy row pointer
    delete []triAry;
    cout << "tri-array deleted\n\n";
}

template<class T>
void Array<T>:: fillArray()
{
    //Declare the 1-D Array
    int cols = rows;
    colAry=new T[cols];

    //Fill the array with random numbers
    for(int col=0;col<cols;col++)
    {
        colAry[col]=rand()%9+2;
    }

    //Declare the 2-D Array
    array=new T*[rows];

    //Fill the array with random numbers
    for(int row=0;row<rows;row++)
    {
         array[row]=new T[(int)colAry[row]];

        for(int col=0;col<colAry[row];col++)
        {
            array[row][col]=((float)rand()/(float)(RAND_MAX))*100;
            //cout<<"Row Col"<<row<<" "<<col<<endl;
        }
    }

    //Declare the Tri Array
    triAry =new T* [rows];

    //Fill the array with random numbers
    for(int row=0;row<rows;row++)
    {
        triAry[row]=new T[nCols];

        for(int col=0;col<nCols;col++)
        {
            triAry[row][col]=((float)rand()/(float)(RAND_MAX)) * 100;
        }
    }
}

template<class T>
void Array<T>:: printArray()
{
    //Print the 2-D Array
    cout<<endl;
    cout << fixed << setprecision(2);
    for(int row=0;row<rows;row++)
    {
        for(int col=0;col<nCols;col++)
        {
            cout << array[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<< "array" <<endl;

    //Print the 1-D Array
    int cols = rows;
    cout<<endl;
    for(int col=0;col<cols;col++)
    {
        cout << colAry[col]<<" ";
        if(col%perLine==(perLine-1))cout<<endl;
    }
    cout<<"\ncolAry" <<endl;

    //Print the TriAry
    cout<<endl;
    for(int row=0;row<rows;row++)
    {
        for(int col=0;col<colAry[row];col++)
        {
            cout << triAry[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<"triAry\n" <<endl;
}


int main()
{
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));

    Array<float> a(5,10,10);
    a.buildArray();
    Array<int> b(5,10,10);
    b.buildArray();

    //Exit stage right
    return 0;
}
