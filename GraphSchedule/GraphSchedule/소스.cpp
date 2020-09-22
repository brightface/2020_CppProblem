#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//���� ����

int check[110][110];
int graphSchedule[110]; //���� ���� �̾ƾ��ϴ°�.
queue<int> arr;
int main()
{
	int nodeCnt=0;
	int roadCnt=0;
	
	cin >> nodeCnt >> roadCnt;
	for (int i = 1; i <= roadCnt; i++){
		int a, b;
		cin >> a >> b;
		check[a][b] = 1;
		graphSchedule[b]++;
	}
	for (int i = 1; i <= nodeCnt; i++) 
		if (graphSchedule[i] == 0) arr.push(i);

	while(!arr.empty()) {
		int now = arr.front();
		cout << now << " ";
		arr.pop(); 
		for (int i = 1; i <= nodeCnt; i++) //�߿��Ѱ� �̷��� ��ȣġ���Ѵ�.
		{
			if (check[now][i]) { // �ؾ��Ѵ�. �̾��������� �Ҷ��� �˻�. �̾����ͺ��� �Ѵ�. 
				graphSchedule[i]--;
				if (graphSchedule[i] == 0) arr.push(i);
			}
		}
	}

}