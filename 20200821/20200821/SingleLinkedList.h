#pragma once

#include <iostream>
using namespace std;

template<typename T> 
class SingleLinkedList
{
public:
	struct Node
	{
		T data;
		Node* next = nullptr;
		//Node* prev = nullptr; //�����
	};

	static Node* Create(T data)
	{
		Node * node = new Node();
		//ó����������ϱ� ���ῡ ���� ������ �����ž�
		node->data = data;
		return node;
	}

	static void Destroy(Node* node) //���� �����ʹ�. ������ ����� �׷���, ���������� ���� ������
	{
		if (node == nullptr) return;
		delete(node); //������ ���ư��µ� �� �ּҴ� �˰��ִ�. �� ������ �����Ϸ��� ������ ���������
		node = nullptr; //����������. �׷��� �����������ؾߵ� - ���� ����� �ƴ϶� �������Ʈ ���� ���۸� ����Ʈ

		//���������  ���� - ��� ��ü�� �����;�.
	}
	static void Destroy(Node** node) //������ �� ��带 ����Ű�� ������
	{
		if (node == nullptr) return;
		delete(*node); //������ ���ư��µ� �� �ּҴ� �˰��ִ�. �� ������ �����Ϸ��� ������ ���������
		*node = nullptr; //����������. �׷��� �����������ؾߵ� - ���� ��尡
		//��������� ���� �ذ�
	}

public:
	~SingleLinkedList()
	{
		Clear();
	}
	void Push_Back(T data)
	{
		Node* node = Create(data); // ��带 �������.
		//���� ó���� ������. 
		if (head == nullptr)
		{
			//�Ӹ����� ������
			head = node;
			tail = node;
		}
		else
		{	//���� �ִ´�. tail���ٰ� �����ϰ� ��.
			//���� ã�ư����� ���� �־���Ѵ�.
			tail->next = node;
			tail = tail->next;
		}//��尡 ���ο� �������ݾ�.
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
			node->next = head;
			head = node;
		}size++;
	}

	//////////////////////////////////////////�߿�////////////////////////////////////////////////////
	//head �� tail�� ��������� ���� ������� �����Ͷ�� ���� ����, �׷��ǹ̿��� �����Ͱ� �ȵ��µ�
	//////////////////////////////////////////////////////////////////////////////////////////////////
	void Pop_Back()
	{
		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr;
		}
		else
		{
			//head = head -> next; //�̷��� ���� ã�ư��ٵ� ����� ���� ������ ���ݾ�. 
			//�ӽú��� �����.
			Node* node = head;
			//���� ������ ����� �ȵ�
			//���ο� ������ �Ǿ����� ���� ������ ����� ���� ������ ��ã�´�. �׷��� �����Ѵ�.
			Node* temp = nullptr;
			while (node->next != nullptr)
			{	
				//0 1 2 3 4
				temp = node;
				node = node->next;
			}//ã�Ҿ�// ������ temp��
			tail = temp; //����� �ϳ� ��
			tail->next = nullptr;
			Destroy(&node); 
		}size--;//3�� temp���� tail / 4�� node/ �׸��� 3���� ������� ���������.������ ���̰�
	}

	void Insert(Node* target, T data)
	{

		if (target->next == nullptr)
			Push_Back(data);
		else
		{	
			//÷���� ���
			Node* newNode = Create(data);
			Node* temp = target->next;//���⿡ ÷���ɳ�尡 ÷���ȴ�.
			target->next = newNode;
			newNode->next = temp; //����� �ؽ�Ʈ�� target �ؽ�Ʈ �־ ��
			size++;
		}
	}
	//÷���� ��� ����� �ӽ� ��� �����Ѵ�.
	//////////////////////////////////////////////////////
	//÷���� ��带 �մ´�./���� ÷����ų Ÿ���� ������带 ������ ����, ���� Ÿ���� ������带 ������� ������忡 �־
	void Remove(T key)
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{	
			//temp�� �̿��� ��带 �ٽ� ��´�. ��带 ������
			if (temp == head && temp->data == key)
			{
				temp = temp->next;
				Destroy(&head);
				head = temp;
			}//��带 ������ �� ���� ��带  ���� ����

			//��尡 �ƴҶ�, ��尡 3���̻�
			//�� ���Ÿ� �� �ʿ䰡 ���� �������./�հŸ� �� �ʿ䰡 ���� �������/
			else if (temp->next->data == key)
			{
				Node* toRemove = temp->next;//�����
				temp->next = temp->next->next;//3�� �̻� �������� ����
				Destroy(&toRemove);
				size--;
			}
			/* �������� ��� 2��¥�� �������� ���ﶧ
			else if (temp->data == key && temp != head)
			{
				Node* toRemove = temp;
				temp = temp->next;
				Destroy(&toRemove);
				size--;
			}*/
			else //�׿ܿ��� ��� ��� ����
				temp = temp->next; 
			//Todo:: tail�϶��� ���س���. tail�� ã�°��� �غ���.
		}
	}
	void Clear()
	{
		for (int i = size; i > 0; i--)
			Pop_Back();
	}

	int Size() { return size; }

	Node* operator [](int index)
	{
		//head += index;// �ȵǴϱ�. �̷��� �Ѵ�.
		//�ݺ��� ������.
		Node* node = head;
		while (node != nullptr && index-- > 0)
			node = node->next;
		return node;
	}

private:
	Node* head = nullptr;
	Node* tail = nullptr;
		
	int size = 0; //��尡 �� � �ִ��� 
};