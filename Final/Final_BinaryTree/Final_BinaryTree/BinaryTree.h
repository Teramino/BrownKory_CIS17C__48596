    //
    //  BinaryTree.h
    //  Final_BinaryTree
    //
    //  Created by Kory Brown on 12/13/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Final_BinaryTree_BinaryTree_h
#define Final_BinaryTree_BinaryTree_h

#include "BinaryTreeHelper.h"

#include <fstream>
#include <ctime>
using namespace std;
class BinaryTree
{
public:
    BinaryTree(){}
    ~BinaryTree(){}
    
    void simulate()
    {
        BinaryTreeHelper tree;
        int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 10;
        float avgTime = 0.0f, time = 0.0f, time_fastest = 100000, time_slowest = 0;
        float timeSearch[1000];
        fstream file("initials.txt", ios::in);
        
        file.clear();
        file.seekp(0L, ios::beg);
        file.seekg(0L, ios::beg);
        
        string nameList[1000];
        
        for(int i = 0; (i < 1000) && (file >> nameList[i]); i++)
            tree.root = tree.Insert(tree.root,nameList[i]);
        
        file.clear();
        file.seekp(0L, ios::beg);
        file.seekg(0L, ios::beg);
        
        clock_t begin, end;
        for(int i = 0; (i < 1000) && (file >> nameList[i]); i++)
        {
            begin = clock();
            tree.Search(tree.root,nameList[i]);
            end = clock();
            time = double(end - begin) / CLOCKS_PER_MSEC;
            timeSearch[i] = time;
            
            if(timeSearch[i] < time_fastest)
                time_fastest = timeSearch[i];
            
            if(timeSearch[i] > time_slowest)
                time_slowest = timeSearch[i];
            
            avgTime += timeSearch[i];
        }
        
        avgTime /= CLOCKS_PER_MSEC;
        
        string initials;
        cout<<"Enter 3 char string be searched: ";
        cin>>initials;
        
        clock_t newSearchStop;
        float currentTime;
        clock_t newSearchStart = clock();
        if(tree.Search(tree.root,initials) == true)
        {
            cout<<"Found!\n";
            
            newSearchStop = clock();
            
            currentTime = (newSearchStop - newSearchStart) / CLOCKS_PER_MSEC;
        }
        
        else cout<<"Not Found\n";
        
        cout << "fastest search time: " << time_fastest << " milliseconds" << endl;
        cout << "Slowest search time: " << time_slowest << " milliseconds" << endl;
        cout << "Average search time: " << avgTime << " milliseconds" << endl;
        cout << "Search time for " <<  initials << ": " << currentTime << " milliseconds" << endl;
        
        file.close();
        
    }
};

#endif
