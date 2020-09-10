#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n + 1), dy(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	//int max = 0;
	int ans = 0;
	dy[1] = 1;
	//dynamic programming

	//항상 dy를 정의해 놓는다.
	//dy란 그 칸까지의 최대 수열인 거리다. 
	for (int i = 2; i <= n; i++)
	{
		int max = 0;
		//뒤로 간다. 실시간으로 잡기 때문에
		for (int j = i-1; j >=1 ; j--)
		{	
			if (arr[i] > arr[j] && dy[j] > max)
			{
				max = dy[j];
			}
		}
		dy[i] = max + 1;
		if (ans < dy[i]) ans = dy[i];

	}
	cout << ans;
	
}