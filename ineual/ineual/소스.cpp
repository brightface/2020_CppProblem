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
		//�ٳ��������� �Ѿ�°� �ƴ϶�
		//������ �ϸ鼭 �Ѿ�±���.- ������ �ϸ鼭 �ϴ°� ��¥ ��� �̱� �ѵ� .
		//�� ���������� �� �Ҽ��� ����
		//���� �ְ� �񱳸� �ؾ� �ϱ� ������ ���� �ְ� ��� �����ǵ�??? ���־� �ù� ������ 
		// �ְ� ���ϰ� �ְ� ���ϰ� �̷��� ���ߵ� ��͸� �� ���������� ����. �˰����� �ٸ���. �˰����� x?
		//�ϰ� �ڵ�ó�� �Ӳ����� �������� �Ѿ�°ͺ��� �ְ� �� �ϰ� ó�������ΰ� ����.


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