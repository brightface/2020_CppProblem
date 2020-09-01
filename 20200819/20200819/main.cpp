#include <iostream>
#include "Static.h"
using namespace std;

struct Data
{
	int value1 = 0;
	int value2 = 0;

};

void Function(Data* data)
{	
	//
	data = new Data();
	data->value1 = 10;
	data->value2 = 20;
}


//static int global; //전역변수로 놓으면 메모리 공용으로 올라가있는데 다른파일에서는 메모리만 잡혀있고 선언 몰라. extern 해줘야돼, static도 마찬가지이다. 에서는 몰라.

			//C++ 전역변수라는것 잘 안써. C++

//static 
int main()
{	
	//extern int global;
	Static a;
	cout << a.global;
	//static 일반 멤버. 초기화가 한번밖에 안된다.
	//메세지 처리함수가 있잖아. 멤버에 선언하기 귀찮다. 함수안에 스테닉 선언해서 초기화는 한번밖에 안된다.
	//코드블럭 공용메모리 , 전역변수, 
	//4가지 옵션 . 
	//소멸 시기 
	//프로그래밍 종ㅈ료될떄 - 정적 변수들이 날아간다.
	/*
	클래스 안에 선언 해놨으니까 선언 객체 메모리에 같이 포함이 안된다. 공용메모리 프로그램이 꺼질떄 날라간다.
	쓰레기 값이 들어있다. -  정적변수
	스태틱인트 a = 0 들어변수.
	전역변수 - 내부적으로 0으로 초기화 되어있다.

	*/
	Data* data = nullptr;
	Function(data);

	/*static
	1. 공용 메모리 영역에 저장이 된다
	2. 초기화는 한번만된다
	3. 초기화를 안해줘도 0으로 초기화 된다.

	*/

	static int value;
	cout << value << endl;

	//while (true)
	//{
	//	static int value2 = 10; //초기화가 한번만 되서 실행 안됨. 그래서 계속 누적됨
	//	value2 += 10;
	//	cout << value2 << endl;
	//}
	
	//객체메모리에 안잡힌다.(객체의 크기에 포함되지 않는다)
	cout << sizeof(Static) << endl;

	
	//cout << global;
}