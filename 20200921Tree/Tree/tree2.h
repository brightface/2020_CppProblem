#pragma once

#include <iostream>
#include <vector>
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

public:
    void AddChild(Node* parent, Node* child)
    {
        if (parent->leftChild == nullptr)
            parent->leftChild = child;
        else
        {
            Node* node = parent->leftChild;
            while (node->rightSibling != nullptr)
                node = node->rightSibling;
            node->rightSibling = child;
        }
    }

    void PrintNode(Node* node, int level)
    {
        //전위, 중위, 후위
        //node - left - right
        for (int i = 0; i < level; i++)
            cout << "-";

        cout << node->data << endl;

        if (node->leftChild != nullptr)
            PrintNode(node->leftChild, level + 1);

        if (node->rightSibling != nullptr)
            PrintNode(node->rightSibling, level);
    }

    //멤버가 없어. 멤버변수를 할때 맞다. 
    //재귀함수 쓸때 static 잘 생각해야돼. 선언해야된다. 스테틱 : 공용메모리. 크기가 많이 작다. 스텍메모리나 힙메모리나에 비해서
    //메모리 소진이 빨리 일어난다. static 함수가지고 재귀를 안타는게 좋아.
    //스택프레임 끝나면 없어진다. 지역변수같은경우는.
    //이건 프로그램 끝나야 ㅇ벗어진다.
    static void GetNode(Node* root, char data)
    {
        if (root->data == data)
        {
            //arr.push_back(root);
            cout << "데이터의 주소"<< root<<":";
            cout << root->data;
            cout << endl;
        }
        if (root->leftChild != nullptr)
                GetNode(root->leftChild, data);
             
        if (root->rightSibling != nullptr)
                GetNode(root->rightSibling, data);
    }

public:
    vector<Node> arr;
};