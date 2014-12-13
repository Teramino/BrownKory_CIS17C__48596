//
//  Recursive.h
//  Final_Stack
//
//  Created by Kory Brown on 12/12/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Final_Stack_Recursive_h
#define Final_Stack_Recursive_h

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
class Recursive
{
public:
    Recursive(){};
    ~Recursive(){};
    
    void simulate()
    {
        float angDeg, total;
        
        stack<char> letter, letter2;
        cout << "Enter an angle in degrees: ";
        cin >> angDeg;
        
        float angRad=angDeg*atan(1)/45;
        cout << "angle: "<< angDeg <<"  degrees" << endl;
        cout << "hypsine(Computer function): "<< sinh(angRad) << endl;
        cout << "hypsine(Recursive function): "<< h(angRad,letter) << endl;
        cout << "hypcosine(Computer function): "<< cosh(angRad)<<endl;
        cout << "hypcosine(Recursive function): "<< g(angRad, letter2) << endl;
        cout << "Number of iterations for h: "<< letter.size() << endl;
        cout << "Number of iterations for g: "<< letter2.size()<< endl;
        total = letter.size() + letter2.size();
        cout << "Total iterations: "<< total << endl;
    }
    
    float h(float angR, stack<char>& letter)
    {
        float tol=1e-6;
        
        letter.push('p');
        
        if(angR>-tol&&angR<tol)
            return (angR+angR*angR*angR/6);
        
        return 2*h(angR/2, letter)*g(angR/2, letter);
    }
    float g(float angR, stack<char>& letter2)
    {
        float tol=1e-6;
        
        letter2.push('p');
        if(angR>-tol&&angR<tol)
            return (1+angR*angR/2);
        
        float b=h(angR/2,letter2);
        
        return 1+2*b*b;
    }
};

#endif
