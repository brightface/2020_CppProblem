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

	//�׻� dy�� ������ ���´�.
	//dy�� �� ĭ������ �ִ� ������ �Ÿ���. 
	for (int i = 2; i <= n; i++)
	{
		int max = 0;
		//�ڷ� ����. �ǽð����� ��� ������
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