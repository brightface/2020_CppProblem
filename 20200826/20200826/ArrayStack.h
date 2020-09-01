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
		delete[] datas; //���� �迭�ε� []�̷���

	}

	bool Push(T data) //���� ���� ���̻� ���ְ���. 
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
	}//�����Ҵ� ����°��� pop�ɋ� �����. �ٷ� ����°� �ƴ϶�

	bool Empty() { return top == -1; }
private:
	int size = 0;
	T* datas = nullptr;
	int top = -1; //�ֻ��� �������� ��ġ

};