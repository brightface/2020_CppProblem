#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class LinearQueue
{
public:
	LinearQueue(int size)//생성자
		: size(size)
	{
		datas = new int[size];
	}
	~LinearQueue()
	{
		delete[] datas; //소멸자
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
		//가득차있을때 하면 안되잖아.
		if (IsFull() == false)
			datas[++rear] = data;//증가시키고 넣는다
		else
			cout << "가득 차있다." << endl;
	}

	void Dequeue()
	{
		if (Empty() == false) {
			//끝까지 해야 된다. 없는것도 있는것 처럼 처리. rear는 인덱스야.
			for (int i = 1; i < rear + 1; i++)
			{
				datas[i - 1] = datas[i];
			}
			rear--;
		}
		else
			cout << "비어있다." << endl;
	}

	int& Front()
	{
		return datas[0];
	}
	int& Back()//레퍼런스 같은주소를 공유한다. 
	{
		return datas[rear];
	}
private:
	//인덱스를 증가시키고 넣는다.

	//나중에 템플릿으로 할거야
	int* datas = nullptr;
	
	int size = 0;
	//처음 위치
	int front = 0;
	//마지막 위치
	int rear = -1;
};