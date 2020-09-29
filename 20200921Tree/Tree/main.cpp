//������Ʈ ��󺯰� // �ַ�� �ٽð˻�

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
//	//���� �������� �ִ� ����.
//	char token = str[length - 1];
//	if (isdigit(token)) //���ڸ� 
//	{
//		//���鳪�ö����� ã�ư������� strExpression�� �ִ´�.
//		//���� ������ �� ���ڱ����� �����̱� ������ . strExpression ��� ������.
//	}
//	else // �ƴϸ� ���ڸ�
//	{
//		str[length - 1] = '\0';
//		//�־����� ��� Ż�� �׾ձ��� ���ϰ� ���̸� ���Ѵ�.
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
//			//L R Root�ϱ� ������ ���°ž�.
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

	//���� �������� �ִ� ����
	char token = str[length - 1];
	cs.push(token); //�����ϼ� �����ϱ� ������ �Ѵ�. 
	str[length - 1] = '\0';

	switch (cs.top())
	{
		case '+':
		case '-':
		case '/':
		case '*':
		case '%':
		{	
			//������ ���� ���ڿ� ���� ��ƾ���.
			char* temp = new char[2]; //2����Ʈ // why?
			temp[0] = cs.top();
			temp[1] = '\0'; //null���� 
			cs.pop();

			*node = BinaryTree::CreateNode(temp); //������ ��


			//L R Root�ϱ� ������ ���°ž�.
			Expression(postfix, &(*node)->right);
			Expression(postfix, &(*node)->left);
			break;
		}
		default:
		{
			token = str[length -= 2];
			while (isdigit(token) || token == '.') //10�������� �ƴ��� �Ǻ� , �����̳� ���ڳ� .
			{
				cs.push(token);
				if(length - 1 == UINT_MAX) //unsigned int �� ������.
					token = 'n';
				else
				{
					str[length--] = '\0';
					token = str[length];
				}
			}
			char* temp = new char[cs.size() + 1]; //null���� 1�� ��������Ѵ�.
			int index = 0; //���ڿ��� index =0; ���������ž�.
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
			//case '%': return left % right; double�̴ϱ� �ȵȴ�.

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
	
	//�ڽİ����� �������� �Ǵ°�. os���� directory ����
	//����Ƽ �������� ���� Ʈ����. left shoulder bone 
	//ô��, �ϳ��� ����� �и� �����ݾ�. �׷����� �ƴҰ� �ƴϾ�. �׷����� ������ 2���� ������ �ְ���.
	//�׷��Ϳ��� Ʈ���� ������ �ְ���. ���°� ������ ���� ���� Ʈ����. �츮�� �߿��Ѱ� ����Ʈ���̴�. Ʈ�� �˰��� 90�ۼ�Ʈ
	//����Ȯ�� �� ����Ʈ��.
	//���ǥ����Ҷ�  ����Ž��, ����Ʈ���� ����� �˰���. �Ǻ���ġ �� ����Ž�� ����.
	//���� ����Ʈ���� ������ ������ �Ҽ� �ִ�. 
	//�˺�Ʈ�� .
	//vector<Tree::Node*> arr;
	////�Ϲ������� ����Ʈ���� ���̾���.
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
	////Tree::Addchild //�����ϸ� �ȵ��� static �ƴ��ݾ�

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
	
	cout << "������ �Է��Ͻÿ� : " ;
	cin >> exp;
	MakePostfix(post, exp);
	
	cout << "����ǥ���" << post << endl;
	Expression(post, &root);
	
	cout << "PostOrder"<< endl;
	BinaryTree::PostOrder(root); cout << endl;
	
	//Expression(postfix.c_str(), &root);

	cout<<"Result :" <<" " << Evaluate(root) << endl;


}