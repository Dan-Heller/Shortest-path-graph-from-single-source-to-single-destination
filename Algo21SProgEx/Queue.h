#pragma once

struct Node
{
	int Data;
	Node* next;
};

template <class T>
class Queue
{
private:
	Node* head, * tail;
public:

	Queue()
	{
		head = tail = nullptr;
	}
	
	
	
	void MakeEmpty()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
	}

	~Queue()
	{
		MakeEmpty();
	}
	
	bool IsEmpty()
	{
		return (head == nullptr);
	}
	//T Front();
	
	void EnQueue(T item)
	{
		Node* newNode = new Node();
		newNode->Data = item;
		if(head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		
		
	}
	
	T DeQueue()
	{
		Node* temp = head;
		head = head->next;
		T item = temp->Data;
		if (head == nullptr)
			tail = head;
		delete temp;
		return item;
	}
	
};

