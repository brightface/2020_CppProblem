#pragma once
#include "DoubleL.h"
#include <assert.h>

template<typename T>
class ListStack : public DoubleLinkedList<T>
{
public:
	void Push(T data)
	{
		//타입 알수있게 this를 쓴다. 안쓰면 에러난다.
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

	//"depricated fuction" 이전버전에서도 사용안하는것 - 템플릿클래스가 아니면 오버라이딩 하면돼 . 근데 템플릿클래스야. 오버라이딩 안돼 애초에
	//템플릿은 전처리기에서 담당해. 인트타입, 있어야하네 , 오버라이딩에서 컴팡리러 딴에서 판단하게돼 .
	//전처리단계에서 템플릿을 찍어낼때 먼지 모르게 된다. 자료형이. 
	void Push_Front(T data) { assert(("depricated fuction", false))}; // 부모랑 이거랑 있을때 이게 먼저 선언돼
	 //함수 호출은 되잖아.  찾아서 들어가봐야하지. assert 걸어놓고 왜 이런지 하면 삭제된함수는 쓰지말자라고 걸어놓는다. 
	//템플릿클래스 오버라이딩 불가능해 . 
	void Pop_Front() { assert(("Depricated fuction", false)) };
	void Insert(DoubleLinkedList<T>::Node* target, T data) { assert(("depricated function", false)); }
	DoubleLinkedList<T>::Node* operator[](int index) { assert(("depricated function", false)); }
};