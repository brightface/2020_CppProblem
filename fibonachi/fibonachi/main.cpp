#include <iostream>
int cnt1;
int cnt0;
using namespace std;

int fibonacci(int n)
{
	if (n == 0) {
		cnt0++;
		return 0;
	}
	else if (n == 1) {
		cnt1++;
		return 0;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main()
{
	int testCases;
	cin >> testCases;
	
	while (testCases--) {
		int n;
		cin >> n;
		fibonacci(n);
		cout << cnt0 << " " << cnt1;
		cout << endl;
		cnt0 = 0; cnt1 = 0;

	}
}