#include "BST.h"
#include <time.h>
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{	
	srand((UINT)time(NULL));

	BST bst;
	BST::Node* root = nullptr;
	for (UINT i= 0; i < 20; i++)
	{
		bst.InsertNode(&root, rand());
	}
	BST::Node* result = BST::SearchIteration(root, 30000);
	//BST::Node* result2 = BST::SearchRecurrsive(
	if (result) cout << result->key << endl;
	else cout << "없음" << endl;
	/*cout << BST::SearchIteration(root, 30000)->key << endl;*/

	cout << "완료" << endl;
	cout << bst.GetNodeCount(root) << endl;
	cout << bst.GetHeight(root) << endl;

	bst.DeleteNode(&root, 13);
	bst.InOrder(root, 0);

	bst.InOrder(root,bst.GetHeight(root));

	//BST::Node* A = BST::CreateStatic('A');
	//BST::Node* B = BST::CreateStatic('B');
	//BST::Node* C = BST::CreateStatic('C');
	//BST::Node* D = BST::CreateStatic('D');
	//BST::Node* E = BST::CreateStatic('E');
	//BST::Node* F = BST::CreateStatic('F');
	//BST::Node* G = BST::CreateStatic('G');
	//BST::Node* H = BST::CreateStatic('H');
	//BST::Node* I = BST::CreateStatic('I');
	//BST::Node* J = BST::CreateStatic('J');
	////
	//F->left = E;
	//F->right = G;
	//cout<<BST::SearchRecurrsive2(F, 'a');

	////	
	//D->left = B;
	//D->right = F;
	
	



	return 0;
}