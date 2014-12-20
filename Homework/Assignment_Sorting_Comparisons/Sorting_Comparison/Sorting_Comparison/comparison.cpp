#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

template <class T>
void mergesort(T data[], int first, int last);
template <class T>
void merge(T array1[], int first, int last);
template <class T>
void heapsort(T data[], int n);
template <class T>
void moveDown(T data[], int first, int last);
template<class T>
void quicksort(T data[], int first, int last);
template <class T>
void quicksort(T data[], int n);
template <class T>
void bubblesort(T data[], const int n);
template <class T>
void selectionsort(T data[], int n);

int main(int argv, char *argc[])
{
    srand((unsigned int)time(0));
    int const numOfCharacters = 4;
    int const SIZE = 10;
    
    string *sArray = new string[SIZE];
    
        // Create an array of random strings
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < numOfCharacters; j++)
        {
            char mChar = 'A' + rand() % 26;
            sArray[i] += mChar;
        }
    }
    
    cout << "Unsorted array:\n";
    
        // Print unordered array of strings
    for (int i = 0; i < SIZE; i++)
    {
        cout << sArray[i] << '\n';
    }
    
        // comment and uncomment to change sorter
        // Sort array
    selectionsort(sArray, SIZE);
//    bubblesort(sArray, SIZE);
//    quicksort(sArray, SIZE);
//    heapsort(sArray, SIZE);
        //        mergesort(sArray, SIZE);
    
    cout << "\nSorted array:\n";
    
        // Print ordered array of strings
    for (int i = 0; i < SIZE; i++)
    {
        cout << sArray[i] << '\n';
    }
    
    cout << '\n';
    
    delete [] sArray;
    
    return 0;
}

template <class T>
void mergesort(T data[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(data, first, mid);
        mergesort(data, mid + 1, last);
        merge(data, first, last);
    }
}

    //template <class T>
    //void merge(T array1[], int first, int last)
    //{
    //    T temp[];
    //    int mid = (first + last) / 2;
    //    int i1 = 0;
    //    int i2 = first;
    //    int i3 = mid + 1;
    //
    //    while (first <= mid && last >= mid)
    //    {
    //        if (array1[i2] < array1[i3])
    //        {
    //            temp[i1++] = array1[i2++];
    //        }
    //        else
    //        {
    //            temp[i1++] = array1[i3++];
    //        }
    //    }
    //
    //        // Not working
    //
    //
    //}

template <class T>
void heapsort(T data[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
        moveDown(data, i, n - 1);
    
    for (int i = n - 1; i >= 1; --i)
    {
        swap(data[0], data[i]);
        moveDown(data, 0, i - 1);
    }
}

template <class T>
void moveDown(T data[], int first, int last)
{
    int largest = 2 * first + 1;
    
    while (largest <= last)
    {
        if (largest < last && data[largest] < data[largest + 1])
            largest++;
        
        if (data[first] < data[largest])
        {
            swap(data[first], data[largest]);
            first = largest;
            largest = 2 * first + 1;
        }
        else
            largest = last + 1;
    }
}

template<class T>
void quicksort(T data[], int first, int last)
{
    int lower = first + 1, upper = last;
    
    swap(data[first], data[(first + last) / 2]);
    
    T bound = data[first];
    
    while (lower <= upper)
    {
        while (bound > data[lower])
            lower++;
        
        while (bound < data[upper])
            upper--;
        
        if (lower < upper)
            swap(data[lower++], data[upper--]);
        else lower++;
    }
    
    swap(data[upper], data[first]);
    
    if (first < upper - 1)
        quicksort(data, first, upper - 1);
    
    if (upper + 1 < last)
        quicksort(data, upper + 1, last);
}

template <class T>
void quicksort(T data[], int n)
{
    int i, max;
    
    if (n < 2)
        return;
    
    for (i = 1, max = 0; i < n; i++)
    {
        if (data[max] < data[i])
            max = i;
    }
    
    swap(data[n - 1], data[max]);
    
    quicksort(data, 0, n - 2);
}

template <class T>
void bubblesort(T data[], const int n)
{
    bool again = true;
    
    for (int i = 0; i < n - 1 && again; i++)
    {
        for (int j = n - 1, again = false; j > i; --j)
        {
            if (data[j] < data[j - 1])
            {
                swap(data[j], data[j - 1]);
                again = true;
            }
        }
    }
}

template <class T>
void selectionsort(T data[], int n)
{
    for (int i = 0, j, least; i < n - 1; i++)
    {
        for (j = i + 1, least = i; j < n; j++)
        {
            if (data[j] < data[least])
            {
                least = j;
            }
        }
        
        swap(data[least], data[i]);
    }
}
