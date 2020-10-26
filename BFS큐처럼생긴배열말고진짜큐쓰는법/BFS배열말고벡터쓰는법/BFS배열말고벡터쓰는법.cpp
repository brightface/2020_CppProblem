// BFS배열말고벡터쓰는법.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

queue<int> q;
vector<int> map[10];
int ch[10];
int sizeOfNode;
int sizeOfEdge;
int dist[10];
int main()
{
	cin >> sizeOfNode>>sizeOfEdge;
	for (int i = 0; i < sizeOfEdge; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);//방향그래프
	}
	//1부터 시작
	q.push(1);
	ch[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		//ch[cur] = 1; 여기서 체크하면 안된다. 중요하다!!! 프론트에서 체크하는거 아니다.큐에 넣을떄 체크하는거다.
		//cout << cur<<" ";
		q.pop();
		for (int i = 0; i < map[cur].size(); i++) {
			if (ch[map[cur][i]] == 0) {
				q.push(map[cur][i]);
				ch[map[cur][i]] = 1;
				dist[map[cur][i]] = dist[cur] + 1;
			}
		}
	}
	cout << endl;
	for (int i = 2; i <= sizeOfNode; i++) {
		cout<< i <<": " << dist[i] << endl;
	}

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
