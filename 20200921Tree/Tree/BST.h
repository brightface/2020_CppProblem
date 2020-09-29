#pragma once
//binary search tree
#include <iostream>
#include <algorithm>
using namespace std;

/*
	���� Ž�� Ʈ�� : �ð����⵵ logN
	Ž���� ������ �ִ�.
	4���� ����� �ִµ� 
	1). ù��° ����
	������ �� �ְ��� = Ű��. ��� ���鿡 �����ž�. �ߺ��Ǵ� ���� ����. �����ϴ�. ù��° ����. �߰� �ȵǵ��� ���ٰž�.
	2). ���� ����Ʈ���� ��� Ű������ ��Ʈ�� Ű ������ �۴�.
	3). �����ʿ� �ִ� ����Ʈ���� Ű���� ��Ʈ�� �ִ°����� ũ��.
			20
		x			32				//x�� 10~14����
	9	  15	t		45       //t�� 21~31����
							r    //r�� ���� ū��.
	4). ����Ʈ���� �� ����Ž��Ʈ���̴�.
		
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
		delete(*node); //���������
		*node = nullptr; //�����������
	}

	static Node* SearchIteration(Node* node, int key)
	{
		//��尡 ����� ���ݾ�. �׷��� while��
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
		return nullptr;//������ʿ���� �̷��� ��ȸ�� ���� �Ҽ� �ִ�.
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


	//���Ÿ�°� �ƴϴ�. static���� �ص� �ȴ�.
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
			//root�� ������Ʈ ����ó��
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
			//��͸� Ÿ������ ���� �������� ����.
			height = 1 + max(GetHeight(node->left), GetHeight(node->right));
		}
		return height;
	}

	//�������� LRootR �ݴ�� ȣ��
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

	//����� �Լ�.
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
		if (current == nullptr) { cout << "�ش� Ű���� ���� ��尡 �������� �ʴ´�." << endl; return; }

		//����Ʈ�� �Ѵ� ������
		if (current->left == nullptr && current->right == nullptr)
		{
			if (parent != nullptr)
			{
				if (parent->left == current) parent->left = nullptr;
				else parent->right = nullptr;
			}
			else *root = nullptr;
		}

		//����Ʈ�� �ϳ�������
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
		//Ʈ�� 2�� ������.
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
			//���� �������� ������ ���� Ű����.
			current->key = next->key;
			//next�� ����������.
			current = next; //�̷��� �ְ� �����.
		}


		
		Delete(&current);
	}

};
