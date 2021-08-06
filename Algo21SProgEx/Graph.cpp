#include "Graph.h"

Graph::Graph()
{
	
}

Graph::~Graph()
{
	Node *ptr, *temp;
	for(int i = 0; i < numOfVertex; i++)
	{
		ptr = vertexArray[i].next;
		while(ptr != nullptr)
		{
			temp = ptr->next;
			delete ptr;
			ptr = temp;
		}
		vertexArray[i].next = nullptr;
	}
	delete[] vertexArray;
	vertexArray = nullptr;
	numOfVertex = 0;
}

void Graph::MakeEmptyGraph(int n)
{
	vertexArray = new Node[n];

	for (int i = 0; i < n; i++)
	{
		vertexArray[i].Data = i + 1;
		vertexArray[i].next = nullptr;
	}
	numOfVertex = n; //5
}

int Graph::AddEdge(int u, int v)
{
	int result = 1;
	
	if (u > numOfVertex || v > numOfVertex || u < 1 || v < 1) //check correctness of range
	{
		return 0;
	}

	Node* ptr = vertexArray[u - 1].next;//check that edge does not exist in the graph
	while(ptr != nullptr)
	{
		if(ptr->Data == v)
		{
			result = 0;
			break;
		}
		ptr = ptr->next;
	}

	Node* newEdge = new Node;
	newEdge->Data = v;
	newEdge->next = vertexArray[u - 1].next;
	vertexArray[u - 1].next = newEdge;

	return result;
}

bool Graph::IsAdjacent(int u, int v)
{
	bool result = false;
	
	Node* ptr = vertexArray[u - 1].next;//check that edge does not exist in the graph
	while (ptr != nullptr)
	{
		if (ptr->Data == v)
		{
			result = true;
			break;
		}
		ptr = ptr->next;
	}

	return result;
}

Node* Graph::GetAdjList(int u)
{
	return vertexArray[u - 1].next;
}

int Graph::RemoveEdge(int u, int v)
{
	int result = 0;

	if (u > numOfVertex || v > numOfVertex || u < 1 || v < 1) //check correctness of range
	{
		return result;
	}

	Node* ptr = vertexArray[u - 1].next;//check that edge does not exist in the graph
	Node* temp;
	while (ptr != nullptr)
	{
		if (ptr->next->Data == v)
		{
			temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
			result = 1;
			break;
		}
		ptr = ptr->next;
	}
	return result;
}


int Graph::IsEmpty()
{
	return (numOfVertex == 0);
}

int Graph::ReadGraph()
{
	int result = 1;
	int u, v;
	bool vertexFlag = true;  // true than its u turn 
	char tempchar;
	
	while(!cin.eof())
	{
		if (vertexFlag)
		{
			cin >> u;
			
		}
		else
		{
			cin >> v;
			//add keshet
			result = AddEdge(u, v);
			
		}
		vertexFlag = !vertexFlag;
		//cin.ignore();
	}
	//cin.ignore();

	//if(!vertexFlag) // v not inserted
	//{
	//	cout << "error";
	//	exit(1);
	//}

	return result;
}

void Graph::PrintGraph()
{
	Node* ptr;
	for (int i = 0; i < numOfVertex; i++)
	{
		ptr = vertexArray[i].next;
		while (ptr != nullptr)
		{
			cout <<"   "<<i+1 <<"   "<< ptr->Data<<endl;
			ptr = ptr->next;
		}
	}
}

int Graph::getNumOfVertex()
{
	return numOfVertex;
}

void Graph::removeEdges(int* d)
{
	int tempData;
	Node* ptr;
	for (int i = 0; i < numOfVertex; i++)
	{
		ptr = vertexArray[i].next;
		while (ptr != nullptr)
		{
			if(d[(ptr->Data) - 1] != d[i] + 1)
			{
				tempData = ptr->Data;
				ptr = ptr->next;
				RemoveEdge(i + 1, tempData);
			}
			else
			{
				ptr = ptr->next;
			}
		}
	}
}

Graph* Graph::getGraphTranspose()
{
	Graph* Gst = new Graph();
	Gst->MakeEmptyGraph(numOfVertex);


	Node* ptr;
	for (int i = 0; i < numOfVertex; i++)
	{
		ptr = vertexArray[i].next;
		while (ptr != nullptr)
		{
			Gst->AddEdge(ptr->Data, i + 1);
			ptr = ptr->next;
		}
	}

	return Gst;
}

void Graph::removeUnreachableEdges(int* d)//delete all edges of infinite vertex
{
	
	Node* ptr, *tempNode;
	for (int i = 0; i < numOfVertex; i++)
	{
		if(d[i] == INT_MAX)
		{
			ptr = vertexArray[i].next;
			while (ptr != nullptr)
			{
				tempNode = ptr->next;
				RemoveEdge(i + 1, ptr->Data);
				ptr = tempNode;
			}
			vertexArray[i].next = nullptr;
		}
		
	}
}
