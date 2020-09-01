#include <iostream>
#include <functional>

using namespace std;

struct S
{
	int value = 0;
	S(int value) : value(value) {}

	S operator()(const S& other)
	{
		cout << "() ������ ������" << endl;
		return other;
	}

	//��ȣ �Ƚᵵ ���ݾ�. + �����ڵ� �ٵ� �Լ� �����ͷ� ���� 
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
	//��ȯ��, �Ű����� 2��, �Լ������ͷ� ������ ���� &S::operator+
	function<S&(S&, S&)> fp1 = &S::operator+;
	S s3 = fp1(s, s2);
	cout<<s3.value<<endl;

	/*
		�Լ� �����ͷ� ����� �ִ°͵�.
		//�Լ�
		callable
		() 
		���� �ݰ� �Ҽ� �ִ¾ֵ�
		
		//������ - �Լ���°Ŵ�. 
		()
		���� 
		��ȣ ���� �ݰ��ϴ¾ֵ� , callable
	*/
}