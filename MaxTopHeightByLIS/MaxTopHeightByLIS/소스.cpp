#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Brick
{
	int width;
	int height;
	int weight;
	//�����ڸ� ����� ��� �ű⿡ ���� �����δ�. 
	Brick(int a,int b,int c)
	{
		width = a; height = b; weight = c;
	}
	bool operator<(Brick& B)//���̿� ���� �����Ѵ�.
	{
		width < B.width;
	}//const�� �Ⱥٿ� ���Ҵ�.
};	

int dy[1000];

int main()
{
	int n;
	cin >> n;
	//Brick �迭 ���� �ʿ����. ���͸� ����� �迭 ���� �����ص� ���ݾ�. ���ĵ� �� ���ؿ� ���� �Ҽ� �ְ�
	vector<Brick> B;
	for (int i = 0; i < n; i++)
	{
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;
		B.push_back(Brick(temp1, temp2, temp3));
	}
	sort(B.begin(), B.end());

	B[1]=
	for(int i=2;)


}