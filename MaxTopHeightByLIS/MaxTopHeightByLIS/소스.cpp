#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Brick
{
	int width;
	int height;
	int weight;
	//생성자를 만들어 줘야 거기에 따라 움직인다. 
	Brick(int a,int b,int c)
	{
		width = a; height = b; weight = c;
	}
	bool operator<(Brick& B)//넓이에 따라 정렬한다.
	{
		width < B.width;
	}//const를 안붙여 보았다.
};	

int dy[1000];

int main()
{
	int n;
	cin >> n;
	//Brick 배열 만들 필요없다. 벡터를 만들면 배열 수를 안정해도 되잖아. 정렬도 내 기준에 따라 할수 있고
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