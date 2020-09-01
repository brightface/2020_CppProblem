/*
���� ���� ���� ǥ���

���� ǥ���
3+ (4*2)

���� ǥ��
+3 * 4 2

���� ǥ��

3 4 2 * +

1. ���꺰�� ��ȣ�� �����. 
2. ���� ���Ե� ��ȣ : �����ڸ� �ٷ� �ڿ� ������.
3(4*2)+
3(42)*+
342*+

7+ ((2 * 5) /3) - (3 * 2))
7 2 5 * 3 / + 3 2 * -

���� :(12 * 11) + 32 - (8 / 2 * 19) + 20 - 3 - 3

���� : 12 11 * 32 + 8 2 19 / * - 20 3 3 + - - 

�� : 12 11 * 32 + 8 2 / 19 * - 20 + 3 - 3 -
//////////////////////////

���� : 32 11 4 * - 3 / 12 + 2 +    => ������

����: (32 - (11*4) - 3)/12   

�� : (32 - ((11*4 ) / 3 + 12 + 2)

*/

/*
1)
	1. ���ڿ� - ���ڿ� ����
	2. ������ ���ڿ� ����

	1. ���ڸ� ������ ������ ���ۿ� �־��ش�.
	���ڰ� ���������� ���ü� �ְ���. 34  ���ڸ� �����ϴ� ���ӵ� ���ڸ� ��� �����ؼ� �ϳ��� ���ڷ� �����, �̾����� �ǿ�����(����)�� ������ ���� ������ �ϳ� �����Ѵ�.
	1111 *
	1 * 111
	11 * 11
	111 * 1 ���� �𸣴� ������ �ϳ� �����Ѵ�.

2)  1. �����ڸ� ���ÿ��� �ִ´�.
	2. �ι�° ���ʹ� ������ �˻��Ͽ� �ڽ�(������)���� �켱������ ���� �����ڵ��� ��� ������ ���ۿ� �ִ´�.

	11 * 11 + 3
	11 11 * /
	stack 
	+

	+ ( * /
3) 1. ���°�ȣ  '(' �� ������ ���ÿ� �ִ´�. - ������ �켱������ ���� ���� ���ٰž�. ���� ����� ����� �ƴϴ�. �ݴ� ��ȣ�� ������ �����ְ�
	- ���ÿ��� �켱������ �����ڸ� ������ �������ΰ��� �����ϱ� �����̴�.

4) 1. �ݴ� ��ȣ ')'�� ������ ���þȿ� �ִ� ���� ��ȣ�� ������ ���� ���þȿ� �����ڵ��� ��� ���ۿ� �־��ش�.

5) 1) ~ 4) ���� �ݺ��� �ϰ� �������� ������ ���ÿ� �����ִ� �����ڵ��� ���ʷ� ������ ���ۿ� �־��ش�. �������� �����ִ� �����ڴ� ���� ���� �켱������ �������̴�.

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

	return 100; //�̻��Ѱ� �������� 100�̴�.
}

void MakePostfix(char* post, const char* mid)
{
	//mid : ������
	//post ; �������� ����
	const char* expression = mid;
	char* newExp = post;
	char c; //�ٷ��Ҷ� ���� �Ͻ��� ����

	ArrayStack<char> cs(256); //256�� �迭
	while (*expression)
	{	
		//������ �ɸ� ���ڳ� �����ְ���. ���ڸ� 4, 10������ ��ȯ�Ҽ� ���� ���ڶ�� 0, // => ���ڸ� true//
		if (isdigit(*expression))
		{
			//�Ҽ��� ������ �ִ�.
			while (isdigit(*expression) || *expression == '.')
				*newExp++ = *expression++;

			*newExp++ = ' ';
		}
		else
		{
			if (strchr("^*-/+-", *expression)) //�̹��ڿ� �ȿ� �̰� �ִ��� ������ �Ǵ����ش�.
			{
				while (cs.Empty() != true && GetPriority(cs.Top()) >= GetPriority(*expression))
				{
					*newExp++ = cs.Top();
					cs.Pop();
				}
				//ó������ �־��ش�.
				cs.Push(*expression++);
			}
			else
			{
				//���� ��ȣ���� �ݴ� ��ȣ����.
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
					expression++; //4������ �� �ߴ�.
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
	//Ʈ�������� �Ҳ��� �׋��� ����ϰ� �ϸ��.
}

double CalcPostfix(const char* post)
{
	//���̵� ����. ������ ���� ���ǵ�. 
	//������. ���ڵ��� ���⿡ �ִ°ž�.

	//3 +4* 8 == 3 4 8 * +

	//�������� �ƴ��� �� �о�
	//���ڷ� ��������� ���ÿ� �־�. 

	//������ ������ 2�� ������ ������.
	//�׸��� �ٽ� ���ÿ� �־�.
	ArrayStack<double> number(200);
	//stirng ���� �ι��� ����.
	//print("%s ", string);
	/////////////////////////////////
	string c_str;
	c_str.c_str(); //const char����Ʈ ������ ��ȯ�ȴ�. �Լ���. �ι��ڰ� �ٿ��ִ°ž�.
	/////////////////////////////////
	
	for (const char* p = post; *p != 0; p++) {
		string temp;
		if (isdigit(*p) || *p == '.')
		{
			//�Ҽ��� ������ �ִ�.
			temp += *p;		
			int a = 0;
		}

		//atof
		else if (*p == ' ') {
			number.Push(atof(temp.c_str()));
		}//���ڸ� ���ؿ� �־���.
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

	while (*p) //������ null���� �����ϱ� ������.
	{	//���ڿ� �ٷ�¹�/ ���ڿ� ó��.
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
						ds.Push(0.0); //assert �ɾ�ߵ�
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

//��ȯ���� �����Ŀ� �־��ְڴ�. ��ȣ¦�� true �� true bError
double CalcExp(const char* exp, bool *bError = nullptr)
{
	char post[256];
	const char* p;
	int count;

	if (bError != nullptr)
	{	//���ڿ������� ���ƶ�. *p !=0;
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
	//char* mid = "3+4*7"; //const�� ������ �ֵ�.
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
	//	cout << "������ �Է��ϼ��� : ";
	//	cin >> exp;

	//	if (strcmp(exp, "0") == 0) break;
	//	
	//	result = CalcExp(exp, &bError);
	//	//��ȣ¦�� �ȸ´ٰ� �̻��ϰ� �Ǵ°ͻ��̾� �ƴϵǴ°� �ƴϾ�

	//	if (bError == true)
	//		cout << "������ ��ȣ¦�� Ʋ���ϴ�.";
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




