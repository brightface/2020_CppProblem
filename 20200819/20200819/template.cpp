#include <iostream>
using namespace std;

/*
C++ ��Ƽ �з����� ���.
1. ��ü���� ���α׷���.
->1. ĸ��ȭ(���м�- �����ִ°�)
->2. �߻�ȭ(�ϳ����ϳ��� �߰��� �ϴ°ž�, ���Ǽ��迡 �ִ°��� �𵨸��ϴ°�
->3. ������ - �������̵�, �����ε�- �Ű����� �ٸ���. �Լ��̸��� ���� 
->4. ��Ӽ� - ���α׷����̴�.



*/


//���ø� ���� ���� �����Լ�
void swap(int& a, int&b) //����ȯ �ȵ�. & ���� , ���� inter ����� ����� �ϸ� ��������ȯ. �ǟ����� �ʾ�.
{
	int temp = a;
	a = b;
	b = temp;
}
void swap(float& a, float&b) //����ȯ �ȵ�. & ���� , ���� inter ����� ����� �ϸ� ��������ȯ. �ǟ����� �ʾ�.
{
	float temp = a;
	a = b;
	b = temp;
}

//�̷��� ������ ���ϸ� void �����ͷ� �Ѵ�. �ڷ����� ���̱��� �Ѱ�����Ѵ�. �׸�ŭ ���ø��� �ڵ� �޸� �����ϰ� �ʹ�. ���� 
void Swap(void* a, void* b, int len)//void point ������ũ�⸦ ����ߵ�
{
	void* temp = nullptr;//memcpy �Ϸ���
	temp = malloc(len);
	memcpy(temp, a, len);
	memcpy(a, b, len);
	memcpy(b, temp, len);
	free(temp);
}

#define SWAP(T,a,b){ T temp; temp = a; a=b; b = temp; }//�ڷ��� ��ü�� ��ũ�η� �Ѱ��ش�.
//������� �ȵȴ�. ũ��. define���� �Լ��� ����������. 30��¥�� �Լ��� ���� �ȳ���.

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
	SWAP(int, a, b); //���α׷� ���̰� �����. �ڵ���̰� �����. inline�Լ��� ����.exe���� ũ�Ⱑ Ŀ����.
	cout << a << " " << b << endl;

	SwapMacro(a, b);
	cout << a << " " << b << endl; // ���������� ���ø��̶� �Ȱ��� ������.
	//��ó���Ⱑ �Ѵ�. - ����

	//���ø��� �����Ϸ����Ѵ�. - �ڵ��� �Ѵ�. 

	//���ø����� ������

	//-����
	Swap(a, b);

	////////////////////////////////////////////////////////////////

	//�����ε��� �Ҷ� ��ȯ���� ���ԾȵǴ°��̴�.
	//�Լ��� �̸�, �Լ��� �Ű�����. ��ȯ���� �ȵ���ִ�. 
	//�Լ��� �����Ҷ� �Լ��ñ״�ó�� �Ѵ�.

	//�������̵� - �����. �����Լ�. 
	//Ŭ���� �����Լ� ���̺� ������. �����Լ� 
	//�����Լ� ���̺� �����ͷ� ������.
	//4����Ʈ�̴�. 12����Ʈ�� ������. 3���Լ�.

	//��ü������ ��� - ����ƽ�� ���� c++ �����鼭 ����

	//2. �������� ���α׷���
	//�������� 
	//prodedural Programming 
	//���������� ���� 
	//procedure(���ν���) : ���α׷����� �������� ������ �����Ѱ� 
	//�����Լ��ݾ�.== ���ϸ��� ����Ǵ°�. ���α׷� = �Լ����� ����
	/*
		�Լ�ȣ���� ������ �������� ���α׷��� �ۼ��ϴ� ��� // ���� �ǹ̰� �޶�.
		
	*/
	//3. �Լ����� ���α׷��� - ���� ���Ѱ�
	/*
		����ó���ϱ� ���� �Լ���.
		computeShader ����ó���� ���ݾ�.

	*/
	//4. �Ϲ�ȭ ���α׷��� 
	/*
		���ø�. ������������? C��� ó�� ���ߵɶ����� �־���.
		�Լ����ø� �̶�°� �־���.
		->���� Ÿ�Կ� ���� �����ϴ� �Լ��� Ŭ������ �ۼ��ϴ� ���,
		�ڷ��� �߽����� ���α׷��� ����� ���.
		������ ���Ǽ��� ������ �ִ�.
	
		stl : ���Ĵٵ� 

	*/


}