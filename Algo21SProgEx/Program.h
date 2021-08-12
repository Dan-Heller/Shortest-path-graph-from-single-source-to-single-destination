#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <string>
#include "Graph.h"
using namespace std;

int* BFS(Graph& G, int s);  //input: Graph and starting vertex. output: array of Vertices distance from s.

//input: Directed graph , vertex s and t.  output: Shortest Path Graph From Single Source To Single Destination.
Graph* ShortestPathGraphFromSingleSourceToSingleDestination(Graph& G, int s, int t);

//get number of vertices in the graph and start and destination.
void GetFirstInputFromUser(int& numOfVertex, int& s, int& t);

//input: Directed graph , vertex s and t.  output: runs the algorithm that prints the shortest Path Graph, and measures the runtime of it.
void MeasureTimeAndPrintToStdout(Graph& G, int s, int t);