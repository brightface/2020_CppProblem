#include <iostream>
#include <functional> //c++ ��Ÿ�� �Լ�������
#include <vector>

using namespace std;

class TClass
{
public:
	TClass(int value) : value(value) {}
	~TClass() = default;

	void TestFunction()
	{
		cout << "��� �Լ�" << endl;
	}

	static void StaticFunction()
	{
		cout << "���״�" << endl;
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
	function<void(TClass& )> fp1 = /*�ϴ��� �ּҰ� �ʿ��ϰ�*/&TClass::TestFunction; // �ϴ��� �ּҰ� �ʿ��ϰ� ,��ü������ �Ѱ���ߵ� 
	function<void()> fp2 = TClass::StaticFunction; // �������ݾ�. �׷��� ������ �ȵ�

	fp1(t);//������ ������ ������ ����ϴ°�
	
	//������� ����� tŬ������ �Լ��� ȣ���ϰ���� ��Ȳ�̾�.
	//tŬ������ ��ü�� �ʿ��ϴ�?

	function<void()> fp3 = bind(&TClass::TestFunction, t); //���δ� ������� �����. �Լ������͵��� �Լ��� �ʿ��� �Ű����� ����� 
	fp3();
														   //��ü�� ����� ȣ���ϰ� ������Ȳ�̾� ������� ����ʹ�. �Լ������͸� ���鋚 �������� �����ž�. �Լ������;� ���� ����ְ� �Ǵ°���.
	function<void(int)> fp4 = bind(&TClass::TestFunction2, t, placeholders::_1);
	fp4(10);
	//function<void(&Rint)> fp3 = bind(&TClass::TestFunction2, t, placeholders);
	//function<void(int)> fp5 = bind(&TClass::TestFunction2, t, placeholders); //������ �ǹ̰� �ֵ�. ���� ������ �������� �ȴ�.
	function<void(int, int)>fp5 = bind(&TClass::TestFunction3, t, placeholders::_1, placeholders::_2);
	fp5(10, 20);
	//Ŭ������ �Ű� �Լ��ε� ��ü������ �Ѿ���Ѵ�.
	//�װ��� �ذ��ϱ����� ���°� bind, ������Ű�� �ʹ�. ���� �����ϵ���. //��������
	function<void(int)> fp6 = bind(&TClass::TestFunction3, t, 20, placeholders::_1); //�ٲ� - �ڿ��� 1��
	//function<void(int)> fp6 = bind(&TClass::TestFunction3, t, 20, placeholders::_2); //����/ �տ��� ���� ����. ���� �ڹٲ�� �ٲܶ�� 1�� ������ �ڿ� ���� ��߳���.
	fp6(10);
	//��������� ������ų���� �ִ�.
	function<void(int)> fp7 = bind(&TClass::TestFunction3, t, placeholders::_1, 20);
	fp7(10);

	
}