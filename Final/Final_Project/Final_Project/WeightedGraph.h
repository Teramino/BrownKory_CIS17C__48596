    //
    //  WeightedGraph.h
    //  Final_WeightedGraph
    //
    //  Created by Kory Brown on 12/12/14.
    //  Copyright (c) 2014 Kory Brown. All rights reserved.
    //

#ifndef Final_WeightedGraph_WeightedGraph_h
#define Final_WeightedGraph_WeightedGraph_h

#include <iostream>
#include "ShortestDistance.h"


class WeightedGraph
{
private:
    ShortestDistance distance;
    
public:
    
    WeightedGraph(){};
    ~WeightedGraph(){};
    
    int simulate( int startingPoint, int destination)
    {
        /*
         ID   Location
         0 -> Car Stop
         1 -> Bank
         2 -> Hospital
         3 -> Grocery Store
         4 -> Gas Station
         */
        
        int graph[V][V] =
        {
            
            {0, 1203, 0, 0, 1357},
            {1203, 0, 800, 0, 0},
            {0, 800, 0, 959, 0},
            {0, 0, 959, 0, 604},
            {1357, 0, 0, 604, 0}
            
        };
        
        cout<<endl;

        string destinationName = "";
        int distanceTraveled = -1;

        cout << "You are going to the " << distance.getLocation(destination);
        cout << endl;
        
        destinationName = distance.getLocation(destination);
        distanceTraveled = distance.transport(graph, startingPoint, destinationName, destination);
        string connectedName2 = "";
        string connectedName1  = "";
        int connectDistance2 = -1;
        int connectDistance1 = -1;
        
        if(distance.getConnectedLocations().size() > 0)
        {
            connectedName2 =  distance.getConnectedLocations()[distance.getConnectedLocations().size()-1];
            distance.connectedLocationsPop();
        }
        if(distance.getConnectedLocations().size() > 0)
        {
            connectedName1 =  distance.getConnectedLocations()[distance.getConnectedLocations().size()-1];
            distance.connectedLocationsPop();
        }
        if(distance.getConnectedDistances().size() > 0)
        {
            connectDistance2 = distance.getConnectedDistances()[distance.getConnectedDistances().size()-1];
            distance.connectedDistancesPop();
        }
        if(distance.getConnectedDistances().size() > 0)
        {
            connectDistance1 = distance.getConnectedDistances()[distance.getConnectedDistances().size()-1];
            distance.connectedDistancesPop();
        }
        if ( connectedName1 != "")
            cout << "Started at " << distance.getLocation(startingPoint) << " connected to " << connectedName1 << " | distance: " << connectDistance1 << endl;
        if ( connectedName1 == "" && connectedName2 != "")
            cout << "Started at " << distance.getLocation(startingPoint) << " connected to " << connectedName2 << " | distance: " << connectDistance2 << endl;
        else if (connectedName2 != "")
        {
            cout << connectedName1  << " connected to " << connectedName2 << " | distance: " << connectDistance2 << endl;
        }
        else
        {
            cout << "You are already here\n";
            distanceTraveled = 0;
        }
        cout << "Total distance: " << distanceTraveled << endl << endl;
        cout << endl;
        return distanceTraveled;
    }
    void showLocations()
    {
        cout << "0 -> Car Stop\n"
        << "1 -> Bank\n"
        << "2 -> Hospital\n"
        << "3 -> Grocery Store\n"
        << "4 -> Gas Station\n\n";
    }
    
    ShortestDistance getDistance()
    {
        return distance;
    }
    
};

#endif
