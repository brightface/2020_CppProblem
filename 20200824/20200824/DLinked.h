#pragma once

//DoubleLinkedList
//Node* next;
//Node* prev

#include <iostream>
using namespace std;

template<typename T>
class DoubleLinkedList
{
public:
	struct Node
	{
		Node* prev = nullptr;
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
		delete *node;
		*node = nullptr;
	}

public:
	~DoubleLinkedList()
	{
		Clear();
	}

	void Push_Back(T data)
	{
		Node* node = Create(data);
		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			node->prev = tail;
			tail = tail->next;
		}
		size++;
	}

	void Push_Front(T data)
	{
		Node* node = Create(data);
		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			head->prev = node;
			node->next = head;
			head = node;
		}
		size++;
	}

	void Pop_Back()
	{
		if (size == 0) return;

		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr;
		}
		else
		{
			Node* tempNode = tail->prev;
			Destroy(&tail);
			tail = tempNode;
			tail->next = nullptr;
		}
		size--;
	}

	void Pop_Front()
	{
		if (size == 0) return;

		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr;
		}
		else
		{
			Node* tempNode = head;
			head = head->next;
			Destroy(&tempNode);
			head->prev = nullptr;
		}
		size--;
	}

	void Insert(Node* target, T data)
	{
		if (target == nullptr) return;

		if (target == tail)
			Push_Back(data);
		else
		{
			Node* newNode = Create(data);

			Node* tempNode = target->next;
			target->next = newNode;
			newNode->prev = target;
			newNode->next = tempNode;
			tempNode->prev = newNode;
			size++;
		}

	}

	Node* operator[](int index)
	{
		if (index >= size)
		{
			cout << "ÀÎµ¦½º ¿¡·¯" << endl;
			return nullptr;
		}

		Node* node = head;
		while (node != nullptr && index-- > 0)
			node = node->next;
		return node;
	}

	int Size() { return size; }

	void Clear()
	{
		for (int i = size; i > 0; i--)
			Pop_Back();
	}

	void PrintList()
	{
		for (int i = 0; i < size; i++)
			cout << operator[](i)->data << " ";
		cout << endl;
	}

private:
	Node* head = nullptr;
	Node* tail = nullptr;

	int size = 0;
};
