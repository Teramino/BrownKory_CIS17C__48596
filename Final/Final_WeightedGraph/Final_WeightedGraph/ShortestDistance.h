//
//  ShortestDistance.h
//  Final_WeightedGraph
//
//  Created by Kory Brown on 12/12/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef Final_WeightedGraph_ShortestDistance_h
#define Final_WeightedGraph_ShortestDistance_h

#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

#define V 7
class ShortestDistance
{
public:
    
    ShortestDistance(){}
    ~ShortestDistance(){}
  
    int minDistance(int dist[], bool sptSet[])
    {
            // Initialize min value
        int min = INT_MAX, min_index=0;
        
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        
        return min_index;
    }
    
    void printSolution(int dist[], int n)
    {
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < V; i++){
            int endAirPortNumber = dist[i];
            int startAirPortNumber = i;
            string airPort = "";
            
            switch(startAirPortNumber)
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
            
            cout << airPort <<"      ";
            
            switch(endAirPortNumber)
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
            cout <<endAirPortNumber<<endl;
        }
    }
    
    void dijkstra(int graph[][V], int src)
    {
        int dist[V];
        bool sptSet[V];
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;
        
        
        dist[src] = 0;
        
        
        for (int count = 0; count < V-1; count++)
        {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;

            for (int v = 0; v < V; v++)
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u]+graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }
        
        printSolution(dist, V);
    }
};

#endif
