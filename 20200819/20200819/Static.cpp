#include "Static.h"



Static::Static()
{
	extern int global;
	global = 10;
}


//Ŭ���� �ܺο��� �ʱ�ȭ ���ָ� ��.
int Static::value4 = 4;


//� ��ü�� value2�� . ��������� �ʴ�.Ư����ü�� value2�� �ؾ��Ѵ�.
//void Static::Function()
//{
//	value2 = 10;
//}
void Static::Function2()
{
	value2 = 10;
}

