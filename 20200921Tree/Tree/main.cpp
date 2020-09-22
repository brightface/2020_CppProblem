#include "tree2.h"
#include "binaryTree.h"
#include <string>
int a;

void Expression(const char* postfix, BinaryTree::Node** node)
{
	char* str = const_cast<char*>(postfix);
	//"34*14+-"
	size_t length = strlen(str);
	
	char token = str[length - 1];
	str[length - 1] = '\0';

	switch (token)
	{
		case '+':
		case '-':
		case '/':
		case '*':
		case '%':
		{
			*node = BinaryTree::CreateNode(token);
			//L R Root니까 역으로 가는거야.
			Expression(postfix, &(*node)->right);
			Expression(postfix, &(*node)->left);
			break;
		}
		default:
		{
			*node = BinaryTree::CreateNode(token);
			break;
		}
	}
}

int Evaluate(BinaryTree::Node* node)
{
	if (node == nullptr) return 0;

	switch (node->data)
	{
		case '+':
		case '-':
		case '/':
		case '*':
		case '%':
		{
			int left = Evaluate(node->left);
			int right = Evaluate(node->right);
		
			switch (node->data)
			{
			case '+': return left + right;
			case '-': return left - right;
			case '/': return left / right;
			case '*': return left * right;
			case '%': return left % right;

			}break;
		}
		default:
		{
			char temp[4];
			memset(temp, 0, sizeof(temp));
			temp[0] = node->data;
			return atoi(temp);
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
	BinaryTree::Node* root = nullptr;
	Expression(postfix.c_str(), &root);
	cout << Evaluate(root) << endl;


}