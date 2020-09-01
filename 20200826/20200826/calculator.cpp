/*
전위 중위 후위 표기법

중위 표기법
3+ (4*2)

전위 표기
+3 * 4 2

후위 표기

3 4 2 * +

1. 연산별로 괄호를 씌운다. 
2. 지가 포함된 괄호 : 연산자를 바로 뒤에 보낸다.
3(4*2)+
3(42)*+
342*+

7+ ((2 * 5) /3) - (3 * 2))
7 2 5 * 3 / + 3 2 * -

문제 :(12 * 11) + 32 - (8 / 2 * 19) + 20 - 3 - 3

오답 : 12 11 * 32 + 8 2 19 / * - 20 3 3 + - - 

답 : 12 11 * 32 + 8 2 / 19 * - 20 + 3 - 3 -
//////////////////////////

문제 : 32 11 4 * - 3 / 12 + 2 +    => 중위로

오답: (32 - (11*4) - 3)/12   

답 : (32 - ((11*4 ) / 3 + 12 + 2)

*/

/*
1)
	1. 문자열 - 문자열 버퍼
	2. 후위식 문자열 버퍼

	1. 숫자를 만나면 후위식 버퍼에 넣어준다.
	숫자가 연속적으로 나올수 있겠지. 34  숫자를 구성하는 연속된 문자를 모두 추출해서 하나의 숫자로 만들고, 이어지는 피연산자(숫자)의 구분을 위해 공백을 하나 삽입한다.
	1111 *
	1 * 111
	11 * 11
	111 * 1 인지 모르니 공백을 하나 삽입한다.

2)  1. 연산자를 스택에다 넣는다.
	2. 두번째 부터는 스택을 검사하여 자신(연산자)보다 우선순위가 높은 연산자들을 모두 꺼내서 버퍼에 넣는다.

	11 * 11 + 3
	11 11 * /
	stack 
	+

	+ ( * /
3) 1. 여는괄호  '(' 를 만나면 스택에 넣는다. - 연산자 우선순위를 제일 낮게 해줄거야. 지금 고려할 대상이 아니다. 닫는 괄호를 만나면 날려주고
	- 스택에서 우선순위의 연산자를 어디까지 꺼낼것인가를 결정하기 위함이다.

4) 1. 닫는 괄호 ')'를 만나면 스택안에 있는 여는 괄호를 만날때 까지 스택안에 연산자들을 모두 버퍼에 넣어준다.

5) 1) ~ 4) 까지 반복을 하고 모든과정이 끝나면 스택에 남아있는 연산자들을 차례로 꺼내서 버퍼에 넣어준다. 마지막에 남아있는 연산자는 제일 낮은 우선순위의 연산자이다.

( : 0
+ , - ; 1
*, / : 2
^ : 3

*/

#include "ArrayStack.h"
#include <iostream>
#include <String>

using namespace std;

int GetPriority(int op)
{
	switch (op)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	}

	return 100; //이상한것 들어왔을떄 100이다.
}

void MakePostfix(char* post, const char* mid)
{
	//mid : 중위식
	//post ; 후위식의 버퍼
	const char* expression = mid;
	char* newExp = post;
	char c; //바로할때 쓰는 일시적 변수

	ArrayStack<char> cs(256); //256개 배열
	while (*expression)
	{	
		//역참조 걸면 숫자나 문자있겟지. 숫자면 4, 10진수로 변환할수 없는 문자라면 0, // => 숫자면 true//
		if (isdigit(*expression))
		{
			//소수점 만날수 있다.
			while (isdigit(*expression) || *expression == '.')
				*newExp++ = *expression++;

			*newExp++ = ' ';
		}
		else
		{
			if (strchr("^*-/+-", *expression)) //이문자열 안에 이게 있는지 없는지 판단해준다.
			{
				while (cs.Empty() != true && GetPriority(cs.Top()) >= GetPriority(*expression))
				{
					*newExp++ = cs.Top();
					cs.Pop();
				}
				//처음에는 넣어준다.
				cs.Push(*expression++);
			}
			else
			{
				//여는 괄호인지 닫는 괄호인지.
				if (*expression == '(')
					cs.Push(*expression++);
				else if (*expression == ')')
				{
					while (true)
					{
						c = cs.Top();
						cs.Pop();
						if (c == '(')
							break;
						*newExp++ = c;
					}
					expression++; //4번까지 다 했다.
				}
			}
		}
	}

	while (cs.Empty() != true)
	{
		*newExp++ = cs.Top();
		cs.Pop();
	}
	*newExp = 0; 
	//트리가지고도 할꺼야 그떄도 비슷하게 하면돼.
}

