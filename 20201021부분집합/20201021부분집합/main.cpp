#include <iostream>
#include <algorithm>
using namespace std;

int check[15];
int cnt;

void dfs(int n) //n�� �ڸ���
{
	if (n > cnt) return;
	else if (n == cnt)
	{
		for (int i = 0; i < cnt; i++) {
			if (check[i] == 1) {
				cout << i+1 << " ";
			}
		};
		cout << endl;
	}
	else
	{
		check[n] = 1;
		dfs(n + 1);
		check[n] = 0;
		dfs(n + 1);
	}
}
int main()
{
	//���������� �߿伺
	//int cnt; //�������� �Ἥ ����� ����
	cin >> cnt;
	dfs(0);

}