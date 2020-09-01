#include <iostream>
#include <cstring>
using namespace std;

int answer[1000];
//연속된 자연수의 합
int main()
{
	int n;
	cin >> n;
	int nt = n;
	int cnt = 0;
	for (int i = 2; i < n ; i++)
	{
		nt = n;
		int temp = i * (i + 1) / 2;
		nt -= temp;
			
		if (nt % i == 0 && nt >= 0)
		{
			int k = nt / i;
			for (int j = 1; j <= i; j++)
			{
				answer[j] = j + k;
			}
			cnt++;

			for (int w = 1; w <= i; w++)
			{
				if (answer[w] > 0 && w < i)
				{
					cout << answer[w] << " + ";
				}
				else 
				{	if(w == i)
						cout << answer[w]; 
						
				}
			}cout << " = " << n << endl;
		}
		else continue;

		memset(answer, 0, sizeof(answer));
	}
	cout << cnt <<endl ;	
}