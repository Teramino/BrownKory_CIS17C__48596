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
#include <vector>
using namespace std;

#define V 5

class ShortestDistance
{
private:
    
    vector<string> connectedLocations;
    vector<int> connectedDistances;
    string locations [V][V] =
    {
        {"Car Shop", "Bank", "Hospital", "Grocery Store", "Gas Station"},
        {"Car Shop", "Bank", "Hospital", "Grocery Store", "Gas Station"},
        {"Car Shop", "Bank", "Hospital", "Grocery Store", "Gas Station"},
        {"Car Shop", "Bank", "Hospital", "Grocery Store", "Gas Station"},
        {"Car Shop", "Bank", "Hospital", "Grocery Store", "Gas Station"}
        
    };
    
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
        for (int count = 0; count < V; count++)
        {
            int u = minDistance(dist, sptSet);
            if (dist[u] != 0)
            {
                string location = getLocation(u);
                cout << "-> Conneted to: " << location << " distance: " << dist[u] << endl;
            }
            sptSet[u] = true; // set true for being processed
            
            for (int v = 0; v < V; v++)
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u]+graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
        }
    }
    
    int transport(int graph[][V], int src, string destinationName, int destination)
    {
        int dist[V];
        bool sptSet[V];
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;
        dist[src] = 0;
   
        for (int count = 0; count < V; count++)
        {
            int u = minDistance(dist, sptSet);
            if (dist[u] != 0)
            {
                string location = getLocation(u);
                if (location == destinationName)
                {
                    cout << "To get to the " << location << " the distance is " << dist[u] << endl << endl;
                    return dist[u];
                }
            }
            sptSet[u] = true; // set true for being processed
            
            for (int v = 0; v < V; v++) // calcualtes the distance from starting point to all other points
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u]+graph[u][v] < dist[v])
                {
                    if (v == destination)
                    {
                        connectedLocations.push_back(getLocation(u));
                        connectedDistances.push_back(dist[u]);
                        if(connectedDistances[0] == 0)
                        {
                            connectedLocations.pop_back();
                            connectedDistances.pop_back();
                        }
                        connectedLocations.push_back(getLocation(u,v));
                        connectedDistances.push_back(graph[u][v]);
                    }
                    
                    dist[v] = dist[u] + graph[u][v];
                }
        }
        return -1;
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
        
        return min_index;
    }
    
    
    string getLocation( int location)
    {
        string locationName = "";
        
        
        switch(location)
        {
            case 0: locationName = "Car Stop";
                break;
            case 1: locationName = "Bank";
                break;
            case 2: locationName = "Hospital";
                break;
            case 4: locationName = "Gas Station";
                break;
            case 3: locationName = "Groccery Store";
                break;
        }
        return locationName;
    }
    
    string getLocation( int row, int col)
    {
        return locations[row][col];
    }
    
    vector<string> getConnectedLocations()
    {
        return connectedLocations;
    }
    
    void connectedLocationsPop()
    {
        connectedLocations.pop_back();
    }
    
    
    vector<int> getConnectedDistances()
    {
        return connectedDistances;
    }
    
    void connectedDistancesPop()
    {
        connectedDistances.pop_back();
    }
    
};

#endif
