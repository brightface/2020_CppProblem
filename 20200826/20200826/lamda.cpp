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
	//함수 포인터형이다. 함수 포인터로 받아서 하면 돼.

	//람다
	//무기명 함수. 호출을 못한다. 
	auto lambda1 = []() ->void {};
	////캡처문, 매개변수.

	//함수 포인터를 쓴것이다. 결과값이 주소를 객체화 시키는것이지.

	auto lambda2 = [](int a) ->void {}; //리턴타입 적어주는것
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


	
	//뒤에 매개변수 또 넣으면 함수 매개변수 들어가서 호출하러 들어간것.
	[](int a, int b) ->void
	{
		cout << a + b << endl;
	}(10, 20); //lamda(10,20);
	/////////////////////////////////////////////////////////////
	//대입과 람다 호출 동시에 넣을수는 없다. 
	auto lamda5 = [](int a, int b) 
	{
		cout << a + b << endl;
	}/*(10, 20);*/;
	lamda5(10, 20); //따로 해줘야함.
	/////////////////////////////////////////////////////////////

	int c = 10;
	[=](int a, int b) ->void
	{
		cout << a + b +c<< endl;
	}(10, 20); //lamda(10,20);
	//메인코드 다 변수 캡처해서 가져옴
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
	////callby reference -모든 변수 레퍼런스로 가져온다.

	//int c = 10;
	[&](int a, int b)
	{
		cout << a + b + c << endl;
		return a;//알아서 반환형이 int 로 잡아준다.
	}(10, 20); //lamda(10,20);
	//callby reference -모든 변수 레퍼런스로 가져온다.

}