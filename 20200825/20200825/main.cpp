/*
stack

*/
#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include "ArrayStack.h"
#include "ListStack.h"
using namespace std;


class A
{
public:
	int& Top() { return value; }
	//���� �޴³��� ��� // �ڵ��� �ȿ� �ִ°� ���ٲ�
	const int& Top() const
	{
		return value += 10;
	}
	/*int& Top() const { ///���۷��������� ����Ÿ���ε� const�ΰ� ������ ���ѹ����� ������ ���.
		return value += 10;
	}*/
	//const int& Top() const { //���۷����ΰ� ����Ʈ ����� �ؼ� �����ϴϱ� ���� �ȶ��?? �װ� �ƴ϶� mutable value�� �ٿ��� �����Ѱž�
	//	return value += 10; 
	//}

	//top �ϰ� pop�ϰ� �������� ���� / ���۷����� ��ȯ�ϴµ� ���� ���󰡸� �ȵǰ���
	//���� �Ͼ�� ȿ�� �������ϱ� ���۷����� ��ȯ�ϴ°ž�.

private: 
	 mutable int value; //���̰����� / mutable ���̸� const �پ �ٲܼ��ִ�.
	 //int value;
};

void Function()
{
	const A a;
	a.Top(); // a�ȿ��� ���ٲ�

}

void Function2(const stack<int>& s)
{
	s.top();
}
int main()
{
	//stack<int> s;
	//stack<int, vector<int>> sv;
	////vector�� ������. �˻��� ������, ���Ի����� �ƴ϶�.
	//stack<int, list<int>> sl;
	//s.push(10);
	//s.push(20);
	//s.push(30);
	//s.push(40);

	//while (s.empty() != true) //����־�� true
	//{
	//	cout << s.top() << endl;
	//	s.pop();
	//}

	//s.top();//�����ε� �Ȱ� �ִ�.  //�� �̰� ����ϴ��� �˰���?


	/*ArrayStack<int> as(255);
	as.Push(10);
	as.Push(20);
	as.Push(30);
	as.Push(40);

	while (as.Empty() != true)
	{
		cout << as.Top() << endl;
		as.Pop();
	}*/

	ListStack<int> ls;
	ls.Push(10);
	ls.Push(20);
	ls.Push(30);
	ls.Push(40);

	
}
