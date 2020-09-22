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
        //����, ����, ����
        //node - left - right
        for (int i = 0; i < level; i++)
            cout << "-";

        cout << node->data << endl;

        if (node->leftChild != nullptr)
            PrintNode(node->leftChild, level + 1);

        if (node->rightSibling != nullptr)
            PrintNode(node->rightSibling, level);
    }

    //����� ����. ��������� �Ҷ� �´�. 
    //����Լ� ���� static �� �����ؾߵ�. �����ؾߵȴ�. ����ƽ : ����޸�. ũ�Ⱑ ���� �۴�. ���ظ޸𸮳� ���޸𸮳��� ���ؼ�
    //�޸� ������ ���� �Ͼ��. static �Լ������� ��͸� ��Ÿ�°� ����.
    //���������� ������ ��������. ����������������.
    //�̰� ���α׷� ������ ����������.
    static void GetNode(Node* root, char data)
    {
        if (root->data == data)
        {
            //arr.push_back(root);
            cout << "�������� �ּ�"<< root<<":";
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