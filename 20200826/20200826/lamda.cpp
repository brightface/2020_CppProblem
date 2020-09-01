#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/*int c = 10;
	vector<void(*) (int a, int b)> vec;
	vec.push_back([](int a, int b)
	{
		cout << a+b << endl;
	});

	cout << c << endl;
	vec[0](10, 20);*/
	//�Լ� ���������̴�. �Լ� �����ͷ� �޾Ƽ� �ϸ� ��.

	//����
	//����� �Լ�. ȣ���� ���Ѵ�. 
	auto lambda1 = []() ->void {};
	////ĸó��, �Ű�����.

	//�Լ� �����͸� �����̴�. ������� �ּҸ� ��üȭ ��Ű�°�����.

	auto lambda2 = [](int a) ->void {}; //����Ÿ�� �����ִ°�
	auto lambda3 = [](int a, int b) {}; /*->void {};*/
	
	int a = 10, b = 20;
	auto lambda4 = [=]()->void
	{
		cout << a + b << endl;
	};

	[=]()
	{
		cout << a + b << endl;
	};

	[=]()->void
	{
		cout << a + b << endl;
	};


	
	//�ڿ� �Ű����� �� ������ �Լ� �Ű����� ���� ȣ���Ϸ� ����.
	[](int a, int b) ->void
	{
		cout << a + b << endl;
	}(10, 20); //lamda(10,20);
	/////////////////////////////////////////////////////////////
	//���԰� ���� ȣ�� ���ÿ� �������� ����. 
	auto lamda5 = [](int a, int b) 
	{
		cout << a + b << endl;
	}/*(10, 20);*/;
	lamda5(10, 20); //���� �������.
	/////////////////////////////////////////////////////////////

	int c = 10;
	[=](int a, int b) ->void
	{
		cout << a + b +c<< endl;
	}(10, 20); //lamda(10,20);
	//�����ڵ� �� ���� ĸó�ؼ� ������
	//call by value

	
	[c](int a, int b) ->void
	{
		cout << a + b + c << endl;
	}(10, 20); //lamda(10,20);
	//callby value

	//int c = 10;
	[&c](int a, int b) ->void
	{
		cout << a + b + c << endl;
	}(10, 20); //lamda(10,20);
	//callby reference

	//int c = 10;
	//[&](int a, int b) ->void
	//{
	//	cout << a + b + c << endl;
	//}(10, 20); //lamda(10,20);
	////callby reference -��� ���� ���۷����� �����´�.

	//int c = 10;
	[&](int a, int b)
	{
		cout << a + b + c << endl;
		return a;//�˾Ƽ� ��ȯ���� int �� ����ش�.
	}(10, 20); //lamda(10,20);
	//callby reference -��� ���� ���۷����� �����´�.

}