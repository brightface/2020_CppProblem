#pragma once

/*
길찾는 알고리즘

다익스트라 알고리즘

음의 가중치가 없는 그래프에서 한 노드에서 다른 모든 노드까지의 쵣나거리를 구하는 알고리즘
(현실세계)

벨만 포드 알고리즘 <- 음의 가중치가 있는 그래프에서 최단경로를 찾는 알고리즘
현업에서 쓰는  A* 쓴다. 근데 네비게이션 메시 쓴다.
헤더도 있다. 네비게이션 메시
 스스로 공부를 해보고 
 길찾기 알고리즘의 클래식

 그래프이론에서 정점끼리의 최단경로를 구하는것.
 그래프에서 정점끼리의 최단 경로를 구하는 문제의 종류
 1. 하나의 정점에서 다른 하나의 정점까지의 최단경로를 구하는 문제.(single source and single destination shortest path problem) : 깊이우선
 2. 하나의 정점에서 다른 모든 정점까지의 최단경로를 구하는 문제. (single sorce shortest path problem) : 넓이 우선 탐색 <다익스트라> : 
 3. A* 거기에서 다음까지 가는 거리를 계산한다.
 3. 하나의 목적지로 가는 모든 최단 경로를 구하는 문제(single destination path problem) : 깊이우선 확장. 네이버 지도. 말이 되는 경로
 4. 모든 최단경로를 구하는 문제. 모든 케이스를 다 검사(All pairs shortest path problem)

 경로를 찾는다. 다익스트라는 시작점이 있다.

 다익스트라 로직
 첫 정점을 기준으로 연결되어 있는 정점들을 추가해 가며 최단거리를 갱신하는 방식.
 정점을 연결하기 전까지는 시작점을 제외한 정점(거기까지 가는데 드는 비용)들은 모두 무한대 값을 가진다.

 정점 A에서 정점B로 이어지면, 정점B가 가지는 최단거리는 시작점으로 부터 정점 A까지의 최단거리 + 정점A, 정점B간선의 가중치와, 기존에 가지고 있던
 정점 B의 최단거리중 작은값이 B의 최단거리가 된다.
 B까지의 값이 계속 갱신이된다.
*/

#include <vector>
using namespace std;

typedef pair<int, int> PII;


#define INF 1000000

class Dijkstra
{
public:
	//노드 개수
	Dijkstra(int nodeCount) : nodeCount(nodeCount)
	{
		ad.assign(nodeCount, vector<int>());
		selected.assign(nodeCount, false);
		dist.assign(nodeCount, INF);

	}

	void MakeEdge(int start, int weight) 
	{
		ad[start].push_back(weight);
	}
	//다음에 방문할 노드를 선택하는거야. 단순한 2차원 배열형식이기 때문에 인덱스번호 노드번호가 적은것을 반환을 받을거야.
	//우선순위큐
	int GetSmallIndex()
	{
		int minDist = INF;
		int index = 0;
		for (int i = 0; i < nodeCount; i++) {
			if (dist[i] < minDist && selected[i] == false)
			{
				minDist = dist[i];
				index = i;
			}
		}
		return index;
	}
	void FindPath(int start)
	{
		for (int i = 0; i < nodeCount; i++)
		{
			dist[i] = ad[start][i];
		}
		selected[start] = true;
		for (int i = 0; i < nodeCount - 2; i++)
		{
			int current = GetSmallIndex();
			selected[current] = true;
			for (int j = 0; j < nodeCount; j++) {
				if (selected[j] == false)
				{
					if (dist[current] + ad[current][j] < dist[j]) 
					{
						//dist[j] = INT32_MAX
						//dist[current]
						//ad[current][j] = INT32_MAX 
						//인트 맥스를 안하고 저거를 한거야.
						dist[j] = dist[current] + ad[current][j];

					}
				}
			}
		}
	}


private:
	vector<vector<int>> ad; //간선의 정보를 가지고 있는 배열
	vector<bool> selected; //방문했던 노드인지 아닌지
	vector<int> dist; //옆에 적어두었던 배열
	int nodeCount = 0;
};

#include <queue>
typedef pair<int, int> PII;
class Dijkstra2
{
public:
	Dijkstra2(int nodeCount) :nodeCount(nodeCount)
	{
		ad.assign(nodeCount, vector<PII>()); //공간만을 할당한다. 얼마만큼, 
		dist.assign(nodeCount, INF);
	}
	void MakeEdge(int N, int next, int weight)
	{
		ad[N].push_back(make_pair(next , weight));
	}
	//가중치를 써서 정렬하려고 
	//인접리스트 A* 붙어있는 애들만 계산한다.
	//안붙어있는애들 계산해봐야 의미가 없다.

	void FindPath(int start)
	{
		dist[start] = 0;
		pq.push(PII(0, start));
		//가장 위에있는것만 빼면 되니까. 탐색속도가 빠르다. 
		//A* 알고리즘도 길찾기 알고리즘 잘 알아야겠다.
		while (pq.empty() == false)
		{
			int current = pq.top().second;
			int distance = pq.top().first;
			pq.pop();

			if (dist[current] < distance) continue;

			for (int i = 0; i < nodeCount; i++)
			{
				int next = ad[current][i].second;
				if (next == current) continue; // 현재 노드면 넘어간다.
					int nextDist = distance + ad[current][i].first;
					if (nextDist < dist[next])
					{
						dist[next] = nextDist;
						pq.push(PII(nextDist, next));
						parent.push_back(current);
					}
			}
		}
	}
private:
	vector<vector<PII>> ad;
	priority_queue<PII, vector<PII>, greater<PII>> pq; //간선중 비용이 가장 작은것을 찾기위한 우선순위큐
	vector<int> dist;
	int nodeCount = 0;
	vector<int> parent; //출력잘해봐. 그리고 비용도 출력해!
};