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
	
	cout << "선택하시오 1~3" << endl;
	cout << "1: 추가 2: elo비교 3: 종료" ;
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
		cout << "선택하시오 1~3" << endl;
		cout << "1: 추가 2: elo비교 3: 종료" << endl;
		cin >> testCases;
		if (testCases == 1)
		{	
			
			Data temp;
			cout << "캐릭터이름" << endl;
			cin >> temp.name;
			cout << "캐릭터레벨" << endl;
			cin >> temp.level;
			cout<<"캐릭터 elo : "<<endl;
			cin >> temp.elo;
			temp.sum = temp.level + temp.elo;
			dl.Push_Back(temp);
			
		}
		else if (testCases == 2)
		{
			//배열선언
			
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
				//비교 후 배열에 넣기.
				//출력
			dl.PrintList();
		}
		else if (testCases == 3) return 0;
		else cout << "잘못 입력하였습니다. 다시 입력하세요(1~3)" << endl;
	}

}