#include "DLinked.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

typedef struct Data 
{
	string name;
	int level;
	int elo;
	int sum;
}Data;

int main()
{
	/*map<int, DoubleLinkedList<int>> king;
	
	cout << "�����Ͻÿ� 1~3" << endl;
	cout << "1: �߰� 2: elo�� 3: ����" ;
	int testCases;
	cin >> testCases;
	while (testCases != 3)
	{
		if (testCases == 1)
		{
			DoubleLinkedList<int> dl;
			int level, int elo;
			string k;
			cin >> k>>level>>elo;
			dl.Push_Back(level);
			dl.Push_Back(elo);
			king.insert(make_pair(k, dl));

		}
		else if (testCases == 2)
		{
			king
		}
		else if (testCases == 3)
			break;
	}
   */
	///////////////////////////////////////////////////


	
	int testCases=0;

	cout << endl;
	
	DoubleLinkedList<Data> dl;
	
	while (testCases != 3)
	{
		cout << "�����Ͻÿ� 1~3" << endl;
		cout << "1: �߰� 2: elo�� 3: ����" << endl;
		cin >> testCases;
		if (testCases == 1)
		{	
			
			Data temp;
			cout << "ĳ�����̸�" << endl;
			cin >> temp.name;
			cout << "ĳ���ͷ���" << endl;
			cin >> temp.level;
			cout<<"ĳ���� elo : "<<endl;
			cin >> temp.elo;
			temp.sum = temp.level + temp.elo;
			dl.Push_Back(temp);
			
		}
		else if (testCases == 2)
		{
			//�迭����
			
			//Data print[1000];
			//int cnt = 0;
			int tmp= dl[0]->data.elo;
			int tlevel = dl[0]->data.level;
			string tname = dl[0]->data.name;
			for (int i = 0; i < dl.Size(); i++)
			{
				for (int j = 0; j < dl.Size(); j++)
				{
					if (i == j) continue;
					else if (dl[i]->data.elo < dl[j]->data.elo)
					{
						tmp = dl[j]->data.elo;
						dl[j]->data.elo = dl[i]->data.elo;
						dl[i]->data.elo = tmp;

						tlevel = dl[j]->data.level;
						dl[j]->data.level = dl[i]->data.level;
						dl[i]->data.level= tlevel;

						tname= dl[j]->data.name;
						dl[j]->data.name = dl[i]->data.name;
						dl[i]->data.name = tname;
					}
				}
			}
				//�� �� �迭�� �ֱ�.
				//���
			dl.PrintList();
		}
		else if (testCases == 3) return 0;
		else cout << "�߸� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���(1~3)" << endl;
	}

}