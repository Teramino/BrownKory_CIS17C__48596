    //
    //  Sorting.h
    //  Final_Sorting
    //
    //  Created by Kory Brown on 12/12/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Final_Sorting_Sorting_h
#define Final_Sorting_Sorting_h

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

class Sorting
{
    private :
    const static int size = 100000;
    float t, t1, t2, t3, t4, runningClock;
    int array[size], elements;
public:
    Sorting(){t = 0; t1 = 0;t2 = 0; t3 = 0; t4 = 0;
        runningClock = 0; }
    ~Sorting(){}
    
    void simulate() // make a funct of to select which type of sort to use
    {
        srand(time(0));
        
        bool moreSorting=true;
        while (moreSorting)
        {
            
            cout << "Size of array: 100000" << endl;
            cout << "How many element do you want to see: ";
            cin >> elements;
            cout << endl << endl;
            int choice=-1;
            
            cout << "1) See all sorts\n"
            << "2) Select a sort\n"
            << "0) Quit\n"
            << "choice: ";
            cin  >> choice;
            cout << endl << endl;
            
            switch(choice)
            {
                case 1: runAll();
                    break;
                case 2:
                    choice = -1;
                    cout << "Which sort do you want to run <bubble=1, selection=2, merge=3, quick=4, heap=5>: ";
                    cin  >> choice;
                    cout << endl << endl;
                    sortingMaching(choice);
                    break;
                case 0: moreSorting = false;
                    break;
            }
            cout << endl << endl;
        }
        
        
    }
    void runAll()
    {
            // Bubble Sort
        cout << "For Bubble sort: processing...\n\n";
        random(array,size);
        bubbleSort(array, size);
        runningClock += t = clock() - runningClock;
        printArray(array,elements);
        cout << "\n\nTime to finish bubble sort: " << t/1.0e3f
        << " seconds.\n\n";
        
            // Selection Sort
        cout << "For Selection sort: processing...\n\n";
        random(array,size);
        selectSort(array,size);
        runningClock += t = clock() - runningClock;
        printArray(array,elements);
        cout << "\n\nTime to finish selection sort: " << t/1.0e3f
        << " seconds.\n\n";
        cout << endl;
        
            // Merge Sort
        cout << "For Merge sort: processing...\n\n";
        random(array,size);
        mergeSort(array,0,size-1);
        runningClock += t = clock() - runningClock;
        printArray(array,elements);
        cout << "\n\nTime to finish merge sort: " << t/1.0e3f
        << " seconds.\n\n";
        cout << endl;
        
            // Quick Sort
        cout << "For Quick sort: processing...\n\n";
        random(array,size);
        quickSort(array,0,size-1);
        runningClock += t = clock() - runningClock;
        printArray(array,elements);
        cout << "\n\nTime to finish quick sort: " << t/1.0e3f
        << " seconds." << endl;
        cout << endl;
        
            // Heap Sort
        cout << "For Heap sort: processing...\n\n" ;
        random(array,size);
        heapSort(array,size);
        runningClock += t = clock() - runningClock;
        printArray(array,elements);
        cout << "\nTime to finish heap sort: " << t/1.0e3f
        << " seconds.\n\n";
        
        cout << "\nBubble Sort running time: O(n^2)\n";
        cout << "Selection Sort running time: O(n^2)\n";
        cout << "Merge Sort running time: O(nlog(n))\n";
        cout << "Quick Sort running time: O(nlog(n))\n";
        cout << "Heap Sort running time: O(nlog(n))\n";
        cout << "Fastest sorting algorithm: Heap Sort\n";
        
    }
    
