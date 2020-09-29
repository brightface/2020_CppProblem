//프로젝트 대상변경 // 솔루션 다시검사

#include "tree2.h"
#include "binaryTree.h"
#include <cstring>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

int a;

int GetPriority(int op)
{
	switch (op) {
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

void MakePostfix(char *Post, const char *Mid)
{
	const char *expression = Mid;
	char *newExp = Post;
	char c;

	stack<char> cS;

	while (*expression)
	{
		if (isdigit(*expression))
		{
			while (isdigit(*expression) || *expression == '.')
			{
				*newExp++ = *expression++;
			}
			*newExp++ = ' ';
		}
		else
		{
			if (strchr("^*/+-", *expression))
			{
				while (cS.empty() != true && GetPriority(cS.top()) >= GetPriority(*expression))
				{
					*newExp++ = cS.top();
					cS.pop();
				}
				cS.push(*expression++);
			}
			else
			{
				if (*expression == '(')
				{
					cS.push(*expression++);
				}
				else if (*expression == ')')
				{
					while (true)
					{
						c = cS.top();
						cS.pop();
						if (c == '(')
							break;
						*newExp++ = c;
					}
					expression++;
				}

			}
		}
	}

	while (cS.empty() == false) {

		*newExp++ = cS.top();
		cS.pop();
	}
	*newExp = 0;
}
//void StrExpression(string postfix, BinaryTree::Node** node)
//{
//	char* str = postfix.c_str;
//	size_t length = strlen(str);
//
//	//제일 마지막에 있는 문자.
//	char token = str[length - 1];
//	if (isdigit(token)) //숫자면 
//	{
//		//공백나올때까지 찾아간다음에 strExpression에 넣는다.
//		//공백 나오면 그 숫자까지가 숫자이기 때문에 . strExpression 재귀 돌린다.
//	}
//	else // 아니면 문자면
//	{
//		str[length - 1] = '\0';
//		//넣었으니 재귀 탈때 그앞까지 구하고 길이를 구한다.
//
//		switch (token)
//		{
//		case '+':
//		case '-':
//		case '/':
//		case '*':
//		case '%':
//		{
//			*node = BinaryTree::CreateNode(token);
//			//L R Root니까 역으로 가는거야.
//			StrExpression(postfix, &(*node)->right);
//			StrExpression(postfix, &(*node)->left);
//			break;
//		}
//		default:
//		{
//			*node = BinaryTree::CreateNode(token);
//			break;
//		}
//		}
//	}
//	
//}

void Expression(const char* postfix, BinaryTree::Node** node)
{
	char* str = const_cast<char*>(postfix);
	//"34*14+-"
	size_t length = strlen(str);
	stack<char> cs;

	//제일 마지막에 있는 문자
	char token = str[length - 1];
	cs.push(token); //공백일수 있으니까 유지를 한다. 
	str[length - 1] = '\0';

	switch (cs.top())
	{
		case '+':
		case '-':
		case '/':
		case '*':
		case '%':
		{	
			//연산자 말고 문자열 공간 잡아야해.
			char* temp = new char[2]; //2바이트 // why?
			temp[0] = cs.top();
			temp[1] = '\0'; //null문자 
			cs.pop();

			*node = BinaryTree::CreateNode(temp); //넣으면 돼


			//L R Root니까 역으로 가는거야.
			Expression(postfix, &(*node)->right);
			Expression(postfix, &(*node)->left);
			break;
		}
		default:
		{
			token = str[length -= 2];
			while (isdigit(token) || token == '.') //10진수인지 아닌지 판별 , 공백이냐 문자냐 .
			{
				cs.push(token);
				if(length - 1 == UINT_MAX) //unsigned int 면 터진다.
					token = 'n';
				else
				{
					str[length--] = '\0';
					token = str[length];
				}
			}
			char* temp = new char[cs.size() + 1]; //null문자 1개 더해줘야한다.
			int index = 0; //문자열에 index =0; 만들어놓을거야.
			int stackSize = cs.size();
			while (cs.empty() == false)
			{
				temp[index++] = cs.top();
				cs.pop();
			}
			///////////
			temp[stackSize] = '\0';

			*node = BinaryTree::CreateNode(temp);
			break;
		}
	}
}

double Evaluate(BinaryTree::Node* node)
{
	if (node == nullptr) return 0.0;

	switch (*node->data)
	{
		case '+':
		case '-':
		case '/':
		case '*':
		case '%':
		{
			double left = Evaluate(node->left);
			double right = Evaluate(node->right);
		
			switch (*node->data)
			{
			case '+': return left + right;
			case '-': return left - right;
			case '/': return left / right;
			case '*': return left * right;
			//case '%': return left % right; double이니까 안된다.

			}break;
		}
		default:
		{
			/*char temp[4];
			memset(temp, 0, sizeof(temp));
			temp[0] = node->data;*/
			return atoi(node->data);
		}
	}
	return 0;
}

int main()
{
	
	//자식갯수의 여러개가 되는것. os에서 directory 구조
	//유니티 본구조가 전부 트리다. left shoulder bone 
	//척추, 하나의 공통된 분모를 가지잖아. 그래프는 아닐거 아니야. 그래프는 조상이 2개가 있을수 있겠지.
	//그런것에서 트리를 볼수가 있겠지. 형태가 정해져 있지 않은 트리들. 우리가 중요한건 이진트리이다. 트리 알고리즘 90퍼센트
	//높은확률 로 이진트리.
	//빅오표기법할때  이진탐색, 이진트리에 기반한 알고리즘. 피보나치 도 이진탐색 쓴다.
	//계산기 이진트리를 가지고 수식을 할수 있다. 
	//알비트리 .
	//vector<Tree::Node*> arr;
	////일반적으로 이진트리를 많이쓴다.
	//BinaryTree::Node* Root = BinaryTree::CreateNode('R');
	//BinaryTree::Node* A = BinaryTree::CreateNode('A');
	//BinaryTree::Node* B = BinaryTree::CreateNode('B');
	//BinaryTree::Node* C = BinaryTree::CreateNode('C');
	//BinaryTree::Node* D= BinaryTree::CreateNode('D');
	//BinaryTree::Node* E= BinaryTree::CreateNode('E');
	//BinaryTree::Node* F = BinaryTree::CreateNode('F');
	//BinaryTree::Node* G= BinaryTree::CreateNode('G');

	//A->left = B;
	//A->right = C;

	//B->left = D;
	//B->right = E;

	//C->left = F;
	//C->right = G;

	//BinaryTree::PreOrder(A);
	//cout << endl;
	//BinaryTree::PostOrder(A);
	//cout << endl;
	//BinaryTree::InOrder(A);


	//Tree::Node* Root = Tree::Create('R');
	//Tree::Node* A = Tree::Create('A');
	//Tree::Node* B= Tree::Create('B');
	//Tree::Node* C= Tree::Create('C');
	//Tree::Node* D= Tree::Create('D');
	//Tree::Node* E= Tree::Create('E');
	//Tree::Node* F = Tree::Create('F');
	//Tree::Node* G = Tree::Create('G');
	//Tree::Node* K = Tree::Create('G');
	////Tree::Addchild //일케하면 안되지 static 아니잖아

	//Tree tree;

	//tree.AddChild(Root, A);
	//tree.AddChild(Root, B);

	//tree.AddChild(A, C);
	//tree.AddChild(A, D);

	//tree.AddChild(C, E);
	//tree.AddChild(C, F);

	//tree.AddChild(B, G);
	//tree.AddChild(B, K);

	////tree.PrintNode(Root, 0);

	//tree.GetNode(Root, 'G');
	
	//3*4 - (1+4)
	string postfix = "34*14+-";

	char exp[255];
	char post[255];
	BinaryTree::Node* root = nullptr;
	
	cout << "수식을 입력하시오 : " ;
	cin >> exp;
	MakePostfix(post, exp);
	
	cout << "후위표기식" << post << endl;
	Expression(post, &root);
	
	cout << "PostOrder"<< endl;
	BinaryTree::PostOrder(root); cout << endl;
	
	//Expression(postfix.c_str(), &root);

	cout<<"Result :" <<" " << Evaluate(root) << endl;


}