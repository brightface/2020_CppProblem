#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template<typename T>
class ListStack
{
public:

	struct Node 
	{
		
		Node* next = nullptr;
		T data;
	};

	static Node* Create(T data)
	{
		Node* node = new Node();
		node->data = data;
		return node;
	}

	static void Destroy(Node** node)
	{
		
		delete* node;
		*node = nullptr;
	}
	/*~ListStack() 
	{
		Todo: Clear();
	}*/

	void Push(T data)
	{
		Node* NewNode = Create(data);
		if (top == nullptr)
		{
			top = NewNode;
			head = NewNode;
			//tail = NewNode;
		}
		else
		{	
			/*tail->next = NewNode;
			tail = tail->next;*/
			
			top->next = NewNode;
			top = top->next;
			
		}
		size++;
	}
	void Pop()
	{
		if (size <= 1) 
		{
			if (size == 1)
			{
				Destroy(&head);
				top = nullptr;
			}
			else
			{
				assert("Stack is Empty",top != nullptr);
				
				
			}
		}
		else
		{	
			Node* node = head;
			Node* temp = nullptr;
			
			while (node->next != nullptr)
			{
				temp = node;
				node = node->next;
			} //tail을 찾았어

			//tail = temp;
			//tail->next = nullptr;
			
			top = temp;
			top->next = nullptr;
			
			//Destroy(&node);
		}
		size--;
	}
	//
	//Node* operator[](int index)
	//{
	//	Node* node = head;
	//	while (node != nullptr && index-- > 0)
	//		node = node->next;

	//	return node;
	//}
	Node printTop()
	{
		return *top;
	}
	
	int Size() { return size; }
private:
	int size = 0;
	//T* datas = nullptr;
	//int top = -1;
	Node* top;
	Node* head;
	//Node* tail;
	
};