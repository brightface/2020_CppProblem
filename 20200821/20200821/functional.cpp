#include <iostream>
#include <functional>

using namespace std;

struct S
{
	int value = 0;
	S(int value) : value(value) {}

	S operator()(const S& other)
	{
		cout << "() 연산자 재정의" << endl;
		return other;
	}

	//괄호 안써도 되잖아. + 연산자도 근데 함수 포인터로 가능 
	S& operator+(const S& other)
	{
		S temp(value + other.value);

		return temp;
	}

};

int main()
{
	//S s();
	//function<S(const S&)> fp1 = S();
	//fp1(s);


	S s(10);
	S s2(20);
	//반환형, 매개변수 2개, 함수포인터로 연결할 놈은 &S::operator+
	function<S&(S&, S&)> fp1 = &S::operator+;
	S s3 = fp1(s, s2);
	cout<<s3.value<<endl;

	/*
		함수 포인터로 만들수 있는것들.
		//함수
		callable
		() 
		열고 닫고 할수 있는애들
		
		//연산자 - 함수라는거다. 
		()
		람다 
		괄호 열고 닫고하는애들 , callable
	*/
}