#include <iostream>
#include <functional> //c++ ��Ÿ�� �Լ�������
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
	
	//�Լ��������� �̸�, �Ű������� ��
	void(*fp1)() = Function;

	fp1();

	//void(*fp2)(int) = Function;
	//void(*fp3)(int, int) = Function;
	//---------------------------------------------------------
	function<void()> fp4 = Function;
	function<void(int)> fp5 = Function2;
	function<void(int,int)> fp6 = Function3;
	//////////////////////////////////////////
	//�ڷ����̾� c++��Ÿ�� �Լ�������
	

	vector<void(*)()> vec;
	vec.push_back(fp1);
	vec.push_back([]() {cout << "Lambda" << endl; });

	for (void(*fp1)() : vec)
		fp1();
	//�� �տ� �ִ°�
	vec.front()(); //������ �����ϰ� ���⵵ �����ϰ�.
	////////////////////////////////////////
	
	return 0;
}