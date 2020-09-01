#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100010];
int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//욕심쟁이 기법
	sort(arr, arr + n);
	
	
	//가장 강한 로프 1개만 쓰는것 약한것 추가
	int result = arr[0];
	for (int i = 1; i <= n; i++) {
		result = max(result, arr[n-i]*i);
	}
	cout << result;
}