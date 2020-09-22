#pragma once

#include <iostream>
using namespace std;

class Tree
{
public:
	struct Node
	{
		char data;
		Node* leftChild = nullptr;
		Node* rightSibling = nullptr;
	};

	static Node* Create(char data)
	{
		Node* node = new Node();
		node->data = data;
		return node;
	}

	static void Delete(Node** node)
	{
		delete(*node);
		*node = nullptr;
	}

private:
	void AddChild(Node* parent, Node* child)
	{
		//�ڽ��� �̹� �ִ��� ������
		if (parent->leftChild == nullptr)
			parent->leftChild = child; //�峲�� ù���� �ڽ��̴�.
		else
		{
			//�ڽ��� �־� �׷��� //�ڽ��� �ִٴ� �Ҹ��� leftchild�� �ִٴ� �Ҹ���.
			//������ ���ݾ�.
			Node* node = parent->leftChild; //�峲�� ã��
			//������ ã�´�
			//null�����Ͱ� �ƴҋ����� ������ ã�´�
			while (node->rightSibling != nullptr)
			{
				node = node->rightSibling;
			}

			//node->leftChild = node; �̰� �� �ƴѰ� �θ� ���� �ƴϴ� . �θ�Ƶ鿡�ٰ� �ٿ�����
			node->rightSibling = child;
			
		}
	}
	void PrintNode(Node* node, int level)
	{
		//����, ����, ����
		//node - left - right
		//�۴�� ��� ��������. level
		//����
		for (int i = 0; i < level; i++)
		{
			cout << "-";
		}
		cout << node->data << endl;

		if (node->leftChild != nullptr)
			PrintNode(node->leftChild, level + 1);
		if (node->rightSibling != nullptr)
			PrintNode(node->rightSibling, level);
	//L R D ���� , L D R ����
	}

	Node* GetNode(Node* root, char data)
	{
		Node* node = nullptr;
		if (root->data == data)
			return root;
		else
		{
			if (root->leftChild != nullptr)
			{
				node = GetNode(root->leftChild, data);
			}
			if (node != nullptr)
				return node;
			if(root->rightSibling != nullptr)
			{
				node = GetNode(root->rightSibling, data);
			}
		}
		return nullptr;
	}
	
};
/*
//�̹������ ����Ұž�.
���� 1
Root 
 - A
 - - C
 - - E F
 - - D 
 - B

 ��ø��ȣ
 ��尡 ���۵Ǹ� ��ȣ�� ����.
  ( Root ( A ( C ( E ) (F) ) 
  //��ǻ�Ͱ� �˾Ƶ�� ������
	//����� �����
	//���� ���� ������ ���������� �ƴϴ�.

	
*/

#pragma once
