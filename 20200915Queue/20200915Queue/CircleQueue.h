#pragma once

#include <iostream>
using namespace std;

//�ְ�����
//�����ϰ� ������ ó���� -1���� �����ؾߵ�

template <typename T>
class CircularQueue
{
public:
	CircularQueue(int size)
		:size(size)
	{
		datas = new T[size]; // ������Ť���
	}
	~CircularQueue()
	{
		delete[] datas;
	}

	bool IsFull() { return (rear + 1) % size == front; }

	void Enqueue(T data)
	{
		if(IsFull() == false)
		{
			datas[rear] = data;
			rear = (rear + 1) % size; //0������ ����
		}
		else
		{
		cout << "������" << endl;
		}

		ViewIndex();
	}
	bool Empty()
	{
		return rear == front;
	}
	void Dequeue()
	{
		if (Empty() == false)
		{
			front = (front + 1) % size;
		}
		else
		{
			cout << "�������" << endl;
		}
	
		ViewIndex();
	} //�������� �Ҽ� ������ ������ �ֵ� ����� ����. ��ǥ ������ �ű⿡ �����ž�.

	T& Front()
	{
		return datas[front];
	}

	void ViewIndex()
	{
		cout << "Current front Index : " << front << endl;
		cout << "Current rear Index : " << rear << endl;
	}

private:
	T* datas = nullptr;
	int front = 0;
	int rear = 0;
	int size = 0;

};