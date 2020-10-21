#include <iostream>
using namespace std;
int arr[15];
int check[15];
int cnt;
bool ans;
int answer;
int answer_cnt;
void dfs(int n)//int n
{
	if (n > cnt)return;
	else if (n == cnt) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < cnt; i++) {
			if (check[i] == 1) {
				sum1 += arr[i];
			}
			else if (check[i] == 0) {
				sum1 -= arr[i];
			}
			else {
				continue;
			}
		}
		if (sum1 == answer)
		{
			ans = true;
			answer_cnt++;
		}
		else {
			sum1 = 0;
		}
	}
	else {
		check[n] = 1;
		dfs(n + 1);
		check[n] = 0;
		dfs(n + 1);
		check[n] = 2;
		dfs(n + 1);
	}
}

int main()
{
	cin >> cnt>>answer;
	for (int i = 0; i < cnt; i++) {
		cin >> arr[i];
	}
	dfs(0);
	if (ans == true)cout << answer_cnt;
	else cout << "-1";
}