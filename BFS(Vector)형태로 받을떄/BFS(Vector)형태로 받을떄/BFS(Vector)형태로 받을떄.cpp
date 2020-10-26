// BFS(Vector)형태로 받을떄.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int q[100];
int first = -1;
int back = -1;
int ch[10];
int sizeOfnode;
vector<int> map[10];

int main()
{
	/*
	2가지 방법이 있다.
	1) first와 back인덱스를 잡아서 while(first<back) 을 하면서 사실 큐인데 배열로 해서 배열에서 빼는것처럼 first를 뺄때마다 +1해주고 연결되어있는노드를 또 배열에 넣어줄때마다 back을 +1
	2) 큐를 선언해서 맨앞에 연결되어있는것 팝하고 연결되어있는것 다 큐안에 넣는다. (체크 안되어있는것들)

	*/
	
	cin >> sizeOfnode;
	for (int i = 1; i <= sizeOfnode; i++) {
		int a, b;
		cin >> a >> b;
		//무방향
		map[a].push_back(b);
		map[b].push_back(a);
	}
	ch[1] = 1;
	//q[++back] = map[1][0];
	//일단 처음에 1로 시작
	q[++back] = 1;
	while (first < back) {
		int cur = q[++first];
		cout << cur << " ";
		for (int i = 0; i < map[cur].size(); i++) {
			if (ch[map[cur][i]] == 0 ) {
				ch[map[cur][i]] = 1; //이게 중요하다.
				q[++back] = map[cur][i];
			}
		}
	}
	return 0;

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
