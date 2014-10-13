//
//  main.cpp
//  SimpleVector
//
//  Created by Kory Brown on 9/12/14.
//

#include <iostream>
#include <limits>
#include "SimpleVector.h"

using namespace std;

void displayMenu();

int main()
{
    int startSize=0;
    int typeChoice=NULL;
    int nextInt;
    char nextChar;
    float nextFloat;
    
    cout <<"Which type of vector would you like"
    << " to create?\n1) int\n2) char\n3) float\n";
    while(!(cin>>typeChoice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout<<"What size vector would you like to create?\n";
    cout<<"Input:";
    while(!(cin>>startSize)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    SimpleVector<int> n(startSize);
    SimpleVector<char> c(startSize);
    SimpleVector<float> f(startSize);
    
    cout<<endl;
    
    switch (typeChoice) {
        case 1:
            cout<< "Enter "<<n.size()<<" int elements into the vector.\n";
            
            for(unsigned int i=0;i<n.size();i++) {
                cout<<"Input: "<<i+1<<")";
                cin>>nextInt;
                n[i]=nextInt;
            }
            
            cout<<endl;
            
            do{
                n.displayMenu();
            }while (n.getKeep());
            break;
        case 2:
            cout<< "Enter "<<c.size()<<" char elements into the vector.\n";
            
            for(unsigned int i=0;i<c.size();i++) {
                cout<<"Input: "<<i+1<<")";
                cin>>nextChar;
                c[i]=nextChar;
            }
            
            cout<<endl;
            
            do{
                c.displayMenu();
            }while (c.getKeep());
            break;
        case 3:
            cout<< "Enter "<<f.size()<<" float elements into the vector.\n";
            
            for(unsigned int i=0;i<f.size();i++) {
                cout<<"Input: "<<i+1<<")";
                cin>>nextFloat;
                f[i]=nextFloat;
            }
            
            cout<<endl;
            
            do{
                f.displayMenu();
            }while (f.getKeep());
            break;
            
        default:
            break;
    }
    
    return 0;
}

