#pragma once

/*
��ã�� �˰���

���ͽ�Ʈ�� �˰���

���� ����ġ�� ���� �׷������� �� ��忡�� �ٸ� ��� �������� �C���Ÿ��� ���ϴ� �˰���
(���Ǽ���)

���� ���� �˰��� <- ���� ����ġ�� �ִ� �׷������� �ִܰ�θ� ã�� �˰���
�������� ����  A* ����. �ٵ� �׺���̼� �޽� ����.
����� �ִ�. �׺���̼� �޽�
 ������ ���θ� �غ��� 
 ��ã�� �˰����� Ŭ����

 �׷����̷п��� ���������� �ִܰ�θ� ���ϴ°�.
 �׷������� ���������� �ִ� ��θ� ���ϴ� ������ ����
 1. �ϳ��� �������� �ٸ� �ϳ��� ���������� �ִܰ�θ� ���ϴ� ����.(single source and single destination shortest path problem) : ���̿켱
 2. �ϳ��� �������� �ٸ� ��� ���������� �ִܰ�θ� ���ϴ� ����. (single sorce shortest path problem) : ���� �켱 Ž�� <���ͽ�Ʈ��> : 
 3. A* �ű⿡�� �������� ���� �Ÿ��� ����Ѵ�.
 3. �ϳ��� �������� ���� ��� �ִ� ��θ� ���ϴ� ����(single destination path problem) : ���̿켱 Ȯ��. ���̹� ����. ���� �Ǵ� ���
 4. ��� �ִܰ�θ� ���ϴ� ����. ��� ���̽��� �� �˻�(All pairs shortest path problem)

 ��θ� ã�´�. ���ͽ�Ʈ��� �������� �ִ�.

 ���ͽ�Ʈ�� ����
 ù ������ �������� ����Ǿ� �ִ� �������� �߰��� ���� �ִܰŸ��� �����ϴ� ���.
 ������ �����ϱ� �������� �������� ������ ����(�ű���� ���µ� ��� ���)���� ��� ���Ѵ� ���� ������.

 ���� A���� ����B�� �̾�����, ����B�� ������ �ִܰŸ��� ���������� ���� ���� A������ �ִܰŸ� + ����A, ����B������ ����ġ��, ������ ������ �ִ�
 ���� B�� �ִܰŸ��� �������� B�� �ִܰŸ��� �ȴ�.
 B������ ���� ��� �����̵ȴ�.
*/

#include <vector>
using namespace std;

typedef pair<int, int> PII;


#define INF 1000000

class Dijkstra
{
public:
	//��� ����
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
	//������ �湮�� ��带 �����ϴ°ž�. �ܼ��� 2���� �迭�����̱� ������ �ε�����ȣ ����ȣ�� �������� ��ȯ�� �����ž�.
	//�켱����ť
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
						//��Ʈ �ƽ��� ���ϰ� ���Ÿ� �Ѱž�.
						dist[j] = dist[current] + ad[current][j];

					}
				}
			}
		}
	}


private:
	vector<vector<int>> ad; //������ ������ ������ �ִ� �迭
	vector<bool> selected; //�湮�ߴ� ������� �ƴ���
	vector<int> dist; //���� ����ξ��� �迭
	int nodeCount = 0;
};

#include <queue>
typedef pair<int, int> PII;
class Dijkstra2
{
public:
	Dijkstra2(int nodeCount) :nodeCount(nodeCount)
	{
		ad.assign(nodeCount, vector<PII>()); //�������� �Ҵ��Ѵ�. �󸶸�ŭ, 
		dist.assign(nodeCount, INF);
	}
	void MakeEdge(int N, int next, int weight)
	{
		ad[N].push_back(make_pair(next , weight));
	}
	//����ġ�� �Ἥ �����Ϸ��� 
	//��������Ʈ A* �پ��ִ� �ֵ鸸 ����Ѵ�.
	//�Ⱥپ��ִ¾ֵ� ����غ��� �ǹ̰� ����.

	void FindPath(int start)
	{
		dist[start] = 0;
		pq.push(PII(0, start));
		//���� �����ִ°͸� ���� �Ǵϱ�. Ž���ӵ��� ������. 
		//A* �˰��� ��ã�� �˰��� �� �˾ƾ߰ڴ�.
		while (pq.empty() == false)
		{
			int current = pq.top().second;
			int distance = pq.top().first;
			pq.pop();

			if (dist[current] < distance) continue;

			for (int i = 0; i < nodeCount; i++)
			{
				int next = ad[current][i].second;
				if (next == current) continue; // ���� ���� �Ѿ��.
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
	priority_queue<PII, vector<PII>, greater<PII>> pq; //������ ����� ���� �������� ã������ �켱����ť
	vector<int> dist;
	int nodeCount = 0;
	vector<int> parent; //������غ�. �׸��� ��뵵 �����!
};