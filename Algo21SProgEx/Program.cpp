#define _CRT_SECURE_NO_WARNINGS

#include "Program.h"
#include "Graph.h"


int* BFS(Graph G, int s)
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



int main()
{
	int numOfVertex, s, t;
	cin >> numOfVertex >> s >> t;
	Graph G;
	G.MakeEmptyGraph(numOfVertex);
	G.ReadGraph();
	G.PrintGraph();
	int* d = BFS(G, s);
	
	




	
}
