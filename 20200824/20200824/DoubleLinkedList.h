#pragma once

//DoubleLinkedList
//양방향으로 한다고 하면 돼 //스택 // 큐는 단방향

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

	//클래스 외부에서 선언한것처럼 할려고 한것이다.
	static Node* Create(T data); //객체 없이 할려 한것이다.
	{
		Node* node = new Node();
		node->data = data;
		return node;
	}

	static void Destroy(Node** node)
	{
		delete *node;
		*node = nullptr; // 스택 트리 큐 .
	}

public:
	~DoubleLinkedList()
	{
		Clear();
	}
	

	void Push_Back(Data data)
	{
		Node* node Create(data);
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

	void Push_Front(Data data)
	{
		Node* node = Create(data);
		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			haed->prev = node;
			node->next = head;
			head = node; //새로운 헤드의 위치를 노드로 
		}size++;
	}

	void Pop_Back()
	{
		//assert 디버깅 모드만 된다. release 하면 안먹어.
		if (size == 0) return; //std list 는 assert 걸려있어 비어있는데 팝시키면 터져
		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr; //하나를 날리고 하나를 없애버려
		}
		else(size >= 2)
		{
			//꼬리 앞에있는놈을저장
			Node* tempNode = tail->prev;
			Destroy(&tail);
			tail = tempNode;
			tail->next = nullptr;
		}//포인터들은 항상 저장해놓는다. 사라지지 않는 노드들의 포인터들은
		size--;
	}

	void Pop_Front()
	{
		//assert 디버깅 모드만 된다. release 하면 안먹어.
		if (size == 0) return; //std list 는 assert 걸려있어 비어있는데 팝시키면 터져
		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr; //하나를 날리고 하나를 없애버려
		}
		else
		{
			Node* tempNode = head;
			head = head->next;
			Destroy(&tempNode);
			head->prev = nullptr;
		}size--;
	}
	void Insert(Node* target, T data)
	{
		Node* newNode = Create(data);

		Node* tempNode = target->next;
		target->next = newNode;
		newNode->prev = target;
		newNode->next = tempNode;
		tempNode->prev = newNode;
		size++;
	}
	//배열첨자
	Node* operator[](int index)
	{
		Node* node = head;
		while(node != nullptr && index-- > 0)
			node = node->nexxt;
		return node
	}

	int Size() { return size; }
	void Clear()
	{
		for (int i = size; i > -; i--)
			Pop_Back();
	}

	void PrintList()
	{
		for (int i = 0; i < size; i++)
		{
			cout<< operator[](i)->data<< " ";
		}
		cout << endl;
	}
private:

	Node* head = nullptr;
	Node* tail = nullptr;

	int size = 0;
};