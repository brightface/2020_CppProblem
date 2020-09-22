#pragma once
#include <iostream>
using namespace std;
class LinearQueueByList
{
	struct Node
	{
		Node* next=nullptr;
		int data;
	};
	static Node* Create(int data)
	{
		Node* node = new Node();
		node->data = data;


		return node;
	}

	static void Destroy(Node** node)
	{	
		if (*node == nullptr) return;

		delete (*node);
		*node = nullptr;
	}
public:
	~LinearQueueByList()
	{
		//Clear();
	}
	void Push(int data)
	{
		Node* node = Create(data);
		if (head == nullptr)
		{	
			head = node;
			tail = node;
		}
		else
		{
			//head->next = node;
			tail->next = node;
			tail = tail->next;
		}
		size++;
	}
	void Pop()
	{
		if (size == 0)
		{
			cout << "비어있다." << endl;
		}
		else
		{
			int a = 0;
			cout << head->data <<endl;
			head = head->next;
			size--;
		}

	}
	void Clear()
	{
		for (int i = size; i > 0; i--)
			Pop();
	}

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
};