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


//static int global; //���������� ������ �޸� �������� �ö��ִµ� �ٸ����Ͽ����� �޸𸮸� �����ְ� ���� ����. extern ����ߵ�, static�� ���������̴�. ������ ����.

			//C++ ����������°� �� �Ƚ�. C++

//static 
int main()
{	
	//extern int global;
	Static a;
	cout << a.global;
	//static �Ϲ� ���. �ʱ�ȭ�� �ѹ��ۿ� �ȵȴ�.
	//�޼��� ó���Լ��� ���ݾ�. ����� �����ϱ� ������. �Լ��ȿ� ���״� �����ؼ� �ʱ�ȭ�� �ѹ��ۿ� �ȵȴ�.
	//�ڵ�� ����޸� , ��������, 
	//4���� �ɼ� . 
	//�Ҹ� �ñ� 
	//���α׷��� ������ɋ� - ���� �������� ���ư���.
	/*
	Ŭ���� �ȿ� ���� �س����ϱ� ���� ��ü �޸𸮿� ���� ������ �ȵȴ�. ����޸� ���α׷��� ������ ���󰣴�.
	������ ���� ����ִ�. -  ��������
	����ƽ��Ʈ a = 0 ����.
	�������� - ���������� 0���� �ʱ�ȭ �Ǿ��ִ�.

	*/
	Data* data = nullptr;
	Function(data);

	/*static
	1. ���� �޸� ������ ������ �ȴ�
	2. �ʱ�ȭ�� �ѹ����ȴ�
	3. �ʱ�ȭ�� �����൵ 0���� �ʱ�ȭ �ȴ�.

	*/

	static int value;
	cout << value << endl;

	//while (true)
	//{
	//	static int value2 = 10; //�ʱ�ȭ�� �ѹ��� �Ǽ� ���� �ȵ�. �׷��� ��� ������
	//	value2 += 10;
	//	cout << value2 << endl;
	//}
	
	//��ü�޸𸮿� ��������.(��ü�� ũ�⿡ ���Ե��� �ʴ´�)
	cout << sizeof(Static) << endl;

	
	//cout << global;
}