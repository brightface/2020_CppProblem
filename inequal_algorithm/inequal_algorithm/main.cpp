#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int printMax;
int printMin;
char compare[100];
int result[100];
int check[100]; //� ���ڸ� �־����� Ȯ���ϴ� �迭 , �� ���ڸ� �־����� �ȳִ´�.
int n;

void getMax(int index) {
	if (printMax) return;
	if (index > n)
	{
		for (int i = 0; i <= n; i++) {
			printf("%d", result[i]);
		}printMax = 1;
	}
	else {
		
		//��� �������� ����. �׶��׶� �ְ� �� �ְ� ��
		//������� �� �־������. ������ ���ϱ� ������ CHECK�迭�� �ɾ� �ϳ��ϳ��� �� �ϴ°� ó�� �ذ��Ѵ�.
		//�˰����� �Ȱ���. �ٵ� �̰� �ξ� ���� ����̴�. �ϰ� �Ϸ��� �÷��� ������� continue �ѱ�� ����� �����ϴ� �ʹ� ... �̰� �´�. ��ʹ�
		//��ʹ� �ִ��� ������ ������� �����ؾ��Ѵ�.
		for (int i = 9; i >= 0; i--) 
		{
			int flag = 0;
			result[index] = i; //1)
			if (check[i] == 0) 
			{
				//1)
				if (index == 0) flag = 1;
				else 
				{
					if (compare[index-1] == '<') { if (result[index-1] < result[index ]) { flag = 1; } }
					else if (compare[index-1] == '>') { if (result[index-1] > result[index]) flag = 1; }
				}
			} //������ �ִµ�? �׷��� ������ �ְ� ������ ������ �ִ´�. �׸��� �ƴϸ� �Լ� ��ü�� ������ �ٽ� �ǵ��ư��� ���� i�� �� �����ͺ��� ����.
			///////////�ᱹ check�迭�� ������ flag����(�Լ���������)�� �ϰ� � ���ڸ� �־������� ���ҵ� �Ѵ�. ////////////////////
		//�Ϳ�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ����� ����� ����� ���ư��� �ϴ÷� �����
			if (flag)
			{
				check[i] = 1;
				getMax(index + 1);
				check[i] = 0;
			}
			//1�̸� ���� �ִ´�. i�ϳ� �ٰ� �ٸ��� �ִ´�. �̰� �����̴�. flag���ұ��� �Ѵ�. ó�� üũ�迭�� �߰��� 1�� �ٲ��༭ ��� ����.
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) cin >> compare[i];

	getMax(0);
	

}