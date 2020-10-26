#pragma once
#include <vector>
#define INF 100000
using namespace std;
typedef pair<int, int> PII;
class mincost
{
public:
	mincost(int nodeCount)
		:nodeCount(nodeCount)
	{
		ad.assign(nodeCount,vector<int>());
		dist.assign(nodeCount, INF);
	}
	//6���� ������Ѵ�. �� ���;ȿ� ��� �ִ� �ε����� ���������̴�.
	void addEdge(int start, int weight) 
	{
		ad[start].push_back(weight);
	}
	int getSmallIndex()
	{
		int minDist = INF;
		int index = 0;
		for (int i = 0; i < nodeCount; i++)
		{
			if (dist[i] < minDist && selected[i] == false)
			{
				minDist = dist[i];
				index = i;
			}
		}
		return index;
	}//�ѹ����İ��� �˰���.
	void FindPath(int start)
	{	//���������� ������ ���� �ּҺ���� ���ϴ� �˰��� - ���ͽ�Ʈ��.
		//dist �迭�� �����Ѵ�.
		//������ �� ��� �� ���鼭 ����ġ �����ϴ°�. ��ŸƮ�� �߿��ϴ�.
		for (int i = 0; i < nodeCount; i++)
		{
			dist[i] = ad[start][i];
		}
		selected[start] = true;
		for (int i = 0; i < nodeCount - 2; i++) 
		{
			dist[i] = 
		}
	}


private:
	vector<bool> selected;
	vector<vector<int>> ad;
	int nodeCount;
	vector<int> dist;
};