#include "ArrayStack.h"
#include <iostream>
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

	return 100;
}

void MakePostfix(char* post, const char* mid)
{
	const char* expression = mid;
	char* newExp = post;
	char c;

	ArrayStack<char> cs(256);
	while (*expression)
	{
		//���ڸ� 4
		//10������ ��ȯ�Ҽ� ���� ���ڶ�� 0
		if (isdigit(*expression))
		{
			while (isdigit(*expression) || *expression == '.')
				*newExp++ = *expression++;

			*newExp++ = ' ';
		}
		else
		{
			if (strchr("^*/+-", *expression))
			{
				while (cs.Empty() != true
					&& GetPriority(cs.Top()) >= GetPriority(*expression))
				{
					*newExp++ = cs.Top();
					cs.Pop();
				}

				cs.Push(*expression++);
			}
			else
			{
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
					expression++;
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
}

double CalcPostfix(const char* post)
{
	//stack
	//���ڴ� ���ÿ� �ְ�, �����ڴ� ���ÿ��� ���� �����ͼ� �����Ѵ�.
	//����� ����� �ٽ� ���ÿ� �ִ´�.
	//atof

	const char* p = post;
	double num;
	double left, right;
	ArrayStack<double> ds(256);

	while (*p)
	{
		if (isdigit(*p))
		{
			num = atof(p);
			ds.Push(num);

			while (isdigit(*p) || *p == '.')
				p++;
		}
		else
		{
			if (strchr("^*/+-", *p))
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
					ds.Push(pow(left, right));
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

double CalcExp(const char* exp, bool *bError = nullptr)
{
	char post[256];
	const char* p;
	int count;

	if (bError != nullptr)
	{
		for (p = exp, count = 0; *p != 0; p++)
		{
			if (*p == '(')
				count++;
			if (*p == ')')
				count--;
		}
		*bError = count != 0;
	}

	MakePostfix(post, exp);
	return CalcPostfix(post);
}

int main()
{
	char exp[256];
	bool bError;
	double result;

	while (true)
	{
		cout << "������ �Է��ϼ��� : ";
		cin >> exp;
		if (strcmp(exp, "0") == 0) break;

		result = CalcExp(exp, &bError);
		if (bError == true)
			cout << "������ ��ȣ¦�� Ʋ���ϴ�.";
		else
		{
			cout << exp << " = " << result << endl;
		}

	}

	return 0;
}