    void sortingMaching(int sorterID)
    {
        string sorter = getSorterName(sorterID);
            // Bubble Sort
        cout << "for " << sorter << " sort: processing...\n\n";
        random(array,size);
        getSorter(sorterID);
        runningClock += t = clock() - runningClock;
        printArray(array,elements);
        cout << "\n\nTime to finish " << sorter << " sort: " << t/1.0e3f
        << " seconds." << endl << endl;
        getSorterRuntime(sorterID);
    }
    void getSorterRuntime(int sorterID)
    {
        switch(sorterID)
        {
            case 1: cout << endl << "Bubble Sort running time: O(n^2)" << endl;
                break;
            case 2: cout << "Selection Sort running time: O(n^2)" << endl;
                break;
            case 3: cout << "Merge Sort running time: O(nlog(n))" << endl;
                break;
            case 4: cout << "Quick Sort running time: O(nlog(n))" << endl;
                break;
            case 5: cout << "Heap Sort running time: O(nlog(n))" << endl;
                break;
        }
    }
    void getSorter(int sorterID)
    {
        switch(sorterID)
        {
            case 1: bubbleSort(array,size);
                break;
            case 2: selectSort(array,size);
                break;
            case 3: mergeSort(array,0,size-1);
                break;
            case 4: quickSort(array,0,size-1);
                break;
            case 5: heapSort(array,size);
                break;
        }
    }
    string getSorterName(int sorterID)
    {
        string sorter="";
        switch(sorterID)
        {
            case 1: sorter = "bubble";
                break;
            case 2: sorter = "selection";
                break;
            case 3: sorter = "merge";
                break;
            case 4: sorter = "quck";
                break;
            case 5: sorter = "heap";
                break;
            default: sorter="";
                break;
        }
        return sorter;
    }
    void printArray(int a[],int p)
    {
        for(int i = 0; i < p;i++)
            cout << a[i] << " ";
    }
    void random(int a[], int n)
    {
        for(int i = 0; i < n; i++)
            a[i] = rand()%1000 + 1;
    }
    void bubbleSort(int a[], int n)
    {
        int flag = 1;
        for(int i = 0; i < n; i++)
        {
            flag = 0;
            for(int j = i + 1; j <
                n - 1;j++){
                if (a[i] > a[j]){
                    swap(a[i],a[j]);
                    flag = 1;
                }
            }
        }
    }
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void selectSort(int a[], int n)
    {
        int pos, temp;
        for(int i = 0; i < n;i++){
            pos = i;
            for(int j = i + 1; j < n - 1; j++)
            {
                if(a[j] < a[pos])
                    pos = j;
            }
            if(pos != i)
                swap(a[i],a[pos]);
        }
    }
    void mergeSort(int* A, const int p, const int r){
        if (p < r){
            int q = (p+r)/2;
            mergeSort(A, p,q);
            mergeSort(A,q+1,r);
            merge(A,p,q,r);
        }
    }
    void merge(int* A,int p,const int q, const int r)
    {
        const int n_1=q-p+1;
        const int n_2=r-q;
        int* L = new int [n_1+1];
        int* R = new int [n_2+1];
        L[n_1]=0;
        R[n_2]=0;
        for(int i = 0; i < n_1; i++)
            L[i] = A[p+i];
        for (int j = 0; j < n_2; j++)
            R[j] = A[q+j+1];
        
        int i=0;
        int j=0;
        int k;
        for(k=p; k <= r && i < n_1 && j < n_2; ++k)
        {
            if(L[i] <= R[j]){
                A[k] = L[i];
                i++;
            }
            else{
                A[k] = R[j];
                j++;
            }
        }
        while (i < n_1) {A[k++] = L[i++];}
        while (j < n_2) {A[k++] = R[j++];}
    }
    void quickSort(int a[], int first, int last )
    {
        int pivotElement;
        if(first < last){
            pivotElement = pivot(a, first, last);
            quickSort(a, first, pivotElement-1);
            quickSort(a, pivotElement+1, last);
        }
    }
    int pivot(int a[], int first, int last)
    {
        int  p = first;
        int pivotElement = a[first];
        for(int i = first+1 ; i <= last ; i++)
        {
            if(a[i] <= pivotElement){
                p++;
                swap(a[i], a[p]);
            }
        }
        swap(a[p], a[first]);
        return p;
    }
    void heapSort(int A[], int length)
    {
        int heapsize = length;
        buildheap(A, length);
        for (int i = length-1; i >=1; i--)
        {
            swap(A[0], A[i]);
            heapsize--;
            heapify(A, heapsize, 0);
        }
    }
    void buildheap(int A[], int length)
    {
        for (int i = floor((length)/2); i >= 0 ; i--)
            heapify(A, length, i);
    }
    void heapify(int A[], int heapsize, int root)
    {
        int left = 2*root+1, right = 2*root +2, largest;
        if ( (left < heapsize) && (A[left] > A[root]))
            largest = left;
        else
            largest = root;
        if ( (right < heapsize) && (A[right] > A[largest]))
            largest = right;
        if (largest != root){
            swap(A[root], A[largest]);
            heapify(A, heapsize, largest);
        }
    }
};

#endif
