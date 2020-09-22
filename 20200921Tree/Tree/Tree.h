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
		//자식이 이미 있는지 없는지
		if (parent->leftChild == nullptr)
			parent->leftChild = child; //장남이 첫번재 자식이다.
		else
		{
			//자식이 있어 그러면 //자식이 있다는 소리는 leftchild가 있다는 소리야.
			//개족보 되잖아.
			Node* node = parent->leftChild; //장남을 찾고
			//막내를 찾는다
			//null포인터가 아닐떄까지 막내를 찾는다
			while (node->rightSibling != nullptr)
			{
				node = node->rightSibling;
			}

			//node->leftChild = node; 이게 왜 아닌가 부모가 내가 아니다 . 부모아들에다가 붙여야지
			node->rightSibling = child;
			
		}
	}
	void PrintNode(Node* node, int level)
	{
		//전위, 중위, 후위
		//node - left - right
		//작대기 몇개나 끄을건지. level
		//중위
		for (int i = 0; i < level; i++)
		{
			cout << "-";
		}
		cout << node->data << endl;

		if (node->leftChild != nullptr)
			PrintNode(node->leftChild, level + 1);
		if (node->rightSibling != nullptr)
			PrintNode(node->rightSibling, level);
	//L R D 후위 , L D R 전위
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
//이방식으로 출력할거야.
레벨 1
Root 
 - A
 - - C
 - - E F
 - - D 
 - B

 중첩괄호
 노드가 시작되면 괄호를 연다.
  ( Root ( A ( C ( E ) (F) ) 
  //컴퓨터가 알아듣기 쉬운방식
	//사람은 어려워
	//직접 쓰는 생각은 좋은생각이 아니다.

	
*/

#pragma once
