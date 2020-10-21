#include <iostream>
using namespace std;
int arr[15];
int check[15];
int cnt;
bool ans;
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
		}
		if (sum1 == sum2) 
			ans = true;
		else {
			sum1 = 0;
			sum2 = 0;
		}
	}
	else {
		check[n] = 1;
		dfs(n + 1);
		check[n] = 0;
		dfs(n + 1);
	}
}

int main()
{
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> arr[i];
	}
	dfs(0);
	if (ans == true)cout << "YES";
	else cout << "NO";
}