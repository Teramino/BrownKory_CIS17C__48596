    //
    //  MinimumSpanningTree.h
    //  Final_WeightedGraph
    //
    //  Created by Kory Brown on 12/12/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Final_WeightedGraph_MinimumSpanningTree_h
#define Final_WeightedGraph_MinimumSpanningTree_h

#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <iomanip>
using namespace std;

#define V 7
class MinimumSpanningTree
{
public:
    MinimumSpanningTree(){};
    ~MinimumSpanningTree(){};
    
    int minKey(int key[], bool mstSet[])
    {
        int min = INT_MAX, min_index=0;
        
        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;
        
        return min_index;
    }
    
    void printMST(int parent[], int n, int graph[][V])
    {
        cout << "Spanning the GRID\n\n"
        << "Edge  Edge Weight\n"
        << setw(16) << "[Not in Order]\n";
        for (int i = 1; i < V; i++){
            int startPoint = parent[i];
            int endPoint = i;
            string airPort = "";
            
            switch(startPoint)
            {
                case 0:airPort = "SFO";
                    break;
                case 1: airPort = "ORD";
                    break;
                case 2: airPort = "JFK";
                    break;
                case 3: airPort = "DFW";
                    break;
                case 4: airPort = "MIA";
                    break;
                case 5: airPort = "LAX";
                    break;
                case 6: airPort = "BOS";
                    break;
            }
            
                //            switch(startPoint)
                //            {
                //                case 0:airPort = "Car Stop";
                //                    break;
                //                case 1: airPort = "Bank";
                //                    break;
                //                case 2: airPort = "Hospital";
                //                    break;
                //                case 3: airPort = "Gas Station";
                //                    break;
                //                case 4: airPort = "Groccery Store";
                //                    break;
                //            }
            
            cout << airPort <<" - ";
            
            switch(endPoint)
            {
                case 0:airPort = "SFO";
                    break;
                case 1: airPort = "ORD";
                    break;
                case 2: airPort = "JFK";
                    break;
                case 3: airPort = "DFW";
                    break;
                case 4: airPort = "MIA";
                    break;
                case 5: airPort = "LAX";
                    break;
                case 6: airPort = "BOS";
                    break;
            }
            
                //            switch(endPoint)
                //            {
                //                case 0:airPort = "Car Stop";
                //                    break;
                //                case 1: airPort = "Bank";
                //                    break;
                //                case 2: airPort = "Hospital";
                //                    break;
                //                case 3: airPort = "Gas Station";
                //                    break;
                //                case 4: airPort = "Groccery Store";
                //                    break;
                //            }
            cout << airPort << "  " <<graph[i][parent[i]]<<endl;
        }
    }
    
    void primMST(int graph[][V])
    {
        int parent[V];
        int key[V];
        bool mstSet[V];
        
        for (int i = 0; i < V; i++)
            key[i] = INT_MAX, mstSet[i] = false;
        
        key[0] = 0;
        parent[0] = -1;
        
        for (int count = 0; count < V - 1; count++)
        {
            int u = minKey(key, mstSet);
            
            mstSet[u] = true;
            
            for (int v = 0; v < V; v++)
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                    parent[v] = u, key[v] = graph[u][v];
        }
        
        printMST(parent, V, graph);
    }
    
};

#endif
