//
//  main.cpp
//  Final
//
//  Created by Kory Brown on 12/12/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#include"HashTable.h"
#include "Recursive.h"
#include "Sorting.h"
#include "WaitLine.h"
#include "WeightedGraph.h"

#include <iomanip>

int main()
{
    HashTable hash;
    Recursive recursive;
    Sorting sort;
    WaitLine line;
    WeightedGraph graph;
    
    bool quit = false;
    int choice = 0;
    
    cout << "==================================================\n"
         << setw(30) << "17C FINAL\n"
         << "==================================================\n\n";
    while(!quit)
    {
        cout << "1) Hashing\n"
        << "2) Stacks\n"
        << "3) Queues\n"
        << "4) Sorting\n"
        << "5) Binary Tree\n"
        << "6) Weighted Graph\n"
        << "7) Quit\n"
        << endl
        << "choice: ";
        cin  >> choice;
        cout << endl << endl;
        
        switch(choice)
        {
            case 1:
                hash.simulate();
                break;
            case 2:
                recursive.simulate();
                break;
            case 3:
                line.simulate();
                break;
            case 4:
                sort.simulate();
                break;
            case 5:
                cout << "Waiting\n";
                break;
            case 6:
                graph.simulate();
                break;
            case 0:
                quit = true;
                break;
            default:
                cout << "Invalid input...\n\n";
                break;
        }
        cout << endl << endl;
    }

    
    return 0;
}
