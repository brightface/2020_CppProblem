#include <iostream>
using namespace std;

/*
C++ 멀티 패러다임 언어.
1. 객체지향 프로그래밍.
->1. 캡슐화(은닉성- 열어주는것)
->2. 추상화(하나씩하나씩 추가를 하는거야, 현실세계에 있는것을 모델링하는것
->3. 다형성 - 오버라이딩, 오버로딩- 매개변수 다르다. 함수이름은 같고 
->4. 상속성 - 프로그래밍이다.



*/


//템플릿 없이 쓰는 스왑함수
void swap(int& a, int&b) //형변환 안돼. & 쓰면 , 물론 inter 어찌고 저찌고 하면 강제형변환. 권잫아지 않아.
{
	int temp = a;
	a = b;
	b = temp;
}
void swap(float& a, float&b) //형변환 안돼. & 쓰면 , 물론 inter 어찌고 저찌고 하면 강제형변환. 권잫아지 않아.
{
	float temp = a;
	a = b;
	b = temp;
}

//이렇게 일일히 안하면 void 포인터로 한다. 자료형의 길이까지 넘겨줘야한다. 그만큼 템플릿의 코드 메모리 절약하고 싶다. 따라서 
void Swap(void* a, void* b, int len)//void point 데이터크기를 적어야돼
{
	void* temp = nullptr;//memcpy 하려고
	temp = malloc(len);
	memcpy(temp, a, len);
	memcpy(a, b, len);
	memcpy(b, temp, len);
	free(temp);
}

#define SWAP(T,a,b){ T temp; temp = a; a=b; b = temp; }//자료형 자체를 매크로로 넘겨준다.
//디버깅이 안된다. 크다. define으로 함수를 전개했을때. 30줄짜리 함수면 답이 안나와.

#define MakeSwap(T)\
void SwapMacro(T &a, T& b)\
{\
	T temp;\
	temp = a;\
	a = b;\
	b = temp;\
}

MakeSwap(int)
MakeSwap(double)


template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	SWAP(int, a, b); //프로그램 길이가 길어져. 코드길이가 길어져. inline함수랑 같다.exe파일 크기가 커진다.
	cout << a << " " << b << endl;

	SwapMacro(a, b);
	cout << a << " " << b << endl; // 실제적으로 템플릿이랑 똑같이 동작해.
	//전처리기가 한다. - 수동

	//템플릿은 컴파일러가한다. - 자동이 한다. 

	//템플릿으로 만들어보자

	//-만듬
	Swap(a, b);

	////////////////////////////////////////////////////////////////

	//오버로딩을 할때 반환형은 포함안되는것이다.
	//함수의 이름, 함수의 매개변수. 반환형은 안들어있다. 
	//함수를 구별할때 함수시그니처를 한다.

	//오버라이딩 - 버츄얼. 가상함수. 
	//클래스 가삼함수 테이블 생기지. 가상함수 
	//가상함수 테이블 포인터로 잡힌다.
	//4바이트이다. 12바이트로 잡힌다. 3개함수.

	//객체끼리의 통신 - 스테틱도 연관 c++ 나오면서 생김

	//2. 절차지향 프로그래밍
	//번역오류 
	//prodedural Programming 
	//명사형으로 뜯어보면 
	//procedure(프로시저) : 프로그래밍을 여러개의 단위로 분해한것 
	//메인함수잖아.== 제일먼저 실행되는것. 프로그램 = 함수들의 집합
	/*
		함수호출의 개념을 바탕으로 프로그램을 작성하는 방식 // 전혀 의미가 달라.
		
	*/
	//3. 함수지향 프로그래밍 - 요즘 핫한것
	/*
		병렬처리하기 위한 함수야.
		computeShader 병렬처리로 들어가잖아.

	*/
	//4. 일반화 프로그래밍 
	/*
		템플릿. 언제나왔을까? C언어 처음 개발될때부터 있었어.
		함수템플릿 이라는게 있었어.
		->임의 타입에 대해 동작하는 함수나 클래스를 작성하는 방식,
		자료형 중심으로 프로그램을 만드는 방식.
		재사용점 편의성에 장점이 있다.
	
		stl : 스탠다드 

	*/


}