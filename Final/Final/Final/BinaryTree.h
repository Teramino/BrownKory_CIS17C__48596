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
#include <iomanip>
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

        string nameList[1000];
        
        for(int i = 0; (i < 1000) && (file >> nameList[i]); i++)
            tree.root = tree.Insert(tree.root,nameList[i]);
        
        clock_t begin, end;
        for(int i = 0; (i < 1000) && (file >> nameList[i]); i++)
        {
            begin = clock();
            tree.Search(tree.root,nameList[i]);
            end = clock();
            time = float(end - begin) / CLOCKS_PER_MSEC;
            timeSearch[i] = time;
            
            if(timeSearch[i] < time_fastest)
                time_fastest = timeSearch[i];
            
            if(timeSearch[i] > time_slowest)
                time_slowest = timeSearch[i];
            
            avgTime += timeSearch[i];
        }
        
        avgTime /= CLOCKS_PER_MSEC;
        
        showText();
        
        cout << endl;
        string initials;
        cout<<"Enter 3 char string be searched: <type Uppercase> ";
        cin>>initials;
        
        clock_t newSearchStop;
        float currentTime;
        clock_t newSearchStart = clock();
        if(tree.Search(tree.root,initials) == true)
        {
            cout << setw(8) <<"Found!\n\n";
            
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
    
    void showText()
    {
        string line;
        fstream file("initials.txt", ios::in);
        
            //        file.seekp(0L, ios::beg);
            //        file.seekg(0L, ios::beg);
        
        if (file.is_open())
        {
            while ( !file.eof())
            {
                for (int col=0; col<10; col++)
                {
                    getline (file,line);
                    if (line != "")
                    {
                        cout << "[" <<  line << "] ";
                        cout << setw(2) << "";
                        
                    }
                    
                }
                cout << endl;
            }
            file.close();
        }
        
    }
};

#endif
