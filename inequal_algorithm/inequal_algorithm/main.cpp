#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int printMax;
int printMin;
char compare[100];
int result[100];
int check[100]; //어떤 숫자를 넣었는지 확인하는 배열 , 그 숫자를 넣었으면 안넣는다.
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
		
		//재귀 형식으로 들어간다. 그때그때 넣고 비교 넣고 비교
		//재귀형식 다 넣어버린다. 하지만 비교하기 때문에 CHECK배열을 걸어 하나하나씩 비교 하는것 처럼 해결한다.
		//알고리즘은 똑같다. 근데 이게 훨씬 쉬운 방식이다. 니가 하려는 플레그 방식으로 continue 넘기는 방식은 복잡하다 너무 ... 이게 맞다. 재귀는
		//재귀는 최대한 간단한 방법으로 구현해야한다.
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
			} //끝내고 넣는데? 그렇게 따지면 넣고 끝내고 다음것 넣는다. 그리고 아니면 함수 자체를 끝내서 다시 되돌아가서 빼고 i가 그 다음것부터 돈다.
			///////////결국 check배열은 끝내는 flag역할(함수를끝내는)도 하고 어떤 숫자를 넣었는지의 역할도 한다. ////////////////////
		//와우~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 가즈아 가즈아 가즈아 날아가자 하늘로 가즈아
			if (flag)
			{
				check[i] = 1;
				getMax(index + 1);
				check[i] = 0;
			}
			//1이면 빼고 넣는다. i하나 줄고 다른거 넣는다. 이건 순열이다. flag역할까지 한다. 처음 체크배열이 중간에 1로 바꿔줘서 재귀 들어간다.
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) cin >> compare[i];

	getMax(0);
	

}