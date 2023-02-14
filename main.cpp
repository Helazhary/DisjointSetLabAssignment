#include <iostream>
#include <vector>
#include <unordered_map>
#include "disjointset.h"
#include "graph.h"
using namespace std;


// Disjoint-Set Data Structure (Union Find Algorithm)
int main()
{
vector<Edge> edges_loop =
	{
		{0,1} , {0,2} , {1,3} , {1,4}, {3,4}
	};

	vector<Edge> edges_noloop =
	{
		{0,1} , {0,2} , {1,3} , {1,4}
	};

	int N = 5;

	Graph graph_loop(edges_loop, N);
	cout << "graph 1: "<< (graph_loop.detectCycle() ? "Cycle Detected" : "No Cycle Detected") << endl;

	Graph graph_noloop(edges_noloop, N);
	cout<< "graph 2: "<< (graph_noloop.detectCycle() ? "Cycle Detected" : "No Cycle Detected") << endl;

}