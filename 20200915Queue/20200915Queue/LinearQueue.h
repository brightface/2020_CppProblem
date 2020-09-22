#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class LinearQueue
{
public:
	LinearQueue(int size)//������
		: size(size)
	{
		datas = new int[size];
	}
	~LinearQueue()
	{
		delete[] datas; //�Ҹ���
		datas = nullptr;
	}

	bool IsFull() 
	{
		return rear == (size - 1);
	}
	bool Empty()
	{
		return rear < 0;
	}

	void Enqueue(int data)
	{
		//������������ �ϸ� �ȵ��ݾ�.
		if (IsFull() == false)
			datas[++rear] = data;//������Ű�� �ִ´�
		else
			cout << "���� ���ִ�." << endl;
	}

	void Dequeue()
	{
		if (Empty() == false) {
			//������ �ؾ� �ȴ�. ���°͵� �ִ°� ó�� ó��. rear�� �ε�����.
			for (int i = 1; i < rear + 1; i++)
			{
				datas[i - 1] = datas[i];
			}
			rear--;
		}
		else
			cout << "����ִ�." << endl;
	}

	int& Front()
	{
		return datas[0];
	}
	int& Back()//���۷��� �����ּҸ� �����Ѵ�. 
	{
		return datas[rear];
	}
private:
	//�ε����� ������Ű�� �ִ´�.

	//���߿� ���ø����� �Ұž�
	int* datas = nullptr;
	
	int size = 0;
	//ó�� ��ġ
	int front = 0;
	//������ ��ġ
	int rear = -1;
};