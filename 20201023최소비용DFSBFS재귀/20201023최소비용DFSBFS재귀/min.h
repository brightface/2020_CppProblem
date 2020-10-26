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
	//6번을 해줘야한다. 그 벡터안에 들어 있는 인덱스가 도착지점이다.
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
	}//한번거쳐가는 알고리즘.
	void FindPath(int start)
	{	//한정점에서 모든노드로 가는 최소비용을 구하는 알고리즘 - 다익스트라.
		//dist 배열로 연산한다.
		//로직은 각 노드 다 돌면서 가중치 연산하는것. 스타트가 중요하다.
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