#include <iostream>
#include <algorithm>
using namespace std;

int nodeCount;
int edgeCount;


int check[15][15];
int pass[15];
int ans;
void dfs(int v)//n은 정점
{	
	if (v == nodeCount) {
		ans++;
	}
	else
	{
		for (int i = 1; i <= nodeCount; i++) {
			if (check[v][i] == 1) { //벡터 방법과 유사하다.
				if (pass[i] == 0)
				{
					pass[i] = 1;
					dfs(i);
					pass[i] = 0;
				}
			}

		}
	}
}


int main() {
	
	cin >> nodeCount >> edgeCount;
	//int** arr = new int*[edgeCount];
	//for (int i = 0; i < edgeCount; i++) {
	//	arr[i] = new int[edgeCount];
	//}
	//arr[1][0] = 1;

	//for (int i = 0; i<edgeCount; i++) {
	//	for (int j = 0; j < edgeCount; j++) {
	//		cout << arr[i][j];
	//	}cout << endl;
	//}
	for (int i = 0; i < edgeCount; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		int mx = -1;
		int mi = 999999;
		//방향그래프
		check[tmp1][tmp2] = 1;
		
		//mx = max(tmp1, tmp2);
		//mi = min(tmp1, tmp2);
		//check[mi][mx] = 1;
		//잘못된방법
		
		//양방향그래프 / 무방향 그래프
		/*check[tmp1][tmp2] = 1;
		check[tmp2][tmp1] = 1;*/
	}
	//check[1][1] = 1;
	pass[1] = 1;
	dfs(1);
	cout << ans;

}