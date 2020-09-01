#include <stdio.h>
#include <cstring>
using namespace std;

int getPrintMax;
int getPrintMin;

int check[100];
int resultM[100];
int resultm[100];
char arr[100];
int n;
void getMax(int index)
{
	if (getPrintMax) return;
	if (index > n) {
		for (int i = 0; i < n; i++) {
			printf("%d", arr[i]);
		}
		getPrintMax = 1;
	}
	else {
		int flag = 0;
		for (int i = 0; i < index; i++) {
			if (check[i] == 0) {
				if (arr[i] == '>') {
					if (resultM[i] > resultM[i + 1]) flag = 1;
				}

				else if (arr[i] == '<') {
					if (resultM[i] < resultM[i + 1]) flag = 1;
				}
			}
		}
		//다끝낸다음에 넘어가는게 아니라
		//과정을 하면서 넘어가는구나.- 과정을 하면서 하는게 진짜 재귀 이긴 한데 .
		//다 끝낸다음에 비교 할수가 없어
		//먼저 넣고 비교를 해야 하기 때문에 먼저 넣고 어떻게 넣을건데??? 못넣어 시발 새끼야 
		// 넣고 비교하고 넣고 비교하고 이렇게 가야돼 재귀를 다 끝낸다음에 못해. 알고리즘은 다르다. 알고리즘은 x?
		//일과 코딩처럼 머끄내고 다음으로 넘어가는것보다 넣고 비교 하고 처리과정인것 같다.


		if (flag)
		{
			for (int i = 9; i >= 0; i--)
			{
				check[index] = 1;
				resultM[index] = i;
				getMax(index + 1);
				check[index] = 0;
				resultM[index] = 0;
			}
		}
	}

}
void getMin(int index)
{

}
int main() {

	scanf("%d", &n);
	scanf("%s", arr);
	resultM[0] = 9;
	resultm[0] = 0;
	getMax(0);


	return 0;
}