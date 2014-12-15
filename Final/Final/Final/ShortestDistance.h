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
#include <iomanip>
using namespace std;

#define V 7
class ShortestDistance
{
public:
    
    ShortestDistance(){}
    ~ShortestDistance(){}
    
    void dijkstra(int graph[][V], int src)
    {
        int dist[V];
        bool sptSet[V];
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;
        dist[src] = 0;
        
        
        cout << setw(30) << "[Shown by shortest distance]";
        for (int count = 0; count < V-1; count++)
        {
            int u = minDistance(dist, sptSet);
            if (dist[u] != 0) // doesnt show the Airport started from
            {
                string airport = getAirport(u);
                cout << "-> Conneted to: " << airport << " distance: " << dist[u] << endl;
            }
            sptSet[u] = true; // set true for being processed
            
            for (int v = 0; v < V; v++)
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u]+graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
        }
        
        
            //        printSolution(dist);
    }
    
    
    int minDistance(int dist[], bool sptSet[])
    {
            // Initialize min value
        int min = INT_MAX, min_index=0;
        
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
            {
                min = dist[v], min_index = v;
            }
        cout << endl;
        
        return min_index;
    }
    
    void printSolution(int dist[])
    {
        string departure = "";
        string arrival = "";
        
        cout << "Vertex   Distance from Source\n";
        
        for (int airPort = 0; airPort < V; airPort++)
        {
            int distance = dist[airPort];
            string airPortName = getAirport(airPort);
            cout << airPortName <<"      " << distance << endl;
        }
    }
    
    string getAirport( int airPort)
    {
        string airPortName="";
        
        switch(airPort)
        {
            case 0:airPortName = "SFO";
                break;
            case 1: airPortName = "ORD";
                break;
            case 2: airPortName = "JFK";
                break;
            case 3: airPortName = "DFW";
                break;
            case 4: airPortName = "MIA";
                break;
            case 5: airPortName = "LAX";
                break;
            case 6: airPortName = "BOS";
                break;
        }
        return airPortName;
    }
    
};

#endif
