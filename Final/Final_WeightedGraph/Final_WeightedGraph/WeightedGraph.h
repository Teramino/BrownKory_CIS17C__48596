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
        int graph[V][V] =
        {
            { 0, 1846, 0, 1464, 0, 337, 2704 },
            { 1846, 0, 740, 802, 0, 0, 867   },
            { 0, 740, 0, 0, 1090, 0, 187 },
            { 1464, 802, 0, 0, 1121, 1235, 0},
            { 0, 0, 1090, 1121, 0, 2342, 1258},
            { 337, 0, 0, 1235, 2342, 0, 0},
            { 2704, 867, 187, 0, 1258, 0, 0}
        };
        
        span.primMST(graph);
        
        cout<<endl;

        distance.dijkstra(graph, 0);
    }
};

#endif
