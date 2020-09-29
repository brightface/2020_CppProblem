#pragma once
//binary search tree
#include <iostream>
#include <algorithm>
using namespace std;

/*
	이진 탐색 트리 : 시간복잡도 logN
	탐색에 관점이 있다.
	4가지 요건이 있는데 
	1). 첫번째 조건
	데이터 가 있겠지 = 키값. 모든 노드들에 있을거야. 중복되는 값이 없다. 유일하다. 첫번째 조건. 추가 안되도록 해줄거야.
	2). 왼쪽 서브트리의 모든 키값들은 루트의 키 값보다 작다.
	3). 오른쪽에 있는 서브트리의 키값은 루트의 있는값보다 크다.
			20
		x			32				//x는 10~14까지
	9	  15	t		45       //t는 21~31까지
							r    //r이 제일 큰값.
	4). 서브트리도 다 이진탐색트리이다.
		
*/
class BST
{
public:
	struct Node
	{
		int key;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	static Node* CreateStatic(int key)
	{
		Node* node = new Node();
		node->key = key;
		return node;
	}
	Node* Create(int key)
	{
		Node* node = new Node();
		node->key = key;
		return node;
	}

	static void Delete(Node** node)
	{
		delete(*node); //공간지우기
		*node = nullptr; //포인터지우기
	}

	static Node* SearchIteration(Node* node, int key)
	{
		//노드가 몇개인지 모르잖아. 그래서 while문
		while (node != nullptr)
		{
			if (node->key == key) return node;
			else if(key<node ->key){
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
		return nullptr;//재귀할필요없이 이렇게 순회를 통해 할수 있다.
	}

	/*static Node* SearchRecurrsive(Node* node, int key)
	{
		if (node->key == key) return node;
		else if (node->key > key) SearchRecurrsive(node->left, key);
		else  SearchRecurrsive(node->right, key);
		
		return nullptr;
		
	}*/

	static Node* SearchRecurrsive2(Node* node, int key)
	{
		if (node->key == key) return node;
		else if (node->key > key) SearchRecurrsive2(node->left, key);
		else  SearchRecurrsive2(node->right, key);

		return nullptr;

	}


	//재귀타는게 아니다. static으로 해도 된다.
	void InsertNode(Node** root, int key)
	{
		Node* parent = nullptr;
		Node* current = nullptr;
		Node* newNode = Create(key);
	
		current = *root;
		while (current != nullptr)
		{
			if (key == current->key) return;
			parent = current;
			if (key < parent->key) current = parent->left;
			else current = parent->right;
		}

		if (parent != nullptr)
		{
			//root면 널포인트 따로처리
			if (key < parent->key)
				parent->left = newNode;
			else parent->right = newNode;
		}
		else *root = newNode;
	}

	int GetNodeCount(Node* node)
	{
		int count = 0;
		if (node != nullptr)
			count = 1 + GetNodeCount(node->left) + GetNodeCount(node->right);
		return count;
	}

	int GetHeight(Node* node)
	{
		int height = 0;
		if (node != nullptr)
		{
			//재귀를 타가지고 둘중 높은값을 선택.
			height = 1 + max(GetHeight(node->left), GetHeight(node->right));
		}
		return height;
	}

	//내림차순 LRootR 반대로 호출
	void InOrder(Node* node,int depth)
	{
		if (node == nullptr) return;
		else
		{
			InOrder(node->left, depth);
			for (int i = 0; i < depth; i++) cout << "-";
			cout << node->key << " " << endl;
			InOrder(node->right, depth);
		}
	}

	//지우기 함수.
	void DeleteNode(Node** root, int key)
	{
		Node* parent = nullptr;
		Node* current = nullptr;
		Node* child = nullptr;
		Node* prev = nullptr;
		Node* next = nullptr;


		current = *root;
		while (current->key != key && current != nullptr)
		{
			parent = current;
			current = (key < parent->key) ? parent->left : parent->right;
		}
		if (current == nullptr) { cout << "해당 키값을 가진 노드가 존재하지 않는다." << endl; return; }

		//서브트리 둘다 없으면
		if (current->left == nullptr && current->right == nullptr)
		{
			if (parent != nullptr)
			{
				if (parent->left == current) parent->left = nullptr;
				else parent->right = nullptr;
			}
			else *root = nullptr;
		}

		//서브트리 하나있을때
		else if ((current->left == nullptr) || (current->right = nullptr))
		{
			child = current->left != nullptr ? current->left : current->right;
			if (parent != nullptr)
			{
				if (parent->left == current) parent->left = child;
				else parent->right = child;
			}
			else *root = child;

		}
		//트리 2개 있을때.
		else
		{
			prev = current;
			next = current->right;

			while (next->left != nullptr)
			{
				prev = next;
				next = next->left;
			}

			if (prev->left == next) prev->left = next->right;
			else prev->right = next->right;
			//제일 작은값을 넣으면 되지 키값을.
			current->key = next->key;
			//next가 가장작은값.
			current = next; //이렇게 넣고 지운다.
		}


		
		Delete(&current);
	}

};
