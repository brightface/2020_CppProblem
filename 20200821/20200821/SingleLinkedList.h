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
		//Node* prev = nullptr; //양방향
	};

	static Node* Create(T data)
	{
		Node * node = new Node();
		//처음만들었으니까 연결에 대한 정보는 없을거야
		node->data = data;
		return node;
	}

	static void Destroy(Node* node) //노드는 포인터다. 문제가 생긴다 그러면, 지역변수로 들어가기 때문에
	{
		if (node == nullptr) return;
		delete(node); //공간은 날아갔는데 그 주소는 알고있다. 그 공간에 접근하려고 했을떄 허상포인터
		node = nullptr; //지역변수야. 그래서 더블포인터해야돼 - 원본 노드이 아니라서 허상포인트 문제 뎅글링 포인트

		//허상포인터  문제 - 노드 자체가 포인터야.
	}
	static void Destroy(Node** node) //포인터 즉 노드를 가리키는 포인터
	{
		if (node == nullptr) return;
		delete(*node); //공간은 날아갔는데 그 주소는 알고있다. 그 공간에 접근하려고 했을떄 허상포인터
		*node = nullptr; //지역변수야. 그래서 더블포인터해야돼 - 원본 노드가
		//허상포인터 문제 해결
	}

public:
	~SingleLinkedList()
	{
		Clear();
	}
	void Push_Back(T data)
	{
		Node* node = Create(data); // 노드를 만들었다.
		//제일 처음에 넣을떄. 
		if (head == nullptr)
		{
			//머리이자 꼬리다
			head = node;
			tail = node;
		}
		else
		{	//끝에 넣는다. tail갔다가 간단하게 씀.
			//끝을 찾아가지고 끝에 넣어야한다.
			tail->next = node;
			tail = tail->next;
		}//노드가 새로운 테일이잖아.
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

	//////////////////////////////////////////중요////////////////////////////////////////////////////
	//head 와 tail은 노드이지만 임의 노드형의 포인터라고 보면 편해, 그런의미에서 데이터가 안들어가는듯
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
			//head = head -> next; //이렇게 끝을 찾아갈텐데 헤드의 값이 변경이 되잖아. 
			//임시변수 만든다.
			Node* node = head;
			//먼저 꼬리를 지우면 안돼
			//새로운 꼬리가 되었을때 나의 꼬리를 지우면 다음 꼬리를 못찾는다. 그래서 저장한다.
			Node* temp = nullptr;
			while (node->next != nullptr)
			{	
				//0 1 2 3 4
				temp = node;
				node = node->next;
			}//찾았어// 꼬리가 temp야
			tail = temp; //노드의 하나 전
			tail->next = nullptr;
			Destroy(&node); 
		}size--;//3이 temp이자 tail / 4가 node/ 그리고 3에서 연결고리를 끊어버린다.사이즈 줄이고
	}

	void Insert(Node* target, T data)
	{

		if (target->next == nullptr)
			Push_Back(data);
		else
		{	
			//첨가될 노드
			Node* newNode = Create(data);
			Node* temp = target->next;//여기에 첨가될노드가 첨가된다.
			target->next = newNode;
			newNode->next = temp; //뉴노드 넥스트에 target 넥스트 넣어도 돼
			size++;
		}
	}
	//첨가될 노드 만들고 임시 노드 지정한다.
	//////////////////////////////////////////////////////
	//첨가될 노드를 잇는다./원래 첨가시킬 타겟의 다음노드를 뉴노드로 지정, 원래 타겟의 다음노드를 뉴노드의 다음노드에 넣어서
	void Remove(T key)
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{	
			//temp를 이용해 헤드를 다시 잡는다. 헤드를 날리고
			if (temp == head && temp->data == key)
			{
				temp = temp->next;
				Destroy(&head);
				head = temp;
			}//헤드를 날리고 그 다음 노드를  헤드로 지정

			//헤드가 아닐때, 노드가 3개이상
			//그 전거를 알 필요가 없게 만들려고./앞거를 알 필요가 없게 만드려고/
			else if (temp->next->data == key)
			{
				Node* toRemove = temp->next;//가운데것
				temp->next = temp->next->next;//3개 이상 있을때만 가능
				Destroy(&toRemove);
				size--;
			}
			/* 구현했음 노드 2개짜리 기준으로 지울때
			else if (temp->data == key && temp != head)
			{
				Node* toRemove = temp;
				temp = temp->next;
				Destroy(&toRemove);
				size--;
			}*/
			else //그외에는 계속 노드 전진
				temp = temp->next; 
			//Todo:: tail일때는 안해놨어. tail로 찾는것을 해봐라.
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
		//head += index;// 안되니까. 이렇게 한다.
		//반복문 돌린다.
		Node* node = head;
		while (node != nullptr && index-- > 0)
			node = node->next;
		return node;
	}

private:
	Node* head = nullptr;
	Node* tail = nullptr;
		
	int size = 0; //노드가 총 몇개 있는지 
};