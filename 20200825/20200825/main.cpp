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
	//리턴 받는놈이 상수 // 코드블록 안에 있는걸 못바꿔
	const int& Top() const
	{
		return value += 10;
	}
	/*int& Top() const { ///레퍼런스누르면 참조타입인데 const인걸 변형을 시켜버려서 오류가 뜬다.
		return value += 10;
	}*/
	//const int& Top() const { //레퍼런스인걸 컨스트 상수로 해서 리턴하니까 오류 안뜬다?? 그게 아니라 mutable value에 붙여서 가능한거야
	//	return value += 10; 
	//}

	//top 하고 pop하고 나누어진 이유 / 레퍼런스로 반환하는데 원본 날라가면 안되겠지
	//복사 일어날때 효율 떨어지니까 레퍼런스로 반환하는거야.

private: 
	 mutable int value; //변이가능한 / mutable 붙이면 const 붙어도 바꿀수있다.
	 //int value;
};

void Function()
{
	const A a;
	a.Top(); // a안에서 못바꿔

}

void Function2(const stack<int>& s)
{
	s.top();
}
int main()
{
	//stack<int> s;
	//stack<int, vector<int>> sv;
	////vector는 많을떄. 검색이 많을때, 삽입삭제가 아니라.
	//stack<int, list<int>> sl;
	//s.push(10);
	//s.push(20);
	//s.push(30);
	//s.push(40);

	//while (s.empty() != true) //비어있어야 true
	//{
	//	cout << s.top() << endl;
	//	s.pop();
	//}

	//s.top();//오버로딩 된게 있다.  //왜 이걸 사용하는지 알겠지?


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
