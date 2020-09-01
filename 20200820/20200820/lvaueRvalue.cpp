#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//이동생성자 - rvalue
	//람다 - rvalue
	//2가지 

	int a = 10;
	//연산자 기준으로 왼쪽에 올수 있는게 lvalue

	//오른쪽에 올수있는것 rvalue

	//왼쪽에 있는것 오른쪽 있는것 기준은??
	/*
	 메모리공간을 특정할수 있는게 rvalue 

	 int a = 10;

	 10; //r value
	 int b = 20 + 30;//16 메모리 뜬다. // 4 4 4 더한결과를 임시변수에 저장이 되고 그게 여기에 대입 
	 //임시 변수도 r value다

	 나머지는 다 l value다.

	 개념이 확장되었다. 개념이 c++에서
	 메모리 주소 특정할수 있는것.
	 주소 알고 있음에도 불구하고 데이터를 넣을수 없는것. const 
	 const int a = 10; 
	 lvalue에 개념 확장
	 데이터를 쓸수 있든 없든 

	 int arr[30]
	 arr= 20; //안돼 주소 알수 있잖아. 
	 
	 int & ref = //l-value ref  원본의 주소를 공유한다. 레퍼런스
	 주소를 모르니까 r-value라 하는거야.

	 int&& rRef = 30;
	 이동생성자 : 소유권의 이전이 일어나는거야 - 영화 아일랜드 / 자기걸로 다 넘어와
	 vector<int> vec;
	 vec.push_back(new ); // 복사생성자 호출된다. 원본이 이쓰니까. 메모리 낭비가 심해
	 
	 vec.emplace_back(new
	 
	 //여러번 지우게 되는게 문제: 얉은 복사의 문제. 메모리 하나만 공유하고 있는데- 포인터로 연결만 되어있으니까 원본 지우면 문제생기지

	 
	*/

	int&& rRef = 30;
	vector<int> vec;
	//복사생성자 - 얉은 복사와 비슷하다.
	//vec.emplace_back(new )

	return 0;
}