#define MAX 100
#define min(a,b) (a<b?a:b)
#include <iostream>
using namespace std;

//nCk 이항계수 - 재귀 알고리즘 - 2^n승 시간복잡도
int bin_1(int n, int k)
{
	if (k == 0 || k == n) return 1;
	else if (k > 0 || k < n)
		return bin_1(n - 1, k - 1) + bin_1(n - 1, k);
		
}
//nCk 동적계획법 -nk 시간복잡도
int bin_2(int n, int k)
{
	
	int B[MAX][MAX];
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i) B[i][j] = 1;
			else B[i][j] = B[i - 1][j-1] + B[i - 1][j];
		}
	}
	return B[n][k];
}
int main()
{	
	//cout << min(5, 3);
	cout<<bin_2(4, 2);
}