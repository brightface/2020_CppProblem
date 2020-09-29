#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	queue<pair<int, int>> que;//temp
	priority_queue<int> pq;
	for (int i = 0; i < priorities.size(); i++) {
		que.push(make_pair(i, priorities[i]));
		pq.push(priorities[i]);
	}
	//���� ���� �����Ѵ�.
	while (!que.empty())
	{
		int i = que.front().first;
		int priority = que.front().second;
		que.pop();
		//�̰� ������ �ű��ϴ�.
		//que�� �̻��� �켱���� �ϋ� �μ⸦ �ϱ� ���� ����. ���� �̸��̶�� �ٽ� �ǳ����� �ִ´�. (ť ����)
		if (priority == pq.top()) { 
			pq.pop();
			answer++;
			if (location == i) break;
			//else { //�̷����� ���� ����. 
			//	que.push(make_pair(i, priority));
			//}
		}
		else { //�μ⸦ ���Ѵ�. �ٵ� �̰� �켱���� ť������ ������ �ʴ´�. �׳� ť������ ������ �ڷΰ���.
			que.push(make_pair(i, priority));
			/*answer++;*/ //�μ⸦ ���ϰ� ť������ �ٽ� �ִ´�.
		}
		return answer;
	}
}