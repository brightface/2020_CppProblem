#pragma once

//DoubleLinkedList
//��������� �Ѵٰ� �ϸ� �� //���� // ť�� �ܹ���

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

	//Ŭ���� �ܺο��� �����Ѱ�ó�� �ҷ��� �Ѱ��̴�.
	static Node* Create(T data); //��ü ���� �ҷ� �Ѱ��̴�.
	{
		Node* node = new Node();
		node->data = data;
		return node;
	}

	static void Destroy(Node** node)
	{
		delete *node;
		*node = nullptr; // ���� Ʈ�� ť .
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
			head = node; //���ο� ����� ��ġ�� ���� 
		}size++;
	}

	void Pop_Back()
	{
		//assert ����� ��常 �ȴ�. release �ϸ� �ȸԾ�.
		if (size == 0) return; //std list �� assert �ɷ��־� ����ִµ� �˽�Ű�� ����
		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr; //�ϳ��� ������ �ϳ��� ���ֹ���
		}
		else(size >= 2)
		{
			//���� �տ��ִ³�������
			Node* tempNode = tail->prev;
			Destroy(&tail);
			tail = tempNode;
			tail->next = nullptr;
		}//�����͵��� �׻� �����س��´�. ������� �ʴ� ������ �����͵���
		size--;
	}

	void Pop_Front()
	{
		//assert ����� ��常 �ȴ�. release �ϸ� �ȸԾ�.
		if (size == 0) return; //std list �� assert �ɷ��־� ����ִµ� �˽�Ű�� ����
		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr; //�ϳ��� ������ �ϳ��� ���ֹ���
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
	//�迭÷��
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