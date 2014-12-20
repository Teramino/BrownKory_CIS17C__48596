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
#include "MinimumSpanningTree.h"
#include "ShortestDistance.h"

class WeightedGraph
{
private:
    MinimumSpanningTree span;
    ShortestDistance distance;
    
public:
    
    WeightedGraph(){};
    ~WeightedGraph(){};
    
    void simulate()
    {
        /*
         ID   Location
         0 -> SFO
         1 -> ORD
         2 -> JFK
         3 -> DFW
         4 -> MIA
         5 -> LAX
         6 -> BOS
         */
        
        int graph[V][V] =
        {
                // each coloum reprenest that nodes edges
            { 0, 1846, 0, 1464, 0, 337, 2704 }, // SFO
            { 1846, 0, 740, 802, 0, 0, 867   }, // ORD
            { 0, 740, 0, 0, 1090, 0, 187 },     // JFK
            { 1464, 802, 0, 0, 1121, 1235, 0},  //DFW
            { 0, 0, 1090, 1121, 0, 2342, 1258}, //MIA
            { 337, 0, 0, 1235, 2342, 0, 0},     // LAX
            { 2704, 867, 187, 0, 1258, 0, 0}    // BOS
            
            
        };
        
        
        
        cout<<endl;
        int departure = -1;
        bool moreFlights = true;
        while (moreFlights)
        {
            int choice = -1;
            cout << "1) Show Airports\n"
            << "2) Show shortest connections\n"
            << "3) Show connected flights\n"
            << "0) Quit\n"
            << "choice: ";
            cin >> choice;
            cout << endl << endl;
            switch (choice)
            {
                case 0:
                    moreFlights = false;
                    break;
                case 1: showAirports();
                    break;
                case 2:
                    span.primMST(graph);
                    break;
                case 3:
                    showAirports();
                    cout << "What airport connections do you want to see: ";
                    cin  >> departure;
                    cout << endl;
                    cout << "Starting from: " << distance.getAirport(departure) << endl;
                    distance.dijkstra(graph, departure);
                    break;
            }
            cout << endl << endl;
        }
    }
    void showAirports()
    {
        cout << "0 -> SFO\n"
        << "1 -> ORD\n"
        << "2 -> JFK\n"
        << "3 -> DFW\n"
        << "4 -> MIA\n"
        << "5 -> LAX\n"
        << "6 -> BOS\n\n";
    }
};

#endif
