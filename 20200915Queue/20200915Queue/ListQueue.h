#pragma once

#include <iostream>

using namespace std;

template <typename T>
class ListQueue
{
public:
	//�������� ���Ծ׼� - ����ü��, Ʈ���� ���� �ɷ��� �ȴ�. to�� �ʿ��ϰ���. ������ ����Ϸ��°� �ƴ϶� ���� �̷��͵��� �Ҽ� �ִ�. �����ֱ� ���ؼ� ������ ����°��̴�. �������� �ʿ伺�� ����.
	// ��� �̷��͵� �Ҽ� �ִ�. �����ɻ�. ����. �������ظ� �Ѿ�� �ȴ�. ������ �Ȱ���. 
	
	//--------------------------- �ڵ��׽�Ʈ--------------------------------
	//���, �������ĵ�. �ð� �й赵 ���ؾߵ�.  
	
	//���谡 ����. �ѵδٸ� 

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
			cout << "����á��." << endl;
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
			cout << "�������" << endl;
			return true;
		}
		else return false;
	}

	void Dequeue()
	{
		if (Empty() == false)
		{
			if (size == 1)
			{	//rear�� ����� front������ �������. 
				Destroy(&front);
				rear = nullptr; //��۸� ����Ʈ ������ nullptr ����
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