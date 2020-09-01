#include "Static.h"



Static::Static()
{
	extern int global;
	global = 10;
}


//클래스 외부에서 초기화 해주며 돼.
int Static::value4 = 4;


//어떤 객체의 value2냐 . 상대적이지 않다.특정객체에 value2라 해야한다.
//void Static::Function()
//{
//	value2 = 10;
//}
void Static::Function2()
{
	value2 = 10;
}

