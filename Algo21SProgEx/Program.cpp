#define _CRT_SECURE_NO_WARNINGS

#include "Program.h"
#include "Graph.h"


int* BFS(Graph& G, int s)
{
	int numOfVertex = G.getNumOfVertex();
	int* d = new int[numOfVertex];
	Queue<int> Q;
	
	int u;

	for(int i = 0; i < numOfVertex; i++)
	{
		d[i] = INT_MAX;
	}

	Q.EnQueue(s); //-1 for array indexes
	d[s - 1] = 0;

	while(!Q.IsEmpty())
	{
		u = Q.DeQueue();
		Node* ptr = G.GetAdjList(u);
		while(ptr != nullptr)
		{
			if (d[(ptr->Data)-1] == INT_MAX)
			{
				d[(ptr->Data) - 1] = d[u - 1] + 1;
				Q.EnQueue(ptr->Data);
			}
			ptr = ptr->next;
		}
	}
	return d;
}

Graph*  ShortestPathGraphFromSingleSourceToSingleDestination(Graph& G, int s, int t)
{
	int* d = BFS(G, s);
	G.removeEdges(d);
	Graph* Gst = G.getGraphTranspose();
	delete[] d;
	d = BFS(*Gst, t); // ã
	Gst->removeUnreachableEdges(d); // ã
	Graph* H = Gst->getGraphTranspose(); // ä

	delete[] d;
	return H;
}

void GetFirstInputFromUser(int& numOfVertex,int& s,int& t)
{
	cin >> numOfVertex >> s >> t;

	if(numOfVertex < 1 || s < 1 || t < 1 || s > numOfVertex || t > numOfVertex)
	{
		cout << "invalid input";
		exit(1);
	}
}

void MeasureTimeAndPrintToStdout(Graph& G, int s, int t)
{

	auto start = chrono::high_resolution_clock::now();   // unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	Graph* H = ShortestPathGraphFromSingleSourceToSingleDestination(G, s, t);
	H->PrintGraph();// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();   // Calculating total time taken by the program.
	double time_taken =   chrono::duration_cast<chrono::nanoseconds>(end - start).count();  
	time_taken *= 1e-9;   
	cout << "Time taken by function ShortestPathGraphFromSingleSourceToSingleDestination is : " << fixed << time_taken << setprecision(9) << " sec" << endl; 
	delete H;


	
}


int main()
{
	int numOfVertex, s, t;
	GetFirstInputFromUser(numOfVertex, s, t);

	Graph G;
	G.MakeEmptyGraph(numOfVertex);
	int ReadSucceeded =  G.ReadGraph();
	if(!ReadSucceeded)
	{
		cout << "invalid input";
		exit(1);
	}

	MeasureTimeAndPrintToStdout(G, s, t);
}






