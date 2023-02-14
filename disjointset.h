#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#pragma once

// class to represent a disjoint set
class DisjointSet
{
	unordered_map<int, int> parent;
	unordered_map<int, int> rank;

public:

	// perform MakeSet operation
	void makeSet(vector<int> const &universe)
	{
		// create n disjoint sets (one for each item)
		for (int i : universe) 
		{
			parent[i] = i;
			rank[i] = 1;
		}
	}

	// Find the root of the set in which element k belongs
	int Find(int k)
	{
		// if k is root
		if (parent[k] == k)
			return k;

		// recur for parent until we find root
		return Find(parent[k]);
	}

	// Perform Union of two subsets
	bool Union(int a, int b)
	{
		// find root of the sets in which elements
		// x and y belongs
		int x = Find(a);
		int y = Find(b);

        if (x == y)
			return true;

		if (rank[x] > rank[y])
		{
			parent[y] = x;
			rank[x] = rank[x] + rank[y];
		}
		else
		{
			parent[x] = y;
			rank[y] = rank[y] + rank[x];
		}

		return false;
	}
	
};

void printSets(vector<int> const &universe, DisjointSet &ds)
{
	for (int i : universe)
		cout << ds.Find(i) << " ";

	cout << '\n';
}
#endif