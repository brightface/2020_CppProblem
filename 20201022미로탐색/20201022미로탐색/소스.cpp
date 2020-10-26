#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int map[10][10];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int check[10][10];
int cnt;
typedef pair<int, int> PII;
vector<pair<int, int>> path;
void dfs(int y,int x) {
	
	
	if (y == 6 && x == 6) {
		cnt++;
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i].first << " " << path[i].second << endl;
		}cout << endl;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (check[ny][nx] == 0 && map[ny][nx] == 0 && ny >= 0 && ny < 7 && nx >= 0 && nx < 7)
		{
			check[ny][nx] = 1;
			path.push_back(make_pair(ny, nx));
			dfs(ny, nx);
			check[ny][nx] = 0;
			path.pop_back();
		}
	}
}

int main()
{
	pair<int, int> p;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cin >> map[i][j];
		}
	}
	check[0][0] = 1;
	path.push_back(make_pair(0, 0));
	dfs(0, 0);
	cout << cnt;
}
