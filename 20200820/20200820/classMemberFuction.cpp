#include <iostream>
#include <functional> //c++ 스타일 함수포인터
#include <vector>

using namespace std;

class TClass
{
public:
	TClass(int value) : value(value) {}
	~TClass() = default;

	void TestFunction()
	{
		cout << "멤버 함수" << endl;
	}

	static void StaticFunction()
	{
		cout << "스테닉" << endl;
	}

	void TestFunction2(int value)
	{
		cout << value << endl;
	}
	void TestFunction3(int value, int value2)
	{
		cout <<"value : " <<value<< endl;
		cout << "value2 : " << value2 << endl;
	}

private: 
	int value;
	int value2;
};

int main()
{
	TClass t(10);
	function<void(TClass& )> fp1 = /*일단은 주소가 필요하고*/&TClass::TestFunction; // 일단은 주소가 필요하고 ,객체정보를 넘겨줘야돼 
	function<void()> fp2 = TClass::StaticFunction; // 공용이잖아. 그래서 문제가 안돼

	fp1(t);//누구의 벨류를 가지고 써야하는가
	
	//연결고리를 끊어내고 t클래스의 함수를 호출하고싶은 상황이야.
	//t클래스의 객체가 필요하다?

	function<void()> fp3 = bind(&TClass::TestFunction, t); //점부다 묶어가지고 만든다. 함수포인터들을 함수에 필요한 매개변수 목록을 
	fp3();
														   //객체를 만들고도 호출하고 싶은상황이야 연결고리르 끊고싶다. 함수포인터를 만들떄 고정시켜 버릴거야. 함수포인터아 엔에 들어있게 되는거지.
	function<void(int)> fp4 = bind(&TClass::TestFunction2, t, placeholders::_1);
	fp4(10);
	//function<void(&Rint)> fp3 = bind(&TClass::TestFunction2, t, placeholders);
	//function<void(int)> fp5 = bind(&TClass::TestFunction2, t, placeholders); //순서가 의미가 있따. 들어가는 순서도 뒤집히게 된다.
	function<void(int, int)>fp5 = bind(&TClass::TestFunction3, t, placeholders::_1, placeholders::_2);
	fp5(10, 20);
	//클래스의 매개 함수인데 객체정보가 넘어가야한다.
	//그걸을 해결하기위해 쓰는게 bind, 고정시키고 싶다. 값을 고정하든지. //가변인자
	function<void(int)> fp6 = bind(&TClass::TestFunction3, t, 20, placeholders::_1); //바꿈 - 뒤에가 1로
	//function<void(int)> fp6 = bind(&TClass::TestFunction3, t, 20, placeholders::_2); //에러/ 앞에서 부터 들어간다. 따라서 뒤바뀌면 바꿀라면 1이 들어가야지 뒤에 논리가 어긋나지.
	fp6(10);
	//상수항으로 고정시킬수도 있다.
	function<void(int)> fp7 = bind(&TClass::TestFunction3, t, placeholders::_1, 20);
	fp7(10);

	
}