double CalcPostfix(const char* post)
{
	//가이드 라인. 스택을 쓸긴 쓸건데. 
	//후위식. 숫자들을 여기에 넣는거야.

	//3 +4* 8 == 3 4 8 * +

	//숫자인지 아닌지 쭉 읽어
	//숫자로 만든다음에 스택에 넣어. 

	//연산자 만나면 2개 꺼내서 연산해.
	//그리고 다시 스택에 넣어.
	ArrayStack<double> number(200);
	//stirng 형의 널문자 없다.
	//print("%s ", string);
	/////////////////////////////////
	string c_str;
	c_str.c_str(); //const char포인트 형으로 변환된다. 함수다. 널문자가 붙여주는거야.
	/////////////////////////////////
	
	for (const char* p = post; *p != 0; p++) {
		string temp;
		if (isdigit(*p) || *p == '.')
		{
			//소수점 만날수 있다.
			temp += *p;		
			int a = 0;
		}

		//atof
		else if (*p == ' ') {
			number.Push(atof(temp.c_str()));
		}//숫자를 스텍에 넣었다.
		else 
		{
			if (strchr("*+/^-",*p) )
			{
				double two[2];
				two[0] = number.Top();
				number.Pop();
				two[1] = number.Top();
				number.Pop();
				switch (*p)
				{
					case '+':
						number.Push(two[0] + two[1]);
						break;
					case '-':
						number.Push(two[0] - two[1]);
						break;
					case '*':
						number.Push(two[0] * two[1]);
						break;
					case '/':
						number.Push(two[0] / two[1]);
						break;
					case '^':
						number.Push(pow(two[0] , two[1]));
						break;
				}
			}
		}
	}
	return number.Top();
}

double CalcPostfix2(const char* post)
{
	const char* p = post;
	double num;
	double left, right;
	ArrayStack<double> ds(256);

	while (*p) //마지막 null문자 만나니까 끝난다.
	{	//문자열 다루는법/ 문자열 처리.
		if (isdigit(*p))
		{
			num = atof(p);
			ds.Push(num);

			while (isdigit(*p) || *p == '.')
				p++;
		}
		else
		{
			if (strchr("^+-/*", *p))
			{
				
				right = ds.Top();
				ds.Pop();

				left = ds.Top();
				ds.Pop();

				switch (*p)
				{
				case '+':
					ds.Push(left + right);
					break;
				case '-':
					ds.Push(left - right);
					break;
				case '*':
					ds.Push(left * right);
					break;
				case '/':
					
					if (right == 0.0)
						ds.Push(0.0); //assert 걸어야됨
					else
						ds.Push(left / right);
					break;
				case '^':
					ds.Push(pow(left , right));
					break;
				}
			}
			p++;
		}
	}

	if (ds.Empty() == false)
	{
		num = ds.Top();
		ds.Pop();
	}
	else
		num = 0.0;

	return num;
}

//반환값을 후위식에 넣어주겠다. 괄호짝이 true 면 true bError
double CalcExp(const char* exp, bool *bError = nullptr)
{
	char post[256];
	const char* p;
	int count;

	if (bError != nullptr)
	{	//문자열끝까지 돌아라. *p !=0;
		for (p = exp, count = 0; *p != 0; p++)
		{
			if (*p == '(')
				count++;
			else if (*p == ')')
				count--;
		}
	}
	*bError = count != 0;

	MakePostfix(post, exp);
	return CalcPostfix2(post);
}
int main()
{
	//char post[256];
	//char* mid = "3+4*7"; //const에 넣을수 있따.
	//MakePostfix(post, mid);
	//cout << post << endl;
	//--------------------------------- 8.26

	char exp[256];
	double temp;
	bool bError;
	double result;
	//cin >> exp;
	//cin >> temp;
//	ArrayStack<double> k(256);
//	k.Push(temp);
	//
	//while (true)
	//{
	//	cout << "수식을 입력하세요 : ";
	//	cin >> exp;

	//	if (strcmp(exp, "0") == 0) break;
	//	
	//	result = CalcExp(exp, &bError);
	//	//괄호짝이 안맞다고 이상하게 되는것뿐이야 아니되는건 아니야

	//	if (bError == true)
	//		cout << "수식의 괄호짝이 틀립니다.";
	//	else
	//	{
	//		cout << exp << " = " << result << endl;
	//	}
	//}

	//char post[100];
	// string w;
	// cin >> w;
	//const char* kk= w.c_str();
	//
	//MakePostfix(post,kk);
	char p[100] = {};
	/*cin >> p;
	cout << p;*/
	string a = "apple is delcious";
	for(int i=0; i<17; i++)
		cout << a[i];
	//cout<<CalcPostfix2(post);
	return 0;
}




