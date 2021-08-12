#pragma once
#include "Queue.h"
#include <iostream>
using namespace std;

//graph class represented by List of neighbors.
class Graph
{
private:
	Node* vertexArray;
	int numOfVertex;
 
public:	
	Graph();
	~Graph();

	void MakeEmptyGraph(int n);// input: number of vertex. assign the vertex array.
	int AddEdge(int u,int v); //input: two vertex indexes. create an edge between them.
	bool IsAdjacent(int u, int v);//input: two vertexes. output: true if they have an edge between them.
	Node* GetAdjList(int u);//input:index of vertex. output: he's adj list.
	int RemoveEdge(int u, int v); //input: indexes of two vertex. remove the edge between them if exist.
	int IsEmpty();//output: is the graph empty
	int ReadGraph();//input: edges from std.
	void PrintGraph();//output: print the edges of the graph.
	int getNumOfVertex();// return the number of vertex in the graph.
	void removeEdges(int* d);// input: pointer to d array. remove hes edges.
	Graph* getGraphTranspose();// output: pointer to a new allocated transposed graph.
	void removeUnreachableEdges(int* d);// input: pointer to d array. remove edges that not reachable from s.
	

	
};



