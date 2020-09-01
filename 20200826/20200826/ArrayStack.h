#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template<typename T>
class ArrayStack
{
public:
	ArrayStack(int size)
		:size(size)
	{
		datas = new T[size];
	}

	~ArrayStack()
	{
		delete[] datas; //동적 배열인데 []이런데

	}

	bool Push(T data) //가득 차면 더이상 못넣겠지. 
	{
		if (top < size - 1)
		{
			//top++;
			datas[++top] = data;
			return true;
		}
		else 
			return false;
	}

	T& Top()
	{
		assert(("Stack is Empty", top != -1));
		return datas[top];
	}

	void Pop()
	{
		assert(("Stack is Empty", top != -1));
		top--;
		//return datas[top];
	}//동적할당 지우는것은 pop될떄 지운다. 바로 지우는게 아니라

	bool Empty() { return top == -1; }
private:
	int size = 0;
	T* datas = nullptr;
	int top = -1; //최상위 데이터의 위치

};