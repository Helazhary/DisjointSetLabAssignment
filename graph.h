#include <iostream>
#include <vector>
#include "disjointset.h"
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

#pragma once

//data structure to store graph edges
struct Edge {
    int src, dest;
};

//class to represent a graph object
class Graph {
public:
    //construct a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
    //graph constructor
    Graph(vector<Edge> const &edges, int N)
    {// resize the vector to N elements of type vector <int>
        adjList.resize(N);
        //add edges to the graph
        for(auto &edge: edges)
        {
            //insert at the end
            adjList[edge.src].push_back(edge.dest);
        }
    }

    
    bool detectCycle()
   {
     // you are supposed to implement this function
		DisjointSet ds;
		vector<int> universe;
		int counter = 0;

		for (vector<int> v : adjList)
		{
			universe.push_back(counter++);
		}
		
		ds.makeSet(universe);

		for (int i : universe)
		{
			for (int j : adjList[i])
			{
				if (i < j)
				{
					if (ds.Union(i, j))
					{
						return true;
					}
				}
			}
		}
        return false;


	}

};

#endif