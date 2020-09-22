#pragma once

#include <iostream>
using namespace std;

//넣고증가
//증가하고 넣으면 처음에 -1에서 시작해야돼

template <typename T>
class CircularQueue
{
public:
	CircularQueue(int size)
		:size(size)
	{
		datas = new T[size]; // 동적배ㅕㅇㄹ
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
			rear = (rear + 1) % size; //0번부터 시작
		}
		else
		{
		cout << "가득참" << endl;
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
			cout << "비어있음" << endl;
		}
	
		ViewIndex();
	} //임의접근 할수 없으니 데이터 둬도 상관이 없다. 좌표 같은걸 거기에 넣을거야.

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