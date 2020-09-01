#pragma once
#include "DoubleL.h"
#include <assert.h>

template<typename T>
class ListStack : public DoubleLinkedList<T>
{
public:
	void Push(T data)
	{
		//Ÿ�� �˼��ְ� this�� ����. �Ⱦ��� ��������.
		this->Push_Back(data);
	}

	T&top()
	{
		if (Empty() != true)
			return this->tail = data;
		else
		{
			assert(("Stack is Empty", Empty() == true));
		}
	}

	bool Empty() { return this->head == nullptr; }

	void Pop()
	{
		this->Pop_Back();
	}
private:
	/*using DoubleLinkedList<T>::Push_Front;
	using DOubleLinkedList<T>::Pop_Front;
	using DOubleLinkedList<T>::Insert;
	using DOubleLinkedList<T>::operator[];*/

	//"depricated fuction" �������������� �����ϴ°� - ���ø�Ŭ������ �ƴϸ� �������̵� �ϸ�� . �ٵ� ���ø�Ŭ������. �������̵� �ȵ� ���ʿ�
	//���ø��� ��ó���⿡�� �����. ��ƮŸ��, �־���ϳ� , �������̵����� ���θ��� ������ �Ǵ��ϰԵ� .
	//��ó���ܰ迡�� ���ø��� ���� ���� �𸣰� �ȴ�. �ڷ�����. 
	void Push_Front(T data) { assert(("depricated fuction", false))}; // �θ�� �̰Ŷ� ������ �̰� ���� �����
	 //�Լ� ȣ���� ���ݾ�.  ã�Ƽ� ����������. assert �ɾ���� �� �̷��� �ϸ� �������Լ��� �������ڶ�� �ɾ���´�. 
	//���ø�Ŭ���� �������̵� �Ұ����� . 
	void Pop_Front() { assert(("Depricated fuction", false)) };
	void Insert(DoubleLinkedList<T>::Node* target, T data) { assert(("depricated function", false)); }
	DoubleLinkedList<T>::Node* operator[](int index) { assert(("depricated function", false)); }
};