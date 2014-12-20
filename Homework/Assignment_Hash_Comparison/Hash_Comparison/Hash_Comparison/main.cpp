
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Hash2.h"

using namespace std;

void Sort(char [], int);
void LnSearch(char [], char [], int);
void bnSearch(char [], char [], int, float);
void Random(char [], int);

int main()
{
    srand(time(0));
    hshFun hashy;
    
    int count = 0, count2 = 0, count3 = 0;
    cout << "Linear Search:\n" << endl;
    
    while(count <= 700000)
    {
        char str[count], str2[count];
        Random(str, count);
        Random(str2, count);
        LnSearch(str, str2, count);
        count += 10000;
    }
    
    cout << endl << endl;
    
    float ti = clock();
    
    cout << "Binary Search:\n";
    char str3[count2], str4[count2];
    Random(str3, count2);
    Random(str4, count2);
    Sort(str3, count2);
    Sort(str4, count2);
    
    while(count2 <= 10000)
    {
        bnSearch(str3,str4, count2, ti);
        count2 += 500;
    }
    
    float tc = clock();
    cout << "Hash search:\n";
    char array[count3],brray[count3];
    Random(array,count3);
    Random(brray,count3);
    
    float t3;
    while (count3 <= 10000)
    {
        t3 = 0;
        for(int i = 1; i < count3; i++)
            hashy.addItem(array[i]);
        int total = 0, count = 0, count2 = 0;
        for(int i = 1; i < count3; i++)
        {
            hashy.find(brray[i]);
        }
        
        t3 = clock() - tc;
        cout << " N = " << count3 << "\tTime: " << t3/1.0e3f << endl;
        count3 += 1000;
    }
        // Exit Stage Right
    return 0;
}
void LnSearch(char str[], char str2[], int size)
{
        // Linear Search
    float t = 0;
    long int count = 0;
    
    for(int i = 0; i <= (size - 1); i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(str[i] == str2[j])
                break;
        }
    }
    
    t = clock();
    cout << " N:  " << size
    << "\tTime: " << t/1.0e3f << " seconds." ;
    cout << endl;
}
void bnSearch(char str[], char str2[], int size, float ti)
{
    float t2 = 0;
    int position, count = 1;
    int low = 0, high = size -1;
    position = (low + high)/2;
    
    for(int i = 0; i <= size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if (str[i] == str2[j])
                count++;
            else if(str[j] > str2[i])
                low = position - 1;
            else
                low = position + 1;
            position = (low + high)/2;
        }
    }
    
    t2 = clock() - ti;
    cout << " N: " << size
    << "\tTime: " << t2/1.0e3f << " seconds." ;
    cout << endl;
}
void Sort(char str[], int size)
{
    for(int i = 0; i < (size - 1); i++)
    {
        int min = i;
        for(int j = i + 1; j < size; j++)
        {
            if(str[j] < str[min])
                min = j;
        }
        
        int temp;
        temp = str[min];
        str[min] = str[i];
        str[i] = temp;
    }
}
void Random(char inp[], int n)
{
    for (int i = 0; i <= n; i++)
        inp[i] = rand()%26 + 97;
}


