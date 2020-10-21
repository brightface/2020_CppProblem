#include <iostream>
using namespace std;

int ch[11];
int cnt;

void dfs(int n)
{
	if (n > cnt) return;
	else if (n == cnt)
	{
		for (int i = 1; i <= cnt; i++)
		{
			if (ch[i] == 1) cout << i;
		}
		cout << endl;
	}
	else {
		ch[n] = 1;
		dfs(n + 1);
		ch[n] = 0;
		dfs(n + 1);
	}
}
int main() {
	cin >> cnt;
	dfs(1);
}