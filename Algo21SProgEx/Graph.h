#pragma once
#include "Queue.h"
#include <iostream>
using namespace std;


class Graph
{
private:
	Node* vertexArray;
	int numOfVertex;
 
public:	
	Graph();
	~Graph();
	void MakeEmptyGraph(int n);
	int AddEdge(int u,int v);
	bool IsAdjacent(int u, int v);
	Node* GetAdjList(int u);
	int RemoveEdge(int u, int v); 
	int IsEmpty();
	int ReadGraph();
	void PrintGraph();
	int getNumOfVertex();
	void removeEdges(int* d);
	Graph* getGraphTranspose();
	void removeUnreachableEdges(int* d);
	

	
};



