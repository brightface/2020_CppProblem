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
	//������� ���
	sort(arr, arr + n);
	
	
	//���� ���� ���� 1���� ���°� ���Ѱ� �߰�
	int result = arr[0];
	for (int i = 1; i <= n; i++) {
		result = max(result, arr[n-i]*i);
	}
	cout << result;
}