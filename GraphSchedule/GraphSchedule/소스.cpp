#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//위상 정렬

int check[110][110];
int graphSchedule[110]; //누굴 먼저 뽑아야하는가.
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
		for (int i = 1; i <= nodeCnt; i++) //중요한건 이렇게 괄호치고한다.
		{
			if (check[now][i]) { // 해야한다. 이어졌을때만 할때만 검사. 이어진것부터 한다. 
				graphSchedule[i]--;
				if (graphSchedule[i] == 0) arr.push(i);
			}
		}
	}

}