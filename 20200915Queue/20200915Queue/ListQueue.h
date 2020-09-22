#pragma once

#include <iostream>

using namespace std;

template <typename T>
class ListQueue
{
public:
	//공포게임 잠입액션 - 롤토체스, 트랜드 만들 능력이 된다. to가 필요하겠지. 게임을 출시하려는게 아니라 내가 이런것들을 할수 있다. 보여주기 위해서 포폴을 만드는것이다. 개연성은 필요성이 없다.
	// 배경 이런것도 할수 있다. 서류심사. 토익. 일정수준만 넘어가면 된다. 포폴도 똑같다. 
	
	//--------------------------- 코딩테스트--------------------------------
	//기법, 전공지식들. 시간 분배도 잘해야돼.  
	
	//업계가 좁다. 한두다리 

	static Node{
		T data;
		Node* next = nullptr;
	};

	static Node* Create(T data)
	{
		Node* node = new Node();
		node->data = data;
		return node;
	}
	static void Destroy(Node** node)
	{
		delete(*node);
		*node = nullptr;

	}

	ListQueue(int size)
		:Maxsize = size
	{

	}
	~ListQueue()
	{
		Clear();
	}
	bool IsFull()
	{
		if (size >= maxSize)
		{
			cout << "가득찼다." << endl;
			return true;
		}
		else return false;
	}

	void Enqueue(T data)
	{
		if (isFull() == false)
		{
			Node* node = Create(data);
			if (front == nullptr)
				front = rear = node;
			else
			{
				rear->next = node;
				rear = node;
			}
			size++;
		}
		
	}
	bool Empty()
	{
		if (size < 0)
		{
			cout << "비어있음" << endl;
			return true;
		}
		else return false;
	}

	void Dequeue()
	{
		if (Empty() == false)
		{
			if (size == 1)
			{	//rear를 지우면 front지워도 상관없지. 
				Destroy(&front);
				rear = nullptr; //댕글링 포인트 때문에 nullptr 만듬
			}
			else
			{
				Node* node = front;
				front = front->next;
				Destory(&node);
			}
			size--;
		}
	}

	T& Front() { return front->data; }

	void Clear()
	{
		while (Empty() == false)
			Dequeue();
	}
private:
	Node* front = nullptr;
	Node* rear = nullptr;
	int size = 0;
	int maxSize = 0;

	
};