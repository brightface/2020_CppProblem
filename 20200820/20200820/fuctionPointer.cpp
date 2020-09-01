#include <iostream>
#include <functional> //c++ 스타일 함수포인터
#include <vector>
using namespace std;

void Function()
{
	cout << "print Function " << endl;
}
void Function2(int a)
{
	cout << "overloading2" << endl;
}
void Function3(int a , int b)
{
	cout << "overloading2" << endl;
}

//
//void Function(int a, int b)
//{
//	cout << "overloading2" << endl;
//}
//void Function(int a)
//{
//	cout << "overloading2" << endl;
//}
int main()
{
	//Function(); 
	
	//함수포인터의 이름, 매개변수가 들어가
	void(*fp1)() = Function;

	fp1();

	//void(*fp2)(int) = Function;
	//void(*fp3)(int, int) = Function;
	//---------------------------------------------------------
	function<void()> fp4 = Function;
	function<void(int)> fp5 = Function2;
	function<void(int,int)> fp6 = Function3;
	//////////////////////////////////////////
	//자료형이야 c++스타일 함수포인터
	

	vector<void(*)()> vec;
	vec.push_back(fp1);
	vec.push_back([]() {cout << "Lambda" << endl; });

	for (void(*fp1)() : vec)
		fp1();
	//젤 앞에 있는것
	vec.front()(); //문법도 괴상하고 쓰기도 괴상하고.
	////////////////////////////////////////
	
	return 0;
}