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
			//L R Root�ϱ� ������ ���°ž�.
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
	BinaryTree::Node* root = nullptr;
	Expression(postfix.c_str(), &root);
	cout << Evaluate(root) << endl;


}